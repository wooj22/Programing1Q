#include <iostream>
#include <windows.h>

// ������ Ÿ�̸�
// Windows���� �ý��� ��Ƽ ���� ����� �ð��� ��Ÿ���� ������ 1�� ������
// ������ ���̸� ����Ϸ��� double, ������ ���� ���� ������ ��� float�� ��´�. (�� 100ns���� ���� X)

//int main() {
//    LARGE_INTEGER freq, start, end;
//    QueryPerformanceFrequency(&freq); // QPC ���ļ�(�ʴ� Tick ��) ��������
//    QueryPerformanceCounter(&start);  // ���� �ð� ���� (tickCount get)
//
//    // ������ �ݺ���
//    volatile int sum = 0; // ����ȭ ������ volatile : �����Ϸ��� �� ������ ����ȭ ���� �ʵ��� ������
//    for (int i = 0; i < 100000000; ++i) {
//        sum += i;
//    }
//
//    QueryPerformanceCounter(&end);    // ���� �ð� ���� (tickCount get)
//
//    // ��� �ð� ���
//    double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / freq.QuadPart;
//    std::cout << "�ݺ��� ���� �ð�: " << elapsedTime << " ��" << std::endl;
//
//    return 0;
//}
