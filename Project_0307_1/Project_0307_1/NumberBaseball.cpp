#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#pragma warning(disable:4996)
using namespace std;

// ������ �� 3�� ��ȯ(�ߺ�X)
void RandomIntCreating(int &n1, int &n2, int &n3) {
	srand(static_cast<unsigned int>(time(NULL)));
	while (true) {
		n1 = rand() % 10;
		n2 = rand() % 10;
		n3 = rand() % 10;

		if (n1 != n2 && n1 !=n3 && n2!=n3)
			break;
	}
}

int main(){
	int result[3];			// ����
	int playerResult[3];	// �Է°�

	int ball = 0;			// ���� ��
	int strike = 0;			// �ڸ� ��, ���� ��
	int out = 0;			// �ڸ� X, ���� x

	RandomIntCreating(result[0], result[1], result[2]);
	printf("�̸����� ���䤾 %d %d %d \n", result[0], result[1], result[2]);

	printf("�߱� ������ �����մϴ�! 3���� ���ڸ� �����ּ���. (0~9)\n");

	int i = 5;
	for (i; i > -1; i--) {
		// input
		printf("���ڸ� �Է����ּ���(���� ��ȸ %d��) : ", i);
		scanf_s("%d%d%d", &playerResult[0], &playerResult[1], &playerResult[2]);

		// cheak - strike, out
		for (int k = 0; k < 3; k++) {
			if (result[k] == playerResult[k]) { strike++; }
			else {
				int j = 0;
				for (j = 0; j < 3; j++) {
					if (result[k] == playerResult[j]) break;
				}
				if (j == 3) { out++; }
			}
		}

		// cheak - ball
		for (int k = 0; k < 3; k++) {
			for (int j = 0; j < 3; j++) {
				if (result[k] == playerResult[j]) { ball++; }
			}
		}

		// ���� output
		if (strike == 3) break;

		// ���� output
		printf("Ball :%d   Strike : %d   Out : %d\n", ball, strike, out);

		// �ʱ�ȭ
		ball = 0;
		strike = 0;
		out = 0;
	}

	// ���� or ���� �޽���
	if (i == -1) {
		printf("����.... ������... %d %d %d", result[0], result[1], result[2]);
	}
	else { printf("�����Դϴ�! �����մϴ�. "); }
}