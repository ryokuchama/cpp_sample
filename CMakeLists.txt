cmake_minimum_required(VERSION 3.5)
project(encryptor)
set(CMAKE_CXX_STANDARD 17)
option(TESTING "unittest mode" OFF)



add_subdirectory(src)

if(TESTING)
    add_subdirectory(test)
endif(TESTING)

