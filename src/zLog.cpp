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
    bool showCategoryColors = true;
    WORD defaultColor = 7;

    void Initialize()
    {
        CONSOLE_SCREEN_BUFFER_INFO info;

        GetConsoleScreenBufferInfo(
            GetStdHandle(STD_OUTPUT_HANDLE),
            &info
        );

        defaultColor = info.wAttributes;
    }

    void SetColor(WORD color)
    {
        SetConsoleTextAttribute(
            GetStdHandle(STD_OUTPUT_HANDLE),
            color
        );
    }

    void ResetColor()
    {
        SetColor(defaultColor);
    }

    void EnableTimestamp(bool enabled)
    {
        showTimestamp = enabled;
    }

    void EnableCategoryColors(bool enabled)
    {
        showCategoryColors = enabled;
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

    void PrintCategory(const std::string& category, WORD color)
    {
        if (!category.empty())
        {
            if (showCategoryColors)
            {
                SetColor(color);
            }
            else
            {
                ResetColor();
            }

            std::cout << "[" << category << "] ";

            ResetColor();
        }
    }

    void Info(const std::string& message, const std::string& category)
    {
        SetColor(7);

        std::cout << "[*] ";

        ResetColor();

        PrintTimestamp();

        PrintCategory(category, 7);

        std::cout << message << std::endl;

        ResetColor();
    }

    void Warning(const std::string& message, const std::string& category)
    {
        SetColor(14);

        std::cout << "[!] ";

        ResetColor();

        PrintTimestamp();

        PrintCategory(category, 14);

        std::cout << message << std::endl;

        ResetColor();
    }

    void Error(const std::string& message, const std::string& category)
    {
        SetColor(12);

        std::cout << "[-] ";

        ResetColor();

        PrintTimestamp();

        PrintCategory(category, 12);

        std::cout << message << std::endl;

        ResetColor();
    }

    void Success(const std::string& message, const std::string& category)
    {
        SetColor(10);

        std::cout << "[+] ";

        ResetColor();

        PrintTimestamp();

        PrintCategory(category, 10);

        std::cout << message << std::endl;

        ResetColor();
    }
}
