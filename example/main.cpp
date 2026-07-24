#include <zLog.h>

int main()
{
    zLog::EnableTimestamp(true);

    zLog::Info("info message");
    zLog::Warning("warning message");
    zLog::Error("error message");

    return 0;
}
