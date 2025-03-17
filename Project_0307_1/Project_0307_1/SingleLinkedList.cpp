#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

// �ܼ� ���� ����Ʈ(Single Linked List)
// �� �����Ͱ� ���ӵ��� ���� �޸� ������ ���� �Ҵ�Ǹ�, �� ���� ���� �����Ͱ� ����ִ� ��带 ����Ű�� �����͸� ������.
// �ܼ� ���� ����Ʈ�� before ��忡 ���� ������ ���� �ʱ� ������ ����, ���� ����ÿ��� ������ ���� ��尡 �ʿ�!
// ��� ���� : ��带 �����ϰ� ��������Ͱ� ������ ��带 ����Ű�� ��.
// ��� ���� : ��带 �����ϰ� ��ũ�� �������� next�� ����Ű��, �����尡 �ڽ��� ����Ű�� ��.
// ��� ���� : ������ ����� �����尡 �ڽ��� next�� ����Ű���ϰ� ����
// ��������� : ù��° ��带 ����Ű�� ������
// Node* head = NULL;
// �����͸� ������� �ʰ� ��带 �����Ͽ� ��� ���� Ȱ���ϴ� ����� �ִ�.

/*---- ��� ����ü ----*/
class Node {
private:
	int data;						// ������ �ʵ�
	struct Node* next = NULL;		// ��ũ �ʵ�(�ļ� ���)

public :
	Node* getNext() { return next; }
	Node(int num = 0) { this->data = num; }
	int getData() { return data; }
	void setNext(Node* next) { this->next = next; }
	void setData(int data) { this->data = data; }

	// ���� : �ڽŰ� �ļӳ�� ���̿� ���ο� ��带 ����
	void insertNext(Node* n) {
		if (n != NULL) {
			n->next = this->next;
			this->next = n;
		}
	}

	// ���� : �ڽ��� �ļӳ�� ����
	Node* removeNext() {
		if (this->next != NULL) {
			Node* removed = this->next;
			this->next = removed->next;
			return removed;
		}
	}
};

/*---- ����Ʈ ����ü ----*/
class LinkedList {
	Node head;	// ��� ���

public:
	LinkedList() { head.setNext(NULL); }				    // ������
	~LinkedList() { clear(); }							    // �Ҹ���
	void clear() { while (!isEmpty()) delete remove(0); }	// ����Ʈ ����
	bool isEmpty() { return head.getNext() == NULL; }	    // ����˻�
	
	// ��� ��ȯ
	// ����!!!! �� -1�� �ؾ��ϴ���...?(get Entry���꿡�� ��� 2ĭ�� �и�) 
	// ��� �߸��� �� ������ �ϴ� �����ϰ� �����ϰڽ��ϴ�...
	Node* getEntry(int index) {
		Node* n = &head;
		for (int i = -1; i < index; i++, n = n->getNext()) {
			if (n == NULL) break;
		}
		return n;
	}

	// ���� : index�� Node n ����
	void insert(int index, Node* n) {
		Node* pre = getEntry(index - 1);
		if(pre != NULL) pre->insertNext(n);
	}

	// ���� : index�� �����带 ã�� ���� ���� ȣ��
	Node* remove(int index) {
		Node* prev = getEntry(index - 1);
		return prev->removeNext();
	}

	// Ž�� : value���� �ִ� ����� index�� ��ȯ
	int find(int value) {
		int index = 0;
		for (Node* p = head.getNext(); p != NULL; p = p->getNext()) {
			if (p->getData() == value) return index;
			index++;
		}
		return -1;
	}

	// ����Ʈ �׸� ���� ��ȯ
	int size() {
		int count = 0;
		for (Node* p = head.getNext(); p != NULL; p = p->getNext()) {
			count++;
		}
		return count;
	}

	// ���
	void display() {
		if (head.getNext() == NULL) printf("��� ����");
		else {
			for (Node* p = head.getNext(); p != NULL; p = p->getNext()) {
				printf("%d  ", p->getData());
			}
		}
	}
};

int main() {
	/*--- single linked list�� Ȱ���� List ���α׷�(����, ����) ---*/
	LinkedList list;
	char input[100] = { 0, };
	char command[20];
	int num;

	while (true) {
		// ���� ��� (����Ʈ ���, ��ɾ�)
		list.display();
		printf("[��ɾ�] add ����, del ����\n"); // ex) Add 10

		// ��ɾ� �Է�
		fgets(input, sizeof(input), stdin);	// fgets(������ ���ö����� �о��), stdin(ǥ�� �Է� ��Ʈ�� ������)

		// ��ɾ� ����
		// sscanf�� ��ȯ���� �о���� �׸��� ����
		sscanf(input, "%s %d", command, &num);

		// ��ɾ� ����
		if (strcmp(command, "add") == 0) {
			list.insert(list.size(), new Node(num));
		}
		else if (strcmp(command, "del") == 0) {
			int index = list.find(num);
			if (index != -1) list.remove(index);
			else printf("%d�� ã�� �� �����ϴ�.\n", num);
		}
	}
}
