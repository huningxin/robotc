#pragma config(StandardModel, "Clawbot IQ With Sensors")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*------------------------------------------------------------------------------------------------
This program will use the VEX IQ Wirless Controller to drive your Clawbot. This program uses
If/Else statements to provide a "threshold" for the transmitter - this allows your robot to
come to a stop even if the joysticks on the Wireless Controller haven't perfectly returned to
their zero position.

Note: You will have to set ROBOTC to enable "Wireless Control" to use the VEX IQ joystick.

ROBOT CONFIGURATION: VEX IQ Clawbot
MOTORS & SENSORS:
[I/O Port]          [Name]              [Type]                			[Location]
Port 1        			leftMotor           VEX IQ Motor		      			Left side motor
Port 6       				rightMotor          VEX IQ Motor		      			Right side motor (reversed)
Port 10							armMotor						VEX IQ Motor								Arm Up/Down motor
Port 11							clawMotor						VEX IQ Motor								Claw Open/Close motor
------------------------------------------------------------------------------------------------*/
#include "JoystickDriver.c"

task main()
{
	int threshold = 10;
	while(true)
	{
		getJoystickSettings(joystick);

		//If the joy1_y1 (left Y-Axis) is greater than the threshold value,
		//then we'll set the speed of the motor to vlaue from the joystick.
		if(joystick.joy1_y1 > threshold || joystick.joy1_y1 < -threshold)
		{
			setMotorSpeed(leftMotor, joystick.joy1_y1);
		}
		else  //If less than the threshold, we'll set the motor to zero.
		{
			setMotorSpeed(leftMotor, 0);
		}

		//If the joystick.joy1_y2 (right Y-Axis) is greater than the threshold value,
		//then we'll set the speed of the motor to vlaue from the joystick.
		if(joystick.joy1_y2 > threshold || joystick.joy1_y2 < -threshold)
		{
			setMotorSpeed(rightMotor, joystick.joy1_y2);
		}
		else  //If less than the threshold, we'll set the motor to zero.
		{
			setMotorSpeed(rightMotor, 0);
		}

		displayTextLine(1, "%d", joystick.joy1_Buttons);

		//If Button "Btn5" is pressed in, we'll set the arm motor to run in reverse.
		if(joystick.joy1_Buttons == 1)
		{
			setMotorSpeed(armMotor, -127);
		}
		//If the "Btn5" isn't pressed, but "Btn7" is, we'll set the motor to run forward.
		else if(joystick.joy1_Buttons == 8)
		{
			setMotorSpeed(armMotor, 127);
		}
		else  //If neither button is pressed, we'll set the motor off.
		{
			setMotorSpeed(armMotor, 0);
		}

		//If Button "Btn6" is pressed in, we'll set the arm motor to run in reverse.
		if(joystick.joy1_Buttons == 4)
		{
			setMotorSpeed(clawMotor, -127);
		}
		//If the "Btn6" isn't pressed, but "Btn8" is, we'll set the motor to run forward.
		else if(joystick.joy1_Buttons == 2)
		{
			setMotorSpeed(clawMotor, 127);
		}
		else	//If neither button is pressed, we'll set the mot																																					or off.
		{
			setMotorSpeed(clawMotor, 0);
		}
	}
}
