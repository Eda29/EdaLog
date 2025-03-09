# Eda::Util Logger

This is a simple logging utility for writing log messages to both the console and a log file (`log.txt`). It allows logging of messages at various levels of severity (DEBUG, INFO, WARNING, ERROR, and CRITICAL ERROR). The log messages are output both to the standard console and a file for later review, with each log level being associated with its own message prefix.

## Features

- Logs messages at 4 levels of severity:
  - `DEBUG`: Debug informational messages   
  - `INFO`: Regular informational messages
  - `WARNING`: Non-critical issues that should be addressed
  - `ERROR`: Critical errors that need immediate attention
  - `CRITICAL`: Severe errors that may cause the application to stop functioning
- Each message is printed to the console and written to a `log.txt` file.
- Log levels are associated with a text prefix to indicate the severity.

## Files
- **log.txt**: A text file where all log messages are written for persistent storage.

## Code Explanation

### `LogInfoLevel` Enum
This enum defines the different log levels supported by the logger:
- `DEBUG`
- `INFO`
- `WARNING`
- `ERROR`
- `CRITICAL`

Each log level is associated with a string representation that is printed when the log is written.

### `levelTexts` Map
A static map that maps each `LogInfoLevel` enum value to a corresponding string prefix that is printed along with the message. The prefixes are as follows:
- `[DEBUG]: ` for `DEBUG`
- `[INFO]: ` for `INFO`
- `[WARNING]: ` for `WARNING`
- `[ERROR]: ` for `ERROR`
- `[CRITICAL ERROR]: ` for `CRITICAL`

### `Logger` Class
This class contains a single static method for logging messages.

#### `static void Log(LogInfoLevel level, std::string msg)`
- **Parameters**:
  - `level`: The severity level of the log message (one of `LogInfoLevel` values).
  - `msg`: The message to log.
- **Functionality**:
  - Logs the message to the console using `std::cout`.
  - Appends the message to a `log.txt` file if it's open.
  - The log message is prefixed with the appropriate string based on the severity level.

### Example Usage

```cpp
#include "Log.hpp"

int main() {
  Eda::Util::Logger::Log(Eda::Util::LogInfoLevel::DEBUG, "This is an Debug informational message.");
  Eda::Util::Logger::Log(Eda::Util::LogInfoLevel::INFO, "This is an informational message.");
  Eda::Util::Logger::Log(Eda::Util::LogInfoLevel::WARNING, "This is a warning.");
  Eda::Util::Logger::Log(Eda::Util::LogInfoLevel::ERROR, "This is an error.");
  Eda::Util::Logger::Log(Eda::Util::LogInfoLevel::CRITICAL, "This is a critical error.");
  
  return 0;
}
```

In the example above:
- A message is logged for each level.
- Each message is prefixed with the corresponding severity label (`DEBUG`, `INFO`, `WARNING`, `ERROR`, `CRITICAL ERROR`).
- The message is displayed in the console and written to the `log.txt` file.

## Requirements
- C++11 or later (for static initialization and other features).
- A file system that allows reading and writing files.

## License
This code is provided under the GNU GPL-3.0 license.
