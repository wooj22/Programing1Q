#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>

/// 동적할당시에 메모리 누수를 방지하는 방법
/// 할당하고 메모리를 해제하지 않은 것을 확인할 수 있다. (출력창에서)
/*
int main() {
    // 종료시 메모리릭 정보 자동 출력 설정
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    

    // 동적 메모리 할당
    int* p = (int*)malloc(sizeof(int) * 5);

    // 메모리 해제하여 누수 방지
    //free(p);

    _CrtDumpMemoryLeaks();  // 초기 {번호}를 포함한 메모리 상태 출력  -> {77}
    _CrtSetBreakAlloc(77);  // {77} 번호의 메모리 할당을 추적
    return 0;
}
*/
