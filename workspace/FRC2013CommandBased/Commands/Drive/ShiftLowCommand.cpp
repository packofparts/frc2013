#include "ShiftLowCommand.h"

ShiftLowCommand::ShiftLowCommand()
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

void ShiftLowCommand::Initialize()
{
	drive->ShiftLow();
}

bool ShiftLowCommand::IsFinished()
{
	return true;
}

void ShiftLowCommand::Execute() { }
void ShiftLowCommand::End() { }
void ShiftLowCommand::Interrupted() { }
