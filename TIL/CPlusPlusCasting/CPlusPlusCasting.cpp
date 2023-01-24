// CPlusPlusCasting.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class FightUnit
{
protected:
	int Hp = 100;
	int Att = 50;
	virtual int GetAtt()
	{
		return Att;
	}
public:
	// 부모의 형태이면서
	// 특정 상황에서는 다양한 자식들의 형태로 동작해야하는 경우가 존재한다.virtual
	void Fight(FightUnit* _Fight)
	{
		if (this == _Fight)
		{
			return;
		}
		// 내부에서는 Att를 쉽게 쓸 수 있다. 
		// FightUnit 포인터는 두 개다 
		// 하나는 this
		this->Hp -= _Fight->GetAtt(); // this의 HP를 들어온 놈의 공격력으로 깎아라
		_Fight->Hp -= this->GetAtt();
		// 그래서 두 개의 FightUnit*가 서로 싸운다.

		// 싸운다
		int a = 0;
	}

	FightUnit()
	{
		std::cout << "파이트 유니트 생성자" << std::endl;
	}

	FightUnit(int _Att, int _Hp) : Att(_Att), Hp(_Hp)
	{
		std::cout << "파이트 유니트 생성자" << std::endl;
	}

	~FightUnit()
	{
		std::cout << "파이트 유니트 소멸자" << std::endl;
	}
};

class Player : public FightUnit
{
public:
	int Lv = 1;
	int Equip = 1;
	// 자식쪽에서 부모의 함수를 재정의 했다는 명시 
	int GetAtt() override
	{
		return Att + Lv + Equip;
	}
	// 부모를 상속받은 클래스면 
	// 부모의 생성자가 아래와 같은 방식으로 무조건 먼저 호출됩니다.
	Player() : FightUnit() // 명시적으로 표현
	{
		Hp = 20; // 부모에서 먼저 만들어져야 자식에서 사용할 수 있다.
		std::cout << "Player 생성자" << std::endl;
	}
	~Player()
	{
		std::cout << "Player 소멸자" << std::endl;
	}

};

class Monster : public FightUnit
{
public:
	int Fury;
public:
	Monster()
	{
		std::cout << "Monster 생성자" << std::endl;
	}
	~Monster()
	{
		std::cout << "Monster 소멸자" << std::endl;
	}
};


class NPC
{
public:
	NPC()
	{
		std::cout << "NPC 생성자" << std::endl;
	}
	~NPC()
	{
		std::cout << "NPC 소멸자" << std::endl;
	}
};

int main()
{
    int Value;

    int* Ptr4 = &Value;
    __int64* Ptr16 = (__int64*)Ptr4;
    // C 캐스팅이라고 한다.
    // C때 사용하던 캐스팅

    // C++에서는
    // 그걸 종류에 따라서 세분화한 C++ casting을 지원한다.

    {
        // 바이트차이가 나는 값과 값사이의 형변환은 static_cast<>
        int Value = 10;
        short Test = static_cast<short>(Value);
        short Test = (short)(Value); // 위에랑 똑같음 위에는 명시적인것
        // 컴파일러가 알아서 바꿔주는 거임 근데 정확히 명시안해주면 느림
    }

    {
        // 포인터형을 정수형으로 혹은 정수형을 포인터형으로 변경할 수 있는 캐스팅
        int Value = 0;
        int* Test0 = reinterpret_cast<int*>(Value);

        __int64 Address = reinterpret_cast<__int64>(Test0);
    }

    {
        // 상수화를 푼다
        int Value = 0;

        // 안쓸거다
        const int* Ptr = &Value;
        int* Test0 = const_cast<int*>(Ptr);
    }

    {
		Player* PlayerPtr = new Player();

		NPC* NPCptr = dynamic_cast<NPC*>(PlayerPtr);

		// 업캐스팅의 경우에는 다이나믹 캐스트를 안해도 된다.
		FightUnit* FightUnitPtr = dynamic_cast<FightUnit*>(PlayerPtr);

		// 다형클래스 -> virtual이 존재하는 클래스
		// virtual이 존재하는 클래스여야만 다이나믹 클래스의 대상이 될 수 있다.
		// FightUnit* FightUnitPtr = dynamic_cast<FightUnit*>(NPCptr);

		Monster* FightUnitToMonsterPtr = dynamic_cast<Monster*>(FightUnitPtr); // 비정상

		Player* FightUnitToPlayerPtr = dynamic_cast<Player*>(FightUnitPtr); // 정상

		if (nullptr == FightUnitToMonsterPtr)
		{

		}

    }
    



    std::cout << "Hello World!\n";
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
