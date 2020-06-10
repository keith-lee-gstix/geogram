set(VORPALINE_ARCH_64 true)
set(VORPALINE_BUILD_DYNAMIC true)
include(${GEOGRAM_SOURCE_DIR}/cmake/platforms/Linux-gcc.cmake)


set(ARM64_FLAGS -pthread -march=armv8-a -O2)

add_flags(CMAKE_CXX_FLAGS -DGEO_OS_L4T -std=c++11 ${ARM64_FLAGS})
add_flags(CMAKE_C_FLAGS -DGEO_OS_L4T ${ARM64_FLAGS})
