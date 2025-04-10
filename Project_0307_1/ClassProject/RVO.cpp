#include <iostream>
using namespace std;

// ROV (return value optimization)
// 리턴 하는 클래스의 생성 은 사용 방법에 따라 컴파일러가 최적화한다. 

class Person
{
public:
    std::string name;

    Person(const std::string& n) : name(n) {
        std::cout << this << " 생성자 호출: " << name << "\n";
    }
    /*Person& operator = (const Person& other) {
        std::cout << this << " 대입 연산자 호출: " << name << "\n";
        name = other.name;
        return *this;
    }*/
    Person(const Person& other) {
        name = other.name;
        std::cout << this << " 복사 생성자 호출: " << name << "\n";
    }
    ~Person() {
        std::cout << this << " 소멸자 호출: " << name << "\n";
    }
};


Person CreatePerson()
{
    Person p("Alice");
    std::cout << "CreatePerson 주소확인" << &p << "\n";
    return p;
}

int main()
{
    // 여기 함수 안에 리턴하는 객체는 main 스택 영역에 생성 
    // 복사생성자가 아닌 생성자를 호출한다(컴파일러 최적화)
    // 둘이 스택이 달라서 주소가 다를듯 하지만 주소도 같음 
    Person person1 = CreatePerson(); 
    cout << "person1 주소확인"  << &person1 << "\n";;

    // 여기는 main스택과 CreatePerson스택에 각각 생성 후 대입연산
    Person person2("person2");
    person2 = CreatePerson();
    std::cout << "person2 주소확인" << &person2 << "\n";
}

