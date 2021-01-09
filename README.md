# GDebugger
GDebugger: Simple header only debugging tools library.

## Project is open to contributions!

- Report a bug or request a feature.
- Give new ideas for debugging tools.
- Update function implementation for efficiency.

## Files

### GDebugger/all.hpp

Includes:
- Testing.
- Timing.
- Logging.

### GDebugger/testing.hpp

Includes:
-Testing.

### GDebugger/logging.hpp

Includes:
- Logging.

### GDebugger/timing.hpp

Includes:
- Timing.

### GDebugger/hidden.hpp

Includes nothing.

## Sections
### Testing
#### `GDebugger::testing::testcase` (class)

##### Public Methods
`template<typename callable, typename T, typename... _Args> testcase(callable f, T expectedOutput, _Args&&... args)` (ctor.) -> Creates a testcase with the function, expected output and arguments provided.

`std::string getMessage() const` -> Returns the testcase message including arguments, output and whether it was accepted or not.

`bool isAccepted() const` -> Returns `true` if the testcase was accepted and `false` if not.

##### Public Members

Not public members.

### Logging
#### `GDebugger::logging::logger` (class)

##### Public Methods

`logger(const std::vector<std::ostream*>& outputs = {}, const std::string& name = "Logger")` (ctor.) -> Creates a logger and sets it name and outputs.

`void addOutput(std::ostream* stream)` -> Adds an output for the logger.

`loggerhelper operator<<(Args... args)` -> Sends the message input to all the logger's output.

##### Public Members

Not public members.

### `GDebugger::logging::tracker` (class template) **(Experimental)**

##### Public Methods

(This description is WIP).

##### Public Members

Not public Members

### Timing
#### `GDebugger::timing::timer` (class)

##### Public Methods

`timer()` (ctor.) -> Returns a timer.

`bool isRunning() const` -> Returns whether the timer is running or not.

`double getTime() const` -> Returns the transcurred time.

`void start()` -> Starts the timer.

`void stop()` -> Stops the timer.

`void reset()` -> Resets the timer.

##### Public Members

Not public members.
