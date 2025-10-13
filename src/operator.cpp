#include <iostream>
#include <ostream>
#include <string>

static int s_Level = 1;
static int s_Speed = 2;

struct Vector2
{
    float x, y;

    Vector2(float x, float y) // : x(x), y(y)
    {
        this->x = x; // this 是当前类的指针
        this->y = y;
    }

    Vector2 Add(const Vector2 &other) const
    {
        return Vector2(x + other.x, y + other.y);
        // return *this + other;
    }

    Vector2 operator+(const Vector2 &other) const
    {
        return Add(other);
    }

    Vector2 Multiply(const Vector2 &other) const
    {
        return Vector2(x * other.x, y * other.y);
    }

    Vector2 operator*(const Vector2 &other) const
    {
        return Multiply(other);
    }
};

std::ostream &operator<<(std::ostream &stream, const Vector2 &other)
{
    stream << other.x << "," << other.y;
    return stream;
}

int main()
{
    // if (s_Level > 5)
    //     s_Speed = 10;
    // else
    //     s_Speed = 5;

    // // 上下两个同样的意思
    // s_Speed = s_Level > 5 ? 10 : 5;

    // std::string rank = s_Level > 10 ? "Master" : "Beginner";
    // // 三元运算符

    // std::cout << rank << std::endl;

    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.1f, 1.1f);

    // Vector2 result = position.Add(speed.Multiply(powerup));
    Vector2 result2 = position + speed * powerup;

    std::cout << result2 << std::endl;
}