#include <stdio.h>
#include <iostream>
#include "Add.h"

using namespace std;

/*
  �������α׷���
   - ���� ���� .c , .cpp ���Ϸ� Ư¡ ���� �и�(���ȭ)�Ͽ� �����ϴ� ���
   - �����(.h)�� �ٸ� cpp���� �����ϸ� ��ũ�������� ���Ǻθ� ã�� ������
   - #pragma once(������� ���ù�)�� .h���Ͽ��� �����ϸ� cpp ������ �������� �ѹ��� include�Ͽ� �ߺ� ������ ������

  ���� ���̺귯��(Static Library)
   - ���̺귯���� ���� ���� �ϴ� ���
  �ܺ� ���̺귯��
*/

int main() {
	cout << add(1, 2); //add()�Լ��� ����Ǿ��ִ� Add.h�� include�Ͽ� ���Ǻ�(Add.cpp)�� ã�� ������
} 