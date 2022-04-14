# GTEST CMakeLists.txt

CMAKE_MINIMUM_REQUIRED(VERSION 3.21 FATAL_ERROR)

# main src files---> allows to use my classes inside tests
SET(CPP_SRC_DIR "${BIOALGORITHMS_SOURCE_DIR}/src/")
SET(TEST_SRC_DIR "${BIOALGORITHMS_SOURCE_DIR}/test/")

file(GLOB INCLUDE_DIRS_SRCS ${CPP_SRC_DIR}/*.cpp ${TEST_SRC_DIR}/*.cpp)

include_directories(${BIOALGORITHMS_SOURCE_DIR}/include/)

# Build the googletest library from source in test/googletest
set(GTEST_ROOT "${BIOALGORITHMS_SOURCE_DIR}/test/googletest")
add_subdirectory(${GTEST_ROOT})

# to have <gtest/gtest.h> header
include_directories(${GTEST_ROOT}/googletest/include)
# Name of the Googletest lib we need
set(GTEST_LIB gtest_main)

# Create new myUnitTests target from test sources and link with ${GTEST}_LIB and ${MY_LIB}
# Call the target  <xx>UnitTests so that compile.sh can run it.
######### CREATE UNIT TEST BINARY ###################
set(UNIT_TESTS launchTests)
add_executable(${UNIT_TESTS} ${INCLUDE_DIRS_SRCS})
target_link_libraries(${UNIT_TESTS} ${GTEST_LIB} bio)
#####################################################
