#include <iostream>
#include <functional>

using namespace std;

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
};

class Player
{
public:
    void Play()
    {
        cout << "Play!" << endl;
    }

    int Add(int a, int b)
    {
        cout << (a + b) << endl;
        return a + b;
    }
};

int main()
{
    Game game;
    Player player;

    function<void()> Function;
    Function = bind(&Game::Attack, game);
    Function();

    Function = bind(&Player::Play, player);
    Function();

    
    function<int(int, int)> AddFunction;
    AddFunction = bind(&Player::Add, player, 5, placeholders::_2);  // placeholders�� ����ؼ� �ش� ��ġ�� ����� �� �ִ� �Ű��������� �˷���� �Ѵ�.
    AddFunction(10, 20);


    return 0;
}