#include <teleop_example/teleop_example.h>

TeleopExample::TeleopExample(rclcpp::NodeOptions options) : Node("teleop_example", options)
{
    // setup subscriber for joystick
    joystick_sub_ = this->create_subscription<sensor_msgs::msg::Joy>(
        "joy", 
        10,
        std::bind(&TeleopExample::joystickCallback, this, std::placeholders::_1)
    );

    // setup publisher for twist commands
    twist_publisher_ = this->create_publisher<geometry_msgs::msg::TwistStamped>("/servo_node/delta_twist_cmds", 10);

    // Setup frame
    twist_msg_.header.frame_id = "meca_base_link";
}

void TeleopExample::mainTelemanipulation()
{
    twist_msg_.header.stamp = this->get_clock()->now();

    twist_publisher_->publish(twist_msg_);
}

void TeleopExample::joystickCallback(const sensor_msgs::msg::Joy& msg)
{
    if (msg.buttons[0] == 0)
    {
        twist_msg_.twist.linear.x = -lin_gain_*msg.axes[1];
        twist_msg_.twist.linear.y = -lin_gain_*msg.axes[0];
        twist_msg_.twist.linear.z = lin_gain_*msg.axes[2];
        twist_msg_.twist.angular.x = 0;
        twist_msg_.twist.angular.y = 0;
        twist_msg_.twist.angular.z = 0; 
    }
    else
    {
        twist_msg_.twist.linear.x = 0;
        twist_msg_.twist.linear.y = 0;
        twist_msg_.twist.linear.z = 0;
        twist_msg_.twist.angular.x = -ang_gain_*msg.axes[1];
        twist_msg_.twist.angular.y = -ang_gain_*msg.axes[0];
        twist_msg_.twist.angular.z = ang_gain_*msg.axes[2];; 
    }
}

int main(int argc, char** argv)
{
    // initialize the node
    rclcpp::init(argc, argv);

    rclcpp::NodeOptions options;

    options.automatically_declare_parameters_from_overrides(true);
    
    // create instance of class
    auto node = std::make_shared<TeleopExample>(options);
    rclcpp::sleep_for(std::chrono::seconds(2));

    // Set loop rate
    rclcpp::Rate rate = rclcpp::Rate(100); // Hz
    
    while (rclcpp::ok())
    {
        node->mainTelemanipulation();
        rclcpp::spin_some(node);
        rate.sleep();
    }
    rclcpp::shutdown();
    return 0;
}