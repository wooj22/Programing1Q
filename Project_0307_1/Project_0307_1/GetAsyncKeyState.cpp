#include <stdio.h>
#include <windows.h>

// GetAsyncKeyState()
// WindowsAPI로서 가상키 값으로 실시간 키 입력 확인이 가능하다.
// 메세지큐와 연관없이 단독으로 사용할 때는 0x8000 비트만  활용한다.
// 처음 눌린 순간을 확인하고 싶을때는 이전 상태를 저장해서 (지금은 눌림)&&!(이전에 눌림)을 체크해야함

int main() {
    SHORT prevState = 0;  // 이전 키 상태 저장
    printf("스페이스바 키 입력 감지 (ESC로 종료)\n");

    while (1) {
        SHORT state = GetAsyncKeyState(VK_SPACE); // 스페이스바 상태 가져오기

        if (state & 0x8000) {
            printf("스페이스바 눌려있음 (KeyPressed) \n");
        }

        // Key Down Event (이전에는 안 눌려있고, 지금 눌림)
        if ((state & 0x8000) && !(prevState & 0x8000)) {

            printf("스페이스바 눌림 순간 (Key Down) \n");
        }

        // Key Up Event (이전에는 눌려 있었고, 지금 안 눌림)
        if (!(state & 0x8000) && (prevState & 0x8000)) {
            printf("스페이스바 뗌 (Key Up)\n");
        }

        // ESC 키 입력 시 종료
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            printf("ESC 키 입력! 프로그램 종료\n");
            break;
        }
        prevState = state; // 현재 키 상태 저장        
    }
    return 0;
}

