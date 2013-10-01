#ifndef BLOCKERUPCOMMAND_H
#define BLOCKERUPCOMMAND_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Matthew
 */
class BlockerUpCommand: public CommandBase {
public:
	BlockerUpCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
