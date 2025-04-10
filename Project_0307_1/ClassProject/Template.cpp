#include <iostream>

template<typename T>
T Min(T a, T b) {
    return (a < b) ? a : b;
}

template<typename T>
T Max(T a, T b) {
    return (a > b) ? a : b;
}

//int main()
//{
//    float a = 1.5f, b = 2.5f;
//
//    a = Min<float>(a, b); // 명시적 타입 지정
//    b = Max(a, b); // 컴파일러 추론
//}
