#include <iostream>
/*
����Լ� : �Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ��� ���Ѵ�.

������� : ����Լ��� ������ ������ �غ��ϱ� ���� �뵵�� ����Ѵ�.
������͸� ����ȭ�ϱ� ���� ���°� �ְ�, �����Ϸ� ���� ������͸� ������ �� �ִ� �����Ϸ����� �Ѵ�.
���������� �����Ϸ����� ������͸� �������� ���ϰ� �Ϲ� ����Լ��� �νĵ� ���̴�.
������͸� �����ϴ� �����Ϸ��� ��� ������͸� �ݺ������� �ν��Ѵ�.
*/
//int Factorial(int Number)
//{
//	Factorial(Number); // ������ ���ѷ����� ���ư��� ������ �������� �� ����.
//}
int Factorial(int Number)
{
	// ������ ���丮�� �Լ� ����(�����)
	if (Number == 1)
	{
		return 1;
	}
	return Number * Factorial(Number - 1); 
}

// ����Լ��� �߰����� ������ ����.
int FactorialTail(int Number, int Result)
{
	if (Number == 1)
		return Result;

	return FactorialTail(Number - 1, Result * Number);
}

int FactorialTail(int Number)
{
	return FactorialTail(Number, 1);
}



int main()
{
	int Number = 1;

	for (int i = 1; i <= 5; ++i)
	{
		Number *= i;
	}
	std::cout << Number << std::endl;

	Number = FactorialTail(5); // 5���丮���ϱ� 

	std::cout << Number << std::endl;
	return 0;
}