#include <cstdio>
using namespace std;

// 1차원 배열은.. 다 알죠...?

// 2차원 이미지에서 최대 밝기값을 구해서 반환하는 함수
// 2차원 배열을 매개변수로 받을때는 반드시 열 값(size)를 지정해주어야 한다는 문제가 있다.
// 즉 임의의 크기의 영상에는 적용할 수 없다.
// 이러한 경우에는 동적할당과 2중포인터를 활용하여 알고리즘을 작성해야한다.

int findMaxPixel(int a[][5], int h, int w) {
	int maxVal = 0;
	for(int i=0; i<h; i++)
		for (int j = 0; j < w; j++) {
			if (maxVal < a[i][j]) maxVal = a[i][j];
		}

	return maxVal;
}