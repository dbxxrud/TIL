#include <iostream>

class FightUnit
{
protected:
	int Hp = 100;
	int Att = 50;

public:
	void Fight(FightUnit* _Fight)
	{
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
	int Lv;
	int Equip;
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

int main()
{
	{
		Player NewPlayer = Player();
		Monster NewMonster;

		// 자식의 자료형은 언제나 쉽게 부모의 참조형이 될 수 있다.
		// 무조건 클래스는 부모의 기능을 다 구현하고 내가 만들어 지기 때문에
		// 자식클래스는 부모형이 될 수 있고 포인터화 되기가 슆다.
		// 업캐스팅이다.
		// Player와 Monster는 FightUnit가 맞다
		NewPlayer.Fight(&NewMonster);
	}

	{
		Player NewPlayer = Player();
		Monster NewMonster;
		
		FightUnit* FightUnitPtr = &NewPlayer; // 이거 쓰면 안돼

		// 다운캐스팅을 아예 하지 않을 수는 없다.
		// 그런데 절대로 실수하면 안됩니다.
		Player* playerPtr = (Player*)FightUnitPtr;

		// 안전장치가 있는데 그 안전장치를 쉽게 사용할수가 없다.
	}
	

	return 0;
}