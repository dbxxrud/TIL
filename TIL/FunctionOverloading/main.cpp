#include <iostream>

/*
�Լ� �����ε� : ���� �̸��� �Լ��� �پ��� ���·� ������� �� �ִ� ����̴�.
�Լ��� �����ε��� �����Ǳ� ���ؼ��� ������ ������ �ٸ��ų� ������ Ÿ���� �޶�� �����ε��� �����ȴ�.
����Ÿ���� �Լ��� �����ε��� ���谡 ����.

�Խ��� ����Ʈ ���� : �Լ��� ���ڿ� �⺻���� �������ִ� ����̴�.
�⺻���� ������ ���ڴ� �Լ��� ȣ���Ҷ� ���� �ȳ־��� ��� �⺻������
������ �ǰ� ���� �־��ָ� �־��� ������ �����̵ȴ�.

��, �Լ��� ����Ʈ ���ڸ� �����Ҷ� �׻� ���� �����ʿ� �ִ� ���ں���
���ʷ� �������� ���鼭 ���ڸ� �����ؾ� �Ѵ�.
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