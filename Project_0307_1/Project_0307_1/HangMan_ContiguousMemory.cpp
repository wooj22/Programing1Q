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

    // 2차원 문자열 배열 연속된 메모리 공간으로 동적 할당하기
    char* wordList2 = new char[maxWords * MAX_LENGTH];

    // 단어 읽기
    for (int i = 0; i < maxWords * MAX_LENGTH; i+=MAX_LENGTH) {
        if (fgets(wordList2+i, MAX_LENGTH, fp) != NULL) {
            size_t len = strcspn(wordList2 + i, "\n");
            wordList2[i + len] = '\0';
        }
    }

    // 단어 확인
    cout << "단어 리스트를 미리 보여드립니다." << endl;
    for (int i = 0; i < maxWords * MAX_LENGTH; i += MAX_LENGTH) {
        cout << (wordList2 + i) << endl;
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
        // 정답 문자열 배열 포인터
        // 1차원 배열의 포인터로 바꿨으므로 wordList2를 사용해서 게임 진행
        //char* correctWordsP = wordList[i]; 

        currentAttempts = 0;
        wrong = 0;

        // 1. 현재 단어 자리수 초기화
        printf("\n\n<%d번째 문제..  기회 %d번!>\n\n", i + 1, MAX_ATTEMPTS);

        for (int j = 0; wordList2[j] != '\0'; j++) {
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
            for (j = 0; j < wordList2[j] != '\0'; j++) {
                if (wordList2[j] == inputValue) {
                    infoValues[j] = inputValue;
                    isWrong = false;
                }
                if (infoValues[j] == '-') isAllCorrect = false;
            }

            if (isWrong) wrong++;
            if (isAllCorrect) {
                printf("정답! %s\n\n", wordList2);
                break;
            }

            // (3) 결과 출력
            printf("Wrong : %d,  입력한 알파벳 : %s\n\n", wrong, inputWords);

            currentAttempts++;
            if (currentAttempts >= MAX_ATTEMPTS) break;
        }

        // 3. 다음 단계로
        wordList2 += MAX_LENGTH;
    }
    
    printf("\n\n행맨 게임을 종료합니다!");
    return 0;
}
