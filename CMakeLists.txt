cmake_minimum_required(VERSION 3.5)
project(encryptor)
set(CMAKE_CXX_STANDARD 17)
option(TESTING "unittest mode" OFF)

include(ExternalProject)
ExternalProject_Add(
  ### Target name
  CRYPTO++
  ### Path to Git repository
  GIT_REPOSITORY https://github.com/weidai11/cryptopp
  ### Specify TAG
  GIT_TAG CRYPTOPP_8_7_0
  ### Path to source tree
  SOURCE_DIR ${DEPEND_LIB_ROOT}
  ### Specify Generator
  CMAKE_GENERATOR "Ninja"
  ### Add cmake args CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${DEPEND_LIB_ROOT} -DCMAKE_BUILD_TYPE=Release
  ### Path to build tree
  BINARY_DIR ${DEPEND_LIB_ROOT}/build
  BUILD_COMMAND ninja
)

### Test depends
add_dependencies(${PROJECT_NAME} CRYPTO++)

add_subdirectory(src)

if(TESTING)
    add_subdirectory(test)
endif(TESTING)

