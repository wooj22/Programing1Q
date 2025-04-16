//#include <iostream>
//using namespace std;
//
//int main() {
//	/*-------- 1차원 배열 ---------*/ 
//	int arr1[3] = { 1,5,10 };
//
//	// 1.배열로 접근하기
//	cout << "[1차원 배열] 배열로 접근하기" << endl;
//
//	// 1-1. 배열 인덱싱
//	for (int i = 0; i < 3; i++) cout << arr1[i] << '\t';
//	cout << endl;
//
//	// 1-2. 배열을 포인터 관점으로 포인터 연산
//	for (int i = 0; i < 3; i++) cout << *(arr1+i) << '\t';
//	cout << endl << endl;
//
//
//	// 2. 포인터로 접근하기 (배열 포인터)
//	cout << "[1차원 배열] 포인터로 접근하기" << endl;
//	int* p_arr1 = arr1;
//
//	// 2-1. 포인터 인덱스
//	for (int i = 0; i < 3; i++) cout << p_arr1[i] << '\t';
//	cout << endl;
//
//	// 2-2. 포인터 연산
//	for (int i = 0; i < 3; i++) cout << *(p_arr1 + i) << '\t';
//	cout << endl;
//
//	// 3-3. 포인터 연산 - 포인터 자체를 이동
//	for (int i = 0; i < 3; i++) cout << *p_arr1++ << '\t';
//	cout << endl << endl;
//	
//
//
//	/*-------- 2차원 배열 ---------*/
//	int arr2[2][3] = { {2,4,6} , 
//				    	{8,10,12} };
//
//	// 1. 배열로 접근하기
//	cout << "[2차원 배열] 배열로 접근하기" << endl;
//
//	// 1-1. 배열 인덱싱
//	for (int i = 0; i < 2; i++) {
//		for (int j = 0; j < 3; j++) {
//			cout << arr2[i][j] << '\t';
//		}
//		cout << endl;
//	}
//	cout << endl;
//
//	// 1-2. 배열을 포인터 관점으로 2차원 포인터 연산
//	for (int i = 0; i < 2; i++) {
//		for (int j = 0; j < 3; j++) {
//			cout << *(*(arr2 + i) + j) << '\t';
//		}
//		cout << endl;
//	}
//	cout << endl;
//
//
//	// 2. 포인터로 접근하기
//	cout << "[2차원 배열] 포인터로 접근하기" << endl;
//	int* p_arr3 = &arr2[0][0];
//
//	// 2-1. 1차원 배열 관점으로 포인터 연산
//	for (int i = 0; i < 2 * 3; i++) {
//		cout << *(p_arr3 + i) << '\t';
//	}
//	cout << endl;
//
//	// 2-2. 2차원 배열 관점으로 포인터 연산
//	for (int i = 0; i < 2; i++) {
//		for (int j = 0; j < 3; j++) {
//			cout << *((p_arr3 + i) + j) << '\t';
//		}
//		cout << endl;
//	}
//	cout << endl;
//
//	// 3. 배열 포인터로 접근하기
//	// 2차원 배열의 포인터 관점 자료형은 int (*)[]
//	// 배열 포인터 선언 방법은 int (*포인터명)[배열의 열 size]
//	// [size]개짜리 배열을 가리키는 포인터 라는 의미
//	// 2차원 배열 등에서 행 단위로 접근할 때 주로 사용한다.
//	cout << "[2차원 배열] 배열 포인터로 접근하기" << endl;
//	int (*p_arr4)[3] = arr2;
//	
//	for (int i = 0; i < 2; i++) {
//		for (int j = 0; j < 3; j++) {
//			cout << p_arr4[i][j] << '\t';
//		}
//		cout << endl;
//	}
//	cout << endl << endl;
//
//
//	/*-------- 2차원 동적 배열일 경우 ---------*/
//	// 이중포인터
//	// **prt은 각 행이 메모리상에 다른 주소에 위치하고 있을때 사용하는 개념이다.
//	cout << "[2차원 동적 배열] 이중 포인터 접근하기" << endl;
//
//	int** dynArr = new int* [2];
//	for (int i = 0; i < 2; i++) {
//		dynArr[i] = new int[3];
//	}
//
//	int value = 1;
//	for (int i = 0; i < 2; i++) {
//		for (int j = 0; j < 3; j++) {
//			dynArr[i][j] = value++;
//		}
//	}
//
//	for (int i = 0; i < 2; i++) {
//		for (int j = 0; j < 3; j++) {
//			cout << dynArr[i][j] << '\t';
//		}
//		cout << endl;
//	}
//	cout << endl;
//
//	for (int i = 0; i < 2; i++) {
//		delete[] dynArr[i];
//	}
//	delete[] dynArr;
//
//}