#include "StartLauncherCommand.h"

StartLauncherCommand::StartLauncherCommand()
{
	Requires(launcher);
}

// Called just before this Command runs the first time
void StartLauncherCommand::Initialize()
{
	launcher->SetLauncherSpeed(LAUNCHER_SPEED);
}

// Called repeatedly when this Command is scheduled to run
void StartLauncherCommand::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool StartLauncherCommand::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void StartLauncherCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StartLauncherCommand::Interrupted()
{
}
