#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Robotmap.h"

class OI
{
private:
	Joystick* joystickDriveLeft;
	Joystick* joystickDriveRight;
	Joystick* joystickGameMech;

	// **************************************
	// **************** Drive ***************
	// **************************************
	JoystickButton* btnBrake;
	JoystickButton* btnCoast;
	JoystickButton* btnShift;
	
	// **************************************
	// ********** Launcher Motors ***********
	// **************************************
	JoystickButton* btnStartLauncher;
	JoystickButton* btnStopLauncher;
	
	// **************************************
	// ********** Loader/Launcher ***********
	// **************************************
	JoystickButton* btnFire;
	JoystickButton* btnLoad;
	JoystickButton* btnUnjam;
	
	// **************************************
	// *************** Climber **************
	// **************************************
	JoystickButton* btnBeginClimb;
	JoystickButton* btnEndClimb;
public:
	OI();
	float GetStickLeftY();
	float GetStickRightY();
	float GetThrottle();
	bool GetLeftClimbUp();
	bool GetLeftClimbDown();
	bool GetRightClimbUp();
	bool GetRightClimbDown();
};

#endif
