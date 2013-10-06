#include "BlockerSubsystem.h"
#include "../Robotmap.h"

BlockerSubsystem::BlockerSubsystem() :
	Subsystem("BlockerSubsystem") {
	
	this->blockUpper = new Solenoid(SOLENOID_BLOCKER_UPPER);
	this->blockLower = new Solenoid(SOLENOID_BLOCKER_LOWER);
}

void BlockerSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void BlockerSubsystem::SetBlocker(bool state)
{
	this->blockLower->Set(state);
	this->blockUpper->Set(state);
}
