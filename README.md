## zLog
A simple console **message-logger** using & made with *C++*.

### Setup
1. To get started, download the latest release, and extract it.
2. Inside of your project, create an include folder with zLog.h, and a lib folder with zLog.lib.
3. Open your project settings in Visual Studio 2022-26, navigate to C/C++ - General and inside of Additional Include Directories add the path to the include folder. Then, go to Linker - General and find Additional Library Directories and add the path to the lib folder. And finally, go to Linker - Input and inside of Additional Dependencies add "zLog.lib".

*Note: Make sure to add #include <zlog.h> inside the file that you are going to use zLog in. Also, pretty sure this will not work on anything but Windows as of right now.*

### Using zLog
*Info Log:*
```
zlog::Info("info message");
```

*Warning Log:*
```
zlog::Warning("warning message");
```

*Error Log:*
```
zlog::Error("error message");
```

*Timestamps:*
```
zLog::EnableTimestamp(true);
```

<img width="931" height="576" alt="example" src="https://github.com/user-attachments/assets/713dbd8b-8fe6-4d85-8011-f082082ef974" />
