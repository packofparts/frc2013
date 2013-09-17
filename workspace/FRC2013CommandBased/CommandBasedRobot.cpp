#include "WPILib.h"
#include "Commands/Command.h"

#include "CommandBase.h"
#include "Commands/Autonomous/AutonomousCommand.h"
#include "Commands/Drive/TankDriveCommand.h"

class CommandBasedRobot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	Command *tankControl;
	Compressor* c;

	virtual void RobotInit()
	{
		printf("RobotInit Called\n");
		CommandBase::init();

		autonomousCommand = new AutonomousCommand(AUTO_SCRIPT);
		tankControl = new TankDriveCommand();
		c = new Compressor(COMPRESSOR_TRANSDUCER, COMPRESSOR_SPIKE);
	}

	virtual void AutonomousInit()
	{
		printf("AutonomousInit Called\n");
		autonomousCommand->Start();
	}

	virtual void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	virtual void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		autonomousCommand->Cancel();
		tankControl->Start();
		c->Start();
	}

	virtual void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot)
;

