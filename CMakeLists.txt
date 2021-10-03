cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(RSA VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# add the executable
add_executable(Encrypt src/Encrypt.cpp)
add_executable(Decrypt src/Decrypt.cpp)


target_include_directories(Encrypt PUBLIC
                          ./include)
target_include_directories(Decrypt PUBLIC
                           ./include)                           