#!/usr/bin/env python

import rospy
import sys
import copy
import moveit_commander
import moveit_msgs.msg
import geometry_msgs.msg

from math import pi
from std_msgs.msg import String
from moveit_commander.conversions import pose_to_list
from moveit_commander import move_group

moveit_commander.roscpp_initialize(sys.argv)
rospy.init_node('move_group_python_interface_tutorial', anonymous=True)
robot = moveit_commander.RobotCommander()

scene = moveit_commander.PlanningSceneInterface()

display_trajectory_publisher = rospy.Publisher('/move_group/display_planned_path', moveit_msgs.msg.DisplayTrajectory)

arm_group = moveit_commander.MoveGroupCommander("arm_1")

arm_group.set_goal_tolerance(0.001)
arm_group.set_pose_target([-0.21276836989992579, -0.08053166249451255, 0.06926823632600863, -3.059393209187374, 0.35467872670412576, 0.5607715476412943])
plan1 = arm_group.go()
print ("============ Waiting while RVIZ displays ...")
rospy.sleep(2)

arm_group = moveit_commander.MoveGroupCommander("arm_1")
arm_group.set_goal_tolerance(0.001)
arm_group.set_named_target("candle")
plan1 = arm_group.go()

print ("============ Waiting while RVIZ displays pose arm 'candle'...")
rospy.sleep(2)

pose_goal = geometry_msgs.msg.Pose()

arm_group.set_goal_tolerance(0.001) 

pose_goal.orientation.x = -0.021027103229867356
pose_goal.orientation.y = 0.9847913553849971
pose_goal.orientation.z = -0.033741517797799485
pose_goal.orientation.w = 0.16913118359853688

pose_goal.position.x = 0.2701612151168107
pose_goal.position.y = -0.04366693859869809
pose_goal.position.z = 0.0851442819119589

arm_group.set_pose_target(pose_goal)

plan = arm_group.go(wait=True)
arm_group.stop()
arm_group.set_pose_target(pose_goal)


print ("============ Waiting while RVIZ displays pose arm 'go to the point'...")
rospy.sleep(2)

pose_goal = geometry_msgs.msg.Pose()

arm_group.set_goal_tolerance(0.001) 

pose_goal.orientation.x = -0.4041826937939327
pose_goal.orientation.y = -0.3787447172124559
pose_goal.orientation.z = -0.7925394347800557
pose_goal.orientation.w = 0.25508828577503717

pose_goal.position.x = 0.13331382776312894
pose_goal.position.y = 0.1970488322766667
pose_goal.position.z = 0.2374053480400728

arm_group.set_pose_target(pose_goal)

plan = arm_group.go(wait=True)
arm_group.stop()
arm_group.set_pose_target(pose_goal)


print ("============ Waiting while RVIZ displays pose arm 'go to the point'...")
rospy.sleep(2)


moveit_commander.roscpp_shutdown()
