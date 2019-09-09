#pragma config(StandardModel, "Clawbot IQ With Sensors")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void turnRightByGyro(int degrees)
{
	resetGyro(port4);
	while(getGyroDegrees(port4)>-degrees)
	{
		setMotorSpeed(motor1,50);
		setMotorSpeed(motor6,-50);
	}
	setMotorSpeed(motor1,0);
	setMotorSpeed(motor6,0);
}

void turnLeftByGyro(int degrees)
{
	resetGyro(port4);
	while(getGyroDegrees(port4)<degrees)
	{
		setMotorSpeed(motor1,-50);
		setMotorSpeed(motor6,50);
	}
	setMotorSpeed(motor1,0);
	setMotorSpeed(motor6,0);
}

task main()
{
	// 247.5 by motor is 90 by gyro
	//turnRight(247.5, degrees, 100);

	turnRightByGyro(90);
	//sleep(1000);
	//turnLeftByGyro(90);


}