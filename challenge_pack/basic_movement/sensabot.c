#pragma config(StandardModel, "Clawbot IQ With Sensors")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	forward(2.5, rotations, 75);
	moveMotor(motor10,3,seconds,63);
	moveMotor(motor10,3,seconds,-63);
	forward(2.5, rotations, 75);
	moveMotor(motor10,3,seconds,63);
	moveMotor(motor10,3,seconds,-63);
	forward(2.5, rotations, 75);
	moveMotor(motor10,3,seconds,63);
	moveMotor(motor10,3,seconds,-63);
	backward(2.5*3, rotations, 75);
}
