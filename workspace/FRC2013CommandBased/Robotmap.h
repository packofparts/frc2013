#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "logging.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

#define AUTO_SCRIPT "/ni-rt/auto.rts"

//       #  #######  #     #   #####   #######  ###   #####   #    # 
//       #  #     #   #   #   #     #     #      #   #     #  #   #  
//       #  #     #    # #    #           #      #   #        #  #   
//       #  #     #     #      #####      #      #   #        ###    
// #     #  #     #     #           #     #      #   #        #  #   
// #     #  #     #     #     #     #     #      #   #     #  #   #  
//  #####   #######     #      #####      #     ###   #####   #    # 

/************** Left Drive ******************/
#define JOYSTICK_DRIVE_LEFT 1


/************** Right Drive *****************/

#define JOYSTICK_DRIVE_RIGHT 2

#define JOYSTICK_BUTTON_BRAKE 4
#define JOYSTICK_BUTTON_COAST 5

#define JOYSTICK_BUTTON_SHIFT 1


/**************** Game Mech *****************/

#define JOYSTICK_GAME_MECH 3

#define JOYSTICK_BUTTON_FIRE 3
#define JOYSTICK_BUTTON_START_LAUNCHER 2
#define JOYSTICK_BUTTON_STOP_LAUNCHER 4
#define JOYSTICK_BUTTON_INIT_SHOT 1
#define JOYSTICK_BUTTON_UNJAM 8
#define JOYSTICK_BUTTON_TIP 9
#define JOYSTICK_BUTTON_UNTIP 7


//  #####   #######  #     #   #####   #######  ######    #####  
// #     #  #        ##    #  #     #  #     #  #     #  #     # 
// #        #        # #   #  #        #     #  #     #  #       
//  #####   #####    #  #  #   #####   #     #  ######    #####  
//       #  #        #   # #        #  #     #  #   #          # 
// #     #  #        #    ##  #     #  #     #  #    #   #     # 
//  #####   #######  #     #   #####   #######  #     #   #####

#define GYRO_YAW_PIN 1
#define FEED_SWITCH 13
#define COMPRESSOR_TRANSDUCER 14

// #######  #     #  #######  ######   #     #  ####### 
// #     #  #     #     #     #     #  #     #     #    
// #     #  #     #     #     #     #  #     #     #    
// #     #  #     #     #     ######   #     #     #    
// #     #  #     #     #     #        #     #     #    
// #     #  #     #     #     #        #     #     #    
// #######   #####      #     #         #####      #  


#define MOTOR_LEFT 2
#define MOTOR_RIGHT 3

#define MOTOR_LAUNCHER_STAGE_1 4
#define MOTOR_LAUNCHER_STAGE_2 5
#define MOTOR_CLIMBER_LEFT 6
#define MOTOR_CLIMBER_RIGHT 7

#define MOTOR_FEEDER 8

#define SOLENOID_SHIFTER 1
// This is the solenoid channel that pushes the frisbee into the wheels
#define SOLENOID_FEEDER 2

#define SOLENOID_CLIMBER_ARMS 3
#define SOLENOID_TIP 4



#define COMPRESSOR_SPIKE 8

//  #####   #######  #     #   #####   #######   #####  
// #     #  #     #  ##    #  #     #     #     #     # 
// #        #     #  # #   #  #           #     #       
// #        #     #  #  #  #   #####      #      #####  
// #        #     #  #   # #        #     #           # 
// #     #  #     #  #    ##  #     #     #     #     # 
//  #####   #######  #     #   #####      #      #####  
  
// This is how fast the wheels get spun when they're on.  This is absolute voltage.
#define LAUNCHER_SPEED 12.00

// The voltage that gets fed to the loader motor when it's loading.
#define FEEDER_MOTOR_VOLTAGE 5.00

// Gyro rotation PID constants
#define GYRO_ROTATE_kP 0.05
#define GYRO_ROTATE_kI 0
#define GYRO_ROTATE_kD 0.2

// Number of encoder counts per meter of forward travel
#define DRIVE_COUNTS_PER_REV (360)
#define DRIVE_CHAIN_RATIO (24 / 12)
#define DRIVE_WHEEL_DIAMETER (0.1588)

// Approximate robot speed in m/s
#define ROBOT_SPEED 1.5
// Straight drive PID constants
#define DRIVE_kP 0.8
#define DRIVE_kI 0
#define DRIVE_kD 0.05

#define MINIMUM_LOG_LEVEL kInformation

// Pi.
#define MATH_PI 3.14159
#endif
