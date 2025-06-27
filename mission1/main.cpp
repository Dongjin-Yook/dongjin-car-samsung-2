#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define CLEAR_SCREEN "\033[H\033[2J"
#define SELECT_DELAY 800
#define TEST_DELAY 2000

bool printCarType(void);
bool printEngine(void);
bool printSystem(void);
bool printSteeringSystem(void);
bool printRunTest(void);
void selectCarType(int num);
void selectEngine(int num);
void selectbrakeSystem(int num);
void selectSteeringSystem(int num);
void runProducedCar();
void testProducedCar();
void customized_delay(int ms);
bool printManufacture(int step);
int selectManufacture(int step, int num);

enum QuestionType
{
    CarType_Q,
    Engine_Q,
    brakeSystem_Q,
    SteeringSystem_Q,
    Run_Test,
    END_QType
};

enum CarType
{
    SEDAN = 1,
    SUV,
    TRUCK,
    END_CType
};

enum Engine
{
    GM = 1,
    TOYOTA,
    WIA,
    END_Engine
};

enum brakeSystem
{
    MANDO = 1,
    CONTINENTAL,
    BOSCH_B,
    END_breakSystem
};

enum SteeringSystem
{
    BOSCH_S = 1,
    MOBIS,
    END_SteeringSystem
};

int manufacture[END_QType];


int main()
{
    char buf[100];
    int step = CarType_Q;

    while (1)
    {
        // select manafacture
        printManufacture(step);

        printf("INPUT > ");
        fgets(buf, sizeof(buf), stdin);

        // 엔터 개행문자 제거
        char* context = nullptr;
        strtok_s(buf, "\r", &context);
        strtok_s(buf, "\n", &context);

        if (!strcmp(buf, "exit"))
        {
            printf("바이바이\n");
            break;
        }

        // 숫자로 된 대답인지 확인
        char* checkNumber;
        int num = strtol(buf, &checkNumber, 10); // 문자열을 10진수로 변환

        // 입력받은 문자가 숫자가 아니라면
        if (*checkNumber != '\0')
        {
            printf("ERROR :: 숫자만 입력 가능\n");
            customized_delay(SELECT_DELAY);
            continue;
        }

        if (num == 0)
        {
            if (step == Run_Test)
                step = CarType_Q;
            else if (step >= 1)
                step -= 1;
            continue;
        }

        step = selectManufacture(step, num);
    }
}

bool printCarType(void)
{
    printf(CLEAR_SCREEN);
    printf("        ______________\n");
    printf("       /|            | \n");
    printf("  ____/_|_____________|____\n");
    printf(" |                      O  |\n");
    printf(" '-(@)----------------(@)--'\n");
    printf("===============================\n");
    printf("어떤 차량 타입을 선택할까요?\n");
    printf("1. Sedan\n");
    printf("2. SUV\n");
    printf("3. Truck\n");

    return true;
}

bool printEngine(void)
{
    printf(CLEAR_SCREEN);
    printf("어떤 엔진을 탑재할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. GM\n");
    printf("2. TOYOTA\n");
    printf("3. WIA\n");
    printf("4. 고장난 엔진\n");

    return true;
}

bool printSystem(void)
{
    printf(CLEAR_SCREEN);
    printf("어떤 제동장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. MANDO\n");
    printf("2. CONTINENTAL\n");
    printf("3. BOSCH\n");

    return true;
}

bool printSteeringSystem(void)
{
    printf(CLEAR_SCREEN);
    printf("어떤 조향장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. BOSCH\n");
    printf("2. MOBIS\n");

    return true;
}

bool printRunTest(void)
{
    printf(CLEAR_SCREEN);
    printf("멋진 차량이 완성되었습니다.\n");
    printf("어떤 동작을 할까요?\n");
    printf("0. 처음 화면으로 돌아가기\n");
    printf("1. RUN\n");
    printf("2. Test\n");

    return true;
}

void selectCarType(int num)
{
    manufacture[CarType_Q] = num;
    if (num == SEDAN)
        printf("차량 타입으로 Sedan을 선택하셨습니다.\n");
    if (num == SUV)
        printf("차량 타입으로 SUV을 선택하셨습니다.\n");
    if (num == TRUCK)
        printf("차량 타입으로 Truck을 선택하셨습니다.\n");
}

void selectEngine(int num)
{
    manufacture[Engine_Q] = num;
    if (num == GM)
        printf("GM 엔진을 선택하셨습니다.\n");
    if (num == TOYOTA)
        printf("TOYOTA 엔진을 선택하셨습니다.\n");
    if (num == WIA)
        printf("WIA 엔진을 선택하셨습니다.\n");
}

void selectbrakeSystem(int num)
{
    manufacture[brakeSystem_Q] = num;
    if (num == MANDO)
        printf("MANDO 제동장치를 선택하셨습니다.\n");
    if (num == CONTINENTAL)
        printf("CONTINENTAL 제동장치를 선택하셨습니다.\n");
    if (num == BOSCH_B)
        printf("BOSCH 제동장치를 선택하셨습니다.\n");
}

void selectSteeringSystem(int num)
{
    manufacture[SteeringSystem_Q] = num;
    if (num == BOSCH_S)
        printf("BOSCH 조향장치를 선택하셨습니다.\n");
    if (num == MOBIS)
        printf("MOBIS 조향장치를 선택하셨습니다.\n");
}

