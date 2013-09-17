#include "AutonomousCommand.h"

AutonomousCommand::AutonomousCommand(const char* autoScriptFile)
{
	// Only require the launcher, because that is the only thing that we don't
	// set via another command.
	
	fireShot = NULL;
	gyroRotate = NULL;
	//driveCmd = NULL;
	
	
	Requires(launcher);

	si = new ScriptInterpreter();
	si->OpenScript(autoScriptFile); // Point the interpereter at our file
	si->SetCallback(AutonomousCommand::CallbackSt); // Wire up the callback to our static wrapper
}

AutonomousCommand::~AutonomousCommand()
{
	delete si;
	delete fireShot;
	delete gyroRotate;

	this->si = NULL;
	this->fireShot = NULL;
	this->gyroRotate = NULL;
}

// Called just before this Command runs the first time
void AutonomousCommand::Initialize()
{
	this->scriptIsCompleted = false; // We aren't done, we've barely begun!
	si->Start(this); // Init the interpreter and tell it to call us back when it needs to.
}

// Called repeatedly when this Command is scheduled to run
void AutonomousCommand::Execute()
{
	si->Tick(); // Tick the interpereter so that it processes everything that is scheduled.
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousCommand::IsFinished()
{
	return this->scriptIsCompleted;
}

// Called once after isFinished returns true
void AutonomousCommand::End()
{
	this->launcher->SetLauncherSpeed(0.0); // Safety thing
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousCommand::Interrupted()
{
	this->launcher->SetLauncherSpeed(0.0); // Safety thing
}

void AutonomousCommand::Callback(const char* func, float param)
{
	/**
	 * 
	 * Most of the following follow the same pattern:
	 * 		Check if we need to construct the command, and if so, do that.
	 * 		Set any parameters on it.
	 * 		Start!
	 * 
	 */

	if (!strcmp(func, "fireShot"))
	{
		if (!fireShot)
			fireShot = new FireShotCommand();

		fireShot->Start();
	}
	else if (!strcmp(func, "rotate"))
	{
		if (!this->gyroRotate)
			this->gyroRotate = new GyroRotateCommand();

		this->gyroRotate->SetParams(param, 3.0); // Angle and timeout
		this->gyroRotate->Start();
	}
	/*
	else if (!strcmp(func, "drive"))
	{
		if(!driveCmd)
			driveCmd = new DriveDistCommand();
		
		this->driveCmd->SetParams(param);		// Go the distance specified
		this->driveCmd->Start();
	}*/
	else if (!strcmp(func, "setShooter"))
	{
		launcher->SetLauncherSpeed(param);
	}
	else if (!strcmp(func, "return"))
	{
		this->scriptIsCompleted = true;
	}
	else
	{
		log(kError, "Unknown function called: Func: %s Arg: %s", func, param);
	}
}
