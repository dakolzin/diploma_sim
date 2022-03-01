#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv)
{
  /**
   * Функция ros::init() требуется для проверки аргументов argc и argv, чтобы выполнить
   * преобразования или переопределение аргументов ROS, задаваемых через командную строку.
   * Для программного переопределения вы можете использовать другую версию init(), которая
   * принимает переопределение напрямую, но для большинства программ командной сроки, обработка
   * argc и argv - простейший путь реализовать это. Третий аргумент init() - это название узла.
   *
   * Вы должны вызвать одну из версий ros::init() перед использованием любых других
   * частей системы ROS.
   */
  ros::init(argc, argv, "talker");
  /**
   * NodeHandle - главная точка доступа для взаимодействия с системой ROS.
   * Конструктор NodeHandle полностью инициализирует этот узел, а в конце,
   * деструктор NodeHandle завершит работу узла.
   */
  ros::NodeHandle n;
  /**
   * Функция advertise() определяет для ROS что вы будете публиковать в задаваемую Тему.
   * Это включает в себя вызов Мастер-узла ROS, который сохраняет регистрационные данные
   * кто является издателем, а кто является подписчиком.
   * После завершения advertise(), Мастер-узел ROS извещает всех, кто пытается подписаться
   * на заданную Тему и они должны устанавливать прямое соединение
   * (peer-to-peer connection)  между собой и этим узлом.
   * Функция advertise() возвращает объект Издатель (Publisher), который позволяет Вам
   * публиковать сообщения в Тему, с помощью метода publish(). После того, как все
   * копии возвращённого объекта Издателя (Publisher) будут разрушены, Тема будет автоматически
   * отписана (unadvertised).
   *
   * Второй параметр метода advertise() - это размер очереди сообщений, используемый для
   * публикуемых сообщений. Если сообщения публикуются быстрее, чем они могут быть отправлены,
   * этот параметр задаёт сколько сообщений необходимо сохранять в буфере прежде чем
   * бросать исключение.
   */
  ros::Publisher chatter_pub = n.advertise("chatter", 1000);
  ros::Rate loop_rate(10);
  /**
   * count - счётчик, в котором сохраняется число отправленных сообщений. Используется
   * при создании уникальной строки для каждого сообщения.
   */
  int count = 0;
  while (ros::ok())
  {
    /**
     * Это объект сообщения. Вы сохраняете в него данные, а затем публикуете их.
     */
    std_msgs::String msg;
    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());
    /**
     * Метод publish() для отправки сообщений. Параметр - это объект сообщения.
     * Тип объекта должен совпадать с типом, который задавался параметром шаблона
     * при вызове advertise<>(), как это сделано в конструкторе выше.
     *
     */
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
  return 0;
}