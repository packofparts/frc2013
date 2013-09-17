#ifndef FRISBEELAUNCHER_H
#define FRISBEELAUNCHER_H

#include "WPIlib.h"
#include "Commands/Subsystem.h"
#include "../Robotmap.h"

/**
 *
 *
 * @author Matthew
 */
class FrisbeeLauncher: public Subsystem {
private:
	CANJaguar* firstStage;
	CANJaguar* secondStage;
	bool _isRunning;
public:
	FrisbeeLauncher();
	void InitDefaultCommand();
	void SetLauncherSpeed(float voltage);
	bool IsRunning();
};

#endif
