// FunctionPointer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void PlayerAttack() 
{
    std::cout << "플레이어가 공격합니다" << std::endl;
}

void MenuOpen()
{
    std::cout << "메뉴를 오픈합니다." << std::endl;
}

class Image
{

};

class UIButton
{
public:
    Image ButtonImage;

    void(*FunctionPtr)() = nullptr;
    /*
     어떤 함수를 넣어주는지에 따라서 클래스는 딱 하나지만 함수의 요건만 맞춰주면 UIButton은
    */

public:
   //virtual void Click()
   // {
   //     // 플레이어가 버튼을 호출하면 이게 호출됨
   // }

    void Click()
    {
        if (nullptr == FunctionPtr)
            return;

        FunctionPtr();
    }
    

    void PlayerAttack()
    {

    }


};

class PlayerAttackButton : public UIButton
{
public:
    //void Click() override
    //{
    //    // 근데 이런 방식은 잘 쓰이지 않는다.
    //}
};

int main()
{
    std::cout << "Hello World!\n";

    UIButton PlayerAttackButton;
    UIButton MenuButton;


    PlayerAttackButton.FunctionPtr = PlayerAttack;
    MenuButton.FunctionPtr = MenuOpen;

    PlayerAttackButton.Click();
    MenuButton.Click();

    // 이런 구조로 가게 되면 클래스를 여러개 만들 필요가 없다.

    // 전역함수만 이 함수포인터로 가능하다.
    void(*Function)();
    int att; // int를 선언한거랑 같은 개념

    std::cout << sizeof(Function) << std::endl; // 8바이트



    //void(*FucntionPtr)() = nullptr;
    ////FucntionPtr이 함수포인터의 이름이 됩니다. 

    //FucntionPtr = PlayerAttack; // 함수의 위치를 받고 포인터를 함수로서 쓸 수 있다.
    //                            // 이름이 곧 주소값이 되서 들어간것임.

    //FucntionPtr();

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
