#include <iostream>
/*
����Լ� : �Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ��� ���Ѵ�.
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

int main()
{
	int Number = 1;

	for (int i = 1; i <= 5; ++i)
	{
		Number *= i;
	}
	std::cout << Number << std::endl;

	Number = Factorial(5);

	std::cout << Number << std::endl;
	return 0;
}