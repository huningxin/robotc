#pragma config(StandardModel, "Clawbot IQ With Sensors")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Using the Gyro Sensor, program you robot to accurately go around a square box!
// Program the robot to go one lap around a square or rectangular box, using the Gyro Sensor to help make precise turns. While the robot is moving around the box, the Touch LED should display a color, corresponding to it?��s current action

// When moving straight, the Touch LED should display the color orange.
// When turning, the Touch LED should display the color blue.
// Note: It is recommended to reset the gyro count after each turn!
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
task main()
{
	for(int i = 0; i < 4; i++){
		setTouchLEDColor(port2, colorOrange);
		forward(7, rotations, 100);
		setTouchLEDColor(port2, colorBlue);
		turnRightByGyro(90);
	}
}
