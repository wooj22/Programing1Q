#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX_WORDS 10
#define MAX_LENGTH 15

char words[MAX_WORDS][MAX_LENGTH] = {
    "elephant\0",
    "computer\0",
    "tomorrow\0",
    "hospital\0",
    "football\0",
    "umbrella\0",
    "birthday\0",
    "mountain\0",
    "sandwich\0",
    "language\0"
};

int main() {
    const int MAX_ATTEMPTS = 10;           // 최대 시도 횟수
    int currentAttempts;                   // 현재 시도 횟수
    int wrong;                             // 현재 틀린 횟수
    bool isWrong;                         // 현재 틀림 여부      
    bool isAllCorrect;                     // 정답 여부
    char inputValue;                       // 사용자 입력값

    printf("/////////////////////////\n///// HANG MAN GAME /////\n/////////////////////////\n\n");

    for (int i = 0; i < MAX_WORDS; i++) {
        // 초기화
        char infoValues[MAX_LENGTH] = {};      // 현재 문자 정보 배열
        char inputWords[MAX_ATTEMPTS] = {};    // 입력한 알파벳 배열
        char* inputWordsP = inputWords;        // 입력한 알파벳 배열 포인터
        char* correctWordsP = words[i];        // 정답 문자열 배열 포인터

        currentAttempts = 0;
        wrong = 0;

        // 1. 현재 단어 자리수 초기화
        printf("\n\n<%d번째 문제..  기회 %d번!>\n\n", i + 1, MAX_ATTEMPTS);
        for (int j = 0; j < words[i][j] != '\0'; j++) {
            infoValues[j] = '-';
        }

        // 2. 게임 진행
        while (true) {
            // (1) 사용자 입력값 받기, 입력한 알파벳 저장
            printf("%s\n 영어 한자리 수 입력 (남은 시도 %d) >> ", infoValues, MAX_ATTEMPTS - currentAttempts - 1);
            scanf(" %c", &inputValue);
            *inputWordsP = inputValue;
            inputWordsP++;


            // (2) 정답 체크
            int j;
            isWrong = true;
            isAllCorrect = true;
            for (j = 0; j < correctWordsP[j] != '\0'; j++) {
                if (correctWordsP[j] == inputValue) {
                    infoValues[j] = inputValue;
                    isWrong = false;
                }
                if (infoValues[j] == '-') isAllCorrect = false;
            }

            if (isWrong) wrong++;
            if (isAllCorrect) {
                printf("정답! %s\n\n", correctWordsP);
                break;
            }

            // (3) 결과 출력
            printf("Wrong : %d,  입력한 알파벳 : %s\n\n", wrong, inputWords);

            currentAttempts++;
            if (currentAttempts >= MAX_ATTEMPTS) break;
        }

        // 3. 다음 단계로
        correctWordsP++;
    }
    printf("\n\n행맨 게임을 종료합니다!");
}