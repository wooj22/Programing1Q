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
// 배열과 포인터
void Test(int InputArray[], int* p, int length) {
	printf("Array Address : %d\n", InputArray);
	printf("Array Pointer Address : %d\n", p);
	printf("Size : %d\n", sizeof(p));

	for (int i = 0; i < length; i++) {
		InputArray[i] = 0xFF;
		printf("배열 %d번째 인덱스의 원소 값은 %d\n", i, InputArray[i]);
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

// Char 문자열 (char는 문자, char문자열은 \n로 끝나는 문자열)
// 문자열(배열)은 주소를 출력하지 않고 전체 문자열 값이 출력됨 (0을 찾을 떄 까지)
/*
const char* g_Test = "Hello\n";
char g_Test2[20] = "Hello2한글\n";
*/