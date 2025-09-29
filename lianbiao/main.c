#include <stdio.h>
#include <stdlib.h>

// 定义结点结构体
typedef struct Node {
    int data;           // 数据域
    struct Node* next;  // 指针域
} Node;

// 创建新结点
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 头插法：在链表开头插入
void insertHead(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// 尾插法：在链表末尾插入
void insertTail(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {  // 空链表
        *head = newNode;
        return;
    }
    Node* p = *head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
}

// 删除某个值的结点（只删第一个匹配的）
void deleteNode(Node** head, int value) {
    Node* p = *head;
    Node* prev = NULL;

    while (p != NULL && p->data != value) {
        prev = p;
        p = p->next;
    }

    if (p == NULL) {
        printf("未找到 %d\n", value);
        return;
    }

    if (prev == NULL) { // 删除头结点
        *head = p->next;
    } else {
        prev->next = p->next;
    }
    free(p);
}

// 遍历打印链表
void printList(Node* head) {
    Node* p = head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

// 释放链表
void freeList(Node* head) {
    Node* p;
    while (head != NULL) {
        p = head;
        head = head->next;
        free(p);
    }
}

int main() {
    Node* head = NULL;  // 初始为空链表

    // 用尾插法插入
    insertTail(&head, 10);
    insertTail(&head, 20);
    insertTail(&head, 30);
    printf("尾插法建立链表: ");
    printList(head);

    // 用头插法插入
    insertHead(&head, 5);
    insertHead(&head, 1);
    printf("头插法后: ");
    printList(head);

    // 删除结点
    deleteNode(&head, 20);
    printf("删除 20 后: ");
    printList(head);

    // 释放链表
    freeList(head);
    return 0;
}
