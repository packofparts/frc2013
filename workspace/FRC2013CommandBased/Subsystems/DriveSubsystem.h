#ifndef DRIVESUBSYSTEM_H
#define DRIVESUBSYSTEM_H

#include "WPILib.h"
#include "Commands/Subsystem.h"
#include "../Robotmap.h"

/**
 *
 *
 * @author Matthew Kennedy of FRC1294
 */
class DriveSubsystem: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	RobotDrive* drive;
	CANJaguar* motorLeft;
	CANJaguar* motorRight;
	Solenoid* shiftSolenoid;
	bool _isClosedLoop;
public:	
	DriveSubsystem();
	void InitDefaultCommand();
	void TankDrive(float l, float r);
	void RotateSpeed(float x);
	
	void Shift(bool high);
	void ShiftLow();
	void ShiftHigh();
	
	void SetCoastBrakeMode(CANJaguar::NeutralMode mode);
};

#endif
