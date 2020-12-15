
# Where the logic is.
new_cpp_library_shared(
        NAME mem_reallocation_lib
        SOURCES mem_reallocation.cpp mem_reallocation.hpp
        INCLUDE_PUBLIC ${CMAKE_CURRENT_LIST_DIR}
        NO_CPPCHECK false
        USE_CLANG_TIDY_IF_CLANG_COMPILER false)

# For command line execution.
new_cpp_executable(
        NAME day6
        SOURCES main.cpp
        LINK_PRIVATE mem_reallocation_lib
        NO_CPPCHECK false
        USE_CLANG_TIDY_IF_CLANG_COMPILER false)
