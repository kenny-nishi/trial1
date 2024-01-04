// File: publisher.cpp
// it is using the wifi to do the publisher 

#include <Arduino.h>
#include <micro_ros_platformio.h>
#include <WiFi.h>
#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <std_msgs/msg/string.h>

//执行器,用于驱动节点的事件循环和定时器。
rclc_executor_t executor;
//支持结构体,用于存储分配器和上下文。
rclc_support_t support;
//分配器,用于分配内存。
rcl_allocator_t allocator;
//节点,用于存储节点相关信息。
rcl_node_t node;
//发布者,用于发布消息。
rcl_publisher_t publisher;
//定时器,用于定时发布消息。
rcl_timer_t timer;
//消息,用于存储消息数据。
std_msgs__msg__String msg;


/* 
 * timer_callback - 定时器回调函数 
 * @timer: 定时器结构体指针 
 * @last_call_time: 上一次回调执行时间 
 */ 
void timer_callback(rcl_timer_t * timer, int64_t last_call_time)
{
    static int times; // 静态变量记录回调执行次数
    RCLC_UNUSED(last_call_time); // 防止编译器警告

    if (timer != NULL) // 判空处理
    {
        rcl_publish(&publisher, &msg, NULL); // 使用发布者发布消息

        // 分配内存与消息初始化
        std_msgs__msg__String__init(&msg); // 初始化消息结构体
        msg.data.data = (char*)malloc(20); // 分配20字节内存，用于存储消息数据
        msg.data.capacity = 20; // 设置消息的缓冲区大小为20字节
        snprintf(msg.data.data, msg.data.capacity,("Running times:"+std::to_string(times)).c_str()); // 生成消息的数据内容
        msg.data.size = strlen(msg.data.data); // 设置消息的实际大小

        times+=1; // 将回调执行次数加1，用于下一次生成消息内容时使用
    }
}



void setup()
{
  Serial.begin(115200);
  // 设置通过WIFI进行MicroROS通信
  IPAddress agent_ip;
  agent_ip.fromString("192.168.43.146");//注意此处IP应该与上位机局域网IP一致
  // 设置wifi名称，密码，电脑IP,端口号
  set_microros_wifi_transports("faiphone", "12345678", agent_ip, 8888);
  // 延时时一段时间，等待设置完成
  delay(2000);
  // 初始化内存分配器
  allocator = rcl_get_default_allocator();
  // 创建初始化选项
  rclc_support_init(&support, 0, NULL, &allocator);
  // 创建节点 microros_wifi
  rclc_node_init_default(&node, "microros_wifi", "", &support);
  // 创建节点话题发布者
  rclc_publisher_init_default(
    &publisher,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, String),
    "Esp32_Time");
  //创建定时器(1s发一次)
  rclc_timer_init_default(
    &timer,
    &support,
    RCL_MS_TO_NS(1000),
    timer_callback);
  // 创建执行器
  rclc_executor_init(&executor, &support.context, 1, &allocator);
  // 给执行器添加定时器
  rclc_executor_add_timer(&executor, &timer);
}

void loop()
{
  delay(100);
  // 循环处理数据
  rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
}




