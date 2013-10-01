#include "OI.h"

#include "Commands/Drive/SetCoastBrakeCommand.h"
#include "Commands/Drive/ShiftHighCommand.h"
#include "Commands/Drive/ShiftLowCommand.h"
#include "Commands/Drive/TankDriveCommand.h"
#include "Commands/Launcher/LauncherMotors/StartLauncherCommand.h"
#include "Commands/Launcher/LauncherMotors/StopLauncherCommand.h"
#include "Commands/Launcher/FireShotCommand.h"
#include "Commands/Launcher/LoadFrisbeeCommand.h"
#include "Commands/Launcher/UnjamLoaderCommand.h"
#include "Commands/Blocker/BlockerDownCommand.h"
#include "Commands/Blocker/BlockerUpCommand.h"

#include "etc/JoystickAxisButton.h"

OI::OI()
{
	/**********************************/
	/************** Drive *************/
	/**********************************/
	joystickDriveLeft = new Joystick(JOYSTICK_DRIVE_LEFT);
	joystickDriveRight = new Joystick(JOYSTICK_DRIVE_RIGHT);

	// Coast and brake for jags
	btnBrake = new JoystickButton(joystickDriveRight, JOYSTICK_BUTTON_BRAKE);
	btnBrake->WhenPressed(
			new SetCoastBrakeCommand(CANJaguar::kNeutralMode_Brake));
	btnCoast = new JoystickButton(joystickDriveRight, JOYSTICK_BUTTON_COAST);
	btnCoast->WhenPressed(
			new SetCoastBrakeCommand(CANJaguar::kNeutralMode_Coast));

	// Define a button for shifting the gearboxes
	btnShift = new JoystickButton(joystickDriveRight, JOYSTICK_BUTTON_SHIFT);
	btnShift->WhenPressed(new ShiftHighCommand());
	btnShift->WhenReleased(new ShiftLowCommand());

	/**********************************/
	/************ Game Mech ***********/
	/**********************************/
	joystickGameMech = new Joystick(JOYSTICK_GAME_MECH);

	// Fire button
	btnFire = new JoystickButton(joystickGameMech, JOYSTICK_BUTTON_FIRE);
	btnFire->WhenPressed(new FireShotCommand());

	// Load one frisbee after we fire our last frisbee
	btnLoad = new JoystickButton(joystickGameMech, JOYSTICK_BUTTON_INIT_SHOT);
	btnLoad->WhenPressed(new LoadFrisbeeCommand());
	
	// The two directions of the switch to spin the launcher
	btnStartLauncher = new JoystickButton(joystickGameMech,
			JOYSTICK_BUTTON_START_LAUNCHER);
	btnStartLauncher->WhenPressed(new StartLauncherCommand());
	btnStopLauncher = new JoystickButton(joystickGameMech,
			JOYSTICK_BUTTON_STOP_LAUNCHER);
	btnStopLauncher->WhenPressed(new StopLauncherCommand());
	
	// Run backwards to unload a frisbee
	btnUnjam = new JoystickButton(joystickGameMech, JOYSTICK_BUTTON_UNJAM);
	btnUnjam->WhenPressed(new UnjamLoaderCommand());
	
	
	// Put the blocker up
	btnBlockUp = new JoystickButton(joystickGameMech, JOYSTICK_BUTTON_BLOCK);
	btnBlockUp->WhenPressed(new BlockerUpCommand());
	// Put the blocker down
	btnBlockDown = new JoystickButton(joystickGameMech, JOYSTICK_BUTTON_UNBLOCK);
	btnBlockDown->WhenPressed(new BlockerDownCommand());
}

float OI::GetStickLeftY()
{
	return joystickDriveLeft->GetAxis(Joystick::kYAxis);
}

float OI::GetStickRightY()
{
	return joystickDriveRight->GetAxis(Joystick::kYAxis);
}

float OI::GetThrottle()
{
	// Scale from [1, -1] to [0, 1]
	//return (joystickDriveRight->GetAxis(Joystick::kThrottleAxis) - 1) / -2;
	return 1.0;
}
