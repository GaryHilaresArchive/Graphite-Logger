#include "../include/Graphite-Logger/logging.hpp"

int main()
{
    GraphiteLogger::Logging::Logger logger;
    logger.addOutput(&std::cout);
    logger << "Test";
}
