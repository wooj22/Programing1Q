//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
///*---- C��� �ܼ����Ḯ��Ʈ - ����, ����, ��� ----*/
///*--------------- Node Struct  ----------------*/
//struct Node {
//    int data;
//    struct Node* next;
//};
//
///*--------------- Head Pointer  --------------*/
//Node* g_head = NULL; 
//
///*---------------- Functions  ---------------*/
//// 1. ����
//void insert(int value) {
//    Node* node = (Node*)malloc(sizeof(Node));
//    node->data = value;
//    node->next = g_head;
//    g_head = node;
//}
//
//// 2. ����
//// ���Ḯ��Ʈ�� �ٸ� �޸𸮿� �����Ҵ�� ������ �����ͷ� �����ϴ� ���̹Ƿ�, �������� �ļӳ�带 �����ϸ� �ȴ�.
//void remove(int inputData) {
//    Node* preNode = NULL;
//
//    for (Node* curNode = g_head; curNode != NULL; curNode = curNode->next) {
//        if (curNode->data == inputData) {
//            // (1) ������ ��尡 ù��° ����� ���
//            if (preNode == NULL) { g_head = curNode->next; }
//            // (2) �̿��� ���
//            else { preNode->next = curNode->next; }
//
//            free(curNode);
//            return;
//        }
//        preNode = curNode;
//    }
//}
//
//// 3. ���
//void display() {
//    if (g_head == NULL) {
//        printf("��� ���� ");
//        return;
//    }
//
//    for (Node* curNode = g_head; curNode != NULL; curNode = curNode->next) {
//        printf("%d  ", curNode->data);
//    }
//}
//
///*------------------- Program -------------------*/
//int main() {
//    char buffer[100] = { 0 };
//    char inputCommand[20];
//    int inputData;
//
//    printf("���α׷��� �����մϴ�. [stop] ����.\n\n");
//    while (true) {
//        // ���� ��� (����Ʈ ���, ��ɾ�)
//        display();
//        printf("[��ɾ�] add ����, del ����\n");
//
//        // ��ɾ� �Է�
//        fgets(buffer, sizeof(buffer), stdin);
//
//        // ��ɾ� ����
//        sscanf(buffer, "%s %d", inputCommand, &inputData);
//
//        // ��ɾ� ����
//        if (strcmp(inputCommand, "add") == 0) { insert(inputData); }
//        else if (strcmp(inputCommand, "del") == 0) { remove(inputData); }
//        else if (strcmp(inputCommand, "stop") == 0) { break; }
//    }
//
//    printf("\n���α׷��� �����մϴ�\n");
//    return 0;
//}
