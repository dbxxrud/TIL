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

class NPC : public FightUnit
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
	Player NewPlsyer0;
	Player NewPlsyer1;

	NPC NewNPC0;

	NewPlsyer0.Fight(&NewPlsyer1); // 이러면 PVP
	NewPlsyer0.Fight(&NewNPC0); // 이러면 PVP
	// 즉, FightUnit를 상속받은 애들은 Fight를 사용하면 싸우게 되는것.


	return 0;
}