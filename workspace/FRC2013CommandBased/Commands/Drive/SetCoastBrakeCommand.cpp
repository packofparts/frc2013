#include "SetCoastBrakeCommand.h"

SetCoastBrakeCommand::SetCoastBrakeCommand(CANJaguar::NeutralMode mode)
{
	this->m_mode = mode;
	isdone = false;
}

// Called just before this Command runs the first time
void SetCoastBrakeCommand::Initialize()
{
	drive->SetCoastBrakeMode(this->m_mode);
}

void SetCoastBrakeCommand::Execute()
{
	drive->SetCoastBrakeMode(this->m_mode);
	isdone = true;
}

// Make this return true when this Command no longer needs to run execute()
bool SetCoastBrakeCommand::IsFinished()
{
	return isdone;
}

// Called once after isFinished returns true
void SetCoastBrakeCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetCoastBrakeCommand::Interrupted()
{
}
