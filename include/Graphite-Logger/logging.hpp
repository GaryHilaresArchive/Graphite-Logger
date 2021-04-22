#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <array>
#include "../../src/Graphite-Logger/hidden.hpp"

namespace GraphiteLogger
{
    namespace Logging
    {
        using GraphiteLogger::__hidden__::convertToString;
        class Logger
        {
        private:
            std::string name;
            std::vector<std::ostream*> outputs;
            template<typename First>
            std::string getMessage(First first)
            {
                return convertToString(first);
            }
            template<typename First, typename... Args>
            std::string getMessage(First first, Args... args)
            {
                return convertToString(first) + getMessage(args...);
            }
            class LoggerHelper
            {
            private:
                template<typename First>
                std::string getMessage(First first)
                {
                    return convertToString(first);
                }
                template<typename First, typename... Args>
                std::string getMessage(First first, Args... args)
                {
                    return convertToString(first) + getMessage(args...);
                }
                std::vector<std::ostream*>& outputs;
            public:
                LoggerHelper(std::vector<std::ostream*>& _outputs): outputs(_outputs) {}
                template<typename... Args>
                LoggerHelper& operator<<(Args... args)
                {
                    std::string arrangedMessage = getMessage(args...);
                    for(unsigned int i = 0; i < this->outputs.size(); i++)
                        *(this->outputs[i]) << arrangedMessage;
                    return *this;
                }
                ~LoggerHelper()
                {
                    for(unsigned int i = 0; i < this->outputs.size(); i++)
                        *this->outputs[i] << ".\n";
                }
            };
        public:
            Logger(const std::vector<std::ostream*>& outputs = {}, const std::string& name = "Logger")
            {
                this->name = name;
                this->outputs = outputs;
            }
            template<typename... Args>
            LoggerHelper operator<<(Args... args)
            {
                std::time_t now = std::time(0);
                std::string nowInStr = std::ctime(&now);
                std::string arrangedMessage = (std::string) "[" + nowInStr.substr(0,nowInStr.size()-1) + "] " + name + ": " + getMessage(args...);
                for(unsigned int i = 0; i < this->outputs.size(); i++)
                    *(this->outputs[i]) << arrangedMessage;
                return LoggerHelper(this->outputs);
            }
            void addOutput(std::ostream* stream)
            {
                this->outputs.push_back(stream);
            }
        };
    }
}
