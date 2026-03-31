#include <teleop_example/teleop_example.h>

TeleopExample::TeleopExample(rclcpp::NodeOptions options) : Node("teleop_example", options)
{
    // setup subscriber for joystick

    // setup publisher for twist commands

    // set base frame
}

void TeleopExample::mainTelemanipulation()
{
    // set time stamp

    // publish message
}

void TeleopExample::joystickCallback(const sensor_msgs::msg::Joy& msg)
{
    // if A button is pressed control robot in translation
    // else control in orientation
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

    // Set loop rate to 100 hz
    
    while (rclcpp::ok())
    {
        // call mainTelemanipulation
        rclcpp::spin_some(node);
        rate.sleep();
    }
    rclcpp::shutdown();
    return 0;
}