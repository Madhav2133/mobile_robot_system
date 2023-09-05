# Mobile Robot System

This is an implementation of collision detection and obstacle avoidance system for a mobile robot inside few environments.

Here's a short video demonstration:
<br>
[![Demonstration Video](https://img.youtube.com/vi/UbxiYil5CPc?si=0xY1Q7wkuQWSWP0e/0.jpg)](https://youtu.be/UbxiYil5CPc?si=0xY1Q7wkuQWSWP0e)

## Implementation

Create a ros workspace and clone this repository into it's source folder:

```
mkdir -p ros_ws/src
cd src

git clone https://github.com/Madhav2133/mobile_robot_system.git
```

Build and source the workspace:

```
cd ..
catkin_make && source ~/ros_ws/devel/setup.bash
```

Launch the robot into the gazebo simulation using the following command:

```
roslaunch mobile_robot_system display.launch
```

To observe the sensor output:

```
rosrun mobile_robot_system collision_system
```

## References

- <a href="https://emanual.robotis.com/docs/en/platform/turtlebot3/simulation/#gazebo-simulation">TurtleBot3 </a> - For environments
- Mobile Robot URDF - Google
- Gazebo Plugins - <a href="https://classic.gazebosim.org/tutorials?tut=add_laser&cat=build_robot#AddingaLaser">Hokuyo Sensor</a>
