#include <cstdio>
using namespace std;

// 1���� �迭��.. �� ����...?

// 2���� �̹������� �ִ� ��Ⱚ�� ���ؼ� ��ȯ�ϴ� �Լ�
// 2���� �迭�� �Ű������� �������� �ݵ�� �� ��(size)�� �������־�� �Ѵٴ� ������ �ִ�.
// �� ������ ũ���� ���󿡴� ������ �� ����.
// �̷��� ��쿡�� �����Ҵ�� 2�������͸� Ȱ���Ͽ� �˰����� �ۼ��ؾ��Ѵ�.

int findMaxPixel(int a[][5], int h, int w) {
	int maxVal = 0;
	for(int i=0; i<h; i++)
		for (int j = 0; j < w; j++) {
			if (maxVal < a[i][j]) maxVal = a[i][j];
		}

	return maxVal;
}