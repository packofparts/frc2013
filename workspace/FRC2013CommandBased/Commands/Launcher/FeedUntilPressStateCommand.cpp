#include "FeedUntilPressStateCommand.h"

FeedUntilPressStateCommand::FeedUntilPressStateCommand(bool waitState,
		double timeout)
{
	this->_waitState = waitState;
	this->SetTimeout(timeout);
	Requires(loader);
}

void FeedUntilPressStateCommand::Initialize()
{
	loader->SetFeederMotor(1.0);
}

void FeedUntilPressStateCommand::Execute()
{

}

bool FeedUntilPressStateCommand::IsFinished()
{
	bool b = loader->GetFeedSwitch();
	return (b == this->_waitState) || this->IsTimedOut();
}

void FeedUntilPressStateCommand::End()
{
	loader->SetFeederMotor(false);
}

void FeedUntilPressStateCommand::Interrupted()
{
	loader->SetFeederMotor(false);
}
