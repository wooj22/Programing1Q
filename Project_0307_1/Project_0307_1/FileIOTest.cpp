#include <iostream>
#include <windows.h>
using namespace std;

// ���� ����� ���丮 Ȯ��
// ���� ���μ����� ���� ��ο� �۾� ���丮�� ��δ� ����(Ž���� ����)�� ������ ���� ����� ���� �ٸ� �� ����
// ex) ���־� ��Ʃ������� �ҽ��ڵ带 �����ϴ� ȯ��. Exe��� ��ġ�� �۾� ���丮�� �ٸ�
// ex) ��� ������Ʈ���� Cmd���� ���������� ��α��� �������� �ʰ� ��α��� �����Ͽ� exe�� �����ϴ°��
// ex) �ٷΰ��⸦ ����� �۾� ���丮�� ���� �����ϴ� ���
// ���ҽ� ������ �����Ҷ� ������Ʈ �ٱ��� ���ҽ� ������ ���� ���� �ش� ���丮�� �����ϵ��� ��
void DirectoryCheak() {
	char szBuffer1[MAX_PATH] = { 0, };
	char szBuffer2[MAX_PATH] = { 0, };
	GetModuleFileNameA(NULL, szBuffer1, MAX_PATH);
	GetCurrentDirectoryA(MAX_PATH, szBuffer2);

	cout << "GetModuleFileNameA : " << szBuffer1 << '\n' << "GetCurrentDirectoryA : " << szBuffer2;
}

/*
// ���� ����� ������ (���Ͼ����ϱ� ���� ����)
int FileControll_W() {
	FILE* fp = fopen("example.txt", "w");
	if (fp == NULL) return;

	fprintf(fp, "�̸� : ȫ�浿, ���� : %d\n", 95);
	fputs("hello!", fp);
	fputs("A", fp);

	fclose(fp);
}

// ���� ����� �б��� (���Ͼ����ϱ� ���� ����)
int FileControll_W() {
	FILE* fp = fopen("example.txt", "r");
	if (fp == NULL) return;

	char name[50];
	int score;

	fscanf(fp, "�̸�: %s, ����: %d\n", name, &score);	// ��Ȯ�ϰ� ��ġ�ؾ���
	printf("���� �� -��: %s, ����: %d\n", name, &score);

	char buffer[100];
	fgets(buffer, sizeof(buffer), fp);
	printf("���� ��: %s", buffer);

	char ch = fgetc(fp);
	printf("���� ���� : %c\n", ch);

	fclose(fp);
}


int main() {
	//DirectoryCheak();
	return 0;
}
*/
