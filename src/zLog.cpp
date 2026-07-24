#include <zLog.h>

#include <iostream>
#include <windows.h>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

namespace zLog
{
    bool showTimestamp = false;

    void SetColor(int color)
    {
        SetConsoleTextAttribute(
            GetStdHandle(STD_OUTPUT_HANDLE),
            color
        );
    }

    void ResetColor()
    {
        SetColor(7);
    }

    void EnableTimestamp(bool enabled)
    {
        showTimestamp = enabled;
    }

    std::string GetTimestamp()
    {
        auto now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

        std::tm localTime;
        localtime_s(&localTime, &currentTime);

        std::stringstream output;

        output << std::setfill('0')
            << std::setw(2) << localTime.tm_hour << ":"
            << std::setw(2) << localTime.tm_min << ":"
            << std::setw(2) << localTime.tm_sec;

        return output.str();
    }

    void PrintTimestamp()
    {
        if (showTimestamp)
        {
            std::cout << "[" << GetTimestamp() << "] ";
        }
    }

    void Info(const std::string& message)
    {
        SetColor(7);
        std::cout << "[*] ";
        ResetColor();

        PrintTimestamp();

        std::cout << message << std::endl;
    }

    void Warning(const std::string& message)
    {
        SetColor(14);
        std::cout << "[!] ";
        ResetColor();

        PrintTimestamp();

        std::cout << message << std::endl;
    }

    void Error(const std::string& message)
    {
        SetColor(12);
        std::cout << "[-] ";
        ResetColor();

        PrintTimestamp();

        std::cout << message << std::endl;
    }
}
