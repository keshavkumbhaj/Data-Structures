#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *prev;
    struct Node *next;
    struct Node *child;
};

struct Node* flatten(struct Node *head) {
    if (head == NULL)
        return NULL;

    struct Node *curr = head;

    while (curr != NULL) {
        if (curr->child != NULL) {
            struct Node *nextNode = curr->next;
            struct Node *childNode = curr->child;

            curr->next = childNode;
            childNode->prev = curr;
            curr->child = NULL;

            struct Node *temp = childNode;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = nextNode;

            if (nextNode != NULL)
                nextNode->prev = temp;
        }

        curr = curr->next;
    }

    return head;
}

void display(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    struct Node *head = NULL;
    struct Node *temp, *newNode;
    int n, value;

    printf("Enter number of main-level nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter value: ");
        scanf("%d", &value);

        newNode->val = value;
        newNode->prev = NULL;
        newNode->next = NULL;
        newNode->child = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    /*
       Example:
       Attach a child list to a selected node.
    */

    int position, childValue;

    printf("Enter position to attach child (-1 for none): ");
    scanf("%d", &position);

    if (position >= 0 && position < n) {
        struct Node *parent = head;

        for (int i = 0; i < position; i++)
            parent = parent->next;

        printf("Enter child value: ");
        scanf("%d", &childValue);

        newNode = (struct Node *)malloc(sizeof(struct Node));

        newNode->val = childValue;
        newNode->prev = NULL;
        newNode->next = NULL;
        newNode->child = NULL;

        parent->child = newNode;
    }

    head = flatten(head);

    printf("Flattened List: ");
    display(head);

    return 0;
}