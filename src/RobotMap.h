#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

//Init joysticks

static const uint32_t STICK_LEFT = 0;
static const uint32_t STICK_RIGHT = 1;
static const uint32_t GAMEPAD = 2;

//DRIVING MOTORS

static const uint32_t LEFT_MOTOR_FRONT_PORT = 1;
static const uint32_t LEFT_MOTOR_REAR_PORT = 2;
static const uint32_t RIGHT_MOTOR_FRONT_PORT = 3;
static const uint32_t RIGHT_MOTOR_REAR_PORT = 4;

//PNEUMATICS

//static const uint32_t SOLENOID_PORT = 0;

//TALONS

static const uint32_t LIFT_MOTOR = 9;
static const uint32_t ARM_LEFT = 10;
static const uint32_t ARM_RIGHT = 11;

//ENCODER CHANNELS

static const uint32_t ENCODER_CHANNEL_A = 0;
static const uint32_t ENCODER_CHANNEL_B = 1;

//LIMIT SWITCHES

static const uint32_t TOP_LIMIT = 2;
static const uint32_t BOTTOM_LIMIT = 3;


#endif
