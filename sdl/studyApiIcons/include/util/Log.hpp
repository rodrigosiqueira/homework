#ifndef __LOG_H__
#define __LOG_H__

#include <string>

class Log
{
  public:
    static void e(const std::string& pMsg);
    static void d(const std::string& pMsg);
    static void i(const std::string& pMsg);
    static void w(const std::string& pMsg);

  private:
    static void doLog(const std::string& pType, const std::string& pMsg);
};

#endif
