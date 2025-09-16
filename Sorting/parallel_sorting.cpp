#include "bits/stdc++.h"

#include <cstdint>

constexpr int     MAX      = INT32_MAX;
constexpr int     N        = 1000000;
const std::string FILENAME = "random_numbers.txt";

std::vector<int> generateRandomNums() {
    auto               start = std::chrono::high_resolution_clock::now();
    std::random_device rd;               // Obtain a random number from hardware
    std::mt19937       generator(rd());  // Seed the generator

    // Define the range
    std::uniform_int_distribution<int> distribution(1, MAX);

    std::vector<int> arr(N);

    for (int i = 0; i < N; ++i) {
        arr[i] = distribution(generator);
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Time taken to generate random numbers: " << duration.count()
              << " ms" << std::endl;

    return arr;
}

void writeNumbersToFile(const std::vector<int>& numbers,
                        const std::string&      filename) {
    std::ofstream out(filename);

    if (out.is_open()) {
        for (const auto& num : numbers) {
            out << num << "\n";
        }
        out.close();
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

std::vector<int> readNumbersFromFile() {
    std::ifstream    in(FILENAME);
    std::vector<int> numbers;
    int              number;

    if (in.is_open()) {
        while (in >> number) {
            numbers.push_back(number);
        }
        in.close();
    } else {
        std::cerr << "Unable to open file for reading." << std::endl;
    }

    return numbers;
}

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

void split_array(std::vector<int>& arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        split_array(arr, start, mid);
        split_array(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
    return;
}

void parallelMergeSort(std::vector<int>& arr, int start, int end) {
    if (end - start <
        10000) {  // Threshold for switching to single-threaded sort
        split_array(arr, start, end);
        return;
    }

    int mid = start + (end - start) / 2;

    std::thread leftThread(parallelMergeSort, std::ref(arr), start, mid);
    std::thread rightThread(parallelMergeSort, std::ref(arr), mid + 1, end);

    leftThread.join();
    rightThread.join();

    merge(arr, start, mid, end);
}
std::vector<int> parallelSort(std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1)
        return arr;

    parallelMergeSort(arr, 0, n - 1);
    return arr;
}
int main() {
    auto numbers = generateRandomNums();
    writeNumbersToFile(numbers, FILENAME);

    if (numbers.empty()) {
        std::cerr << "No numbers to sort." << std::endl;
        return 1;
    }

    auto start = std::chrono::high_resolution_clock::now();

    auto result = parallelSort(numbers);

    auto end = std::chrono::high_resolution_clock::now();
    auto threadDuration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken to sort in parallelSort: "
              << threadDuration.count() << " ms" << std::endl;

    writeNumbersToFile(result, "Sorted_" + FILENAME);

    start = std::chrono::high_resolution_clock::now();
    split_array(numbers, 0, numbers.size() - 1);
    end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken to sort in split_array: " << duration.count()
              << " ms" << std::endl;

    auto percent = (duration.count() - threadDuration.count()) * 100.0 /
                   threadDuration.count();

    std::cout << "Parallel sort is " << percent << "% faster than split_array"
              << std::endl;

    return 0;
}
