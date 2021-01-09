#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <array>
#include "hidden.hpp"

#undef __hidden__AX32WFAJP

namespace GDebugger
{
    namespace logging
    {
        using GDebugger::__hidden__AX32WFAJP::convertToString;
        class logger
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
            class loggerhelper
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
        template<typename T>
        class tracker
        {
        private:
            constexpr static size_t notificationTypesAmount = 5;
            T val;
            mutable std::ostream* log;
            inline static std::array<bool,notificationTypesAmount> defaultNotifications = {true,true,true,true,true};
            std::string trackerName;
            bool initialized;
            std::array<bool,notificationTypesAmount> notificate;
        public:
            enum notifications
            {
                read = 0,
                write = 1,
                undefinedBehavior = 2,
                constructor = 3,
                others = 4,
            };
            static void setDefaultNotifications(notifications notification, bool enable)
            {
                defaultNotifications[notification] = enable;
            }
            tracker()
            {
                this->log = &std::cout;
                this->trackerName = "Tracker";
                this->initialized = false;
                this->notificate = defaultNotifications;
                if(this->notificate[notifications::constructor])
                    *this->log << "[Constructor] " << this->trackerName << ": Variable created but not initialized." << std::endl;
            }
            tracker(T newVal)
            {
                this->trackerName = "Tracker";
                this->log = &std::cout;
                this->val = newVal;
                this->initialized = true;
                this->notificate = defaultNotifications;
                if(this->notificate[notifications::constructor])
                    *this->log << "[Constructor] " << this->trackerName << ": Variable initialized to " << convertToString(newVal) << "." << std::endl;
            }
            tracker(std::ostream* newLog, T newVal)
            {
                this->trackerName = "Tracker";
                this->log = newLog;
                this->val = newVal;
                this->initialized = true;
                this->notificate = defaultNotifications;
                if(this->notificate[notifications::constructor])
                    *this->log << "[Constructor] " << this->trackerName << ": Variable initialized to " << convertToString(newVal) << "." << std::endl;
            }
            tracker(std::string newTrackerName, std::ostream* newLog, T newVal)
            {
                this->trackerName = newTrackerName;
                this->log = newLog;
                this->val = newVal;
                this->initialized = true;
                this->notificate = defaultNotifications;
                if(this->notificate[notifications::constructor])
                    *this->log << "[Constructor] " << this->trackerName << ": Variable initialized to " << convertToString(newVal) << "." << std::endl;
            }
            tracker(tracker<T>&& rvalue)
            {
                this->val = std::move(rvalue);
                this->log = std::move(rvalue.log);
                this->trackerName = std::move(rvalue.trackerName);
                this->initialized = std::move(rvalue.initialized);
                this->notificate = rvalue.notificate;
                if(this->notificate[notifications::constructor])
                    *this->log << "[Constructor] " << this->trackerName << ": Called move constructor. Value assigned to " << convertToString(rvalue.val) << std::endl;
            }
            tracker(const tracker<T>& lvalue)
            {
                this->val = lvalue;
                this->log = lvalue.log;
                this->trackerName = lvalue.trackerName;
                this->initialized = lvalue.initialized;
                this->notificate = lvalue.notificate;
                if(this->notificate[notifications::constructor])
                    *this->log << "[Constructor] " << this->trackerName << ": Called copy constructor. Value assigned to " << convertToString<T>(lvalue.val) << std::endl;
            }
            T operator=(const T& newVal)
            {
                this->val = newVal;
                this->initialized = true;
                if(this->notificate[notifications::write])
                    *log << "[Write] " << this->trackerName << ": Value assigned to " << convertToString(newVal) << "." << std::endl;
                return this->val;
            }
            operator T() const
            {
                if(!this->initialized && this->notificate[notifications::undefinedBehavior])
                    *this->log << "[Undefined Behavior] " << this->trackerName <<  ": Reading unitialized value." << std::endl;
                if(this->notificate[notifications::read])
                    *this->log << "[Read] " << trackerName << ": Value " << convertToString(this->val) << " read." << std::endl;
                return val;
            }
            operator T&()
            {
                if(!this->initialized && this->notificate[notifications::undefinedBehavior])
                    *this->log << "[Undefined Behavior] " << this->trackerName <<  ": Reading unitialized value." << std::endl;
                if(this->notificate[notifications::others])
                    *this->log << "[Others] " << trackerName << ": Got reference." << std::endl;
                return val;
            }
            T& getVal()
            {
                if(this->notificate[notifications::others])
                    *this->log << "[Others] " << trackerName << ": Got reference." << std::endl;
                return val;
            }
            void setNotifications(notifications notification, bool enable)
            {
                this->notificate[notification] = enable;
            }
            auto operator++(int) -> decltype(this->val++)
            {
                T old = this->val;
                decltype(this->val++) ret = this->val++;
                if(old == this->val && this->notificate[notifications::others])
                    *this->log << "[Others] " << trackerName << ": Value " << convertToString(this->val) << " possible reads in operator++." << std::endl;
                else if(this->notificate[notifications::others])
                    *this->log << "[Others] " << trackerName << ": Value " << convertToString(this->val) << " writes (and possible reads) in operator++." << std::endl;
                return ret;
            }
            auto operator++() -> decltype(++this->val)
            {
                T old = this->val;
                decltype(++this->val) ret = ++this->val;
                if(old == this->val && this->notificate[notifications::others])
                    *this->log << "[Others] " << this->trackerName << ": Value " << convertToString(this->val) << " possible reads in operator++(int)." << std::endl;
                else if(this->notificate[notifications::others])
                    *this->log << "[Others] " << this->trackerName << ": Value " << convertToString(this->val) << " writes (and possible reads) in operator++(int)." << std::endl;
                return ret;
            }
            #define createOperator(operatorVar) template<typename U> \
            auto operator operatorVar(U param) -> decltype(this->val operatorVar param) \
            { \
                T old = this->val; \
                decltype(this->val operatorVar param) ret = this->val operatorVar param; \
                if(old == this->val && this->notificate[notifications::others]) \
                    *this->log << "[Others] " << this->trackerName << ": Possible reads in operatoroperatorVar. New value: " << convertToString(this->val) << std::endl; \
                else if(this->notificate[notifications::others]) \
                    *this->log << "[Others] " << this->trackerName << ": Writes and possible reads in operatoroperatorVar. Current value: " << convertToString(this->val) << std::endl; \
                return ret; \
            }
            createOperator(+=);
            createOperator(+);
            createOperator(-=);
            createOperator(-);
            createOperator(*=);
            createOperator(*);
            createOperator(/=);
            createOperator(/);
            createOperator(%=);
            createOperator(%);
            #undef createOperator
        };
    }
}

#define __hidden__AX32WFAJP __hidden__
