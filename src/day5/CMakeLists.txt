
# Where the logic is.
new_cpp_library_shared(
        NAME jump_instructions_lib
        SOURCES jump_instructions.cpp jump_instructions.hpp
        INCLUDE_PUBLIC ${CMAKE_CURRENT_LIST_DIR}
        NO_CPPCHECK false
        USE_CLANG_TIDY_IF_CLANG_COMPILER true)

# For command line execution.
new_cpp_executable(
        NAME day5
        SOURCES main.cpp
        LINK_PRIVATE jump_instructions_lib
        NO_CPPCHECK false
        USE_CLANG_TIDY_IF_CLANG_COMPILER true)
