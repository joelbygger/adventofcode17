
# Where the logic is.
new_cpp_library_shared(
        NAME captcha_lib
        SOURCES captcha.cpp captcha.hpp
        INCLUDE_PUBLIC ${CMAKE_CURRENT_LIST_DIR}
        NO_CPPCHECK false)

# For command line execution.
new_cpp_executable(
        NAME day1
        SOURCES main.cpp
        LINK_PRIVATE captcha_lib
        NO_CPPCHECK false)
