#ifndef STOPLAUNCHERCOMMAND_H
#define STOPLAUNCHERCOMMAND_H

#include "../../../CommandBase.h"

/**
 *
 *
 * @author Matthew
 */
class StopLauncherCommand: public CommandBase
{
public:
	StopLauncherCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
