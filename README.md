# C Logger

A fairly simple logger configurable at compile time.

## Usage

1. Define `LOG_LEVEL` (NOTSET, TRACE, INFO, DEBUG, WARNING, ERROR, FATAL).
2. Include logger.h
3. Use any `LOG_X` macro

### Example
```C
#define LOG_LEVEL DEBUG
#include <logger.h>

int main(void) {
    int x = 4;
    LOG_DEBUG("Value of x: %d", x);
    return 0;
}
```

Output:

    2024-11-25 15:21:54 | DEBUG | main.c (6) | in function main: Value of x: 4

## Thanks

Do check [dmcrodrigues/macro-logger](https://github.com/dmcrodrigues/macro-logger)
