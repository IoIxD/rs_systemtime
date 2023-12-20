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

# Building

Download rust and run `make`. The resulting .a file will be in the root directory (or .dll if you use Windows).
