﻿// ClassSize.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 바이트 패딩
class Test0
{
    // 1. 내부에서 가장큰 바이트 자료형을 찾는다.
    // 2. 그리고 순서대로 읽으면서
    // 3. 자료형이 하나있을때 무조건 가장 큰 자료형의 바이트로 할당한다.
    // 4. 그리고 후속 자료형과 합쳐서 그 가장 큰 자료형의 크기를 넘기지 않으면
    //    하나로 합친다.
    // 5. 계속 반복하면서 읽는다.

    char Value0; // 8
    __int64 Value2;  // 8
    char Value1; // 8

    void TTT()
    {

    }
};

class Test2
{
    char Test;

    virtual void ttt()
    {

    }
};
int main()
{
    std::cout << "Hello World!\n";
    std::cout << sizeof(Test0) << std::endl;
    // 결과는 1 바이트가 나온다.
    // 0바이트로 100개 짜리 배열을 만들어도 0바이트다.
    // 포인터의 플러스 연산 또한 주소값의 이동이다.
    // 그래서 더하기 100, 200이든 문법의 모순이 있기 때문에
    // 멤버 변수가 없는 클래스가 있어도 바이트는 1이여야 한다.
    // 함수가 있다고 크기가 바뀌지 않는다.
}

