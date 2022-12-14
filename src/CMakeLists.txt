file(GLOB CPP_FILES *.cc)
add_library(${PROJECT_NAME} STATIC ${CPP_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC
 ${PROJECT_SOURCE_DIR}/include)