#ifndef GYROSUBSYSTEM_H
#define GYROSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Matthew
 */
class GyroSubsystem: public Subsystem
{
private:
	Gyro* gyroYaw;
public:
	GyroSubsystem();
	void InitDefaultCommand();
	
	float GetYawAngle();
	void ResetYaw();
};

#endif
