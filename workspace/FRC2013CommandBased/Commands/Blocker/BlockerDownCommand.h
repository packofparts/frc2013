#ifndef BLOCKERDOWNCOMMAND_H
#define BLOCKERDOWNCOMMAND_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Matthew
 */
class BlockerDownCommand: public CommandBase {
public:
	BlockerDownCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
