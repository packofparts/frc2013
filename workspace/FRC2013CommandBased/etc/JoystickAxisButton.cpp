/*
 * JoystickAxisButton.cpp
 *
 *  Created on: Feb 8, 2013
 *      Author: Matthew
 */

#include "JoystickAxisButton.h"
#include <math.h>

JoystickAxisButton::JoystickAxisButton(GenericHID* joystick, int axisNumber, float threshold, AxisTriggerType triggerType)
{
	this->m_joystick = joystick;
	this->m_axisNumber = axisNumber;
	this->m_axisThreshold = threshold;
	this->m_triggerType = triggerType;
}

bool JoystickAxisButton::Get()
{
	float value = this->m_joystick->GetRawAxis(this->m_axisNumber);
	
	switch(this->m_triggerType)
	{
	case kGreaterThan:
		return value > this->m_axisThreshold;
	case kLessThan:
		return value < this->m_axisThreshold;
	case kEqualTo:
		return fabs(value - this->m_axisThreshold) < 0.01;
	}
	
	return 0;
}
