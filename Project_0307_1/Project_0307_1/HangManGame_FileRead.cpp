#include <stdio.h>
#include <string.h>
#include <iostream>

#pragma warning(disable:4996)
//#define MAX_WORDS 10
#define MAX_LENGTH 15
using namespace std;

/*
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
*/
int main() {
    /*-------------- File Input -------------*/
    // 파일열기
    FILE* fp = fopen("wordList.txt", "r");
    if (fp == NULL) {
        printf("파일 읽기 실패\n");
        return 0;
    }
    
    // 단어 개수 읽기
    int maxWords;
    fscanf(fp, "%d", &maxWords);
    fgetc(fp);
    printf("총 단어의 수 : %d\n", maxWords);

    // 2차원 문자열 배열 동적할당하기 (char[단어수][단어길이])
    char** wordList = new char* [maxWords];
    for (int i = 0; i < maxWords; i++) {
        wordList[i] = new char[MAX_LENGTH];
    }

    // 단어 읽기
    for (int i = 0; i<maxWords; i++) {
        if (fgets(wordList[i], MAX_LENGTH, fp) != NULL) {
            wordList[i][strcspn(wordList[i], "\n")] = 0;
            cout << wordList[i] << endl;
        }
    }


    // 파일 닫기
    fclose(fp);

    /*------------- Game -------------*/
    printf("/////////////////////////\n///// HANG MAN GAME /////\n/////////////////////////\n\n");
    const int MAX_ATTEMPTS = 10;           // 최대 시도 횟수
    int currentAttempts;                   // 현재 시도 횟수
    int wrong;                             // 현재 틀린 횟수
    bool isWrong;                          // 현재 틀림 여부
    bool isAllCorrect;                     // 정답 여부
    char inputValue;                       // 사용자 입력값

    for (int i = 0; i < maxWords; i++) {
        // 초기화
        char infoValues[MAX_LENGTH] = {};      // 현재 문자 정보 배열
        char inputWords[MAX_ATTEMPTS] = {};    // 입력한 알파벳 배열
        char* inputWordsP = inputWords;        // 입력한 알파벳 배열 포인터
        char* correctWordsP = wordList[i];        // 정답 문자열 배열 포인터

        currentAttempts = 0;
        wrong = 0;

        // 1. 현재 단어 자리수 초기화
        printf("\n\n<%d번째 문제..  기회 %d번!>\n\n", i + 1, MAX_ATTEMPTS);
        for (int j = 0; j < wordList[i][j] != '\0'; j++) {
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
    return 0;
}
