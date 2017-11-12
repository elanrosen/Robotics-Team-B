#pragma config(Sensor, dgtl2,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl4,  leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,            ,             tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           leftBack,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rightBack,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           armLeft,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rightFront,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           leftFront,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           armRight,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           mobileGoalLeft, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          mobileGoalRight, tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void armUp() {
		motor[armLeft] = 63;
		motor[armRight] = -63;
	}
	void armUp() {
		motor[armLeft] = -63;
		motor[armRight] = 63;
	}

	void mobileGoalUp() {
		motor[mobileGoalLeft] = -63;
		motor[mobileGoalRight] = 63;
	}
	void mobileGoalDown() {
		motor[mobileGoalLeft] = 63;
		motor[mobileGoalRight] = -63;
	}
task autonomous()
{
	/* 4.25 in dia
	Circumference = Diameter * pi
	Circumference = 13.345 in
	4.5 ft to mobile goal --> 54 inches
	4.04646
	1457 deg
	*/



	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;

	while(SensorValue[rightEncoder] < 1457 || SensorValue[leftEncoder] < 1457) {
		motor[rightFront] = 127;
		motor[rightBack] = 127;
		motor[leftFront] = 127;
		motor[leftBack] = 127;
	}
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
int forwardSpeed = 127;
void motorsForward() { //Function to start drivetrain
	motor[rightFront] = forwardSpeed;
	motor[rightBack] = forwardSpeed;
	motor[leftFront] = forwardSpeed;
	motor[leftBack] = forwardSpeed;
}

int waitTime = 10; //Wait time before trying straight
int degreesRotation = 360; //Degrees of rotation on each encoder



int increaseSpeed = 20; //Increase speed by this amount
void leftSpeedIncrease() { //Increase speed of left motors
	motor[leftFront] = forwardSpeed + increaseSpeed;
	motor[leftBack] = forwardSpeed + increaseSpeed;
}
void rightSpeedIncrease() { //Increase speed of right motors
	motor[rightFront] = forwardSpeed + increaseSpeed;
	motor[rightBack] = forwardSpeed + increaseSpeed;
}
void motorsStop() { //Function to stop drivetrain
	motor[rightFront] = 0;
	motor[rightBack] = 0;
	motor[leftFront] = 0;
	motor[leftBack] = 0;
}

task usercontrol()
{
	while (1==1) {
		motor[rightFront] = vexRT[Ch2];
		motor[rightBack] = vexRT[Ch2];
		motor[leftFront] = vexRT[Ch3];
		motor[leftBack] = vexRT[Ch3];

		if (vexRT[Btn7U]) {
			motor[mobileGoalLeft] = 63;
			motor[mobileGoalRight] = 63;
			wait1Msec(10);
			motor[mobileGoalLeft] = 0;
			motor[mobileGoalRight] = 0;
		}

		if (vexRT[Btn7D]) {
			motor[mobileGoalLeft] = -63;
			motor[mobileGoalRight] = -63;
			wait1Msec(10);
			motor[mobileGoalLeft] = 0;
			motor[mobileGoalRight] = 0;
		}

		if (vexRT[Btn6U]) {
			motor[armLeft] = 63;
			motor[armRight] = 63;
			wait1Msec(10);
			motor[armLeft] = 0;
			motor[armRight] = 0;
		}
		if (vexRT[Btn6D]) {
			motor[armLeft] = -63;
			motor[armRight] = -63;
			wait1Msec(10);
			motor[armLeft] = 0;
			motor[armRight] = 0;
		}
		if (vexRT[Btn5U]) {
			motor[claw] = 63;
			wait1Msec(10);
			motor[claw] = 0;
		}
		if (vexRT[Btn5D]) {
			motor[claw] = -63;
			wait1Msec(10);
			motor[claw] = 0;
		}

		/*if (vexRT[Btn8D]) { //Practice autonomous
		motorsForward();
		while (SensorValue[leftEncoder] <= degreesRotation && SensorValue[rightEncoder] <= degreesRotation) { //While rotations are less than threshold
		if(SensorValue[leftEncoder] > SensorValue[rightEncoder]) { //Implement self-righting mechanism
		leftSpeedIncrease();
		wait1Msec(waitTime);
		motorsForward();
		}
		if(SensorValue[rightEncoder] > SensorValue[leftEncoder]) {
		rightSpeedIncrease();
		wait1Msec(waitTime);
		motorsForward();
		}
		}
		motorsStop();
		}*/
	}
}
