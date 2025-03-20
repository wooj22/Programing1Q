#include <iostream>
#include <windows.h>

// 고정밀 타이머
// Windows에서 시스템 부티 이후 경과한 시간을 나타내는 값으로 1씩 누적됨
// 정밀한 차이를 계산하려면 double, 하지만 보통 게임 루프의 경우 float에 담는다. (약 100ns부터 정밀 X)

//int main() {
//    LARGE_INTEGER freq, start, end;
//    QueryPerformanceFrequency(&freq); // QPC 주파수(초당 Tick 수) 가져오기
//    QueryPerformanceCounter(&start);  // 시작 시간 측정 (tickCount get)
//
//    // 측정할 반복문
//    volatile int sum = 0; // 최적화 방지용 volatile : 컴파일러가 이 변수를 최적화 하지 않도록 강제함
//    for (int i = 0; i < 100000000; ++i) {
//        sum += i;
//    }
//
//    QueryPerformanceCounter(&end);    // 종료 시간 측정 (tickCount get)
//
//    // 경과 시간 계산
//    double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / freq.QuadPart;
//    std::cout << "반복문 실행 시간: " << elapsedTime << " 초" << std::endl;
//
//    return 0;
//}
