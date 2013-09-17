#ifndef UNJAMLOADERCOMMAND_H
#define UNJAMLOADERCOMMAND_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Matthew
 */
class UnjamLoaderCommand: public CommandBase
{
public:
	UnjamLoaderCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
