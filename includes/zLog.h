#pragma once

#include <string>

namespace zLog
{
    void EnableTimestamp(bool enabled);

    void Info(const std::string& message);
    void Warning(const std::string& message);
    void Error(const std::string& message);
}
