#ifndef YOUR_SOLUTION_SRC_SPIN_SLOW_UPDATE_H_
#define YOUR_SOLUTION_SRC_SPIN_SLOW_UPDATE_H_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
using ArrayMsg = std_msgs::msg::Float64MultiArray;

class SlowSolution : public rclcpp::Node {
 public:
  SlowSolution();
 private:
  void pos_callback(const ArrayMsg::SharedPtr msg);
  void vel_callback(const ArrayMsg::SharedPtr msg);

  rclcpp::Subscription<ArrayMsg>::SharedPtr pos_subscription_;
  rclcpp::Subscription<ArrayMsg>::SharedPtr vel_subscription_;
};

#endif //YOUR_SOLUTION_SRC_SPIN_SLOW_UPDATE_H_