#include "ShiftHighCommand.h"

ShiftHighCommand::ShiftHighCommand()
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void ShiftHighCommand::Initialize()
{
	drive->ShiftHigh();
}

bool ShiftHighCommand::IsFinished()
{
	return true;
}

void ShiftHighCommand::Execute() { }
void ShiftHighCommand::End() { }
void ShiftHighCommand::Interrupted() { }
