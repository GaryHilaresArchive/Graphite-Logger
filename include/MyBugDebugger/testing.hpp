#pragma once
#include <iostream>

namespace myBugDebugger
{
    namespace testing
    {
        template<typename T>
        class testcase
        {
        private:
            T actualOutput;
            T expectedOutput;
        public:
            testcase(const T& actualOutput,const T& expectedOutput)
            {
                this->actualOutput = actualOutput;
                this->expectedOutput = expectedOutput;
            }
            bool accepted()
            {
                return this->actualOutput == this->expectedOutput;
            }
            std::string message()
            {
                return (std::string) "----------------\n    TESTCASE    \n----------------\nAccepted: " + (this->accepted() ? "Yes":"No") + "\n";
            }
        };
    }
}
