#pragma once

#include <variant>
#define FMT_HEADER_ONLY

#include <fmt/chrono.h>
#include <fmt/color.h>
#include <fmt/format.h>
#include <fmt/ranges.h>

#include <fstream>
#include <string>

enum class LogLevel : uint8_t { DEBUG, INFO, WARN, ERROR, FATAL, PRINT };

static std::ofstream logFile_;
static LogLevel      currentLevel_ = LogLevel::DEBUG;

// Convert log level to string
inline auto getLevelString(LogLevel level) -> std::string {
    switch (level) {
        case LogLevel::DEBUG:
            return "DEBUG";
        case LogLevel::INFO:
            return "INFO";
        case LogLevel::WARN:
            return "WARN";
        case LogLevel::ERROR:
            return "ERROR";
        case LogLevel::FATAL:
            return "FATAL";
        case LogLevel::PRINT:
            return "PRINT";
    }
}

// Convert log level to console color
inline auto getLevelColor(LogLevel level) -> fmt::terminal_color {
    switch (level) {
        case LogLevel::DEBUG:
            return fmt::terminal_color::cyan;
        case LogLevel::INFO:
            return fmt::terminal_color::green;
        case LogLevel::WARN:
            return fmt::terminal_color::yellow;
        case LogLevel::ERROR:
            return fmt::terminal_color::red;
        case LogLevel::FATAL:
            return fmt::terminal_color::magenta;
        default:
            return fmt::terminal_color::white;
    }
}

// Set log file
inline void setLogFile(const std::string& filename) {
    if (logFile_.is_open()) {
        logFile_.close();
    }
    logFile_.open(filename, std::ios::app);
}

// Set current log level
inline void setLevel(LogLevel level) {
    currentLevel_ = level;
}

// Core logging function (single variadic template handles all cases)
template <typename... Args>
void log(LogLevel level, const Args&... args) {
    if (level < currentLevel_) {
        return;
    }

    // Timestamp
    auto now       = std::chrono::system_clock::now();
    auto timestamp = std::chrono::system_clock::to_time_t(now);

    // Format message
    std::string message =
        fmt::format("{}", fmt::join({fmt::format("{}", args)...}, " "));

    std::string logLine;
    if (level == LogLevel::PRINT) {
        logLine = fmt::format("{}\n", message);
    } else {
        // Final log line
        logLine = fmt::format("[{}] [{}] {}\n", getLevelString(level),
                              timestamp, message);
    }

    auto color = getLevelColor(level);
    fmt::print(fg(color), "{}", logLine);

    // File output without color
    if (logFile_.is_open()) {
        logFile_ << logLine;
        logFile_.flush();
    }
}

// Convenience functions
template <typename... Args>
inline void debug(const Args&... args) {
    log(LogLevel::DEBUG, args...);
}

template <typename... Args>
inline void info(const Args&... args) {
    log(LogLevel::INFO, args...);
}

template <typename... Args>
inline void warn(const Args&... args) {
    log(LogLevel::WARN, args...);
}

template <typename... Args>
inline void error(const Args&... args) {
    log(LogLevel::ERROR, args...);
}

template <typename... Args>
inline void fatal(const Args&... args) {
    log(LogLevel::FATAL, args...);
}

template <typename... Args>
inline void print(const Args&... args) {
    log(LogLevel::PRINT, args...);
}
