#include <zLog.h>

int main()
{
    zLog::EnableTimestamp(true);

    zLog::Info("info message", "no color category");
    zLog::Warning("warning message", "no color category");
    zLog::Error("error message", "no color category");
    zLog::Success("success message", "no color category");

    zLog::EnableCategoryColors(false);

    zLog::Info("info message", "color category");
    zLog::Warning("warning message", "color category");
    zLog::Error("error message", "color category");
    zLog::Success("success message", "color category");

    return 0;
}
