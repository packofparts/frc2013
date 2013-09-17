#ifndef CLIMBERSUBSYSTEM_H
#define CLIMBERSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Matthew
 */
class ClimberSubsystem: public Subsystem
{
private:
	Jaguar *climbJagLeft;
	Jaguar *climbJagRight;
	Solenoid* solenoidTip;
	Solenoid* solenoidArm;
public:
	ClimberSubsystem();
	void InitDefaultCommand();

	void SetLeftClimbMotor(float speed);
	void SetRightClimbMotor(float speed);
	
	void SetArmPosition(bool out);
	void SetRobotTip(bool tipped);
};

#endif
