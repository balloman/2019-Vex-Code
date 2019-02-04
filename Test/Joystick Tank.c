#pragma config(Motor,  port2,           frontRightMotor, tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port3,           backRightMotor, tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port4,           frontLeftMotor, tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           backLeftMotor, tmotorServoContinuousRotation, openLoop)

short deadZone(short value, float deadzonePercent) {
	float range = 0.01 * deadzonePercent * 127;
	if (abs(value) < range)
  {
    return 0;
  }
  else
  {
    return value;
  }

}

task main()
{
	while(true){
		short rightValue = deadZone(vexRT[Ch2], 8);
		short leftValue = deadZone(vexRT[Ch3], 8);
		motor[frontRightMotor] = rightValue;
		motor[backRightMotor] = rightValue;

		motor[frontLeftMotor] = leftValue;
		motor[backLeftMotor] = leftValue;
	}
}
