#include <iostream>
#include <windows.h>

int main() {
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq); // QPC 주파수(초당 Tick 수) 가져오기

    QueryPerformanceCounter(&start); // 시작 시간 측정 (tickCount get)

    // 측정할 반복문
    volatile int sum = 0; // 최적화 방지용 volatile
    for (int i = 0; i < 100000000; ++i) {
        sum += i;
    }

    QueryPerformanceCounter(&end); // 종료 시간 측정 (tickCount get)

    // 경과 시간 계산
    double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / freq.QuadPart;

    std::cout << "반복문 실행 시간: " << elapsedTime << " 초" << std::endl;

    return 0;
}
