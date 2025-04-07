//#include <iostream>
//using namespace std;
//
//// 추상화 (Abstraction)
//// 가상함수 선언을 하고 구체적인 구현을 작성하지 않은 함수(인터페이스)만을 제공
//
//// 추상 클래스
//// 순수 가상 함수 → 구현 없음 → 추상 클래스
//// 인스턴스 생성은 불가능
//class IInteractable {
//public:
//    virtual void Interact() = 0;
//    virtual ~IInteractable() { }
//};
//
//class Door : public IInteractable {
//public:
//    void Interact() override {
//        cout << "문을 엽니다.\n";
//    }
//
//    ~Door() {
//        cout << "[Door] 소멸\n";
//    }
//};
//
//int main() {
//    IInteractable* obj = new Door();
//    obj->Interact();
//
//    delete obj;
//}
