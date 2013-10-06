#include "FireShotCommand.h"
#include "FeedUntilPressStateCommand.h"
#include "LoadFrisbeeCommand.h"

class FireShotEngageCommand: public CommandBase
{
private:
	bool _on;
public:
	FireShotEngageCommand(double timeout, bool on)
	{
		this->SetTimeout(timeout);
		this->_on = on;
		Requires(loader);
	}

	// Called just before this Command runs the first time
	void Initialize()
	{
		loader->SetPusher(this->_on); // Put the solenoid in/out based on [_out]
	}

	// Nothing to do here
	void Execute()
	{
	}

	// Return true when we are timed out.
	bool IsFinished()
	{
		return IsTimedOut();
	}

	void End() // Do nothing
	{
	}
	void Interrupted() // Do nothing
	{
	}
};

FireShotCommand::FireShotCommand()
{
	//this->SetTimeout(1.1);

	AddSequential(new FireShotEngageCommand(0.5, true)); // Pusher out
	AddSequential(new FireShotEngageCommand(0.5, false)); // Pusher in
	AddSequential(new LoadFrisbeeCommand());
}
