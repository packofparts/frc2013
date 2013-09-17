#ifndef SETCOASTBRAKECOMMAND_H
#define SETCOASTBRAKECOMMAND_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Matthew
 */
class SetCoastBrakeCommand: public CommandBase
{
private:
	CANJaguar::NeutralMode m_mode;
	bool isdone;
public:
	SetCoastBrakeCommand(CANJaguar::NeutralMode m_mode);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
