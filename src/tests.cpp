#define GRAPHITE_LOGGER__USE_DEFAULT_LOG_LEVELS
#include "../include/Graphite-Logger/logging.hpp"

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

    using namespace GraphiteLogger::LogLevels;
    logger = GraphiteLogger::Logger("UsefulLogger",critical);
    logger[emergency] << "Terminating program... Exit code: " << 4;
    logger[critical] << "Undefined behaviour detected.";
    logger[error] << "atoi() cannot transform \"479878754524347787864456546\" (out of range).";
    logger[warning] << "Comparison of integers of different flavors.";
    logger[notice] << "Pass by const reference would be more efficient than past by value";
    logger[info] << "Exited struggleFunction() successfully.";
    logger[debug] << "i is " << 1;
}
