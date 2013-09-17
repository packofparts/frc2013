/*
 * JoystickAxisButton.h
 *
 *  Created on: Feb 8, 2013
 *      Author: Matthew
 */

#ifndef JOYSTICKAXISBUTTON_H_
#define JOYSTICKAXISBUTTON_H_

#include "GenericHID.h"
#include "Buttons/Button.h"

class JoystickAxisButton : public Button
{
public:
	typedef enum AxisTriggerType
	{
		kGreaterThan,
		kLessThan,
		kEqualTo
	};
	
	JoystickAxisButton(GenericHID* joystick, int axisNumber, float threshold, AxisTriggerType triggerType);
	virtual ~JoystickAxisButton() {}
	
	virtual bool Get();
private:
	GenericHID *m_joystick;
	int m_axisNumber;
	float m_axisThreshold;
	AxisTriggerType m_triggerType;
};

#endif /* JOYSTICKAXISBUTTON_H_ */
