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

struct Node *removeNthFromEnd(struct Node *head, int n) {
    struct Node dummy;
    struct Node *first = &dummy;
    struct Node *second = &dummy;

    dummy.next = head;

    for (int i = 0; i <= n; i++) {
        first = first->next;
    }

    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    struct Node *temp = second->next;
    second->next = temp->next;
    free(temp);

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
    int n, removePosition;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    printf("Enter N (node to remove from end): ");
    scanf("%d", &removePosition);

    head = removeNthFromEnd(head, removePosition);

    printf("Linked List after deletion:\n");
    display(head);

    return 0;
}