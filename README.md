# Graphite Logger
[![badge-lastcommit](https://img.shields.io/github/last-commit/GaryNLOL/Graphite-Logger?style=for-the-badge)](https://github.com/GaryNLOL/Graphite-Logger/commits/main)
[![badge-openissues](https://img.shields.io/github/issues-raw/GaryNLOL/Graphite-Logger?style=for-the-badge)](https://github.com/GaryNLOL/Graphite-Logger/issues)
[![badge-license](https://img.shields.io/github/license/GaryNLOL/Graphite-Logger?style=for-the-badge)](https://github.com/GaryNLOL/Graphite-Logger/blob/main/LICENSE)
[![badge-contributors](https://img.shields.io/github/contributors/GaryNLOL/Graphite-Logger?style=for-the-badge)](https://github.com/GaryNLOL/Graphite-Logger/graphs/contributors)
[![badge-codesize](https://img.shields.io/github/languages/code-size/GaryNLOL/Graphite-Logger?style=for-the-badge)](https://github.com/GaryNLOL/Graphite-Logger)

## What is Graphite Logger?
Graphite Logger is a logging library for C++.

### Features
- Scalable.
- Free.
- Open-source.

## Platforms
- Cross-platform.

## Dependencies
- None, it just uses the standard C++ library.

## Usage
Sample code:
```cpp
#define GRAPHITE_LOGGER__USE_DEFAULT_LOG_LEVELS
#include >Graphite-Logger/logging.hpp>

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
#include <Graphite-Logger/logging.hpp>

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
#include <Graphite-Logger/logging.hpp>

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
#include <Graphite-Logger/logging.hpp>

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

## Contributing
### Pull requests
We encourage you to make pull requests. To do so, follow those steps:
1. Clone the repository.
2. Start the repository in your local computer.
3. Think about one issue or feature you want to work on or go to the issues sections of GitHub and pick one.
4. Commit your changes.
5. Push your changes to your fork.
6. Create a pull request.
That's it!

### Feature requests
If you want to request a feature, please do it in the Issues section. Additionally, mark it clearly as a feature request and then provide the maximum details you can. Follow this format:
```markdown
## Description:
Describe your feature clearly.

## Example outputs:
Explain what is supposed to happen (e. g. what your function should return when is called).
Post as many examples as you can.

## Notes:
If there is something you must add do it here.
```

### Issues
You're welcome to posts issues. Just use the following format:
```markdown
## Description:
Describe your problem clearly.

## Minimal reproducible example:
Post the minimal piece of code that can reproduce the problem.

## Expected VS actual output:
A clear explanation about the output that you expected to obtain and the output you obtained.

## Platform:
Include your OS.

## Notes:
If there is something you must add do it here.
```

## Useful links
- [C++ Style Guide](https://github.com/GaryNLOL/GSS-Language/blob/main/docs/C%2B%2B%20Style%20Guide.md).
- [Discord Server.](https://discord.gg/RQN6gcDQwX)
