#include "DriveSubsystem.h"

DriveSubsystem::DriveSubsystem() :
	Subsystem("DriveSubsystem")
{
	shiftSolenoid = new Solenoid(SOLENOID_SHIFTER);

	motorLeft = new CANJaguar(MOTOR_LEFT, CANJaguar::kPercentVbus);
	motorRight = new CANJaguar(MOTOR_RIGHT, CANJaguar::kPercentVbus);
	//_isClosedLoop = false;
	
	drive = new RobotDrive(motorLeft, motorRight);
	drive->SetSafetyEnabled(false);
	motorLeft->SetSafetyEnabled(false);
	motorRight->SetSafetyEnabled(false);
}

void DriveSubsystem::InitDefaultCommand()
{
	
}

void DriveSubsystem::TankDrive(float l, float r)
{
	drive->TankDrive(l, r, false);
}

void DriveSubsystem::SetCoastBrakeMode(CANJaguar::NeutralMode m)
{
	motorLeft->ConfigNeutralMode(m);
	motorRight->ConfigNeutralMode(m);
}

void DriveSubsystem::RotateSpeed(float x)
{
	drive->TankDrive(-x, x, false);
}

void DriveSubsystem::Shift(bool o)
{
	shiftSolenoid->Set(o);
}

void DriveSubsystem::ShiftLow()
{
	this->Shift(false);
}

void DriveSubsystem::ShiftHigh()
{
	this->Shift(true);
}
