# Research Track - Assignment 1
##### Submitted by Muhammad Ali Haider Dar (S5046263)

1. Start the ROS master node using `roscore &`. The `&` argument makes the command line available after initialization of master node.

2. Navigate to the the local workspace repository using `cd /workspace/` command.

3. Clone the remote repository of assignment in your local repository/workspace using the command:
```
git clone https://github.com/alihaidersays/ResearchTrack_Assignment1.git
```

4. Build the file using `catkin_make` in the root folder of your workspace.

5. Execute the command `rospack profile` to read and parse the .xml for each package and assemble a complete dependency tree for all packages.

6. Run the 2D simulator, Stage, by executing the following command:
```
rosrun stage_ros stageros $(rospack find assignment1)/world/exercise.world
```

7. In a new command line tab, run the following command:
```
rosrun assignment1_pkg assignment1_node
```

8. In a new command line tab, run the following command:
```
rosrun assignment1_srv newpos_srv
```

9. To display the list of running topics, run  the following command in a new command line tab:
```
rostopic list
```

9. The information getting published in the topics can be printed on the command line using the 'echo' command. Run the following command to see the coordinates of robot's current and new positions:
```
rostopic echo /assignment1/position
```

10. rqt graph 