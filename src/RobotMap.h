#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

//Init joysticks

static const uint32_t STICK_LEFT = 0;
static const uint32_t STICK_RIGHT = 1;
static const uint32_t GAMEPAD = 2;

//DRIVING MOTORS

static const uint32_t LEFT_MOTOR_FRONT = 1;
static const uint32_t LEFT_MOTOR_REAR = 2;
static const uint32_t RIGHT_MOTOR_FRONT = 3;
static const uint32_t RIGHT_MOTOR_REAR = 4;

//PNEUMATICS

//Need the Pneumatics Control Module Channel for the compressor
//static const uint32_t COMPRESSOR_CHANNEL = ;
static const uint32_t SOLENOID_CHANNEL = 0;

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
