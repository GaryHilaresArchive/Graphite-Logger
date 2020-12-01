#pragma once
#include <iostream>
#include <vector>

namespace myBugDebugger
{
    namespace logging
    {
        class logger
        {
        private:
            std::vector<std::ostream*> outputs;
        public:
            void operator<<(const std::string& message)
            {
                for(unsigned int i = 0; i < this->outputs.size(); i++)
                    *(this->outputs[i]) << message << "\n";
            }
            void operator()(const std::string& message)
            {
                for(unsigned int i = 0; i < outputs.size(); i++)
                    *(this->outputs[i]) << message << "\n";
            }
            void addOutput(std::ostream* stream)
            {
                this->outputs.push_back(stream);
            }
        };
    }
}
