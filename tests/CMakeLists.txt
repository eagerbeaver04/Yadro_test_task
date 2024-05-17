enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURS ${CMAKE_CURRENT_BINARY_DIR}/../src)

add_executable(runTests tests.cpp)
include_directories(../src/ReaderLib)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(runTests ${SOURS}/ReaderLib pthread)