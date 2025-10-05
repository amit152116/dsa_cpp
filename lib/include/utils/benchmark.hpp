#pragma once
#include <fmt/color.h>
#include <fmt/core.h>

#include <chrono>
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
    Benchmark(const Benchmark&) = default;
    Benchmark(Benchmark&&)      = delete;

    auto operator=(const Benchmark&) -> Benchmark& = default;
    auto operator=(Benchmark&&) -> Benchmark&      = delete;

    explicit Benchmark(std::string label, bool logToFile = false);

    ~Benchmark();

    [[nodiscard]] auto elapsed() const -> double;

   private:
    using Clock = std::chrono::high_resolution_clock;
    std::string                    label_;
    std::chrono::time_point<Clock> start_;
    bool                           logToFile_;
};
