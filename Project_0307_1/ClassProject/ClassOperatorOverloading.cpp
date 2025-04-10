
// 방법1. 멤버 함수로 연산자 오버로딩
class Vector2 {
public:
    float x, y;
    Vector2(int x = 0, int y = 0) : x(x), y(y) {};
    Vector2 operator+(const Vector2& rhs) const {
        Vector2 result;
        result.x = x + rhs.x;
        result.y = y + rhs.y;
        return result;
    }
};

//int main() {
//    Vector2 a(1, 1);
//    Vector2 b(2,2);
//    Vector2 c1 = a + b; // Vector c = operator+(a, b);
//}


// 방법2. 전역 함수로 연산자 오버로딩
//Vector2 operator+(const Vector2& lhs, const Vector2& rhs) {
//    return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
//}

//int main() {
//    Vector2 a(1, 1);
//    Vector2 b(2, 2);
//    Vector2 c2 = a + b; // Vector c = a.operator+(b);
//}