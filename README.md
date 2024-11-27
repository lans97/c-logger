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

    [2024-11-26 11:48:45] DEBUG   | main.c (   5) | in function main: Value of x: 4

## Building Example

```sh
cmake -S . -B build/ -D BUILD_EXAMPLES=On
cmake --build build
```

Force cmake to use Ninja multi config
```sh
cmake -S . -B build/ -G "Ninja Multi-Config" -D BUILD_EXAMPLES=On
cmake --build build --config Release
```

Then run the example:

```sh
./build/Release/example
```

And enjoy the pretty colors 😃.

## Thanks

Do check [dmcrodrigues/macro-logger](https://github.com/dmcrodrigues/macro-logger)
