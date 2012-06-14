#pragma once

//#include <boost/optional.hpp>
//#include <boost/date_time/posix_time/posix_time.hpp>
#include <sys/time.h>
#include <sys/resource.h>

#include <stdexcept>

namespace utils {

//namespace pt = boost::posix_time;

class MinimalisticTimer {
    public:
        MinimalisticTimer(): totalTime(0.0), started(false) {}

        void start() {
            rusage usage;
            getrusage(RUSAGE_SELF, &usage);
            started = true;
            startTime = usage.ru_utime.tv_sec + usage.ru_utime.tv_usec / 1000000.0;
        }

        void stop() {
            if (!started) {
                throw std::runtime_error("timer has not been started");
            }
            started = false;
            rusage usage;
            getrusage(RUSAGE_SELF, &usage);
            double currentTime = usage.ru_utime.tv_sec + usage.ru_utime.tv_usec / 1000000.0;
            totalTime = currentTime - startTime;
        }

        void reset() {
            totalTime = 0.0;
            started = false;
        }

        double getTime() const {
            return totalTime;
        }
    private:
        //boost::optional<pt::ptime> startTime;
        double startTime;
        double totalTime;
        bool started;
};

}
