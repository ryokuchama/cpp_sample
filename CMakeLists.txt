cmake_minimum_required(VERSION 3.16.5)
project(encryptor)
set(CMAKE_CXX_STANDARD 17)
option(TESTING "unittest mode" OFF)
# include(FetchContent)
# FetchContent_Declare(
#   crypto++
#   URL https://github.com/weidai11/cryptopp/archive/refs/tags/CRYPTOPP_8_7_0.zip
# )
# FetchContent_MakeAvailable(crypto++)
add_subdirectory(src)
target_link_libraries(${PROJECT_NAME} PUBLIC crypto++)
set(DEPEND_LIB_ROOT ${PROJECT_BINARY_DIR}/depends)
set(CMAKE_PREFIX_PATH ${DEPEND_LIB_ROOT})
target_include_directories(${PROJECT_NAME} PUBLIC ${DEPEND_LIB_ROOT}/include)
# target_link_libraries(${DEPEND_LIB_ROOT}/lib)

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
  CMAKE_GENERATOR "Unix Makefiles"
  ### Add cmake args CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${DEPEND_LIB_ROOT} -DCMAKE_BUILD_TYPE=Release
  ### Path to build tree
  BINARY_DIR ${DEPEND_LIB_ROOT}
  BUILD_COMMAND make INSTALL_COMMAND make install
)
### Test depends
add_dependencies(${PROJECT_NAME} CRYPTO++)
if(TESTING)
    add_subdirectory(test)
endif(TESTING)
