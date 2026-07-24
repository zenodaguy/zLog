#pragma once

#include <string>

namespace zLog
{
    void EnableTimestamp(bool enabled);
    void EnableCategoryColors(bool enabled);

    void Info(const std::string& message, const std::string& category = "");
    void Warning(const std::string& message, const std::string& category = "");
    void Error(const std::string& message, const std::string& category = "");
    void Success(const std::string& message, const std::string& category = "");
}
