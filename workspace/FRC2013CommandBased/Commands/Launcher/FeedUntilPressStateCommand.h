#ifndef FEEDUNTILPRESSSTATECOMMAND_H
#define FEEDUNTILPRESSSTATECOMMAND_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Matthew
 */
class FeedUntilPressStateCommand: public CommandBase {
private:
	bool _waitState;
public:
	FeedUntilPressStateCommand(bool waitState, double timeout);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
