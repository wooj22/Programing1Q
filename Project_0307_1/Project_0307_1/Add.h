#pragma once
// #pragma once : 헤더가드 지시문.
// cpp 컴파일 과정에서 한번만 include하여 중복 오류를 방지함
// #ifndef, #define도 있음
// 다른 cpp 파일에서 이 헤더파일(Add.h)만 include하면 여기에 선언된 함수들 사용 가능
// 아래 함수가 구현된 cpp 파일에도 이 헤더파일(Add.h)을 include해서 명확하게 링크함

int add(int a, int b);

