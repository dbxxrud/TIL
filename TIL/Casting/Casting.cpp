#include <iostream>

class FightUnit
{
protected:
	int Hp = 100;
	int Att = 50;

public:
	void Fight(FightUnit* _Fight)
	{
		// �ο��
		int a = 0;
	}

	FightUnit()
	{
		std::cout << "����Ʈ ����Ʈ ������" << std::endl;
	}

	FightUnit(int _Att, int _Hp) : Att(_Att), Hp(_Hp)
	{
		std::cout << "����Ʈ ����Ʈ ������" << std::endl;
	}

	~FightUnit()
	{
		std::cout << "����Ʈ ����Ʈ �Ҹ���" << std::endl;
	}
};

class Player : public FightUnit
{
public:
	int Lv;
	int Equip;
	// �θ� ��ӹ��� Ŭ������ 
	// �θ��� �����ڰ� �Ʒ��� ���� ������� ������ ���� ȣ��˴ϴ�.
	Player() : FightUnit() // ��������� ǥ��
	{
		Hp = 20; // �θ𿡼� ���� ��������� �ڽĿ��� ����� �� �ִ�.
		std::cout << "Player ������" << std::endl;
	}
	~Player()
	{
		std::cout << "Player �Ҹ���" << std::endl;
	}

};

class Monster : public FightUnit
{
public: 
	int Fury;
public:
	Monster()
	{
		std::cout << "Monster ������" << std::endl;
	}
	~Monster()
	{
		std::cout << "Monster �Ҹ���" << std::endl;
	}
};

int main()
{
	{
		Player NewPlayer = Player();
		Monster NewMonster;

		// �ڽ��� �ڷ����� ������ ���� �θ��� �������� �� �� �ִ�.
		// ������ Ŭ������ �θ��� ����� �� �����ϰ� ���� ����� ���� ������
		// �ڽ�Ŭ������ �θ����� �� �� �ְ� ������ȭ �ǱⰡ ����.
		// ��ĳ�����̴�.
		// Player�� Monster�� FightUnit�� �´�
		NewPlayer.Fight(&NewMonster);
	}

	{
		Player NewPlayer = Player();
		Monster NewMonster;
		
		FightUnit* FightUnitPtr = &NewPlayer; // �̰� ���� �ȵ�

		// �ٿ�ĳ������ �ƿ� ���� ���� ���� ����.
		// �׷��� ����� �Ǽ��ϸ� �ȵ˴ϴ�.
		Player* playerPtr = (Player*)FightUnitPtr;

		// ������ġ�� �ִµ� �� ������ġ�� ���� ����Ҽ��� ����.
	}
	

	return 0;
}