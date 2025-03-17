#include <iostream>
#include <stdio.h>
using namespace std;

/*
  ����� ���� �ڷ��� : �⺻ �ڷ���(int, char, float ��)������ ǥ���ϱ� ����� ������ �����͸� �ٷ� �� ���
  ����ü(struct),������(enum),����ü(union), ��Ī(typedef)
*/

// Enum
// Int Ÿ���� ������ ĳ���� ���¸� ǥ���Ѵٸ� �ҽ� �ڵ嵵 ���� ���̸�, ����� ���������� ���� �� ���� Ȯ���ؾ� �Ѵ�.
// ������ �� ����� �۾� ȿ���� �������� ������ ����
enum PlayerState {
	STATE_IDLE,		//0
	STATE_WALK,		//1
	STATE_RUN,		//2...
	STATE_JUMP,
	STATE_ATTACK,
	STATE_HURT
};

// ����ü
// �ڷ����� �������� ���ο� �ڷ����� ���� �Ͽ� �����͸� �𵨸� �� �� �ִ� Ű����
// stack�� �Ҵ�ȴ�.
// ���� ������ ���� ��� ����� �����Ѵ�.  
// ����ü�� �����ϴ� �����ͷ� Ư�� ��������� �����Ҷ��� -> �� ����Ѵ�.
struct Player
{
	char name[50];
	int health = 100;
	enum PlayerState playerState;
};

// Union(����ü)
// ���� ū ��� �������� �޸� ������ Ȯ���ϰ� ������ �޸� ������ ����ϴ� �ڷ����� �����ϴ� Ű���� 
// ���� ��Ʈ�� ����Ʈ���� ����ȴ�.
union Example {
	char a;			// 1byte
	int b;			// 4byte
	double c;		// 8byte----> ���� ū ����̹Ƿ� 8����Ʈ Ȯ��(a,b,c�� ���� �޸� ���)
};

// typedef
// ���� �ִ� ������ Ÿ�Կ� ���ο� �̸�(alias)�� �ο��ϴ� Ű����
// ���� �ڵ��� �������� ���̰�, Ư�� ������ ������ ���� �����ϰ� ǥ���� �� �ִ�.
typedef int INT_TYPEDEF;				// int�� INT_TYPEDEF�� ���� �����Ͽ� ���

typedef __int64 INT_PTR, * PINT_PTR;    // �� Ǯ��� �Ʒ��� ����
typedef __int64 INT_PTR;				// INT_PTR �� __int64
typedef INT_PTR* PINT_PTR;			    // PINT_PTR �� INT_PTR�� ������ (��, __int64*)


//int main() {
//	Player player1;
//	player1.playerState = STATE_IDLE;
//
//	union Example ex;
//	ex.a = 0x12;		// ����
//	ex.b = 0x12345678;	// a �̷�� ����
//	ex.c = 3.141592583498234;	// ���� ������ �����Ƿ� a, b�� �̷� ������� c ����
//}