A better C* library for getting the date and time.

```c
SystemTime *time = new_system_time();
// ...
Duration *elapsed = system_time_get_duration(time);
float secs = duration_as_secs_f32(elapsed);
printf("%1.1f\n", secs);
// ...
free(time);
```

*it's actually just bindings to Rust's std::time::SystemTime

It's used via Cmake:

```cmake
FetchContent_Declare(
    better_ctime
    GIT_REPOSITORY "https://github.com/IoIxD/better_ctime.git"
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(better_ctime)
include_directories(${BETTER_CTIME_INCLUDE_DIRECTORY})
```