#pragma once
#include <iostream>
#include "hidden.hpp"

#undef __hidden__AX32WFAJP

namespace GDebugger
{
    namespace testing
    {
        class testcase
        {
        private:
            std::string message;
            bool accepted;
        public:
            template<typename First>
            std::string getArguments(int n, First first)
            {
                n++;
                return "Argument " + std::to_string(n) + ": " + GDebugger::__hidden__AX32WFAJP::convertToString(first) + ".\n";
            }

            template<typename First, typename... Args>
            std::string getArguments(int n, First first, Args... args)
            {
                n++;
                return "Argument " + std::to_string(n) + ": " + GDebugger::__hidden__AX32WFAJP::convertToString(first) + ".\n" + getArguments(n,args...);
            }
            template<typename callable, typename T, typename... _Args>
            testcase(callable f, T expectedOutput, _Args&&... args)
            {
                static_assert(std::is_same<decltype(f(args...)),decltype(expectedOutput)>::value,"The return type is not of the same type that the expected output.");
                T actualOutput = f(args...);
                this->accepted = actualOutput == expectedOutput;
                this->message = (std::string) "---Testcase---\n" + "Arguments:\n" + getArguments(0,args...) + "Expected Output: " + GDebugger::__hidden__AX32WFAJP::convertToString(expectedOutput) + ".\nActual Output: " + GDebugger::__hidden__AX32WFAJP::convertToString(actualOutput) + ".\nAccepted: " + (this->accepted ? "Yes":"No") + "\n--------------\n";
            }
            std::string getMessage() const
            {
                return this->message;
            }
            bool isAccepted() const
            {
                return this->accepted;
            }
        };
    }
}

#define __hidden__AX32WFAJP __hidden__
