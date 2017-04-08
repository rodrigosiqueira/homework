#include <string>
#include <iostream>
#include "Log.hpp"

void Log::e(const std::string& pMsg)
{
  Log::doLog("ERROR", pMsg);
}

void Log::d(const std::string& pMsg)
{
  Log::doLog("DEBUG", pMsg);
}

void Log::i(const std::string& pMsg)
{
  Log::doLog("INFO", pMsg);
}

void Log::w(const std::string& pMsg)
{
  Log::doLog("WARN", pMsg);
}

void Log::doLog(const std::string& pType, const std::string& pMsg)
{
  std::cout << pType << ": " << pMsg << std::endl;
}
