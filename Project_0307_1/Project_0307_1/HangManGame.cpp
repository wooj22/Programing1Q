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
    const int MAX_ATTEMPTS = 10;           // �ִ� �õ� Ƚ��
    int currentAttempts;                   // ���� �õ� Ƚ��
    int wrong;                             // ���� Ʋ�� Ƚ��
    bool isWrong;                         // ���� Ʋ�� ����      
    bool isAllCorrect;                     // ���� ����
    char inputValue;                       // ����� �Է°�

    printf("/////////////////////////\n///// HANG MAN GAME /////\n/////////////////////////\n\n");

    for (int i = 0; i < MAX_WORDS; i++) {
        // �ʱ�ȭ
        char infoValues[MAX_LENGTH] = {};      // ���� ���� ���� �迭
        char inputWords[MAX_ATTEMPTS] = {};    // �Է��� ���ĺ� �迭
        char* inputWordsP = inputWords;        // �Է��� ���ĺ� �迭 ������
        char* correctWordsP = words[i];        // ���� ���ڿ� �迭 ������

        currentAttempts = 0;
        wrong = 0;

        // 1. ���� �ܾ� �ڸ��� �ʱ�ȭ
        printf("\n\n<%d��° ����..  ��ȸ %d��!>\n\n", i + 1, MAX_ATTEMPTS);
        for (int j = 0; j < words[i][j] != '\0'; j++) {
            infoValues[j] = '-';
        }

        // 2. ���� ����
        while (true) {
            // (1) ����� �Է°� �ޱ�, �Է��� ���ĺ� ����
            printf("%s\n ���� ���ڸ� �� �Է� (���� �õ� %d) >> ", infoValues, MAX_ATTEMPTS - currentAttempts - 1);
            scanf(" %c", &inputValue);
            *inputWordsP = inputValue;
            inputWordsP++;


            // (2) ���� üũ
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
                printf("����! %s\n\n", correctWordsP);
                break;
            }

            // (3) ��� ���
            printf("Wrong : %d,  �Է��� ���ĺ� : %s\n\n", wrong, inputWords);

            currentAttempts++;
            if (currentAttempts >= MAX_ATTEMPTS) break;
        }

        // 3. ���� �ܰ��
        correctWordsP++;
    }
    printf("\n\n��� ������ �����մϴ�!");
}