#include "mobile_robot_system/CollisionDetection.h"

ros::Publisher cmd_vel_pub_;

CollisionSystem::CollisionSystem() {
  scan_sub_ = nh_.subscribe("/scan", 10, &CollisionSystem::scanCallback, this);
  cmd_vel_pub_ = nh_.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
}

float arrayMin(float array[], int n) {
  float temp = 0.5;
  for (int i = 0; i < n; i++) {
    if (temp > array[i]) {
      temp = array[i];
    }
  }
  return temp;
}

void checkValues(float front, float back) {
  geometry_msgs::Twist msg;

  if (front > FRONT_THRESHOLD && back > BACK_THRESHOLD) {
    ROS_INFO_ONCE("No Obstacle Nearby :)");
  }

  else if (front < FRONT_THRESHOLD && back > BACK_THRESHOLD) {
    ROS_WARN_ONCE("Obstacle on front");
    msg.linear.x = 0.0;
    cmd_vel_pub_.publish(msg);

  }

  else if (front > FRONT_THRESHOLD && back < BACK_THRESHOLD) {
    ROS_WARN_ONCE("Obstacle on back");
    msg.linear.x = 0.0;
    cmd_vel_pub_.publish(msg);
  }

  else if (front < FRONT_THRESHOLD && back < BACK_THRESHOLD) {
    ROS_WARN_ONCE("Obstacle on front and back");
    msg.linear.x = 0.0;
    cmd_vel_pub_.publish(msg);
  }
}

void CollisionSystem::scanCallback(
    const sensor_msgs::LaserScan::ConstPtr& scan_msg) {
  float angle_max = scan_msg->angle_max;
  float angle_min = scan_msg->angle_min;

  int angle_min_deg = angle_min * DEGREES;
  int angle_max_deg = (angle_max * DEGREES) + 1;

  int range_angles = angle_max_deg - angle_min_deg;
  int n = range_angles / 2;

  float front[n], back[n];

  for (int i = 0; i < 2; i++) {
    int start_angle = (i * n + 90) % angle_max_deg;
    int end_angle = ((i + 1) * n + 90) % angle_max_deg;

    if (i == 0) {
      // Back
      int count = 0;
      for (int angle = start_angle; angle < end_angle; angle++) {
        if (!std::isinf(scan_msg->ranges[angle])) {
          back[count] = scan_msg->ranges[angle];
          count++;
        } else {
          back[count] = INF;
          count++;
        }
      }
    }

    if (i == 1) {
      // Front
      int count = 0;
      for (int angle = start_angle; angle < end_angle + angle_max_deg;
           angle++) {
        int another = angle % angle_max_deg;
        if (!std::isinf(scan_msg->ranges[another])) {
          front[count] = scan_msg->ranges[another];
          count++;
        } else {
          front[count] = INF;
          count++;
        }
      }
    }
  }

  float front_min = arrayMin(front, n);
  float back_min = arrayMin(back, n);

  checkValues(front_min, back_min);
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "collision_system");
  CollisionSystem obj;
  ros::spin();
  return 0;
}
