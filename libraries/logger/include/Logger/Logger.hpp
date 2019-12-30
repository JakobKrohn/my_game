#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <chrono>
#include <cstring>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <memory>

#define __FILENAME__ \
    (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define print(...) \
    log_lib::Logger::getInstance().log(__FILENAME__, " [", __LINE__, "] ", __VA_ARGS__)

namespace log_lib
{

enum class Mode
{
    NONE,
    TERMINAL,
    FILE,
    FULL
};

class Logger
{
public:
    static Logger &getInstance()
    {
        static Logger instance;
        return instance;
    }

    Logger(Logger const &) = delete;
    void operator=(Logger const &) = delete;

    ~Logger();

    void setMode(Mode mode);

    template <class... Msg>
    void log(Msg const &... msg)
    {
        if (m_mode == Mode::NONE)
            return;

        std::ostringstream stream;
        using List = int[];
        (void)List{0, ((void)(stream << msg), 0)...};

        writeLog(stream.str());
    }

private:
    Mode m_mode;
    std::fstream m_file;
    int m_numberOfRuns;

    Logger();

    void writeLog(std::string message);

    void readNumberOfRuns();

    void logNumberOfRuns();

    void openFile();

    void closeFile();

    std::string readLastLogLine();

    void createHeader();
};

} // namespace log_lib

// https://stackoverflow.com/questions/21806561/concatenating-strings-and-numbers-in-variadic-template-function

#endif // LOGGER_HPP