#include "ClimberSubsystem.h"
#include "../Robotmap.h"

ClimberSubsystem::ClimberSubsystem() :
	Subsystem("ClimberSubsystem")
{
	//this->climbJagRight = new CANJaguar(MOTOR_CLIMBER_RIGHT, CANJaguar::kPercentVbus);
	//this->climbJagLeft = new CANJaguar(MOTOR_CLIMBER_LEFT, CANJaguar::kPercentVbus);
	this->climbJagLeft = new Jaguar(MOTOR_CLIMBER_LEFT);
	this->climbJagRight = new Jaguar(MOTOR_CLIMBER_RIGHT);
	
	this->solenoidArm = new Solenoid(SOLENOID_CLIMBER_ARMS);
	this->solenoidTip = new Solenoid(SOLENOID_TIP);
}

void ClimberSubsystem::InitDefaultCommand()
{
}

void ClimberSubsystem::SetLeftClimbMotor(float speed)
{
	climbJagLeft->Set(speed);
}

void ClimberSubsystem::SetRightClimbMotor(float speed)
{
	climbJagRight->Set(speed);
}

void ClimberSubsystem::SetArmPosition(bool out)
{
	solenoidArm->Set(out);
}

void ClimberSubsystem::SetRobotTip(bool tipped)
{
	solenoidTip->Set(tipped);
}
