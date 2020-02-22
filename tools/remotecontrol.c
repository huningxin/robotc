#pragma config(Sensor, port2,  touchLED,       sensorVexIQ_LED)
#pragma config(Sensor, port3,  colorDetector,  sensorVexIQ_Color12Color)
#pragma config(Sensor, port4,  gyroSensor,     sensorVexIQ_Gyro)
#pragma config(Sensor, port7,  distanceMM,     sensorVexIQ_Distance)
#pragma config(Sensor, port8,  bumpSwitch,     sensorVexIQ_Touch)
#pragma config(Motor,  motor1,          leftMotor,     tmotorVexIQ, openLoop, driveLeft, encoder)
#pragma config(Motor,  motor6,          rightMotor,    tmotorVexIQ, openLoop, reversed, driveRight, encoder)
#pragma config(Motor,  motor10,         armMotor,      tmotorVexIQ, openLoop, encoder)
#pragma config(Motor,  motor11,         clawMotor,     tmotorVexIQ, openLoop, encoder)
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
			setTouchLEDColor(port2, colorGreen);
			setMotorSpeed(leftMotor, joystick.joy1_y1);
		}
		else  //If less than the threshold, we'll set the motor to zero.
		{
			setTouchLEDColor(port2, colorRed);
			setMotorSpeed(leftMotor, 0);
		}

		//If the joystick.joy1_y2 (right Y-Axis) is greater than the threshold value,
		//then we'll set the speed of the motor to vlaue from the joystick.
		if(joystick.joy1_y2 > threshold || joystick.joy1_y2 < -threshold)
		{
			setTouchLEDColor(port2, colorGreen);
			setMotorSpeed(rightMotor, joystick.joy1_y2);
		}
		else  //If less than the threshold, we'll set the motor to zero.
		{
			setTouchLEDColor(port2, colorRed);
			setMotorSpeed(rightMotor, 0);
		}

		displayTextLine(1, "%d", joystick.joy1_Buttons);

		//If Button "Btn5" is pressed in, we'll set the arm motor to run in reverse.
		if(joystick.joy1_Buttons == 1)
		{
			setTouchLEDColor(port2, colorYellow);
			setMotorSpeed(armMotor, -127);
		}
		//If the "Btn5" isn't pressed, but "Btn7" is, we'll set the motor to run forward.
		else if(joystick.joy1_Buttons == 8)
		{
			setTouchLEDColor(port2, colorYellow);
			setMotorSpeed(armMotor, 127);
		}
		else  //If neither button is pressed, we'll set the motor off.
		{
			setTouchLEDColor(port2, colorRed);
			setMotorSpeed(armMotor, 0);
		}

		//If Button "Btn6" is pressed in, we'll set the arm motor to run in reverse.
		if(joystick.joy1_Buttons == 4)
		{
			setTouchLEDColor(port2, colorBlue);
			setMotorSpeed(clawMotor, -127);
		}
		//If the "Btn6" isn't pressed, but "Btn8" is, we'll set the motor to run forward.
		else if(joystick.joy1_Buttons == 2)
		{
			setTouchLEDColor(port2, colorBlue);
			setMotorSpeed(clawMotor, 127);
		}
		else	//If neither button is pressed, we'll set the mot																																					or off.
		{
			setTouchLEDColor(port2, colorRed);
			setMotorSpeed(clawMotor, 0);
		}
	}
}
