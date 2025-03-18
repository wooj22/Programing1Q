#include <stdio.h>
#include <iostream>
#include "Add.h"

using namespace std;

/*
  다중프로그래밍
   - 여러 개의 .c , .cpp 파일로 특징 별로 분리(모듈화)하여 관리하는 방식
   - 선언부(.h)를 다른 cpp에서 포함하면 링크과정에서 정의부를 찾아 연결함
   - #pragma once(헤더가드 지시문)을 .h파일에서 선언하면 cpp 컴파일 과정에서 한번만 include하여 중복 오류를 방지함

  정적 라이브러리(Static Library)
   - 라이브러리를 만들어서 재사용 하는 방식
  외부 라이브러리
*/

int main() {
	cout << add(1, 2); //add()함수가 선언되어있는 Add.h를 include하여 정의부(Add.cpp)를 찾아 연결함
} 