
#include <utils/benchmark.hpp>

#include <fstream>
#include <utility>

Benchmark::Benchmark(std::string label, bool logToFile)
    : label_(std::move(label)), start_(Clock::now()), logToFile_(logToFile) {}

Benchmark::~Benchmark() {
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

[[nodiscard]] auto Benchmark::elapsed() const -> double {
    return std::chrono::duration_cast<
               std::chrono::duration<double, std::milli>>(Clock::now() - start_)
        .count();
}
