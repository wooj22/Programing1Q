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
    // ���Ͽ���
    FILE* fp = fopen("wordList.txt", "r");
    if (fp == NULL) {
        printf("���� �б� ����\n");
        return 0;
    }
    
    // �ܾ� ���� �б�
    int maxWords;
    fscanf(fp, "%d", &maxWords);
    fgetc(fp);
    printf("�� �ܾ��� �� : %d\n", maxWords);

    // 2���� ���ڿ� �迭 �����Ҵ��ϱ� (char[�ܾ��][�ܾ����])
    char** wordList = new char* [maxWords];
    for (int i = 0; i < maxWords; i++) {
        wordList[i] = new char[MAX_LENGTH];
    }

    // �ܾ� �б�
    for (int i = 0; i<maxWords; i++) {
        if (fgets(wordList[i], MAX_LENGTH, fp) != NULL) {
            wordList[i][strcspn(wordList[i], "\n")] = 0;
            cout << wordList[i] << endl;
        }
    }


    // ���� �ݱ�
    fclose(fp);

    /*------------- Game -------------*/
    printf("/////////////////////////\n///// HANG MAN GAME /////\n/////////////////////////\n\n");
    const int MAX_ATTEMPTS = 10;           // �ִ� �õ� Ƚ��
    int currentAttempts;                   // ���� �õ� Ƚ��
    int wrong;                             // ���� Ʋ�� Ƚ��
    bool isWrong;                          // ���� Ʋ�� ����
    bool isAllCorrect;                     // ���� ����
    char inputValue;                       // ����� �Է°�

    for (int i = 0; i < maxWords; i++) {
        // �ʱ�ȭ
        char infoValues[MAX_LENGTH] = {};      // ���� ���� ���� �迭
        char inputWords[MAX_ATTEMPTS] = {};    // �Է��� ���ĺ� �迭
        char* inputWordsP = inputWords;        // �Է��� ���ĺ� �迭 ������
        char* correctWordsP = wordList[i];        // ���� ���ڿ� �迭 ������

        currentAttempts = 0;
        wrong = 0;

        // 1. ���� �ܾ� �ڸ��� �ʱ�ȭ
        printf("\n\n<%d��° ����..  ��ȸ %d��!>\n\n", i + 1, MAX_ATTEMPTS);
        for (int j = 0; j < wordList[i][j] != '\0'; j++) {
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
    return 0;
}
