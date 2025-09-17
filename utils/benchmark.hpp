#pragma once
#include <fmt/color.h>
#include <fmt/core.h>

#include <chrono>
#include <fstream>
#include <string>

// -----------------------------------------------------------------------------
// Benchmark Utility
// -----------------------------------------------------------------------------
// Usage:
//     {
//         Benchmark bench("Prims MST");
//         prims_MST();
//     } // prints "[Benchmark] Prims MST: 12.34 ms"
// -----------------------------------------------------------------------------
class Benchmark {
   public:
    Benchmark(const std::string& label, bool logToFile = false)
        : label_(label), start_(Clock::now()), logToFile_(logToFile) {}

    ~Benchmark() {
        std::string logLine =
            fmt::format("[Benchmark] {}: {:.3f} ms", label_, elapsed());

        // Print to console (green)
        fmt::print(fmt::fg(fmt::color::green), "{}\n", logLine);

        // Optional file output
        if (logToFile_) {
            static std::ofstream logFile("benchmark.log", std::ios::app);
            if (logFile.is_open()) {
                logFile << logLine << std::endl;
            }
        }
    }

    double elapsed() const {
        return std::chrono::duration_cast<
                   std::chrono::duration<double, std::milli>>(Clock::now() -
                                                              start_)
            .count();
    }

   private:
    using Clock = std::chrono::high_resolution_clock;
    std::string                    label_;
    std::chrono::time_point<Clock> start_;
    bool                           logToFile_;
};
