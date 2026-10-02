#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *temp, *newNode, *prev;
    int n, value, deleteValue;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter value: ");
        scanf("%d", &value);

        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            temp = head;

            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
    }

    printf("Enter value to delete: ");
    scanf("%d", &deleteValue);

    if (head == NULL) {
        printf("List is empty.\n");
        return 0;
    }

    temp = head;
    prev = NULL;

    // Delete head node
    if (head->data == deleteValue) {
        while (temp->next != head) {
            temp = temp->next;
        }

        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            struct Node *deleteNode = head;
            head = head->next;
            temp->next = head;
            free(deleteNode);
        }
    } else {
        temp = head;

        while (temp->next != head &&
               temp->next->data != deleteValue) {
            temp = temp->next;
        }

        if (temp->next == head) {
            printf("Element not found.\n");
        } else {
            struct Node *deleteNode = temp->next;
            temp->next = deleteNode->next;
            free(deleteNode);
        }
    }

    printf("Circular Linked List after deletion:\n");

    if (head != NULL) {
        temp = head;

        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);

        printf("HEAD\n");
    } else {
        printf("List is empty.\n");
    }

    return 0;
}