#ifdef _DEBUG
#include "gmock/gmock.h"
#include "main.cpp"

TEST(Group, TC1) {
	Manufacture t_manufacture;
	int ret = t_manufacture.printManufacture(CarType_Q);

	EXPECT_EQ(true, ret);
}

TEST(Group, TC2) {
	Manufacture t_manufacture;
	int ret = t_manufacture.printManufacture(Engine_Q);

	EXPECT_EQ(true, ret);
}

TEST(Group, TC3) {
	Manufacture t_manufacture;
	int ret = t_manufacture.printManufacture(brakeSystem_Q);

	EXPECT_EQ(true, ret);
}

TEST(Group, TC4) {
	Manufacture t_manufacture;
	int ret = t_manufacture.printManufacture(SteeringSystem_Q);

	EXPECT_EQ(true, ret);
}

TEST(Group, TC5) {
	Manufacture t_manufacture;
	int ret = t_manufacture.printManufacture(Run_Test);

	EXPECT_EQ(true, ret);
}

TEST(Group, TC6) {
	Manufacture t_manufacture;
	int ret = t_manufacture.printManufacture(END_QType);

	EXPECT_EQ(false, ret);
}

TEST(Group, TC7) {
	Manufacture t_manufacture;
	int ret = t_manufacture.selectManufacture(CarType_Q, SEDAN);

	EXPECT_EQ(Engine_Q, ret);
}

TEST(Group, TC8) {
	Manufacture t_manufacture;
	int ret = t_manufacture.selectManufacture(CarType_Q, SUV);

	EXPECT_EQ(Engine_Q, ret);
}

TEST(Group, TC9) {
	Manufacture t_manufacture;
	int ret = t_manufacture.selectManufacture(CarType_Q, TRUCK);

	EXPECT_EQ(Engine_Q, ret);
}

TEST(Group, TC10) {
	Manufacture t_manufacture;
	int ret = t_manufacture.selectManufacture(CarType_Q, END_CType);

	EXPECT_EQ(CarType_Q, ret);
}

TEST(Group, TC11) {
	Manufacture t_manufacture;
	int ret = t_manufacture.selectManufacture(Engine_Q, TOYOTA);

	EXPECT_EQ(brakeSystem_Q, ret);
}

TEST(Group, TC12) {
	Manufacture t_manufacture;
	int ret = t_manufacture.selectManufacture(Engine_Q, GM);

	EXPECT_EQ(brakeSystem_Q, ret);
}

TEST(Group, TC13) {
	Manufacture t_manufacture;
	int ret = t_manufacture.selectManufacture(Engine_Q, WIA);

	EXPECT_EQ(brakeSystem_Q, ret);
}

TEST(Group, TC14) {
	Manufacture t_manufacture;
	int ret = t_manufacture.selectManufacture(Engine_Q, END_Engine+1);

	EXPECT_EQ(Engine_Q, ret);
}

TEST(Group, TC15) {
	Manufacture t_manufacture;
	int ret = t_manufacture.selectManufacture(brakeSystem_Q, MANDO);

	EXPECT_EQ(SteeringSystem_Q, ret);
}

TEST(Group, TC16) {
	Manufacture t_manufacture;
	int ret = t_manufacture.selectManufacture(brakeSystem_Q, CONTINENTAL);

	EXPECT_EQ(SteeringSystem_Q, ret);
}
TEST(Group, TC17) {
	Manufacture t_manufacture;
	int ret = t_manufacture.selectManufacture(brakeSystem_Q, BOSCH_B);

	EXPECT_EQ(SteeringSystem_Q, ret);
}

TEST(Group, TC18) {
	Manufacture t_manufacture;
	int ret = t_manufacture.selectManufacture(brakeSystem_Q, END_breakSystem);

	EXPECT_EQ(brakeSystem_Q, ret);
}

TEST(Group, TC19) {
	Manufacture t_manufacture;
	int ret = t_manufacture.selectManufacture(SteeringSystem_Q, BOSCH_S);

	EXPECT_EQ(Run_Test, ret);
}

TEST(Group, TC20) {
	Manufacture t_manufacture;
	int ret = t_manufacture.selectManufacture(SteeringSystem_Q, MOBIS);

	EXPECT_EQ(Run_Test, ret);
}

TEST(Group, TC21) {
	Manufacture t_manufacture;
	int ret = t_manufacture.selectManufacture(SteeringSystem_Q, END_SteeringSystem);

	EXPECT_EQ(SteeringSystem_Q, ret);
}

