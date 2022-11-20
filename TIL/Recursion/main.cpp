#include <iostream>
/*
재귀함수 : 함수가 자기 자신을 호출하는 함수를 말한다.
*/
//int Factorial(int Number)
//{
//	Factorial(Number); // 일종의 무한루프가 돌아가기 때문에 빠져나갈 수 없다.
//}
int Factorial(int Number)
{
	// 간단한 팩토리얼 함수 구현(재귀적)
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