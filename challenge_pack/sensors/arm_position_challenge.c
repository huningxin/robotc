#pragma config(StandardModel, "Clawbot IQ")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//For this challenge, use the regular VEX IQ Clawbot. Place the robot on a surface,
//and an object approximately 5 rotations' length away from the robot. Starting with
//the arm in the 'up' position, program the robot to lower its arm, move forward 5 rotations,
//grabbing onto the object, then bring it back to the starting location.

task main()
{
	setMultipleMotors(-50, armMotor);
	while(getBumperValue(port8) == 0){
	}
	forward(4.5, rotations, 50);
	moveMotor(clawMotor, 2, seconds, 50);
	backward(4.5, rotations, 50);
}
