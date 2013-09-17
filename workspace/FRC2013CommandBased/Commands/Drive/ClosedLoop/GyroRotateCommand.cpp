#include "GyroRotateCommand.h"

#include "../../../logging.h"

GyroRotateCommand::GyroRotateCommand()
{
	//Requires(drive); // We require the drivetrain
}

void GyroRotateCommand::SetParams(double headingDiff, double timeout)
{
	this->gyro->ResetYaw();
	this->SetTimeout(timeout);
	this->headingGoal = headingDiff; // Set heading to current position + the goal
}

GyroRotateCommand::~GyroRotateCommand()
{
	if (pid)
	{
		pid->Disable();
	}

	delete pid;
	pid = NULL;
}

// Called just before this Command runs the first time
void GyroRotateCommand::Initialize()
{
	this->gyro->ResetYaw();
	pid = new PIDController(GYRO_ROTATE_kP, GYRO_ROTATE_kI, GYRO_ROTATE_kD, this, this, 0.05);
	pid->SetSetpoint(headingGoal);
	pid->SetOutputRange(-0.85, 0.85); // Steering only goes [-1,1]
	pid->Enable();
}

// Called repeatedly when this Command is scheduled to run
void GyroRotateCommand::Execute()
{
	
}

// Return true when we're done
bool GyroRotateCommand::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void GyroRotateCommand::End()
{
	pid->Disable();
	drive->RotateSpeed(0);
	delete pid;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GyroRotateCommand::Interrupted()
{
	pid->Disable();
	this->drive->RotateSpeed(0);
}

void GyroRotateCommand::PIDWrite(float f)
{
	this->drive->RotateSpeed(f);
}

double GyroRotateCommand::PIDGet()
{
	float a = this->gyro->GetYawAngle();
	log(kInformation, "Angle: %.1f Sp: %.1f Err: %.2f\n", a, this->headingGoal, a - this->headingGoal);
	return a;
}
