#ifndef STARTLAUNCHERCOMMAND_H
#define STARTLAUNCHERCOMMAND_H

#include "../../../CommandBase.h"

/**
 *
 *
 * @author Matthew
 */
class StartLauncherCommand: public CommandBase
{
public:
	StartLauncherCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
