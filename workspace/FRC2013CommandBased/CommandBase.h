#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Commands/Command.h"
#include "Subsystems/BlockerSubsystem.h"
#include "Subsystems/DriveSubsystem.h"
#include "Subsystems/FrisbeeLauncher.h"
#include "Subsystems/FrisbeeLoader.h"
#include "Subsystems/GyroSubsystem.h"
#include "OI.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(const char *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static OI *oi;
	
	static DriveSubsystem* drive;
	
	static FrisbeeLauncher* launcher;
	static FrisbeeLoader* loader;
	static BlockerSubsystem* blocker;
	
	static GyroSubsystem* gyro;
	
};

#endif
