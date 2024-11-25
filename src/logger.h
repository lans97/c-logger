#ifndef LOGGER_H
#define LOGGER_H

#include <time.h>
#include <string.h>
#include <stdio.h>

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

#define TRACE_TAG TRACE_COLOR "TRACE" RST_COLOR
#define DEBUG_TAG DEBUG_COLOR "DEBUG" RST_COLOR
#define INFO_TAG INFO_COLOR "INFO" RST_COLOR
#define WARNING_TAG WARNING_COLOR "WARNING" RST_COLOR
#define ERROR_TAG ERROR_COLOR "ERROR" RST_COLOR
#define FATAL_TAG FATAL_COLOR "FATAL" RST_COLOR

#define LOG_FMT             "%s%s%s | %s%-7s%s | %s%s (%d)%s | in function %s%s%s: "
#define LOG_ARGS(LEVEL)     TS_COLOR, get_timestamp(), RST_COLOR,\
                            LEVEL##_COLOR, LEVEL##_TAG, RST_COLOR,\
                            FILE_COLOR, _FILE, __LINE__, RST_COLOR,\
                            FUNC_COLOR, __FUNCTION__, RST_COLOR

#define LOG_PRINT(format, ...) printf(format, __VA_ARGS__)

#if LOG_LEVEL <= TRACE
#define LOG_TRACE(msg, args...) LOG_PRINT(LOG_FMT msg "\n", LOG_ARGS(TRACE), ## args)
#else
#define LOG_TRACE(msg, args...)
#endif

#if LOG_LEVEL <= DEBUG
#define LOG_DEBUG(msg, args...) LOG_PRINT(LOG_FMT msg "\n", LOG_ARGS(DEBUG), ## args)
#else
#define LOG_DEBUG(msg, args...)
#endif

#if LOG_LEVEL <= INFO
#define LOG_INFO(msg, args...) LOG_PRINT(LOG_FMT msg "\n", LOG_ARGS(INFO), ## args)
#else
#define LOG_INFO(msg, args...)
#endif

#if LOG_LEVEL <= WARNING
#define LOG_WARNING(msg, args...) LOG_PRINT(LOG_FMT msg "\n", LOG_ARGS(WARNING), ## args)
#else
#define LOG_WARNING(msg, args...)
#endif

#if LOG_LEVEL <= ERROR
#define LOG_ERROR(msg, args...) LOG_PRINT(LOG_FMT msg "\n", LOG_ARGS(ERROR), ## args)
#else
#define LOG_ERROR(msg, args...)
#endif

#if LOG_LEVEL <= FATAL
#define LOG_FATAL(msg, args...) LOG_PRINT(LOG_FMT msg "\n", LOG_ARGS(FATAL), ## args)
#else
#define LOG_FATAL(msg, args...)
#endif

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
