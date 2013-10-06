#ifndef CLIMBCOMMAND_H
#define CLIMBCOMMAND_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Matthew
 */
class ClimbCommand: public CommandBase {
public:
	ClimbCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
