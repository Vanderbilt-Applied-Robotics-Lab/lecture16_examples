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

    /**
     * Computes the average value of an array
     * @param array The array to compute the average of
     */
    void joystickCallback(const sensor_msgs::msg::Joy& msg);

    // subscriber for joystick
    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr joystick_sub_;

    // publisher for twist
    rclcpp::Publisher<geometry_msgs::msg::TwistStamped>::SharedPtr twist_publisher_;

    // twist message to publish
    geometry_msgs::msg::TwistStamped twist_msg_;

    double lin_gain_ = 0.05; // 10 mm/s max velocity
    double ang_gain_ = 0.05; // 10 rad/s max velocity
    
};

#endif // TELEOP_EXAMPLE