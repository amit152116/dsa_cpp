#include "bits/stdc++.h"
#include "utils/benchmark.hpp"
#include "utils/randomNumbers.hpp"

void merge(std::vector<int>& arr, int start, int mid, int end) {
    std::vector<int> brr;
    int              i = start;
    int              j = mid + 1;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            brr.push_back(arr[i]);
            i++;
        } else {
            brr.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid) {
        brr.push_back(arr[i]);
        i++;
    }
    while (j <= end) {
        brr.push_back(arr[j]);
        j++;
    }
    for (int k = start; k <= end; k++) {
        arr[k] = brr[k - start];
    }
    return;
}

void mergeSort(std::vector<int>& arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
    return;
}

void parallelMergeSort(std::vector<int>& arr, int start, int end,
                       int threshold) {
    if (end - start <
        threshold) {  // Threshold for switching to single-threaded sort
        mergeSort(arr, start, end);
        return;
    }

    int mid = start + (end - start) / 2;

    std::thread leftThread(parallelMergeSort, std::ref(arr), start, mid,
                           threshold);
    std::thread rightThread(parallelMergeSort, std::ref(arr), mid + 1, end,
                            threshold);

    leftThread.join();
    rightThread.join();

    merge(arr, start, mid, end);
}

auto main() -> int {
    auto arr1 = generateRandomNums(20000000, 1243);

    auto arr2 = arr1;
    auto arr3 = arr1;

    std::vector<int> result;
    double           threadDuration, duration;

    int num_threads = std::thread::hardware_concurrency();  // e.g., 8
    int threshold   = arr1.size() / num_threads;            // size per thread
    std::cout << "No. of threads : " << num_threads << std::endl;
    std::cout << "Threshold : " << threshold << std::endl;

    {
        Benchmark bench("Parallel Sort");
        parallelMergeSort(arr1, 0, arr1.size(), threshold);
        threadDuration = bench.elapsed();
    }

    {
        Benchmark bench("Sort");
        mergeSort(arr3, 0, arr3.size() - 1);
        duration = bench.elapsed();
    }

    auto percent = (duration - threadDuration) * 100.0 / threadDuration;

    std::cout << "Parallel mergeSort is " << percent
              << "% faster than mergeSort" << std::endl;

    return 0;
}
