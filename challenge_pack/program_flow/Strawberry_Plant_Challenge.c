#pragma config(StandardModel, "Clawbot IQ With Sensors")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
void turnRightByGyro(int degrees)
{
	resetGyro(port4);
	while(getGyroDegrees(port4)>-degrees + 1)
	{
		setMotorSpeed(motor1,35);
		setMotorSpeed(motor6,-35);
	}
	setMotorSpeed(motor1,0);
	setMotorSpeed(motor6,0);
}

void turnLeftByGyro(int degrees)
{
	resetGyro(port4);
	while(getGyroDegrees(port4)<degrees - 1)
	{
		setMotorSpeed(motor1,-35);
		setMotorSpeed(motor6,35);
	}
	setMotorSpeed(motor1,0);
	setMotorSpeed(motor6,0);
}
task main()
{
	while(1){
		setMultipleMotors(50, rightMotor, leftMotor);
		while(getDistanceValue(port7) > 100){}
		stopMultipleMotors(50, rightMotor, leftMotor);
		moveMotor(motor11, 2, seconds, 50);
		moveMotor(motor10, 0.7, seconds, 50);
		if(getColorName(port3) == colorGreen){
			turnRightByGyro(90);
			moveMotor(motor11, 2, seconds, -50);
			turnLeftByGyro(90);
		}
		else {
			turnLeftByGyro(90);
			moveMotor(motor11, 2, seconds, -50);
			turnRightByGyro(90);
		}
		moveMotor(motor10, 0.7, seconds, -50);
	}
}