#include "BlockerUpCommand.h"

BlockerUpCommand::BlockerUpCommand() {
	// Use requires() here to declare subsystem dependencies
	Requires(blocker);
}

// Called just before this Command runs the first time
void BlockerUpCommand::Initialize() {
	blocker->SetBlocker(true);
}

// Called repeatedly when this Command is scheduled to run
void BlockerUpCommand::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool BlockerUpCommand::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void BlockerUpCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BlockerUpCommand::Interrupted() {
}
