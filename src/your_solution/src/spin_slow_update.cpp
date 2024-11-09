#include "spin_slow_update.h"

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SlowSolution>());
  rclcpp::shutdown();
  return 0;
}

SlowSolution::SlowSolution() : Node("slowsolution")
{
  pos_subscription_ = this->create_subscription<ArrayMsg>(
      "measuredpos", 10, std::bind(&SlowSolution::pos_callback, this, std::placeholders::_1));

  vel_subscription_ = this->create_subscription<ArrayMsg>(
      "measuredvel", 10, std::bind(&SlowSolution::vel_callback, this, std::placeholders::_1));
}

void SlowSolution::pos_callback(const ArrayMsg::SharedPtr msg)
{
  RCLCPP_INFO(this->get_logggiter(), "Received position: [%f, %f]", msg->data[0], msg->data[1]);
}

void SlowSolution::vel_callback(const ArrayMsg::SharedPtr msg)
{
  RCLCPP_INFO(this->get_logger(), "Received velocity: [%f, %f]", msg->data[0], msg->data[1]);
}