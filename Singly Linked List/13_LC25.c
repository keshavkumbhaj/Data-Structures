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

struct Node *reverseKGroup(struct Node *head, int k) {
    struct Node *current = head;
    int count = 0;

    // Check if k nodes are available
    while (current != NULL && count < k) {
        current = current->next;
        count++;
    }

    if (count < k)
        return head;

    // Reverse k nodes
    current = head;
    struct Node *prev = NULL;
    struct Node *next = NULL;

    count = 0;

    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Recursively reverse remaining groups
    head->next = reverseKGroup(current, k);

    return prev;
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
    int n, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Original Linked List:\n");
    display(head);

    head = reverseKGroup(head, k);

    printf("After reversing in groups of %d:\n", k);
    display(head);

    return 0;
}