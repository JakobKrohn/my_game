#ifndef LOGGER_LIB_HPP
#define LOGGER_LIB_HPP

#include <chrono>
#include <cstring>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#define __FILENAME__                                                           \
    (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define print(...)                                                             \
    log_lib::Logger::getInstance().log(__FILENAME__, " [", __LINE__, "] ",     \
                                       __VA_ARGS__)

#define print_limitimed(...)                                                       \
    log_lib::Logger::getInstance().log_timed(__FILENAME__, " [", __LINE__, "] ",     \
                                       __VA_ARGS__)

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
    void setTimeLimit(int limit);

    int getNumberOfStartups() const;

    template <class... Msg> void log(Msg const &... msg)
    {
        if (m_mode == Mode::NONE)
            return;

        std::ostringstream stream;
        using List = int[];
        (void)List{0, ((void)(stream << msg), 0)...};

        writeLog(stream.str());
    }

    template <class... Msg> void log_timed(Msg const &... msg)
    {
        using namespace std::chrono;
        auto now = system_clock::now();
        static auto timer = system_clock::from_time_t(0);

        if (m_mode == Mode::NONE)
            return;

        
        std::chrono::duration<double> last_print = now - timer;

        if (last_print.count() < m_timeLimit)
            return;
        
        timer = now;

        std::ostringstream stream;
        using List = int[];
        (void)List{0, ((void)(stream << msg), 0)...};

        writeLog(stream.str());
    }

  private:
    Mode m_mode;
    std::fstream m_file;
    int m_numberOfRuns;
    int m_timeLimit = 1;

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

#endif // LOGGER_LIB_HPP