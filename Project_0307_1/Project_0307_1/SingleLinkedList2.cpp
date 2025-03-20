//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
///*---- C언어 단순연결리스트 - 삽입, 삭제, 출력 ----*/
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
//// 1. 삽입
//void insert(int value) {
//    Node* node = (Node*)malloc(sizeof(Node));
//    node->data = value;
//    node->next = g_head;
//    g_head = node;
//}
//
//// 2. 삭제
//// 연결리스트는 다른 메모리에 동적할당된 노드들을 포인터로 연결하는 것이므로, 이전노드와 후속노드를 연결하면 된다.
//void remove(int inputData) {
//    Node* preNode = NULL;
//
//    for (Node* curNode = g_head; curNode != NULL; curNode = curNode->next) {
//        if (curNode->data == inputData) {
//            // (1) 삭제할 노드가 첫번째 노드일 경우
//            if (preNode == NULL) { g_head = curNode->next; }
//            // (2) 이외의 경우
//            else { preNode->next = curNode->next; }
//
//            free(curNode);
//            return;
//        }
//        preNode = curNode;
//    }
//}
//
//// 3. 출력
//void display() {
//    if (g_head == NULL) {
//        printf("목록 없음 ");
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
//    printf("프로그램을 실행합니다. [stop] 종료.\n\n");
//    while (true) {
//        // 정보 출력 (리스트 목록, 명령어)
//        display();
//        printf("[명령어] add 숫자, del 숫자\n");
//
//        // 명령어 입력
//        fgets(buffer, sizeof(buffer), stdin);
//
//        // 명령어 저장
//        sscanf(buffer, "%s %d", inputCommand, &inputData);
//
//        // 명령어 실행
//        if (strcmp(inputCommand, "add") == 0) { insert(inputData); }
//        else if (strcmp(inputCommand, "del") == 0) { remove(inputData); }
//        else if (strcmp(inputCommand, "stop") == 0) { break; }
//    }
//
//    printf("\n프로그램을 종료합니다\n");
//    return 0;
//}
