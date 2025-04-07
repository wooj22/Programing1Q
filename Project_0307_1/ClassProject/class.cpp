//#include <iostream>
//using namespace std;
//
//// 다형성 - 런타임 다형성, 실행시간 다형성
//// vtable, vptr
//// '가상함수테이블(Virtual function table)'은 클래스가 어던 함수를 사용하는지 주소가 있음
//// 클래스를 상속받은 클래스는 상위클래스의 '가상 함수 테이블 포인터값'을 갖는다.
//// 런타임에 사용할 함수를 찾아야 하기 때문에 그냥 함수를 호출하는거보다 더 느리지만 생산성을 크게 높인다.
//
//class Animal {
//public:
//    virtual void Speak() {
//        cout << "Animal : Speak" << endl;
//    }
//
//    virtual void Walk() {
//        cout << "Animal : Walk" << endl;
//    }
//};
//
//class Dog : public Animal {
//public:
//    void Speak() override {
//        __super::Speak();
//        cout << "Dog : Speak" << endl;
//    }
//
//    void Walk() override {
//        cout << "Dog : Walk" << endl;
//    }
//};
//
//class Cat : public Animal {
//public:
//    void Speak() override final {
//        __super::Speak();
//        cout << "Cat : Speak" << endl;
//    }
//    void Walk() override {
//        cout << "Cat : Walk" << endl;
//    }
//};
//
//class BabyCat : public Cat {
//    /*void Speak() override {
//        __super::Speak();
//        cout << "Cat : Speak" << endl;
//    }*/
//};
//
//void MakeitWalk(Animal* a)
//{
//    a->Walk();
//}
//
//
//int main() {
//    Dog dog;
//    Cat cat;
//
//    dog.Speak(); 
//    cat.Speak(); 
//
//    dog.Walk();
//    cat.Walk();
//
//    MakeitWalk(&dog);
//    MakeitWalk(&cat);
//}