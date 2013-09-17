#include "UnjamLoaderCommand.h"

UnjamLoaderCommand::UnjamLoaderCommand()
{
	Requires(loader);
	SetTimeout(0.6);
}

// Called just before this Command runs the first time
void UnjamLoaderCommand::Initialize()
{
	loader->SetFeederMotor(-1.0);
}

// Called repeatedly when this Command is scheduled to run
void UnjamLoaderCommand::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool UnjamLoaderCommand::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void UnjamLoaderCommand::End()
{
	loader->SetFeederMotor(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UnjamLoaderCommand::Interrupted()
{
	loader->SetFeederMotor(0);
}
