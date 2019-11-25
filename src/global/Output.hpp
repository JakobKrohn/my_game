#ifndef OUTPUT_H
#define OUTPUT_H

#include <chrono>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

#define __FILENAME__ \
    (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define print(...)\
    Logger::getInstance().log(__FILENAME__, " [", __LINE__, "] ", __VA_ARGS__)

enum class LogMode {
    NONE, 
    TERMINAL, 
    FILE, 
    FULL
};

class Logger {
public: 

    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    // Non copyable
    Logger(Logger const&) = delete;
    void operator = (Logger const&) = delete;

    void setMode(LogMode mode) {
        mode_ = mode;
    }

    template <class ... Msg>
    void log(Msg const& ... msg) {
        if (mode_ == LogMode::NONE) {
            return;
        }
        std::ostringstream stream;
        using List = int[];
        (void)List{0, ( (void) (stream << msg), 0) ... };
        std::cout << stream.str() << "\n";
    }
    
private: 

    LogMode mode_;

    Logger() : mode_(LogMode::NONE)
    {};

};

// https://stackoverflow.com/questions/21806561/concatenating-strings-and-numbers-in-variadic-template-function

#endif // OUTPUT_H