#include <iostream>
/*
재귀함수 : 함수가 자기 자신을 호출하는 함수를 말한다.

꼬리재귀 : 재귀함수가 가지는 단점을 극복하기 위한 용도로 사용한다.
꼬리재귀를 최적화하기 위한 형태가 있고, 컴파일러 또한 꼬리재귀를 지원할 수 있는 컴파일러여야 한다.
낮은버젼의 컴파일러들은 꼬리재귀를 지원하지 못하고 일반 재귀함수로 인식될 뿐이다.
꼬리재귀를 지원하는 컴파일러의 경우 꼬리재귀를 반복문으로 인식한다.
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

// 재귀함수는 추가적인 연산이 없다.
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

	Number = FactorialTail(5); // 5팩토리얼구하기 

	std::cout << Number << std::endl;
	return 0;
}