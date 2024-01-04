# this act as reference for the ros2 server

import rclpy
from rclpy.node import Node
from example_interfaces.srv import AddTwoInts

class MicroROSServer(Node):
    def __init__(self,name):
        super().__init__(name)
        # /micro_ros_client is the name declared in the client
        # rclc_client_init_default(&client, &node, ROSIDL_GET_SRV_TYPE_SUPPORT(example_interfaces, srv, AddTwoInts), "/micro_ros_client");
        self.add_two_ints_server = self.create_service(AddTwoInts, '/micro_ros_client', self.add_two_ints_callback)

    # this is the callback function
    def add_two_ints_callback(self, request, response):
        self.get_logger().info(f'Calculating {request.a} + {request.b}')
        response.sum = request.a + request.b
        return response

def main(args=None):
    print('Hi from microros_server.')
    rclpy.init(args=args)
    node = MicroROSServer('micro_ros_server')
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
