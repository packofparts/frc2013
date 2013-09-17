#include "FrisbeeLoader.h"
#include "../Robotmap.h"

FrisbeeLoader::FrisbeeLoader() :
	Subsystem("FrisbeeLoader")
{
	pusherSolenoid = new Solenoid(SOLENOID_FEEDER);
	feedSwitch = new DigitalInput(FEED_SWITCH);
	feedMotor = new CANJaguar(MOTOR_FEEDER, CANJaguar::kVoltage);
}

void FrisbeeLoader::InitDefaultCommand()
{
	
}

void FrisbeeLoader::SetPusher(bool p)
{
	pusherSolenoid->Set(p);
}

void FrisbeeLoader::SetFeederMotor(float on)
{
	feedMotor->Set(on * FEEDER_MOTOR_VOLTAGE);
}

bool FrisbeeLoader::GetFeedSwitch()
{
	return feedSwitch->Get();
}
