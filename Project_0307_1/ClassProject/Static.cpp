#include <iostream>

/* static 키워드를 클래스 안에서 사용하면 "이 멤버는 객체가 아니라 클래스 자체에 속한다"는 뜻이다.
모든 인스턴스가 같은 값을 공유하며 인스턴스를 만들지 않고도 접근 가능 , 객체마다 따로 존재하지 않음
프로그램 시작 시 생성되고, 프로그램 종료 시 소멸된다. 즉,전역 변수처럼 정적 수명(static storage duration)을 가진다. 
가상메모리에서 위치하는 메모리영역도 전역변수와 동일한 데이터영역에 위치한다.
*/

class Game {
public:
    static int version;

    static void PrintVersion() {
        std::cout << "버전: " << version << std::endl;
    }
};

// 정의 필요
int Game::version = 1;

int main() {
    Game::PrintVersion(); // 클래스 이름으로 직접 호출
}
