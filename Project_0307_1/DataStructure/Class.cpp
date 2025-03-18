//#include <stdio.h>
//#include <string.h>
//using namespace std;
//
///// Ŭ����(class)
///// c++�� Ŭ���� ����Ʈ ���� �����ڴ� private�̴�.
///// ����ο� �����θ� �����Ͽ� .h, .cpp ���Ϸ� �������� �� �ִ�.
///// ����ο� �����θ� �����Ҷ�, ����Ʈ �Ű��������� �����Ϸ��� ����ο��� ���� �־���Ѵ�.
///// �����ڸ� �����ε��ؼ� ������ �ۼ��� �� �ִ�. -> �����ε�, �������̵� �̸� ����!
///// �����ε� ���� -> (1) �Լ��� �̸��� ���� (2) �Ű����� Ÿ���̳� ������ �ٸ���. (3) �Լ��� ����Ÿ���� �����ϴ�(�򰥸��� ����)
///// �Ű����� �� �����ڸ� ������ �����Ϸ��� �⺻�����ڸ� ��������� �ʾƼ� �⺻ ��ü ������ �����ؾ��Ѵ�.
/////  - ��� �ʱ�ȭ ����Ʈ�� �� Ȱ������(�ٸ� Ŭ������ ��ü�� ����� ������ �ְų�,
/////  - �θ�Ŭ������ ��ӹ��� �ڽ�Ŭ������ �����ڿ��� �����ϰ� Ȱ��ȴ�.
///// this ������ : ���� ��ü�� �޸𸮻��� �ּҸ� ��ȯ
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
//void Car::display() { printf("[%s] : ��� %d��, �ӵ� %d km/h\n", name, gear, speed); }
//void Car::whereAmI() { printf("��ü �ּ� = %p\n", this); }
//
///// ���
///// �������̵� : �θ��� ����Լ��� ������ �ϴ°�
///// �������̵� ���� -> (1) �̸� ���� (2) �Ű����� ���� (3) ����Ÿ�� ����
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
///// ��ü�� ����
///// �ȵ� �� ������ c++�� �����ϴ� ����Ʈ ���� �����ڸ� ����Ͽ� �����ϴ�.
///// �������簡 �ƴϴ�. ���� �ٸ� �޸𸮸� ���ϸ� �ϳ��� ���� �����ص� �ٸ� �ϳ��� ������ ��ġ�� �ʴ´�.
///// ����Ǵ� ��ü�� ��� ������ �����ϴ� ��ü�� ��� �����Ѵ�.
///// ���縦 ���� �� �����ϰ� �ϰ� �ʹٸ� '='�� �����ε� �ϸ� �ȴ�. (������ �����ε�)
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
///// ��ü�� �Ű������� ������ ��ü�� Call by Value ������� ���޵ȴ�.
///// ������ ��������� ����. �򰥸��� ���� !!!
///// ���� ��ü�ʹ� ������ �������� ���纻�� ���������, �Լ� ������ ��ü�� �����ص� ���� ��ü���� ������ ��ġ�� �ʴ´�.
///// ������ ����(����)�Ϸ��� Car &c �� ���� ���� Ÿ������ �޾ƾ� �Ѵ�.
//void test(Car c) {
//    c.setName("�̸� �ٲ�?");
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