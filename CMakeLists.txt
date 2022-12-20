cmake_minimum_required(VERSION 3.16.5)
project(encryptor)
set(CMAKE_CXX_STANDARD 17)
option(TESTING "unittest mode" OFF)

find_library(CRYPTO
NAME libcryptopp.a
HINTS ${PROJECT_SOURCE_DIR}/cryptopp-CRYPTOPP_8_7_0/deps/usr/local/lib
REQUIRED)

add_subdirectory(src)
target_link_libraries(${PROJECT_NAME} PUBLIC ${CRYPTO})
target_include_directories(${PROJECT_NAME} PUBLIC 
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/cryptopp-CRYPTOPP_8_7_0/deps/usr/local/include/cryptopp)

if(TESTING)
    add_subdirectory(test)
endif(TESTING)
