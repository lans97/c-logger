#define LOG_LEVEL TRACE
#include <logger.h>

int main(void) {
    int x = 4;
    LOG_TRACE("Value of x: %d", x);
    LOG_DEBUG("Value of x: %d", x);
    LOG_INFO("Value of x: %d", x);
    LOG_WARNING("Value of x: %d", x);
    LOG_ERROR("Value of x: %d", x);
    LOG_FATAL("Value of x: %d", x);
    return 0;
}
