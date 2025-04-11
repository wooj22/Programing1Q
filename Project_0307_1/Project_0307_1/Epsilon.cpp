#include <stdio.h>
#include <float.h>
#include <math.h>

//int main()
//{
//	float a = 0.0f;;
//	for (int i = 0; i < 10; i++)
//	{
//		a += 0.1f;
//	}
//	float b = 1.0f;
//	printf("%f == %f %s\n", a, b, (a == b) ? "true" : "false");
//	return 0;
//}

// 허용오차 (Epsilon) : 아주 작은 값 범위
// <float.h> FLT_EPSILON
int main() {
	float a = 0.0f;
	for (int i = 0; i < 10; i++)
		a += 0.1f;

	float b = 1.0f;

	printf("%f == %f %s\n", a, b, (fabs(a - b) <= FLT_EPSILON) ? "true" : "false");
	return 0;
}
