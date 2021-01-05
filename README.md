# MyBugDebugger
Simple **header only** library for debugging.

## Project is open to contributions!

- Report a bug or request a feature.
- Give new ideas for debugging tools.
- Update function implementation for efficiency.

## Files

### myBugDebugger/all.hpp

Includes:
- Testing.
- Timing.
- Logging.

### myBugDebugger/testing.hpp

Includes:
-Testing.

### myBugDebugger/logging.hpp

Includes:
- Logging.

### myBugDebugger/timing.hpp

Includes:
- Timing.

### myBugDebugger/hidden.hpp

Includes nothing.

## Sections
### Testing
#### `myBugDebugger::testing::testcase` (class)

##### Public Methods
`template<typename callable, typename T, typename... _Args> testcase(callable f, T expectedOutput, _Args&&... args)` (ctor.) -> Creates a testcase with the function, expected output and arguments provided.

`std::string getMessage() const` -> Returns the testcase message including arguments, output and whether it was accepted or not.

`bool isAccepted() const` -> Returns `true` if the testcase was accepted and `false` if not.

##### Public Members

Not public members.

### Logging
#### `myBugDebugger::logging::logger` (class)

##### Public Methods

`logger(const std::vector<std::ostream*>& outputs = {}, const std::string& name = "Logger")` (ctor.) -> Creates a logger and sets it name and outputs.

`void addOutput(std::ostream* stream)` -> Adds an output for the logger.

`loggerhelper operator<<(Args... args)` -> Sends the message input to all the logger's output.

##### Public Members

Not public members.

### Timing
#### `myBugDebugger::timing::timer` (class)

##### Public Methods

`timer()` (ctor.) -> Returns a timer.

`bool isRunning() const` -> Returns whether the timer is running or not.

`double getTime() const` -> Returns the transcurred time.

`void start()` -> Starts the timer.

`void stop()` -> Stops the timer.

`void reset()` -> Resets the timer.

##### Public Members

Not public members.
