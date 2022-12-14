#include <iostream>
/*
오늘의 공부내용 : 메모리 구조 파악과 지역변수, 전역변수, 정적변수 공부하기

C++에서 사용하는 메모리 영역
스택영역, 데이터영역, 힙영역, 코드영역

스택영역 : 지역변수들이 할당되는 메모리 영역이다.
데이터영역 : 전역변수와 정적변수가 할당되는 메모리 영역이다.
코드영역 : 실행파일이 가지고 있는 코드가 저장될 영역이다.
힙영역 : 동적할당된 메모리가 할당되는 영역이다.

지역변수 : 특정 코드블록({}) 안에 소속된 변수이다.
함수의 인자도 지역변수이다. 즉, 이 함수 내에서만 사용이 가능한 변수로 취급이 된다.

지역변수는 특정 함수가 호출이 될때 그 함수 안에서 사용하는 지역변수들이 메모리에
공간이 할당된다. 그 후 그 함수가 호출이 종료가 되면 메모리에서 해제가 된다.

전역변수 : 코드블록에 소속이 안된 변수를 말한다.
전역변수는 이 변수를 선언한 아래에 있는 모든 코드에서 사용할 수 있다.
전역변수는 프로그램이 시작될때 메모리에 할당이 되고 프로그램이 종료될때 메모리에서 해제된다.

정적변수 : static 키워드를 붙여서 지역변수를 정적변수로 만들 수 있다.
정적변수는 이 함수가 호출될때 처음 딱 1번만 값이 초기화 되고 그 후에 이 함수가
종료되도 메모리가 계속 유지된다.
프로그램 종료시에 메모리가 제거된다.
*/

int g_Number = 100; // 전역변수

// 결과값을 return 해주는 함수 형태를 call by value 라고 한다.
int Sum(int Number1, int Number2)
{
	g_Number = 500;
	
	static int Number3 = 100;
	std::cout << Number3 << std::endl;
	++Number3;

	return Number1 + Number2;
}

// 결과값을 레퍼런스를 이용해서 전달해주는 형태를
// call by reference 라고 한다.
void Damage(int& HP, int Attack)
{
	HP -= Attack;
}

// 결과값을 주소를 이용해서 접근하여 전달해주는 형태를
// call by address 라고 한다.
void DamagePointer(int* pHP, int Attack)
{
	*pHP -= Attack;
}

int main()
{
	int Number1 = 100, Number2 = 200;

	std::cout << Sum(Number1, Number2) << std::endl;
	std::cout << g_Number << std::endl;

	return 0;

}