#pragma config(StandardModel, "Clawbot IQ With Sensors")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void turnRightByGyro(int degrees)
{
	resetGyro(port4);
	while(getGyroDegrees(port4) > -degrees)
	{
		setMotorSpeed(motor1,35);
		setMotorSpeed(motor6,-35);
	}
	setMotorSpeed(motor1,0);
	setMotorSpeed(motor6,0);
}
task main()
{
	while(getDistanceValue(port7) > 200){
	setTouchLEDColor(port2, colorGreen);
	setMultipleMotors(50, leftMotor, rightMotor);
	while(getDistanceValue(port7) > 150){
	}
	stopAllMotors();
	setTouchLEDColor(port2, colorYellow);
	turnRightByGyro(90);
	}
	setTouchLEDColor(port2, colorRed);
	while(1){}
}
