#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "hidden.hpp"

#undef __hidden__AX32WFAJP

namespace myBugDebugger
{
    namespace logging
    {
        class logger
        {
        private:
            std::string name;
            std::vector<std::ostream*> outputs;
            template<typename First>
            std::string getMessage(First first)
            {
                return myBugDebugger::__hidden__AX32WFAJP::convertToString(first);
            }
            template<typename First, typename... Args>
            std::string getMessage(First first, Args... args)
            {
                return myBugDebugger::__hidden__AX32WFAJP::convertToString(first) + getMessage(args...);
            }
            class loggerhelper
            {
            private:
                template<typename First>
                std::string getMessage(First first)
                {
                    return myBugDebugger::__hidden__AX32WFAJP::convertToString(first);
                }
                template<typename First, typename... Args>
                std::string getMessage(First first, Args... args)
                {
                    return myBugDebugger::__hidden__AX32WFAJP::convertToString(first) + getMessage(args...);
                }
                std::vector<std::ostream*>& outputs;
            public:
                loggerhelper(std::vector<std::ostream*>& _outputs): outputs(_outputs)
                {

                }
                template<typename... Args>
                loggerhelper& operator<<(Args... args)
                {
                    std::string arrangedMessage = getMessage(args...);
                    for(unsigned int i = 0; i < this->outputs.size(); i++)
                        *(this->outputs[i]) << arrangedMessage;
                    return *this;
                }
                ~loggerhelper()
                {
                    for(unsigned int i = 0; i < this->outputs.size(); i++)
                        *this->outputs[i] << ".\n";
                }
            };
        public:
            logger(const std::vector<std::ostream*>& outputs = {}, const std::string& name = "Logger")
            {
                this->name = name;
                this->outputs = outputs;
            }
            template<typename... Args>
            loggerhelper operator<<(Args... args)
            {
                std::time_t now = std::time(0);
                std::string nowInStr = std::ctime(&now);
                std::string arrangedMessage = (std::string) "[" + nowInStr.substr(0,nowInStr.size()-1) + "] " + name + ": " + getMessage(args...);
                for(unsigned int i = 0; i < this->outputs.size(); i++)
                    *(this->outputs[i]) << arrangedMessage;
                return loggerhelper(this->outputs);
            }
            void addOutput(std::ostream* stream)
            {
                this->outputs.push_back(stream);
            }
        };
    }
}

#define __hidden__AX32WFAJP __hidden__
