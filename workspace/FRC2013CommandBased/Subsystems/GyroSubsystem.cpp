#include "GyroSubsystem.h"
#include "../Robotmap.h"

GyroSubsystem::GyroSubsystem() :
	Subsystem("GyroSubsystem")
{
	this->gyroYaw = new Gyro(new AnalogChannel(GYRO_YAW_PIN));
}

void GyroSubsystem::InitDefaultCommand()
{

}

float GyroSubsystem::GetYawAngle()
{
	return gyroYaw->GetAngle();
}

void GyroSubsystem::ResetYaw()
{
	gyroYaw->Reset();
}
