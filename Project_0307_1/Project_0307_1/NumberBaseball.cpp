#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#pragma warning(disable:4996)
using namespace std;

// 랜덤한 값 3개 반환(중복X)
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
	int result[3];			// 정답
	int playerResult[3];	// 입력값

	int ball = 0;			// 숫자 ㅇ
	int strike = 0;			// 자리 ㅇ, 숫자 ㅇ
	int out = 0;			// 자리 X, 숫자 x

	RandomIntCreating(result[0], result[1], result[2]);
	printf("미리보는 정답ㅎ %d %d %d \n", result[0], result[1], result[2]);

	printf("야구 게임을 시작합니다! 3개의 숫자를 맞춰주세요. (0~9)\n");

	int i = 5;
	for (i; i > -1; i--) {
		// input
		printf("숫자를 입력해주세요(남은 기회 %d번) : ", i);
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

		// 성공 output
		if (strike == 3) break;

		// 실패 output
		printf("Ball :%d   Strike : %d   Out : %d\n", ball, strike, out);

		// 초기화
		ball = 0;
		strike = 0;
		out = 0;
	}

	// 축하 or 실패 메시지
	if (i == -1) {
		printf("실패.... 정답은... %d %d %d", result[0], result[1], result[2]);
	}
	else { printf("정답입니다! 축하합니다. "); }
}