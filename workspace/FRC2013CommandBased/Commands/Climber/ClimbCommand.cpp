#include "ClimbCommand.h"

ClimbCommand::ClimbCommand() 
{
	Requires(climber);
}

// Called just before this Command runs the first time
void ClimbCommand::Initialize()
{
	//climber->SetArmPosition(true);
	//climber->SetRobotTip(true);
}

// Called repeatedly when this Command is scheduled to run
void ClimbCommand::Execute() 
{
	//float l = oi->GetStickLeftY();
	//float r = oi->GetStickRightY();
	//float throttle = oi->GetThrottle();
	
	//printf("Left: %d, Right: %d\n", l, r);
	
	float l = 0, r = 0;
	
	if(oi->GetLeftClimbUp())
	{
		l += 1;
	}
	
	if(oi->GetRightClimbUp())
	{
		r += 1;
	}
	
	if(oi->GetLeftClimbDown())
	{
		l -= 1;
	}
	
	if(oi->GetRightClimbDown())
	{
		r -= 1;
	}
	
	climber->SetLeftClimbMotor(l);
	climber->SetRightClimbMotor(r);
}

// Make this return true when this Command no longer needs to run execute()
bool ClimbCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ClimbCommand::End()
{
	climber->SetArmPosition(false);
	climber->SetRobotTip(false);	
	climber->SetLeftClimbMotor(0);
	climber->SetRightClimbMotor(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClimbCommand::Interrupted() 
{
	climber->SetArmPosition(false);
	climber->SetRobotTip(false);
	climber->SetLeftClimbMotor(0);
	climber->SetRightClimbMotor(0);
}
