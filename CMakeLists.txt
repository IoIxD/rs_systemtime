cmake_minimum_required(VERSION 3.21)
project(rs_systemtime)

FILE(GLOB sources src/dummy.c)

add_library(${PROJECT_NAME} ${sources})

# We use Rust's image crate because it does what C++ can't, somehow.
FetchContent_Declare(
    Corrosion
    GIT_REPOSITORY https://github.com/corrosion-rs/corrosion.git
    GIT_TAG v0.5 # Optionally specify a commit hash, version tag or branch here
)
FetchContent_MakeAvailable(Corrosion)

# Import targets defined in a package or workspace manifest `Cargo.toml` file
corrosion_import_crate(MANIFEST_PATH Cargo.toml)
target_link_libraries(${PROJECT_NAME} bctime)

set(RS_SYSTEMTIME_INCLUDE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE INTERNAL "RS_SYSTEMTIME_INCLUDE_DIRECTORY")