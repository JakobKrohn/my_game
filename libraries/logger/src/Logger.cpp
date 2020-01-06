#include "Logger/Logger.hpp"

using namespace log_lib;

Logger::~Logger()
{
    logNumberOfRuns();
    closeFile();
    std::cout << "Logger destroyed\n";
}

void Logger::setMode(Mode mode)
{
    m_mode = mode;
}

const int Logger::getNumberOfStartups() const
{
    return m_numberOfRuns;
}

// Private
Logger::Logger() : m_mode(Mode::NONE)
{
    openFile();
}

void Logger::writeLog(std::string message)
{
    if (m_mode == Mode::TERMINAL)
    {
        std::cout << message << "\n";
    }
    else if (m_mode == Mode::FILE)
    {
        m_file << message;
    }
    else if (m_mode == Mode::FULL)
    {
        std::cout << message << "\n";
        m_file << message << "\n";
    }
}

void Logger::readNumberOfRuns()
{
    auto lastRun = readLastLogLine();
    if (lastRun.length() < 1)
        m_numberOfRuns = 0;
    else
        m_numberOfRuns = std::stoi(lastRun);
}

void Logger::logNumberOfRuns()
{
    m_file << ++m_numberOfRuns;
}

void Logger::openFile()
{
    m_file.open("log.txt", std::fstream::out | std::fstream::app | std::fstream::in);
    if (!m_file.is_open())
    {
        std::cout << "File could not be opened\n";
        m_file.close();
        return;
    }
    readNumberOfRuns();
    m_file.clear();

    createHeader();
}

void Logger::closeFile()
{
    if (m_file.is_open())
        m_file.close();
}

std::string Logger::readLastLogLine()
{
    m_file.seekg(-1, std::fstream::end); // go to one spot before the EOF

    bool found = true;
    while (found)
    {
        char ch;
        m_file.get(ch);

        if ((int)m_file.tellg() <= 1)
        {                    // If the data was at or before the 0th byte
            m_file.seekg(0); // The first line is the last line
            found = false;   // So stop there
        }
        else if (ch == '\n')
        {                  // If the data was a newline
            found = false; // Stop at the current position.
        }
        else
        {                                        // If the data was neither a newline nor at the 0 byte
            m_file.seekg(-2, std::fstream::cur); // Move to the front of that data, then to the front of the data before it
        }
    }

    std::string lastLine;
    getline(m_file, lastLine);

    return lastLine;
}

void Logger::createHeader()
{
    std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    m_file << "\n=====================================================\n";
    std::cout << "=====================================================\n";

    m_file << std::ctime(&time);
    std::cout << std::ctime(&time);

    m_file << "Number of runs: " << m_numberOfRuns << "\n";
    std::cout << "Number of runs: " << m_numberOfRuns << "\n";

    m_file << "=====================================================\n";
    std::cout << "=====================================================\n";
}