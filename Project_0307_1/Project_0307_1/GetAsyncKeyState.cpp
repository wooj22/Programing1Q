#include <stdio.h>
#include <windows.h>

// GetAsyncKeyState()
// WindowsAPI�μ� ����Ű ������ �ǽð� Ű �Է� Ȯ���� �����ϴ�.
// �޼���ť�� �������� �ܵ����� ����� ���� 0x8000 ��Ʈ��  Ȱ���Ѵ�.
// ó�� ���� ������ Ȯ���ϰ� �������� ���� ���¸� �����ؼ� (������ ����)&&!(������ ����)�� üũ�ؾ���

int main() {
    SHORT prevState = 0;  // ���� Ű ���� ����
    printf("�����̽��� Ű �Է� ���� (ESC�� ����)\n");

    while (1) {
        SHORT state = GetAsyncKeyState(VK_SPACE); // �����̽��� ���� ��������

        if (state & 0x8000) {
            printf("�����̽��� �������� (KeyPressed) \n");
        }

        // Key Down Event (�������� �� �����ְ�, ���� ����)
        if ((state & 0x8000) && !(prevState & 0x8000)) {

            printf("�����̽��� ���� ���� (Key Down) \n");
        }

        // Key Up Event (�������� ���� �־���, ���� �� ����)
        if (!(state & 0x8000) && (prevState & 0x8000)) {
            printf("�����̽��� �� (Key Up)\n");
        }

        // ESC Ű �Է� �� ����
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            printf("ESC Ű �Է�! ���α׷� ����\n");
            break;
        }
        prevState = state; // ���� Ű ���� ����        
    }
    return 0;
}

