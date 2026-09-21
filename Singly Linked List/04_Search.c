#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *temp;
    struct Node *newNode;
    int n, value, target, position = 1;
    int found = 0;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter value: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    printf("Enter element to search: ");
    scanf("%d", &target);

    temp = head;

    while (temp != NULL) {
        if (temp->data == target) {
            found = 1;
            break;
        }

        temp = temp->next;
        position++;
    }

    if (found) {
        printf("Element found at position %d\n", position);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}