#include <iostream>

// using namespace std;
#define LOG(x) std::cout << x << std::endl

class Player // struct 的属性默认是公有的
{            // 类实际上是一个新变量名
public:      // 默认类属性是私有的
    int x, y;
    int speed;

    void Move(int xa, int ya)
    {
        x += xa * speed;
        y += ya * speed;
    }
};

// void Move(Player &player, int xa, int ya)
// {
//     player.x += xa * player.speed;
//     player.y += ya * player.speed;
// }

int main()
{
    Player player;
    player.Move(1, -1);
}