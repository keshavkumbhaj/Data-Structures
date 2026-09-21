#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createList(int n) {
    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newNode;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter value: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }

        temp = newNode;
    }

    return head;
}

struct Node *swapPairs(struct Node *head) {
    struct Node dummy;
    struct Node *prev = &dummy;

    dummy.next = head;

    while (prev->next != NULL && prev->next->next != NULL) {
        struct Node *first = prev->next;
        struct Node *second = first->next;

        first->next = second->next;
        second->next = first;
        prev->next = second;

        prev = first;
    }

    return dummy.next;
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *head;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    printf("Original Linked List:\n");
    display(head);

    head = swapPairs(head);

    printf("After Swapping Pairs:\n");
    display(head);

    return 0;
}