#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *temp, *newNode, *deleteNode;
    int n, value, deleteValue;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter value: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    printf("Enter value to delete: ");
    scanf("%d", &deleteValue);

    temp = head;

    while (temp != NULL && temp->data != deleteValue) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found.\n");
    } else {
        deleteNode = temp;

        if (deleteNode->prev != NULL)
            deleteNode->prev->next = deleteNode->next;
        else
            head = deleteNode->next;

        if (deleteNode->next != NULL)
            deleteNode->next->prev = deleteNode->prev;

        free(deleteNode);
    }

    printf("Doubly Linked List after deletion:\n");

    temp = head;

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return 0;
}