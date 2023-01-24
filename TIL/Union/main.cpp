#include <iostream>

union UTest
{
	// 이 안에서 이름이 없는 class나 struct를 사용하면
	// 메모리 구조를 여기만 이렇게 써줘가 된다.
	// 메모리 구조가 
	int X;
	int Y;
	char Color[4];
};

// 유니온의 메모리 배치는 X랑 Y를 같은 곳에 둔다
// X 
// Y
// Color <- 이름만 다른 Color도 공유하기 시작함
// [][][][] 메모리 영역은 int를 하나 두고 이름을 두 개 붙인다. 레퍼런스에 가깝다. 서로가 서로의 레퍼런스다 
// 그러니까 X와 Y는 메모리 영역을 공유함
// 즉, Y를 수정해도 X가 수정됨
// 그냥 이런 문법이란다

class MyClass
{
	int Att;
	int Hp;
};
// 어떤 클래스를 만들었다고 치면 메모리 구조는 아래와 같이 잡힌다
// Att		HP
// [][][][]	[][][][]
// 클래스가 만들어지는 메모리 구조

int main()
{
	UTest UT = UTest();

	UT.X = 10; 
	UT.Y = 20;
	// 여기까지 보면 평범한 구조체 같음

	return 0;
}