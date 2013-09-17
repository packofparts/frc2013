#ifndef SHIFTHIGHCOMMAND_H
#define SHIFTHIGHCOMMAND_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Matthew
 */
class ShiftHighCommand: public CommandBase
{
public:
	ShiftHighCommand();
	virtual void Initialize();
	virtual bool IsFinished();
	
	virtual void Execute();
	virtual void End();
	virtual void Interrupted();
};

#endif
