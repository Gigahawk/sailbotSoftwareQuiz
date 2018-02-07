// StandardCalcTests.cpp : Defines the entry point for the console application.
//
#include "gtest/gtest.h"

#include "StandardCalc.h"

typedef struct betweenAngles {
	float firstAngle;
	float middleAngle;
	float secondAngle;
	bool inMiddle;

	betweenAngles(float ang1, float angMid, float ang2, bool inMid) {
		firstAngle = ang1;
		middleAngle = angMid;
		secondAngle = ang2;

		inMiddle = inMid;
	}

	friend std::ostream& operator<<(std::ostream& os, const betweenAngles& obj){
		return os
			<< "First Angle: " << obj.firstAngle
			<< " Middle Angle: " << obj.middleAngle
			<< " Second Angle: " << obj.secondAngle
			<< " In Middle: " << obj.inMiddle;
	}
} betweenAngles;

typedef struct boundAngles {
	float inAngle;
	float outAngle;

	boundAngles(float inAng, float outAng) {
		inAngle = inAng;
		outAngle = outAng;
	}

	friend std::ostream& operator<<(std::ostream& os, const boundAngles& obj) {
		return os
			<< "Input Angle: " << obj.inAngle
			<< " Output Angle: " << obj.outAngle;
	}
} boundAngles;

class StandardCalcTest : public ::testing::Test {
public:
	StandardCalc* sc;

	StandardCalcTest() {
		sc = new StandardCalc;
	}

	virtual ~StandardCalcTest() {
		delete sc;
	}
};

class IsAngleBetweenTest : public StandardCalcTest, public ::testing::WithParamInterface<betweenAngles> {

};

class BoundTo180Test : public StandardCalcTest, public ::testing::WithParamInterface<boundAngles> {

};

TEST_P(IsAngleBetweenTest, all_angles) {
	auto params = GetParam();

	auto inMiddle = sc->IsAngleBetween(params.firstAngle, params.middleAngle, params.secondAngle);

	EXPECT_EQ(params.inMiddle, inMiddle);
}

TEST_P(BoundTo180Test, all_angles) {
	auto params = GetParam();

	auto outAngle = sc->BoundTo180(params.inAngle);

	EXPECT_EQ(params.outAngle, outAngle);
}

INSTANTIATE_TEST_CASE_P(Between, IsAngleBetweenTest,
::testing::Values(
	betweenAngles{-90, -180, 110, true},
	betweenAngles{-90, -180, 80, false},
	betweenAngles{ 1, 20, 90, true },
	betweenAngles{ 1, 90, 20, false },
	betweenAngles{20, 1, -90, true},
	betweenAngles{ 20, 25,-90, false },
	betweenAngles{ 20, -25, 90, false },
	betweenAngles{ 20, -25, -90, true },
	betweenAngles{ 20, -90, -25, false },
	betweenAngles{ -20, 90, 125, true },
	betweenAngles{ -20, 90, 45, false },
	betweenAngles{ -20, 125, -30, false },
	betweenAngles{ -30, -20, 90, true },
	betweenAngles{ -30, -90, 20, false },
	betweenAngles{ -20, -90, -120, true },
	betweenAngles{ -20,-120,-90 , false},
	betweenAngles{ 90, 0,-90, true},
	betweenAngles{ 90, 120,-90, true },
	betweenAngles{ 90, 25,-90, true },
	betweenAngles{ 90, -180,-90, true },
	betweenAngles{ -180, 90, 0, true},
	betweenAngles{ -180, -90, 0, true },
	betweenAngles{ 179, 90, 1, true },
	betweenAngles{ 120, 0, -120, false }

));


INSTANTIATE_TEST_CASE_P(Bound, BoundTo180Test,
::testing::Values(
	boundAngles{ 360, 0 },
	boundAngles{ 270, -90 },
	boundAngles{ -450, -90 },
	boundAngles{ 180, -180 },
	boundAngles{ 0,0 },
	boundAngles{ 90, 90 },
	boundAngles{-180, -180}
));