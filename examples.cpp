#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdarg>
#include "include/GDebugger/all.hpp"

void example1()
{
    std::cout << "Printing speed test" << std::endl;
    GDebugger::timing::timer timer;
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
    GDebugger::timing::timer timer;
    GDebugger::logging::logger logger;
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
    std::cout << GDebugger::testing::testcase(&someOperation,(unsigned int) 4,(size_t) 1, (long) 3,"otherString").getMessage();
}

void example4()
{
    GDebugger::logging::tracker<unsigned int> UB;
    std::cout << UB << std::endl;
    GDebugger::logging::tracker<unsigned int> n("n",&std::cout,0);
    n = 5;
    decltype(n)::setDefaultNotifications(decltype(n)::notifications::read,false);
    decltype(n)::setDefaultNotifications(decltype(n)::notifications::others,false);
    GDebugger::logging::tracker<unsigned int> factorial("FactorialAcc",&std::cout,1);
    decltype(n)::setDefaultNotifications(decltype(n)::notifications::others,true);
    for(GDebugger::logging::tracker<unsigned int> i(&std::cout,1); i <= n; i++)
        factorial *= i;
    GDebugger::logging::tracker<unsigned int> six = 6;
    decltype(n)::setDefaultNotifications(decltype(n)::notifications::read,true);
    six.setNotifications(decltype(six)::notifications::others,false);
    std::cout << "Six is " << (six > factorial ? "higher than":"lower or equal to ") << factorial << " which is the factorial of 5" << std::endl;
}

int main()
{
    example1();
    example2();
    example3();
    example4();
}