TEST(Group, TC22) {
	Manufacture t_manufacture;
	int ret = t_manufacture.selectManufacture(Run_Test, 1);

	EXPECT_EQ(Run_Test, ret);
}

TEST(Group, TC23) {
	Manufacture t_manufacture;
	int ret = t_manufacture.selectManufacture(Run_Test, 2);

	EXPECT_EQ(Run_Test, ret);
}

TEST(Group, TC24) {
	Manufacture t_manufacture;
	int ret = t_manufacture.selectManufacture(Run_Test, 3);

	EXPECT_EQ(Run_Test, ret);
}

TEST(Group, TC25) {
	Manufacture t_manufacture;
	int ret, i, j, k, t;

	for (i = 1; i < END_CType; i++) {
		for (j = 1; j < END_Engine; j++) {
			for (k = 1; k < END_breakSystem; k++) {
				for (t = 1; t < END_SteeringSystem; t++) {
					ret = t_manufacture.selectManufacture(CarType_Q, i);
					EXPECT_EQ(Engine_Q, ret);

					ret = t_manufacture.selectManufacture(Engine_Q, j);
					EXPECT_EQ(brakeSystem_Q, ret);

					ret = t_manufacture.selectManufacture(brakeSystem_Q, k);
					EXPECT_EQ(SteeringSystem_Q, ret);

					ret = t_manufacture.selectManufacture(SteeringSystem_Q, t);
					EXPECT_EQ(Run_Test, ret);

					ret = t_manufacture.selectManufacture(Run_Test, 1);
					ret = t_manufacture.selectManufacture(Run_Test, 2);

					EXPECT_EQ(Run_Test, ret);
				}
			}
		}
	}
}

TEST(Group, TC26) {
	Manufacture t_manufacture;
	int ret;

	ret = t_manufacture.selectManufacture(CarType_Q, SEDAN);
	EXPECT_EQ(Engine_Q, ret);

	ret = t_manufacture.selectManufacture(Engine_Q, END_Engine);
	EXPECT_EQ(brakeSystem_Q, ret);

	ret = t_manufacture.selectManufacture(brakeSystem_Q, MANDO);
	EXPECT_EQ(SteeringSystem_Q, ret);

	ret = t_manufacture.selectManufacture(SteeringSystem_Q, BOSCH_S);
	EXPECT_EQ(Run_Test, ret);

	ret = t_manufacture.selectManufacture(Run_Test, 1);
	ret = t_manufacture.selectManufacture(Run_Test, 2);

	EXPECT_EQ(Run_Test, ret);
}

TEST(Group, TC27) {
	Manufacture t_manufacture;
	int ret;

	ret = t_manufacture.selectManufacture(CarType_Q, SEDAN);
	EXPECT_EQ(Engine_Q, ret);

	ret = t_manufacture.selectManufacture(Engine_Q, GM);
	EXPECT_EQ(brakeSystem_Q, ret);

	ret = t_manufacture.selectManufacture(brakeSystem_Q, MANDO);
	EXPECT_EQ(SteeringSystem_Q, ret);

	ret = t_manufacture.selectManufacture(SteeringSystem_Q, BOSCH_S);
	EXPECT_EQ(Run_Test, ret);

	ret = t_manufacture.selectManufacture(Run_Test, 1);
	ret = t_manufacture.selectManufacture(Run_Test, 2);

	EXPECT_EQ(Run_Test, ret);
}

TEST(Group, TC28) {
	Manufacture t_manufacture;
	int ret;

	ret = t_manufacture.selectManufacture(CarType_Q, SEDAN);
	EXPECT_EQ(Engine_Q, ret);

	ret = t_manufacture.selectManufacture(Engine_Q, GM);
	EXPECT_EQ(brakeSystem_Q, ret);

	ret = t_manufacture.selectManufacture(brakeSystem_Q, MANDO);
	EXPECT_EQ(SteeringSystem_Q, ret);

	ret = t_manufacture.selectManufacture(SteeringSystem_Q, BOSCH_S);
	EXPECT_EQ(Run_Test, ret);

	ret = t_manufacture.selectManufacture(Run_Test, 1);
	ret = t_manufacture.selectManufacture(Run_Test, 2);
	ret = t_manufacture.selectManufacture(Run_Test, 3);

	EXPECT_EQ(Run_Test, ret);
}

int main()
{
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
#endif