#define LOG_LEVEL DEBUG
#include <logger.h>

int main(void) {
    int x = 4;
    LOG_DEBUG("Value of x: %d", x);
    return 0;
}
