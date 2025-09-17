#pragma once

#include "benchmark.hpp"
#include "bits/stdc++.h"

#include <cstdint>

constexpr int     MAX      = INT32_MAX;
const std::string FILENAME = "random_numbers.txt";

inline std::vector<int> generateRandomNums(int n, int max = MAX, int seed = 0) {
    std::vector<int> arr(n);
    {
        Benchmark bench("Generate Random Numbers");

        // If seed == 0, use random_device for "true random"
        // Otherwise, use the provided seed for reproducibility
        std::mt19937 generator(seed == 0 ? std::random_device{}() : seed);

        std::uniform_int_distribution<int> distribution(1, max);

        for (int i = 0; i < n; ++i) {
            arr[i] = distribution(generator);
        }
    }

    return arr;
}

inline void writeNumbersToFile(const std::vector<int>& numbers,
                               const std::string&      filename = FILENAME) {
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

inline std::vector<int> readNumbersFromFile(
    const std::string& filename = FILENAME) {
    std::ifstream    in(filename);
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
