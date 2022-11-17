#include <iostream>

/*
함수 오버로딩 : 같은 이름의 함수를 다양한 형태로 만들어줄 수 있는 기능이다.
함수의 오버로딩이 성립되기 위해서는 인자의 개수가 다르거나 인자의 타입이 달라야 오버로딩이 성립된다.
리턴타입은 함수의 오버로딩과 관계가 없다.

함슈의 디폴트 인자 : 함수의 인자에 기본값을 설정해주는 기능이다.
기본값이 설정된 인자는 함수를 호출할때 값을 안넣어줄 경우 기본값으로
설정이 되고 값을 넣어주면 넣어준 값으로 설정이된다.

단, 함수의 디폴트 인자를 설정할때 항상 가장 오른쪽에 있는 인자부터
차례로 왼쪽으로 오면서 인자를 설정해야 한다.
*/

void OutPut(int Number1, int Number2 = 200)
{
	std::cout << "Number1: " << Number1 << std::endl;
	std::cout << "Number2: " << Number2 << std::endl;
}

int Sum(int Number1, int Number2)
{
	return Number1 + Number2;
}

float Sum(float Number1, float Number2)
{
	return Number1 + Number2;
}

int main()
{
	std::cout << Sum(10, 20) << std::endl;
	std::cout << Sum(50.f, 30.f) << std::endl;

	OutPut(100, 500);
	OutPut(100);

	return 0;
}