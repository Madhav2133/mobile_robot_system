# Mobile Robot System

This is an implementation of collision detection and feedback system for a mobile robot inside few environments.

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

## References

- <a href="https://emanual.robotis.com/docs/en/platform/turtlebot3/simulation/#gazebo-simulation">TurtleBot3 </a> - For environments
- Mobile Robot URDF - Google
- Gazebo Plugins
