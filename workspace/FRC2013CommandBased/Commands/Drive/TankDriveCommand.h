#ifndef TANKDRIVECOMMAND_H
#define TANKDRIVECOMMAND_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Matthew
 */
class TankDriveCommand: public CommandBase
{
public:
	TankDriveCommand();
	virtual void Execute();
	virtual void Initialize();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
