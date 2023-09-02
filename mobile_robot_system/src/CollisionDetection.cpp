#include "mobile_robot_system/CollisionDetection.h"

CollisionSystem::CollisionSystem() {
  scan_sub_ = nh_.subscribe("/scan", 10, &CollisionSystem::scanCallback, this);
  cmd_vel_pub_ = nh_.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
}

void CollisionSystem::scanCallback(
    const sensor_msgs::LaserScan::ConstPtr& scan_msg) {
  std::cout << "0: " << scan_msg->ranges[0] << std::endl;
  std::cout << "90: " << scan_msg->ranges[90] << std::endl;
  std::cout << "180: " << scan_msg->ranges[180] << std::endl;
  std::cout << "270: " << scan_msg->ranges[270] << std::endl;

  std::cout << "\n---\n" << std::endl;
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "collision_system");
  CollisionSystem obj;
  ros::spin();
  return 0;
}
