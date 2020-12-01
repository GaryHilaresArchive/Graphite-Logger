#pragma once
#include <ctime>

namespace myBugDebugger
{
    namespace timing
    {
        class timer
        {
        private:
            bool started;
            long double timeElapsed;
            long double lastStart;
        public:
            timer()
            {
                this->timeElapsed = 0;
                this->started = false;
            }
            bool isRunning() const
            {
                return this->started;
            }
            double getTime() const
            {
                if(started)
                    return (this->timeElapsed + clock() - this->lastStart) / CLOCKS_PER_SEC;
                else
                    return this->timeElapsed / CLOCKS_PER_SEC;
            }
            void start()
            {
                this->lastStart = clock();
                this->started = true;
            }
            void stop()
            {
                this->timeElapsed += clock() - this->lastStart;
                this->started = false;
            }
            void reset()
            {
                if(this->started)
                    this->stop();
                this->timeElapsed = 0;
            }
        };
    }
}
