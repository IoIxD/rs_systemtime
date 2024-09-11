Bindings for Rust's `SystemTime` to C/C++, because what's built in to both languages, sucks to use.

# Usage

C++ Usage:
```cxx
#include "rs_systemtime.hpp"
auto time = new SystemTime();
auto elapsed = time->get_duration();
auto secs = elapsed->as_secs_f32();
printf("%1.1f\n", secs);
```

C Usage:
```c
#include "rs_systemtime.h"
SystemTime *time = new_system_time();
Duration *elapsed = system_time_get_duration(time);
float secs = duration_as_secs_f32(elapsed);
printf("%1.1f\n", secs);
free(time);
```

# Installation

It can be imported via cmake:

```cmake
FetchContent_Declare(
    rs_systemtime
    GIT_REPOSITORY "https://github.com/IoIxD/rs_systemtime.git"
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(rs_systemtime)
include_directories(${RS_SYSTEMTIME_INCLUDE_DIRECTORY})
```