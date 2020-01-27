#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S4,     irSensor,       sensorEV3_IRSensor, modeEV3IR_Remote)
#pragma config(Motor,  motorA,          pickupMotor,   tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightMotor,    tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          leftMotor,     tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void pickup() {
	moveMotor(motorA, 0.7, rotations, 50);
}

void putdown() {
	moveMotor(motorA, -0.7, rotations, 50);
}

void rightMotorTurnLeft() {
	moveMotor(motorB, 250, degrees, 1000);
	moveMotor(motorB, -70, degrees, 1000);
}

void rightMotorTurnRight() {
	moveMotor(motorB, -250, degrees, 1000);
	moveMotor(motorB, 70, degrees, 1000);
}

void leftMotorTurnRight() {
	moveMotor(motorC, -250, degrees, 1000);
	moveMotor(motorC, 70, degrees, 1000);
}

void leftMotorTurnLeft() {
	moveMotor(motorC, 250, degrees, 1000);
	moveMotor(motorC, -70, degrees, 1000);
}

task main()
{

	while(getTouchValue(S1) == 0){
		rightMotorTurnLeft();
		rightMotorTurnRight();
		leftMotorTurnRight();
		leftMotorTurnLeft();
		leftMotorTurnRight();
		rightMotorTurnRight();
		leftMotorTurnLeft();
		rightMotorTurnLeft();
		leftMotorTurnLeft();
	}
	sleep(1000);
	pickup();
	sleep(1000);
	putdown();
	sleep(1000);


	//		sleep(1000);
	//	pickup();
	//	sleep(1000);
	//	putdown();
	//	sleep(1000);

	//	sleep(1000);
	//	pickup();
	//	sleep(1000);
	//	putdown();
	//	sleep(1000);
	//	//while(getTouchValue(S1) == 0) {
	//	//	playSound(soundFastUpwardTones);

	//	//}
}
