 #include <iostream>

class FightUnit
{
protected:
	int Hp = 100;
	int Att = 50;

public:
	virtual int GetAtt()
	{
		return Att;
	}
	virtual int GetHp()
	{
		return Att;
	}

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
		this;
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
	// 부모를 상속받은 클래스면 
	// 부모의 생성자가 아래와 같은 방식으로 무조건 먼저 호출됩니다.
	Player() : FightUnit(10, 200) // 명시적으로 표현
	{
		this;
		// Hp = 20; // 부모에서 먼저 만들어져야 자식에서 사용할 수 있다.
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

void Function0()
{

}

void Function1()
{

}

int main()
{
	Player NewPlayer = Player();
	// 클래스 하나마다 이렇게 들고 있고
	//void(*Functions[10])();

	// 0번째 주소값을 다시 내부에 들고 있다.
	// 자료형** Ptr = Functions[0]

	// 함수포인터도 배열이 될 수 있다.
	//Functions[0] = Function0;
	//Functions[1] = Function1;


	return 0;
}