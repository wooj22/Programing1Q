#include <iostream>
#include <stdio.h>
using namespace std;

/*
  사용자 정의 자료형 : 기본 자료형(int, char, float 등)만으로 표현하기 어려운 복잡한 데이터를 다룰 때 사용
  구조체(struct),열거형(enum),공용체(union), 별칭(typedef)
*/

// Enum
// Int 타입의 변수로 캐릭터 상태를 표현한다면 소스 코드도 정수 값이며, 디버깅 정보에서도 정수 값 으로 확인해야 한다.
// 가독성 및 디버깅 작업 효율이 떨어지는 단점이 있음
enum PlayerState {
	STATE_IDLE,		//0
	STATE_WALK,		//1
	STATE_RUN,		//2...
	STATE_JUMP,
	STATE_ATTACK,
	STATE_HURT
};

// 구조체
// 자료형의 묶음으로 새로운 자료형을 정의 하여 데이터를 모델링 할 수 있는 키워드
// stack에 할당된다.
// 대입 연산자 사용시 모든 멤버를 복사한다.  
// 구조체를 참조하는 포인터로 특정 멤버변수에 접근할때는 -> 를 사용한다.
struct Player
{
	char name[50];
	int health = 100;
	enum PlayerState playerState;
};

// Union(공용체)
// 가장 큰 멤버 기준으로 메모리 공간을 확보하고 동일한 메모리 공간을 사용하는 자료형을 선언하는 키워드 
// 낮은 비트의 바이트부터 저장된다.
union Example {
	char a;			// 1byte
	int b;			// 4byte
	double c;		// 8byte----> 가장 큰 멤버이므로 8바이트 확보(a,b,c가 같이 메모리 사용)
};

// typedef
// 원래 있는 데이터 타입에 새로운 이름(alias)을 부여하는 키워드
// 통해 코드의 가독성을 높이고, 특정 데이터 구조를 보다 간결하게 표현할 수 있다.
typedef int INT_TYPEDEF;				// int를 INT_TYPEDEF로 새로 정의하여 사용

typedef __int64 INT_PTR, * PINT_PTR;    // 을 풀어쓰면 아래와 같음
typedef __int64 INT_PTR;				// INT_PTR → __int64
typedef INT_PTR* PINT_PTR;			    // PINT_PTR → INT_PTR의 포인터 (즉, __int64*)


//int main() {
//	Player player1;
//	player1.playerState = STATE_IDLE;
//
//	union Example ex;
//	ex.a = 0x12;		// 저장
//	ex.b = 0x12345678;	// a 미루고 저장
//	ex.c = 3.141592583498234;	// 남은 공간이 없으므로 a, b는 미뤄 사라지고 c 저장
//}