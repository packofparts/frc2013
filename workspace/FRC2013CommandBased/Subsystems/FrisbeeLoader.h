
#ifndef FRISBEELOADER_H
#define FRISBEELOADER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Matthew
 */
class FrisbeeLoader: public Subsystem {
private:
	Solenoid* pusherSolenoid;
	DigitalInput* feedSwitch;
	CANJaguar* feedMotor;
public:
	FrisbeeLoader();
	void InitDefaultCommand();
	/**
	 * true is deployed (firing shot) and false is retracted (reload)
	 */
	void SetPusher(bool position);
	bool GetFeedSwitch();
	void SetFeederMotor(float speed);
};

#endif
