//#include <stdio.h>
//#include <string.h>
//using namespace std;
//
///// 클래스(class)
///// c++의 클래스 디폴트 접근 지정자는 private이다.
///// 선언부와 구현부를 구분하여 .h, .cpp 파일로 구분지을 수 있다.
///// 선언부와 구현부를 구분할때, 디폴트 매개변수값을 지정하려면 선언부에만 값을 넣어야한다.
///// 생성자를 오버로딩해서 여러개 작성할 수 있다. -> 오버로딩, 오버라이드 이름 주의!
///// 오버로딩 조건 -> (1) 함수의 이름이 같고 (2) 매개변수 타입이나 개수가 다르다. (3) 함수의 리턴타입은 무관하다(헷갈리지 말기)
///// 매개변수 없 생성자만 있으면 컴파일러가 기본생성자를 만들어주지 않아서 기본 객체 생성에 유의해야한다.
/////  - 멤버 초기화 리스트를 잘 활용하자(다른 클래스의 객체를 멤버로 가지고 있거나,
/////  - 부모클래스를 상속받은 자식클래스의 생성자에서 유용하게 활용된다.
///// this 포인터 : 현재 객체의 메모리상의 주소를 반환
//
//class Car {
//protected:
//    int speed;
//    char name[40];
//
//public:
//    int gear;
//    Car() : speed(0), gear(0) { strcpy_s(name, "Default"); }
//    Car(int s, int g, const char* n) : speed(s), gear(g) {
//        strcpy_s(name, n);
//    }
//    ~Car() {};
//    void changeGear(int g);
//    void speedUp(int n = 5);
//    void speedDown(int n = 5);
//    void setName(const char* s);
//    void display();
//    void whereAmI();
//};
//
//void Car::changeGear(int g) { gear = g; }
//void Car::speedUp(int n) { speed += n; }
//void Car::speedDown(int n) { speed -= n; }
//void Car::setName(const char* s) { strcpy_s(name, s); }
//void Car::display() { printf("[%s] : 기어 %d단, 속도 %d km/h\n", name, gear, speed); }
//void Car::whereAmI() { printf("객체 주소 = %p\n", this); }
//
///// 상속
///// 오버라이딩 : 부모의 멤버함수를 재정의 하는것
///// 오버라이딩 조건 -> (1) 이름 동일 (2) 매개변수 동일 (3) 리턴타입 동일
//class SportsCar : public Car {
//public:
//    bool bTurbo;
//    void setTurbo(bool bTur) { bTurbo = bTur; }
//    void speedUp() {
//        if (bTurbo) speed += 20;
//        else Car::speedUp();
//    }
//};
//
///// 객체의 복사
///// 안될 것 같지만 c++이 제공하는 디폴트 대입 연산자를 사용하여 가능하다.
///// 참조복사가 아니다. 둘은 다른 메모리를 지니며 하나의 값을 변경해도 다른 하나에 영향을 미치지 않는다.
///// 복사되는 객체의 모든 내용을 복사하는 객체에 모두 저장한다.
///// 복사를 조금 더 세밀하게 하고 싶다면 '='를 오버로딩 하면 된다. (연산자 오버로딩)
//void copyObject() {
//    Car c1, c2;
//    c1.setName("ddd");
//    c2 = c1;
//    c2.display();
//
//    c1.setName("sss");
//    c1.display();
//    c2.display();
//}
//
///// 객체를 매개변수로 받을때 객체는 Call by Value 방식으로 전달된다.
///// 이유는 복사생성자 때문. 헷갈리지 말자 !!!
///// 원본 객체와는 별개로 독립적인 복사본이 만들어지고, 함수 내에서 객체를 변경해도 원본 객체에는 영향을 미치지 않는다.
///// 원본을 공유(참조)하려면 Car &c 와 같이 참조 타입으로 받아야 한다.
//void test(Car c) {
//    c.setName("이름 바뀜?");
//}
//
//int main() {
//    Car c;
//    test(c);
//    c.display();
//
//
//    return 0;
//}