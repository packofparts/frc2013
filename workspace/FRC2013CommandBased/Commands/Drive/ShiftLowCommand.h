#ifndef SHIFTLOWCOMMAND_H
#define SHIFTLOWCOMMAND_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Matthew
 */
class ShiftLowCommand: public CommandBase
{
public:
	ShiftLowCommand();
	virtual void Initialize();
	virtual bool IsFinished();

	virtual void Execute();
	virtual void End();
	virtual void Interrupted();
};

#endif
