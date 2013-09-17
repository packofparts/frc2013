#include "FrisbeeLauncher.h"

FrisbeeLauncher::FrisbeeLauncher() :
	Subsystem("FrisbeeLauncher")
{
	firstStage = new CANJaguar(MOTOR_LAUNCHER_STAGE_1, CANJaguar::kVoltage);
	secondStage = new CANJaguar(MOTOR_LAUNCHER_STAGE_2, CANJaguar::kVoltage);

	this->firstStage->SetSafetyEnabled(false);
	this->firstStage->SetSafetyEnabled(false);
}

void FrisbeeLauncher::InitDefaultCommand()
{
}

void FrisbeeLauncher::SetLauncherSpeed(float voltage)
{
	if (voltage < 0) // So that you can't run the shooter backwards
		return;

	this->_isRunning = voltage > 0; // Set isRunning to true if speed > 0

	this->firstStage->Set(voltage);
	this->secondStage->Set(voltage);
}

bool FrisbeeLauncher::IsRunning()
{
	return _isRunning;
}
