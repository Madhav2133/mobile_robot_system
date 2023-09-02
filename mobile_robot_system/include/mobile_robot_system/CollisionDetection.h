#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

class CollisionSystem {
 public:
  CollisionSystem();

 private:
  void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan_msg);

  ros::NodeHandle nh_;
  ros::Subscriber scan_sub_;
  ros::Publisher cmd_vel_pub_;
};

#endif
