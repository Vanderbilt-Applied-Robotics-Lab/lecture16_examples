#ifndef TELEOP_EXAMPLE
#define TELEOP_EXAMPLE

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist_stamped.hpp>
#include <sensor_msgs/msg/joy.hpp>
#include <cmath>

class TeleopExample : public rclcpp::Node
{
public:
    /**
     * Main constructor
     * @param options Node options
     */
    TeleopExample(rclcpp::NodeOptions options);

    /**
     * Destructor
     */
    ~TeleopExample() = default;


    void mainTelemanipulation();
    
private:

    void joystickCallback(const sensor_msgs::msg::Joy& msg);

    // subscriber for joystick

    // publisher for twist

    // twist message to publish

    // linear and angular gains 
    
};

#endif // TELEOP_EXAMPLE