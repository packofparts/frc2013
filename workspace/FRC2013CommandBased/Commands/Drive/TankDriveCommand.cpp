#include "TankDriveCommand.h"

TankDriveCommand::TankDriveCommand()
{
	Requires(drive);
}

void TankDriveCommand::Initialize()
{
	
}

// Called repeatedly when this Command is scheduled to run
void TankDriveCommand::Execute()
{
	float l = oi->GetStickLeftY();
	float r = oi->GetStickRightY();

	drive->TankDrive(l, r);
}

// Make this return true when this Command no longer needs to run execute()
bool TankDriveCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void TankDriveCommand::End()
{
	drive->TankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDriveCommand::Interrupted()
{
	drive->TankDrive(0, 0);
}
