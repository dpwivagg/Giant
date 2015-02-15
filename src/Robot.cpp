#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "RobotMap.h"

class Robot: public IterativeRobot
{


	RobotDrive giantRobot;
	Joystick stick_left;
	Joystick stick_right;
	Joystick gamepad;
	Encoder encoder;
	CANTalon lift;
	CANTalon arm_left;
	CANTalon arm_right;
	Compressor compressor;
	DigitalInput top_limit;
	DigitalInput bottom_limit;
	Solenoid solenoid;

	int autoLoopCounter;

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

		compressor(/*COMPRESSOR_CHANNEL*/),

		top_limit(TOP_LIMIT),
		bottom_limit(BOTTOM_LIMIT),

		solenoid(SOLENOID_CHANNEL),

		autoLoopCounter(0)
	{
		giantRobot.SetExpiration(0.1);
	}


	void RobotInit()
	{
		CommandBase::init();
		autonomousCommand = new ExampleCommand();
		lw = LiveWindow::GetInstance();


	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();

	}



	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();

		//Start the compressor
		compressor.Start();

		//Drive using tank drive
		giantRobot.TankDrive(stick_left, stick_right);

		//Raise the arm


		//Lower the arm


		//Move the arm to position (top)
		if(gamepad.GetRawButton(/*which button?*/))
		{

		}

		//Move the arm to position (bottom)
		if(gamepad.GetRawButton(/*which button?*/))
		{

		}
	}

	void TestPeriodic()
	{
		lw->Run();
	}


};

START_ROBOT_CLASS(Robot);

