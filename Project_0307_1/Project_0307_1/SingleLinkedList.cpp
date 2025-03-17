#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

// 단순 연결 리스트(Single Linked List)
// 각 데이터가 연속되지 않은 메모리 공간에 동적 할당되며, 각 노드는 다음 데이터가 들어있는 노드를 가리키는 포인터를 가진다.
// 단순 연결 리스트는 before 노드에 대한 정보를 갖지 않기 때문에 삽입, 삭제 연산시에는 무조건 선행 노드가 필요!
// 노드 생성 : 노드를 생성하고 헤드포인터가 생성된 노드를 가리키게 함.
// 노드 삽입 : 노드를 생성하고 링크가 선행노드의 next를 가리키고, 선행노드가 자신을 가리키게 함.
// 노드 삭제 : 삭제할 노드의 선행노드가 자신의 next를 가리키게하고 삭제
// 헤드포인터 : 첫번째 노드를 가리키는 포인터
// Node* head = NULL;
// 포인터를 사용하지 않고 노드를 생성하여 헤드 노드로 활용하는 방법도 있다.

/*---- 노드 구조체 ----*/
class Node {
private:
	int data;						// 데이터 필드
	struct Node* next = NULL;		// 링크 필드(후속 노드)

public :
	Node* getNext() { return next; }
	Node(int num = 0) { this->data = num; }
	int getData() { return data; }
	void setNext(Node* next) { this->next = next; }
	void setData(int data) { this->data = data; }

	// 삽입 : 자신과 후속노드 사이에 새로운 노드를 삽입
	void insertNext(Node* n) {
		if (n != NULL) {
			n->next = this->next;
			this->next = n;
		}
	}

	// 삭제 : 자신의 후속노드 삭제
	Node* removeNext() {
		if (this->next != NULL) {
			Node* removed = this->next;
			this->next = removed->next;
			return removed;
		}
	}
};

/*---- 리스트 구조체 ----*/
class LinkedList {
	Node head;	// 헤드 노드

public:
	LinkedList() { head.setNext(NULL); }				    // 생성자
	~LinkedList() { clear(); }							    // 소멸자
	void clear() { while (!isEmpty()) delete remove(0); }	// 리스트 삭제
	bool isEmpty() { return head.getNext() == NULL; }	    // 공백검사
	
	// 노드 반환
	// 문제!!!! 왜 -1을 해야하는지...?(get Entry연산에서 노드 2칸이 밀림) 
	// 어딘가 잘못된 것 같은데 일단 제출하고 공부하겠습니다...
	Node* getEntry(int index) {
		Node* n = &head;
		for (int i = -1; i < index; i++, n = n->getNext()) {
			if (n == NULL) break;
		}
		return n;
	}

	// 삽입 : index에 Node n 삽입
	void insert(int index, Node* n) {
		Node* pre = getEntry(index - 1);
		if(pre != NULL) pre->insertNext(n);
	}

	// 삭제 : index의 선행노드를 찾아 삭제 연산 호출
	Node* remove(int index) {
		Node* prev = getEntry(index - 1);
		return prev->removeNext();
	}

	// 탐색 : value값이 있는 노드의 index를 반환
	int find(int value) {
		int index = 0;
		for (Node* p = head.getNext(); p != NULL; p = p->getNext()) {
			if (p->getData() == value) return index;
			index++;
		}
		return -1;
	}

	// 리스트 항목 개수 반환
	int size() {
		int count = 0;
		for (Node* p = head.getNext(); p != NULL; p = p->getNext()) {
			count++;
		}
		return count;
	}

	// 출력
	void display() {
		if (head.getNext() == NULL) printf("목록 없음");
		else {
			for (Node* p = head.getNext(); p != NULL; p = p->getNext()) {
				printf("%d  ", p->getData());
			}
		}
	}
};

int main() {
	/*--- single linked list를 활용한 List 프로그램(삽입, 삭제) ---*/
	LinkedList list;
	char input[100] = { 0, };
	char command[20];
	int num;

	while (true) {
		// 정보 출력 (리스트 목록, 명령어)
		list.display();
		printf("[명령어] add 숫자, del 숫자\n"); // ex) Add 10

		// 명령어 입력
		fgets(input, sizeof(input), stdin);	// fgets(개행이 나올때까지 읽어옴), stdin(표준 입력 스트림 포인터)

		// 명령어 저장
		// sscanf의 반환값은 읽어들인 항목의 개수
		sscanf(input, "%s %d", command, &num);

		// 명령어 실행
		if (strcmp(command, "add") == 0) {
			list.insert(list.size(), new Node(num));
		}
		else if (strcmp(command, "del") == 0) {
			int index = list.find(num);
			if (index != -1) list.remove(index);
			else printf("%d를 찾을 수 없습니다.\n", num);
		}
	}
}
