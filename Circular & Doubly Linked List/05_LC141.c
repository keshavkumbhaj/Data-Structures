#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *temp, *newNode;
    struct Node *slow, *fast;
    int n, value, position;

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

    printf("Enter position to create cycle (-1 for no cycle): ");
    scanf("%d", &position);

    if (position >= 0 && position < n) {
        struct Node *cycleNode = head;

        for (int i = 0; i < position; i++) {
            cycleNode = cycleNode->next;
        }

        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = cycleNode;
    }

    slow = head;
    fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            printf("Cycle detected.\n");
            return 0;
        }
    }

    printf("No cycle detected.\n");

    return 0;
}