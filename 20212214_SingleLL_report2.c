#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    char phone[20];
    struct Node* next;
} Node;

Node* addContact(Node* head, char* name, char* phone) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = NULL;

    if (head == NULL) return newNode;

    Node* current = head;
    while (current->next != NULL) current = current->next;
    current->next = newNode;
    return head;
}

void searchContact(Node* head, char* name) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("[%s]의 전화번호: %s\n", current->name, current->phone);
            return;
        }
        current = current->next;
    }
    printf("[%s]님을 찾을 수 없습니다.\n", name);
}

Node* deleteContact(Node* head, char* name) {
    if (head == NULL) return NULL;

    if (strcmp(head->name, name) == 0) {
        Node* temp = head->next;
        free(head);
        return temp;
    }

    Node* current = head;
    while (current->next != NULL && strcmp(current->next->name, name) != 0) {
        current = current->next;
    }

    if (current->next != NULL) {
        Node* temp = current->next;
        current->next = temp->next;
        free(temp);
        printf("[%s] 연락처가 삭제되었습니다.\n", name);
    } else {
        printf("[%s] 삭제할 이름을 찾지 못했습니다.\n", name);
    }
    return head;
}

void printPhoneBook(Node* head) {
    Node* current = head;
    printf("\n=== 현재 전화번호부 목록 ===\n");
    if (current == NULL) printf("비어 있음\n");
    while (current != NULL) {
        printf("이름: %s | 번호: %s\n", current->name, current->phone);
        current = current->next;
    }
    printf("============================\n");
}

void freePhoneBook(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    head = addContact(head, "aaa", "010-1234-5678");
    head = addContact(head, "bbb", "010-1111-2222");
    head = addContact(head, "ccc", "010-9999-8888");

    printPhoneBook(head);

    searchContact(head, "aaa");
    searchContact(head, "ddd");

    head = deleteContact(head, "aaa");
    
    printPhoneBook(head);

    freePhoneBook(head);

    return 0;
}
