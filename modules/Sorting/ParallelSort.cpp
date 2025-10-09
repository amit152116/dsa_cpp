#include "bits/stdc++.h"
#include "utils/benchmark.hpp"
#include "utils/logger.hpp"
#include "utils/randomNumbers.hpp"

#include <cmath>
#include <execution>

void merge(std::vector<int>& src, std::vector<int>& dest, int start, int mid,
           int end) {
    int i = start, j = mid + 1, k = start;

    while (i <= mid && j <= end) {
        if (src[i] <= src[j]) {
            dest[k++] = src[i++];
        } else {
            dest[k++] = src[j++];
        }
    }
    while (i <= mid) {
        dest[k++] = src[i++];
    }
    while (j <= end) {
        dest[k++] = src[j++];
    }
}

void mergeSort(std::vector<int>& src, std::vector<int>& dest, int start,
               int end) {
    if (start < end) {
        int mid = start + ((end - start) / 2);
        mergeSort(dest, src, start, mid);
        mergeSort(dest, src, mid + 1, end);

        // Merge from src into dest
        merge(src, dest, start, mid, end);
    }
}

void parallelMergeSort(std::vector<int>& src, std::vector<int>& dest, int start,
                       int end, int threshold) {
    // Threshold for switching to single-threaded sort
    if (end - start < threshold) {
        mergeSort(src, dest, start, end);
        return;
    }

    int mid = start + ((end - start) / 2);

    std::thread rightThread(parallelMergeSort, std::ref(dest), std::ref(src),
                            mid + 1, end, threshold);

    parallelMergeSort(dest, src, start, mid, threshold);

    rightThread.join();

    merge(src, dest, start, mid, end);
}

auto main() -> int {
    auto masterArr = generateRandomNums(20000000, 1243);

    std::vector<int> result;
    double           threadDuration = NAN;
    double           duration       = 0.0;

    {
        auto nThreads  = std::thread::hardware_concurrency();  // e.g., 8
        auto threshold = masterArr.size() / (nThreads);  // size per thread
        std::cout << "No. of threads : " << nThreads << '\n';
        std::cout << "Threshold : " << threshold << '\n';

        std::vector<int> thresholds = {524288};

        for (int threshold : thresholds) {
            std::vector<int> buffer = masterArr;
            std::vector<int> arr    = masterArr;

            print("Threshold : ", threshold);
            Benchmark bench("Parallel Sort");
            parallelMergeSort(arr, buffer, 0, masterArr.size() - 1, threshold);
            threadDuration = bench.elapsed();
        }
        {
            std::vector<int> arr = masterArr;
            Benchmark        bench("std::Sort with Parallelism");
            std::sort(std::execution::par, arr.begin(), arr.end());
        }
    }

    {
        std::vector<int> arr    = masterArr;
        std::vector<int> buffer = masterArr;
        Benchmark        bench("Sort");
        mergeSort(arr, buffer, 0, arr.size() - 1);
        duration = bench.elapsed();
    }

    auto percent = (duration - threadDuration) * 100.0 / threadDuration;

    std::cout << "Parallel mergeSort is " << percent
              << "% faster than mergeSort" << std::endl;

    for (int i = 0; i < 100; i++) {
        fmt::print("{}, ", masterArr[i]);
    }
    return 0;
}
