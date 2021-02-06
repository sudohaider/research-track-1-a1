# Research Track - Assignment 1
##### Submitted by Muhammad Ali Haider Dar (S5046263)

The assignment requires controlling a holonomic robot in a 2d space with a simple 2d simulator, Stage. 

## Description of Packages

### Controller: _assignment1_pkg_



### Server: _assignment1_srv_

## Instructions for Running the Project

### Getting Started

The following steps will help prepare the necessary environment and dependencies to run this project.

1. Start the ROS master node using `roscore &` in the command line. The `&` argument makes the command line available after initialization of master node.

2. Navigate to the the local workspace repository using `cd /workspace/` command.

3. Clone the remote repository of assignment in your local repository/workspace using the command:
```
git clone https://github.com/alihaidersays/ResearchTrack_Assignment1.git
```

4. Build the file using `catkin_make` in the root folder of your workspace.

5. Execute the command `rospack profile` to read and parse the .xml for each package and assemble a complete dependency tree for all packages.

### Running the Program

The following steps will run the simulator along with the controller nodes.

1. In the command line, run the 2D simulator, Stage, by executing the following command:
```
rosrun stage_ros stageros $(rospack find assignment1)/world/exercise.world
```

2. In a new command line tab, run the following command:
```
rosrun assignment1_pkg assignment1_node
```

3. In a new command line tab, run the following command:
```
rosrun assignment1_srv newpos_srv
```

4. To display the list of running topics, run  the following command in a new command line tab:
```
rostopic list
```

5. The information getting published in the topics can be printed on the command line using the 'echo' command. Run the following command to see the coordinates of robot's current and new positions:
```
rostopic echo /assignment1/position
```

6. To display a graph of what's going on in the system, run the following command in a new command line tab: 
```
rosrun rqt_graph rqt_graph
```
