#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <string>

namespace Eda::Util {
enum class LogInfoLevel { DEBUG, INFO, WARNING, ERROR, CRITICAL };

static std::map<LogInfoLevel, std::string> levelTexts = {
    {LogInfoLevel::DEBUG, "[DEBUG]: "},
    {LogInfoLevel::INFO, "[INFO]: "},
    {LogInfoLevel::WARNING, "[WARNING] "},
    {LogInfoLevel::ERROR, "[ERROR] "},
    {LogInfoLevel::CRITICAL, "[CRITICAL ERROR] "}};

class Logger {
public:
  static void Log(LogInfoLevel level, std::string msg) {
    static std::ofstream logfile("log.txt");

    std::cout << levelTexts[level] << msg << std::endl;
    if (logfile.is_open()) {
      logfile << levelTexts[level] << msg << std::endl;
    }
  }
};
} // namespace Eda::Util
