#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <mutex>
#include <fstream>
class Logger {
    private:
std::ofstream logFile;
std::mutex logMutex;
public:
Logger();
void log(const std::string& user,
const std::string& host,
const std::string& type,
const std::string& status);
~Logger();
};
#endif