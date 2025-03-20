#include <iostream>
#include <windows.h>

int main() {
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq); // QPC ���ļ�(�ʴ� Tick ��) ��������

    QueryPerformanceCounter(&start); // ���� �ð� ���� (tickCount get)

    // ������ �ݺ���
    volatile int sum = 0; // ����ȭ ������ volatile
    for (int i = 0; i < 100000000; ++i) {
        sum += i;
    }

    QueryPerformanceCounter(&end); // ���� �ð� ���� (tickCount get)

    // ��� �ð� ���
    double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / freq.QuadPart;

    std::cout << "�ݺ��� ���� �ð�: " << elapsedTime << " ��" << std::endl;

    return 0;
}
