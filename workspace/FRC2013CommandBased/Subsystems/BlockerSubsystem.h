#ifndef BLOCKERSUBSYSTEM_H
#define BLOCKERSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Matthew
 */
class BlockerSubsystem: public Subsystem
{
private:
	Solenoid* blockUpper;
	Solenoid* blockLower;
public:
	BlockerSubsystem();
	void SetBlocker(bool up);
	void InitDefaultCommand();
};

#endif
