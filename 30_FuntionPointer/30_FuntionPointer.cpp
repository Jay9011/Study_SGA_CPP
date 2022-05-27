#include <iostream>

using namespace std;

/*
*   함수 포인터 (Function Pointer)
*   : 함수의 주소값을 갖는 변수
*   
*   [ 형식 ]
*   선언 - 반환형 (*변수명)(매개변수) = 함수이름;
*   호출 - 변수이름();
*
*/

int Add(int a, int b)
{
    cout << (a + b) << endl;
    return a + b;
}

class Game
{
public:
    void Attack()
    {
        cout << "Attack!" << endl;
    }

    void Defense()
    {
        cout << "Defense!" << endl;
    }

private:

};

namespace Anothor
{
    void Another()
    {
        cout << "Another..." << endl;
    }
}

int main()
{
    /*
    *   같은 namespace 내 함수 포인터
    */
    void (*FunctionPtr)();          // FunctionPtr 라는 함수 포인터 선언 (void 반환형의 매개변수가 없는 함수 포인터)
    int  (*FunctionPtr2)(int, int); // intDelegate 라는 함수 포인터 선언 (int 반환형의 int, int 매개변수의 함수 포인터)

    FunctionPtr2 = Add;         // 지역변수 내에서는 &를 생략할 수 있다. (포인터에서는 주소가 저장된다.)
    FunctionPtr2 = &Add;        // 정식 형식
    FunctionPtr2(10, 20);

    /*
    *   다른 namespace 의 함수 포인터
    */
    void (*AnPtr)();
    AnPtr = Anothor::Another;
    AnPtr();

    /*
    *   class 멤버함수에 대한 함수 포인터
    */
    Game game;

    void (Game:: * GameFunction)();

    GameFunction = &Game::Attack;
    (game.*GameFunction)();

    GameFunction = &Game::Defense;
    (game.*GameFunction)();
}