int isValidCheck()
{
    int car_ret = true;
    int break_ret = true;

    switch (manufacture[CarType_Q]) {
    case SEDAN:
        if (manufacture[brakeSystem_Q] == CONTINENTAL)
            car_ret = false;
        break;
    case SUV:
        if (manufacture[Engine_Q] == TOYOTA)
            car_ret = false;
        break;
    case TRUCK:
        if (manufacture[Engine_Q] == WIA || manufacture[brakeSystem_Q] == MANDO)
            car_ret = false;
        break;
    }

    switch (manufacture[brakeSystem_Q]) {
    case BOSCH_B:
        if (manufacture[SteeringSystem_Q] != BOSCH_S)
            break_ret = false;
        break;
    }

    if (car_ret == false || break_ret == false)
        return false;
    else
        return true;
}

void runProducedCar()
{
    if (isValidCheck() == false)
    {
        printf("자동차가 동작되지 않습니다\n");
    }
    else
    {
        if (manufacture[Engine_Q] == 4)
        {
            printf("엔진이 고장나있습니다.\n");
            printf("자동차가 움직이지 않습니다.\n");
        }
        else
        {
            if (manufacture[CarType_Q] == 1)
                printf("Car Type : Sedan\n");
            if (manufacture[CarType_Q] == 2)
                printf("Car Type : SUV\n");
            if (manufacture[CarType_Q] == 3)
                printf("Car Type : Truck\n");
            if (manufacture[Engine_Q] == 1)
                printf("Engine : GM\n");
            if (manufacture[Engine_Q] == 2)
                printf("Engine : TOYOTA\n");
            if (manufacture[Engine_Q] == 3)
                printf("Engine : WIA\n");
            if (manufacture[brakeSystem_Q] == 1)
                printf("Brake System : Mando");
            if (manufacture[brakeSystem_Q] == 2)
                printf("Brake System : Continental\n");
            if (manufacture[brakeSystem_Q] == 3)
                printf("Brake System : Bosch\n");
            if (manufacture[SteeringSystem_Q] == 1)
                printf("SteeringSystem : Bosch\n");
            if (manufacture[SteeringSystem_Q] == 2)
                printf("SteeringSystem : Mobis\n");

            printf("자동차가 동작됩니다.\n");
        }
    }
}

void testProducedCar()
{
    if (manufacture[CarType_Q] == SEDAN && manufacture[brakeSystem_Q] == CONTINENTAL)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Sedan에는 Continental제동장치 사용 불가\n");
    }
    else if (manufacture[CarType_Q] == SUV && manufacture[Engine_Q] == TOYOTA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("SUV에는 TOYOTA엔진 사용 불가\n");
    }
    else if (manufacture[CarType_Q] == TRUCK && manufacture[Engine_Q] == WIA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 WIA엔진 사용 불가\n");
    }
    else if (manufacture[CarType_Q] == TRUCK && manufacture[brakeSystem_Q] == MANDO)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 Mando제동장치 사용 불가\n");
    }
    else if (manufacture[brakeSystem_Q] == BOSCH_B && manufacture[SteeringSystem_Q] != BOSCH_S)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
    }
    else
    {
        printf("자동차 부품 조합 테스트 결과 : PASS\n");
    }
}

void customized_delay(int ms)
{
    volatile int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int t = 0; t < ms; t++)
            {
                sum++;
            }
        }
    }
}

bool printManufacture(int step)
{
    bool ret = true;

    switch (step) {
    case CarType_Q:
        printCarType();
        break;
    case Engine_Q:
        printEngine();
        break;
    case brakeSystem_Q:
        printSystem();
        break;
    case SteeringSystem_Q:
        printSteeringSystem();
        break;
    case Run_Test:
        printRunTest();
        break;
    default:
        printf("WRN :: Please check step. We can only support CarType, Engine, BreakSystem, SteeringSystem, Run\n");
        ret = false;
        break;
    }
    printf("===============================\n");
    return ret;
}

int selectManufacture(int step, int num)
{
    switch (step) {
    case CarType_Q:
        if (!(num >= SEDAN && num < END_CType)) {
            printf("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
            customized_delay(SELECT_DELAY);
            step = CarType_Q;
            break;
        }
        selectCarType(num);
        customized_delay(SELECT_DELAY);
        step = Engine_Q;
        break;
    case Engine_Q:
        if (!(num >= 0 && num <= END_Engine)) {
            printf("ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n");
            customized_delay(SELECT_DELAY);
            step = Engine_Q;
            break;
        }
        selectEngine(num);
        customized_delay(SELECT_DELAY);
        step = brakeSystem_Q;
        break;
    case brakeSystem_Q:
        if (!(num >= 0 && num < END_breakSystem)) {
            printf("ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n");
            customized_delay(SELECT_DELAY);
            step = brakeSystem_Q;
            break;
        }
        selectbrakeSystem(num);
        customized_delay(SELECT_DELAY);
        step = SteeringSystem_Q;
        break;
    case SteeringSystem_Q:
        if (!(num >= 0 && num < END_SteeringSystem)) {
            printf("ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n");
            customized_delay(SELECT_DELAY);
            step = SteeringSystem_Q;
            break;
        }
        selectSteeringSystem(num);
        customized_delay(SELECT_DELAY);
        step = Run_Test;
        break;
    case Run_Test:
        if (num == 1) {
            runProducedCar();
            customized_delay(TEST_DELAY);
        }
        else if (num == 2) {
            printf("Test...\n");
            customized_delay(TEST_DELAY);
            testProducedCar();
            customized_delay(TEST_DELAY);
        }
        else {
            printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
            customized_delay(SELECT_DELAY);
            step = Run_Test;
            break;
        }
        break;
    }

    return step;
}

#endif