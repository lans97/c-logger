/**
 * @file logger.h
 * @brief This file provides macros for logging messages
 *
 * Config:
 * #define LOG_LEVEL NOTSET/TRACE/DEBUG/INFO/WARNING/ERROR/FATAL
 *
 * Usage:
 * #include <logger.h>
 * ...
 * LOG_TRACE("Hello, world!\nHere's a number: %d", 4);
 * ...
 */
#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <string.h>
#include <time.h>

#define NOTSET 0x00
#define TRACE 0x01
#define DEBUG 0x02
#define INFO 0x03
#define WARNING 0x04
#define ERROR 0x05
#define FATAL 0x06

#ifndef LOG_LEVEL
#define LOG_LEVEL DEBUG
#endif

#define _FILE strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__

#define RST_COLOR "\033[0m"

#define TRACE_COLOR "\033[38;2;175;238;238m"
#define DEBUG_COLOR "\033[38;2;135;206;250m"
#define INFO_COLOR "\033[38;2;144;238;144m"
#define WARNING_COLOR "\033[38;2;255;223;0m"
#define ERROR_COLOR "\033[38;2;255;69;0m"
#define FATAL_COLOR "\033[38;2;139;0;0m"

#define TS_COLOR "\033[38;2;119;136;153m"
#define FILE_COLOR "\033[38;2;0;191;255m"
#define FUNC_COLOR "\033[38;2;186;85;211m"

#define TRACE_TAG "TRACE"
#define DEBUG_TAG "DEBUG"
#define INFO_TAG "INFO"
#define WARNING_TAG "WARNING"
#define ERROR_TAG "ERROR"
#define FATAL_TAG "FATAL"

/* Full log message format. Considers usage of ANSI color escape codes. */
#define LOG_FMT "%s[%s]%s %s%-7s%s | %s%s (%4d)%s | in function %s%s%s: "
/* Aruments to pass to LOG_PRINT macro using LOG_FMT. Includes ANSI color escape
 * codes. */
#define LOG_ARGS(LEVEL)                                                        \
    TS_COLOR, get_timestamp(), RST_COLOR, LEVEL##_COLOR, LEVEL##_TAG,          \
        RST_COLOR, FILE_COLOR, _FILE, __LINE__, RST_COLOR, FUNC_COLOR,         \
        __FUNCTION__, RST_COLOR

/**
 * @macro LOG_PRINT
 * @brief Prints the log line with a given format
 */
#define LOG_PRINT(target, format, ...) fprintf(target, format, __VA_ARGS__)

/**
 * @macro LOG_TRACE
 * @brief Logs trace message.
 *
 * @param msg Format string to log.
 * @param args Values to print with msg as format.
 */
#if LOG_LEVEL <= TRACE
#define LOG_TRACE(msg, args...)                                                \
    LOG_PRINT(stdout ,LOG_FMT msg "\n", LOG_ARGS(TRACE), ##args)
#else
#define LOG_TRACE(msg, args...)
#endif

/**
 * @macro LOG_DEBUG
 * @brief Logs debug message.
 *
 * @param msg Format string to log.
 * @param args Values to print with msg as format.
 */
#if LOG_LEVEL <= DEBUG
#define LOG_DEBUG(msg, args...)                                                \
    LOG_PRINT(stdout, LOG_FMT msg "\n", LOG_ARGS(DEBUG), ##args)
#else
#define LOG_DEBUG(msg, args...)
#endif

/**
 * @macro LOG_INFO
 * @brief Logs informational message.
 *
 * @param msg Format string to log.
 * @param args Values to print with msg as format.
 */
#if LOG_LEVEL <= INFO
#define LOG_INFO(msg, args...)                                                 \
    LOG_PRINT(stdout, LOG_FMT msg "\n", LOG_ARGS(INFO), ##args)
#else
#define LOG_INFO(msg, args...)
#endif

/**
 * @macro LOG_WARNING
 * @brief Logs warning message.
 *
 * @param msg Format string to log.
 * @param args Values to print with msg as format.
 */
#if LOG_LEVEL <= WARNING
#define LOG_WARNING(msg, args...)                                              \
    LOG_PRINT(stdout, LOG_FMT msg "\n", LOG_ARGS(WARNING), ##args)
#else
#define LOG_WARNING(msg, args...)
#endif

/**
 * @macro LOG_ERROR
 * @brief Logs error message.
 *
 * @param msg Format string to log.
 * @param args Values to print with msg as format.
 */
#if LOG_LEVEL <= ERROR
#define LOG_ERROR(msg, args...)                                                \
    LOG_PRINT(stderr, LOG_FMT msg "\n", LOG_ARGS(ERROR), ##args)
#else
#define LOG_ERROR(msg, args...)
#endif

/**
 * @macro LOG_FATAL
 * @brief Logs fatal error message.
 *
 * @param msg Format string to log.
 * @param args Values to print with msg as format.
 */
#if LOG_LEVEL <= FATAL
#define LOG_FATAL(msg, args...)                                                \
    LOG_PRINT(stderr, LOG_FMT msg "\n", LOG_ARGS(FATAL), ##args)
#else
#define LOG_FATAL(msg, args...)
#endif

/**
 * @fn get_timestamp
 * @brief Used by logger to get build timestamp string.
 *
 * @return timestamp with format "%Y-%m-%d %H:%M:%S".
 */
static inline char* get_timestamp() {
    static char buffer[64];
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 64, "%Y-%m-%d %H:%M:%S", timeinfo);
    return buffer;
}

#endif
