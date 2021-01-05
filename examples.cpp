#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdarg>
#include "include/MyBugDebugger/all.hpp"

void example1()
{
    std::cout << "Printing speed test" << std::endl;
    myBugDebugger::timing::timer timer;
    timer.start();
    for(unsigned int i = 0; i < 100; i++)
        std::cout << 'N' << 1 << ": LoveLive!.\n";
    timer.stop();
    double coutTime = timer.getTime();
    timer.reset();
    timer.start();
    for(unsigned int i = 0; i < 100; i++)
        printf("%c%i%s",'N',1,": LoveLive!.\n");
    timer.stop();
    double printfTime = timer.getTime();
    std::cout << "Time taken by std::cout is : " << coutTime << " sec " << std::endl;
    std::cout << "Time taken by printf is : " << printfTime << " sec " << std::endl;
}

void example2()
{
    myBugDebugger::timing::timer timer;
    myBugDebugger::logging::logger logger;
    logger.addOutput(&std::cout);
    timer.start();
    logger << "Test";
    timer.stop();
    logger << "Time elapsed: " << timer.getTime();
}

unsigned int someOperation(unsigned int num1, unsigned int num2, std::string str)
{
    return num1 + num2 + (str == "someString");
}

void example3()
{
    std::cout << myBugDebugger::testing::testcase(&someOperation,(unsigned int) 4,(size_t) 1, (long) 3,"otherString").getMessage();
}

int main()
{
    example1();
    example2();
    example3();
}
