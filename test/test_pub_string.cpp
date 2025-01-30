#include <chrono>

#include "test_fixture.hpp"

#include "rcpputils/scope_exit.hpp"

using namespace testing;
using namespace std::chrono_literals;

/// Verifies that a latched topic is received another node
TEST_F(TestFixture, testPubString) {
  // Initializing the MAP ID
  std_msgs::msg::String msg;
  msg.data = "Wololo";
  tx_string_->publish(msg);
  EXPECT_TRUE(test_client_->wait_for_service(5s));
}

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto always_shutdown = rcpputils::make_scope_exit(
    [](){rclcpp::shutdown();});
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}