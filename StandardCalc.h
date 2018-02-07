//#ifdef STANDARDCALC_H
#define STANDARDCALC_H

class StandardCalc
{
public:
	bool IsAngleBetween(float firstAngle, float middleAngle, float secondAngle);
	float BoundTo180(float angle);
};
//#endif //STANDARDCALC_H
