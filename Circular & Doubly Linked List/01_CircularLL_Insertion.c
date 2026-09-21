#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *temp, *newNode;
    int n, value;

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

    printf("Circular Linked List:\n");

    if (head != NULL) {
        temp = head;

        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);

        printf("HEAD\n");
    }

    return 0;
}