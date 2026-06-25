#include <iostream>

using namespace std;

class Vector2D {
private:
    float x;
    float y;

public:
    Vector2D(float xVal = 0.0f, float yVal = 0.0f) : x(xVal), y(yVal) {}

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D& operator+=(const Vector2D& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    bool operator==(const Vector2D& other) const {
        return (x == other.x && y == other.y);
    }

    friend ostream& operator<<(ostream& os, const Vector2D& vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }
};

int main() {
    Vector2D v1(2.5f, 4.0f);
    Vector2D v2(1.5f, 3.0f);

    Vector2D v3 = v1 + v2;
    v1 += v2;

    cout << "v3: " << v3 << endl;
    cout << "v1: " << v1 << endl;
    cout << "Equal: " << (v1 == v3) << endl;

    return 0;
}
