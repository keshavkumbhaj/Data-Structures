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

        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }

    return head;
}

struct Node *mergeTwoLists(struct Node *a, struct Node *b) {
    struct Node dummy;
    struct Node *temp = &dummy;

    dummy.next = NULL;

    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            temp->next = a;
            a = a->next;
        } else {
            temp->next = b;
            b = b->next;
        }

        temp = temp->next;
    }

    if (a != NULL)
        temp->next = a;
    else
        temp->next = b;

    return dummy.next;
}

int main() {
    struct Node *lists[100];
    struct Node *result = NULL;
    int k, n;

    printf("Enter number of sorted linked lists: ");
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        printf("Enter number of nodes in list %d: ", i + 1);
        scanf("%d", &n);

        printf("Enter elements in sorted order:\n");
        lists[i] = createList(n);
    }

    for (int i = 0; i < k; i++) {
        result = mergeTwoLists(result, lists[i]);
    }

    printf("Merged Linked List:\n");

    while (result != NULL) {
        printf("%d -> ", result->data);
        result = result->next;
    }

    printf("NULL\n");

    return 0;
}