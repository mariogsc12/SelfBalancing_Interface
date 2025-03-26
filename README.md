# Self-Balancing Robot - Interfaces & Tests

This repository contains the interfaces and test scripts for the self-balancing robot project. The implementation includes MATLAB scripts for control and data analysis, as well as a Qt-based graphical interface for visualization and testing.

## Folder Structure

- MATLAB - Contains the MATLAB GUI and scripts for control, data analysis, and testing.

- QT - Holds the Qt-based GUI for real-time data visualization and system interaction via the serial port.

- Firmware - Includes the firmware responsible for sending messages and validating correct reception with the interface.

Initially, the idea was to use a LoRa network to communicate between the robot and the GUI. However, this approach was abandoned for two reasons: the lack of space in the robot and the adoption of ROS2, which provides a simpler way to establish communication.
