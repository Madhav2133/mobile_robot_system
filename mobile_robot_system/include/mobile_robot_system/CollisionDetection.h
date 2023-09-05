#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

#include <cmath>
#define DEGREES 180.0 / M_PI
#define FRONT_THRESHOLD 0.30
#define BACK_THRESHOLD 0.45
#define INF 999999

class CollisionSystem {
 public:
  CollisionSystem();

 private:
  void scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan_msg);

  ros::NodeHandle nh_;
  ros::Subscriber scan_sub_;
};

#endif
