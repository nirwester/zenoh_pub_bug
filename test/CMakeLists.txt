find_package(ament_cmake_gtest REQUIRED)
find_package(ament_cmake_ros REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rcpputils REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)

include(GoogleTest)
include("cmake/cm_add_isolated_gtest_with_command.cmake")

ament_add_gtest_executable(test_pub_string test_pub_string.cpp)
target_link_libraries(test_pub_string gtest_main)
ament_target_dependencies(test_pub_string std_msgs std_srvs rclcpp rcpputils)

cm_add_isolated_gtest_with_command(
  test_pub_string
    GENERATE_RESULT_FOR_RETURN_CODE_ZERO
    COMMAND
    "${CMAKE_CURRENT_SOURCE_DIR}/launch_string_test.py"
    WORKING_DIRECTORY
    "${CMAKE_CURRENT_BINARY_DIR}"
    TIMEOUT
    20
    ENV
    TEST_DIR=${TEST_DIR}
    TEST_LAUNCH_DIR=${TEST_LAUNCH_DIR}
    TEST_EXECUTABLE=$<TARGET_FILE:test_pub_string>)
