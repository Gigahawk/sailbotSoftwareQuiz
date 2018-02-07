#include <iostream>
#include <cmath>
#include "StandardCalc.h"

using namespace std;

float StandardCalc::BoundTo180(float angle)
{
	angle = fmod(angle, 360);

	if (angle < 0)
	{
		if (angle >= -180)
		{
			return angle;
		}
		else
		{
			return 360 + angle;
		}
	}
	else
	{
		if (angle == 180) {
			return -180;
		}
		if (angle < 180)
		{
			return angle;
		}
		else
		{
			return angle - 360;
		}
	}
}

bool StandardCalc::IsAngleBetween(float firstAngle, float middleAngle, float secondAngle)
{
	//Calculate angle difference in arbitrary direction
	float angle_12 = abs(secondAngle - firstAngle);
	float angle_1a = abs(middleAngle - firstAngle);
	float angle_a2 = abs(secondAngle - middleAngle);

	//Rebound differences to 180
	if (angle_12 > 180)
		angle_12 = 360 - angle_12;
	if (angle_1a > 180)
		angle_1a = 360 - angle_1a;
	if (angle_a2 > 180)
		angle_a2 = 360 - angle_a2;

	//Check that the differences match up
	if (angle_1a + angle_a2 == angle_12)
		return true;
	else
		return false;
}
