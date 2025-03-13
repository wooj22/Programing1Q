#include <iostream>
#include <string>
using namespace std;

// 동적 메모리 할당
// 코드 작성 시점에서 메모리 할당 여부나 크기를 할 수 없는 경우에 활용
// 힙 영역을 사용하며 주소를 저장하고, 사용 후 메모리 해제 필요
/*
int main() {
	// C++
	int* p = new int;
	delete p;

	// C
	int* p2 = (int*)malloc(sizeof(int));
	free(p2);

	int* p3 = (int*)malloc(sizeof(int) * 10);
	free(p3);
}
*/