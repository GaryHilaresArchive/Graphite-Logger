#define GRAPHITE_LOGGER__USE_DEFAULT_LOG_LEVELS
#include "../include/Graphite-Logger/logging.hpp"

int main()
{
    using namespace GraphiteLogger::LogLevels;
    GraphiteLogger::Logger logger("UsefulLogger",debug);
    logger.addOutput(&std::cout);
    logger[emergency] << "Terminating program...";
    logger[critical] << "Undefined behaviour detected.";
    logger[error] << "atoi() cannot transform \"479878754524347787864456546\" (out of range).";
    logger[warning] << "Comparison of integers of different flavors.";
    logger[notice] << "Pass by const reference would be more efficient than past by value";
    logger[info] << "Exited struggleFunction() successfully.";
    logger[debug] << "i is 1";
}
