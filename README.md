## zLog
A simple console **message-logger** using & made with *C++*.

![GitHub release](https://img.shields.io/github/v/release/zenodaguy/zLog)

### Setup
1. To get started, download the latest release, and extract it.
2. Inside of your project, create an include folder with zLog.h, and a lib folder with zLog.lib.
3. Open your project settings in Visual Studio 2022-26, navigate to C/C++ - General and inside of Additional Include Directories add the path to the include folder. Then, go to Linker - General and find Additional Library Directories and add the path to the lib folder. And finally, go to Linker - Input and inside of Additional Dependencies add "zLog.lib".

*Note: Make sure to add #include <zlog.h> inside the file that you are going to use zLog in. Also, pretty sure this will not work on anything but Windows as of right now.*

### Using zLog
*Info Log:*
```
zLog::Info("info message");
```

*Warning Log:*
```
zLog::Warning("warning message");
```

*Error Log:*
```
zLog::Error("error message");
```

*Success Log:*
```
zLog::Success("success message");
```

*Timestamps:*
```
zLog::EnableTimestamp(true);
```

*Categories:*
```
zLog::Info("info message", "category name here"); // works with any type (info, error, warning, & success)
```

*Category Colors:*
```
zLog::EnableCategoryColors(false); // off
zLog::EnableCategoryColors(true); // on (default)
```

<img width="923" height="572" alt="example2" src="https://github.com/user-attachments/assets/9bc544de-33cc-48bb-b9c2-fe015b63b67a" />
