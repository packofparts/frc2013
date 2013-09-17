#include "LoadFrisbeeCommand.h"

#include "FeedUntilPressStateCommand.h"

LoadFrisbeeCommand::LoadFrisbeeCommand()
{
	AddSequential(new FeedUntilPressStateCommand(false, 1.5));
	AddSequential(new FeedUntilPressStateCommand(true, 1.5));
}
