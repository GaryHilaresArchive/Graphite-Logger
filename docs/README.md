<p align="center"><img alt="logo" src="https://github.com/GaryNLOL/Graphite-Logger/blob/main/images/logo.png"></p>
<p align="center">
<img alt="badge-lastcommit" src="https://img.shields.io/github/last-commit/GaryNLOL/Graphite-Logger?style=for-the-badge">
<img alt="badge-openissues" src="https://img.shields.io/github/issues-raw/GaryNLOL/Graphite-Logger?style=for-the-badge">
<img alt="badge-license" src="https://img.shields.io/github/license/GaryNLOL/Graphite-Logger?style=for-the-badge">
<img alt="badge-contributors" src="https://img.shields.io/github/contributors/GaryNLOL/Graphite-Logger?style=for-the-badge">
<img alt="badge-codesize" src="https://img.shields.io/github/languages/code-size/GaryNLOL/Graphite-Logger?style=for-the-badge">
</p>

## What is Graphite Logger?
Graphite Logger is a simple, one-header-only logging library for C++.

### Features
- Scalable.
- Free.
- Open-source.
- Easy to use. 

## Platforms
- Cross-platform.

## Dependencies
- Standard C++ 11 support.

## Usage
### Installation
Graphite Logger does not require any spcial installation or building because currently it is a header only library. 
Graphite Logger just needs to be included in your project. 

To do so, follow these steps:
1. Download the repository either by cloning it with Git or from the GitHub page.
2. Move it to either your compiler's include path or to your project's include path.
3. Include it in your source file.
- If you have put it in the compiler's path, add the following line at the begin of yout code:
```cpp
#include <GraphiteLogger/GraphiteLogger.hpp>
```
- Else, write:
```cpp
#include "${your own path}/GraphiteLogger/GraphiteLogger.hpp"
```
- Where "your own path" is the path to the directory where you have Graphite Logger include files.

### Samples
Using default log levels (same as Linux):
```cpp
#define GRAPHITE_LOGGER__USE_DEFAULT_LOG_LEVELS
#include <GraphiteLogger/GraphiteLogger.hpp>

int main()
{
    using namespace GraphiteLogger::LogLevels;
    GraphiteLogger::Logger logger("UsefulLogger",debug);
    logger.addOutput(&std::cout);
    logger[emergency] << "Terminating program... Exit code: " << 4;
    logger[critical] << "Undefined behaviour detected.";
    logger[error] << "atoi() cannot transform \"479878754524347787864456546\" (out of range).";
    logger[warning] << "Comparison of integers of different flavors.";
    logger[notice] << "Pass by const reference would be more efficient than past by value";
    logger[info] << "Exited struggleFunction() successfully.";
    logger[debug] << "i is " << 1;
}
```

Using own levels:
```cpp
#include <GraphiteLogger/GraphiteLogger.hpp>

int main()
{
    constexpr int my_own_level_1 = 4;
    constexpr int my_own_level_2 = 5;
    constexpr int my_own_level_3 = 6;
    GraphiteLogger::Logger logger("UsefulLogger",my_own_level_2);
    logger.addOutput(&std::cout);
    logger[my_own_level_1] << "Some important data that will be shown.";
    logger[my_own_level_2] << "Some not as important data that will be shown.";
    logger[my_own_level_3] << "Some data that will not be shown.";
}
```

Logging to files:
```cpp
#include <GraphiteLogger/GraphiteLogger.hpp>

int main()
{
    constexpr int my_own_level_1 = 4;
    constexpr int my_own_level_2 = 5;
    constexpr int my_own_level_3 = 6;
    GraphiteLogger::Logger logger("UsefulLogger",my_own_level_2);
    std::ofstream ofile("out.log");
    logger.addOutput(&ofile);
    logger[my_own_level_1] << "Some important data that will be shown.";
    logger[my_own_level_2] << "Some not as important data that will be shown.";
    logger[my_own_level_3] << "Some data that will not be shown.";
}
```

Logging to multiple outputs:
```cpp
#include <GraphiteLogger/GraphiteLogger.hpp>

int main()
{
    constexpr int my_own_level_1 = 4;
    std::ofstream ofile1("out1.log");
    GraphiteLogger::Logger logger("UsefulLogger",my_own_level_1,{&std::cout,&ofile1});
    std::ofstream ofile2("out2.log");
    std::ofstream ofile3("out3.log");
    logger.addOutput(&ofile2);
    logger.addOutput(&ofile3);
    logger[my_own_level_1] << "Logging to ofile1, ofile2, ofile3 and to std::cout!";
}
```

## Useful links
- [Contributing Guidelines](https://github.com/GaryNLOL/Graphite-Logger/blob/main/docs/CONTRIBUTING.md)
- [Project's Style Guide](https://github.com/GaryNLOL/Style-Guides/).
- [Discord Server.](https://discord.gg/RQN6gcDQwX)
