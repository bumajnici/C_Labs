#include"my_lib.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char * bookName;
    float price;
    int pagesCount;
    char * language;
    float weight;
    int year;
} Data;

typedef struct Node {
    Data data;
    struct Node * next;
} Node;

char * getNodeData(Node * node);

void printLinkedlist(Node * node);

void insertNodeAtHead(Node ** head, Data data);

void insertNodeAtTail(Node ** head, Data data);

void insertNode(Node ** head, Data data, int position);

int main(void) {
    printDuck(getHeader());

    Node *head = NULL;

    Data book1 = {"Harry Potter and the Philosopher's Stone", 120.0f, 240, "Ukrainian", 0.225f, 2025};
    Data book2 = {"Harry Potter and the Chamber of Secrets", 130.0f, 256, "Ukrainian", 0.234f, 2025};
    Data book3 = {"Harry Potter and the Prisoner of Azkaban", 140.0f, 352, "Ukrainian", 0.250f, 2025};
    Data book4 = {"Harry Potter and the Goblet of Fire", 150.0f, 636, "Ukrainian", 0.310f, 2025};
    Data book5 = {"Harry Potter and the Order of the Phoenix", 160.0f, 816, "Ukrainian", 0.380f, 2025};

    insertNodeAtTail(&head, book1);
    insertNodeAtTail(&head, book2);
    insertNodeAtTail(&head, book3);
    insertNodeAtTail(&head, book4);
    insertNodeAtTail(&head, book5);

    printf("==================== HARRY POTTER BOOK SERIES ====================\n\n");
    printLinkedlist(head);
    printf("\n==================================================================\n");

    Node *current = head;
    Node *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}

char * getNodeData(Node * node) {
    char * bookName = node->data.bookName;
    float price = node->data.price;
    int pagesCount = node->data.pagesCount;
    char * language = node->data.language;
    float weight = node->data.weight;
    int year = node->data.year;

    char * string = (char *)malloc(256 * sizeof(char));

    if (string != NULL) {
        snprintf(string, 256,
                 "Book: %s | Price: %.2f | Pages: %d | Lang: %s | Weight: %.2f | Year: %d",
                 bookName, price, pagesCount, language, weight, year);
    }

    return string;
}

void printLinkedlist(Node * node) {
    char * str;
    while (node != NULL) {
        str = getNodeData(node);
        printf("%s\n", str);
        free(str);
        node = node->next;
    }
}

void insertNodeAtHead(Node ** head, Data data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) return;

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertNodeAtTail(Node ** head, Data data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) return;

    newNode->data=data;
    newNode->next=NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertNode(Node ** head, Data data, int position) {
    if (position == 0) {
        insertNodeAtHead(head, data);
        return;
    }

    Node *temp = *head;
    for (int i = 0; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) return;

    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
}