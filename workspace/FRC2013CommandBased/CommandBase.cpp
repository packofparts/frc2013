#include "CommandBase.h"

CommandBase::CommandBase(const char *name) :
	Command(name)
{
}

CommandBase::CommandBase() :
	Command()
{
}

// Initialize a single static instance of all of your subsystems to NULL
FrisbeeLauncher* CommandBase::launcher = NULL;
FrisbeeLoader* CommandBase::loader = NULL;
DriveSubsystem* CommandBase::drive = NULL;
GyroSubsystem* CommandBase::gyro = NULL;
BlockerSubsystem* CommandBase::blocker = NULL;

OI* CommandBase::oi = NULL;

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	launcher = new FrisbeeLauncher();
	loader = new FrisbeeLoader();
	drive = new DriveSubsystem();
	gyro = new GyroSubsystem();
	blocker = new BlockerSubsystem();
	
	oi = new OI();
}
