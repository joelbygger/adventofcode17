
# Where the logic is.
new_cpp_library_shared(
        NAME checksum_lib
        SOURCES checksum.cpp checksum.hpp
        INCLUDE_PUBLIC ${CMAKE_CURRENT_LIST_DIR}
        NO_CPPCHECK false
        USE_CLANG_TIDY_IF_CLANG_COMPILER true)

# For command line execution.
new_cpp_executable(
        NAME day2
        SOURCES main.cpp
        LINK_PRIVATE checksum_lib
        NO_CPPCHECK false
        USE_CLANG_TIDY_IF_CLANG_COMPILER true)
