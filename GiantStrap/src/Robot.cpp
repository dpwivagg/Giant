#include "WPILib.h"
#include "RobotMap.h"

class Robot: public SampleRobot
{
	RobotDrive giantRobot;
	Joystick stick_left;
	Joystick stick_right;
	Joystick gamepad;
	Encoder encoder;
	CANTalon lift;
	CANTalon arm_left;
	CANTalon arm_right;
	DigitalInput top_limit;
	DigitalInput bottom_limit;
	Solenoid solenoid;

	int *autoLoopCounter;

	Command *autonomousCommand;
	LiveWindow *lw;

public:
	Robot() :
		giantRobot(LEFT_MOTOR_FRONT,
			LEFT_MOTOR_REAR,
			RIGHT_MOTOR_FRONT,
			RIGHT_MOTOR_REAR),

		stick_left(STICK_LEFT),
		stick_right(STICK_RIGHT),
		gamepad(GAMEPAD),

		encoder(ENCODER_CHANNEL_A, ENCODER_CHANNEL_B),

		lift(LIFT_MOTOR),
		arm_left(ARM_LEFT),
		arm_right(ARM_RIGHT),

		top_limit(TOP_LIMIT),
		bottom_limit(BOTTOM_LIMIT),

		solenoid(SOLENOID_CHANNEL),

		autoLoopCounter(0)
	{
		giantRobot.SetExpiration(0.1);
	}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous()
	{
		giantRobot.SetSafetyEnabled(false);
		while (IsAutonomous() && IsEnabled()) {
			giantRobot.Drive(-0.5, -0.5); 	// drive forwards half speed
			Wait(2.0); 				//    for 2 seconds
			giantRobot.Drive(0.0, 0.0); 	// stop robot
		}
	}

	/**
	 * Runs the motors with arcade steering.
	 */
	void OperatorControl()
	{
		giantRobot.SetSafetyEnabled(true);
		while (IsOperatorControl() && IsEnabled())
		{
			giantRobot.TankDrive(stick_left, stick_right); //tank drive
			Wait(0.005);				// wait for a motor update time
		}
	}

	/**
	 * Runs during test mode
	 */
	void Test()
	{
	}
};

START_ROBOT_CLASS(Robot);
