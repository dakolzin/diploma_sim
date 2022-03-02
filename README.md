# diploma_sim

Среда: Ubuntu 20.04.4 LTS

Для начала симуляции в среде Gazebo:

roslaunch youbot_gazebo_robot youbot_arm_only.launch 

Подключение Moveit:

roslaunch youbot_moveit demo.launch

Для работы с реальным роботом необходимо:
1)Установить соединение по ssh между компьютерами.
2)Запустить драйвера робота (roslaunch youbot_driver_ros_interface youbot_driver_arm_only.launch). Только манипулятора.
3)Запуск moveIT (roslaunch youbot_moveit demo.launch).

