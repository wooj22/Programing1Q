#include <iostream>
#include <windows.h>
using namespace std;

// ���� ����� ���丮 Ȯ��
// ���� ���μ����� ���� ��ο� �۾� ���丮�� ��δ� ����(Ž���� ����)�� ������ ���� ����� ���� �ٸ� �� ����
// ex) ���־� ��Ʃ������� �ҽ��ڵ带 �����ϴ� ȯ��. Exe��� ��ġ�� �۾� ���丮�� �ٸ�
// ex) ��� ������Ʈ���� Cmd���� ���������� ��α��� �������� �ʰ� ��α��� �����Ͽ� exe�� �����ϴ°��
// ex) �ٷΰ��⸦ ����� �۾� ���丮�� ���� �����ϴ� ���
// ���ҽ� ������ �����Ҷ� ������Ʈ �ٱ��� ���ҽ� ������ ���� ���� �ش� ���丮�� �����ϵ��� ��

int main() {
	char szBuffer1[MAX_PATH] = { 0, };
	char szBuffer2[MAX_PATH] = { 0, };
	GetModuleFileNameA(NULL, szBuffer1, MAX_PATH);
	GetCurrentDirectoryA(MAX_PATH, szBuffer2);

	cout << "GetModuleFileNameA : " << szBuffer1 << '\n' << "GetCurrentDirectoryA : " << szBuffer2;

	return 0;
}