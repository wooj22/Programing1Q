#include <iostream>
#include <stdio.h>
#include "Add.h"
#include <cstddef>
using namespace std;
/*
int g_Test = 0x123456;
int g_Sum = 0;

int main() {
	int result = add(1, 2);
	int* adress = &g_Test;

	printf("Hello\n");
	cout << adress << "\n";
	cout << result;
	return 0;
}
*/

/*
// �迭�� ������
void Test(int InputArray[], int* p, int length) {
	printf("Array Address : %d\n", InputArray);
	printf("Array Pointer Address : %d\n", p);
	printf("Size : %d\n", sizeof(p));

	for (int i = 0; i < length; i++) {
		InputArray[i] = 0xFF;
		printf("�迭 %d��° �ε����� ���� ���� %d\n", i, InputArray[i]);
	}
}

int main() {
	int Array1[4] = { 0,1,2,3 };
	int Array2[4] = { 2,3,4,5 };

	if (Array1 == Array2) printf("true\n");
	else printf("false\n");

	// Array1 -> Array2
	memcpy_s(Array2, sizeof(Array2), Array1, sizeof(Array1));

	Test(Array2, Array2, sizeof(Array1)/sizeof(Array1[0]));
	return 0;

}
*/

// Char ���ڿ� (char�� ����, char���ڿ��� \n�� ������ ���ڿ�)
// ���ڿ�(�迭)�� �ּҸ� ������� �ʰ� ��ü ���ڿ� ���� ��µ� (0�� ã�� �� ����)
/*
const char* g_Test = "Hello\n";
char g_Test2[20] = "Hello2�ѱ�\n";
*/