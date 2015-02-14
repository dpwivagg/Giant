#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"

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

private:
	Command *autonomousCommand;
	LiveWindow *lw;


	Robot:giantRobot(LEFT_MOTOR_FRONT,
			LEFT_MOTOR_REAR,
			RIGHT_MOTOR_FRONT,
			RIGHT_MOTOR_REAR);

	Robot:stick_left(STICK_LEFT);
	Robot:stick_right(STICK_RIGHT);
	Robot:gamepad(GAMEPAD);

	Robot:encoder(ENCODER_CHANNEL_A, ENCODER_CHANNEL_B);

	Robot:lift(LIFT_MOTOR);
	Robot:arm_left(ARM_LEFT);
	Robot:arm_right(ARM_RIGHT);

	Robot:compressor();

	Robot:top_limit(TOP_LIMIT);
	Robot:bottom_limit(BOTTOM_LIMIT);


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

		compressor.Start();

		giantRobot.TankDrive(stick_left, stick_right);




	}

	void TestPeriodic()
	{
		lw->Run();
	}


};

START_ROBOT_CLASS(Robot);

