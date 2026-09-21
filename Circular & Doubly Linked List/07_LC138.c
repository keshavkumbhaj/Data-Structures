#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

struct Node* copyRandomList(struct Node *head) {
    if (head == NULL)
        return NULL;

    struct Node *curr = head;
    struct Node *newNode;

    /* Step 1: Insert copied nodes after original nodes */
    while (curr != NULL) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->val = curr->val;
        newNode->next = curr->next;
        newNode->random = NULL;

        curr->next = newNode;
        curr = newNode->next;
    }

    /* Step 2: Set random pointers */
    curr = head;

    while (curr != NULL) {
        if (curr->random != NULL)
            curr->next->random = curr->random->next;

        curr = curr->next->next;
    }

    /* Step 3: Separate the copied list */
    curr = head;
    struct Node *copyHead = head->next;

    while (curr != NULL) {
        newNode = curr->next;

        curr->next = newNode->next;

        if (newNode->next != NULL)
            newNode->next = newNode->next->next;
        else
            newNode->next = NULL;

        curr = curr->next;
    }

    return copyHead;
}

void display(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        if (temp->random != NULL)
            printf("Node %d -> Random: %d\n",
                   temp->val, temp->random->val);
        else
            printf("Node %d -> Random: NULL\n", temp->val);

        temp = temp->next;
    }
}

int main() {
    struct Node *head = NULL;
    struct Node *temp, *newNode;
    struct Node *copyHead;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter value: ");
        scanf("%d", &value);

        newNode->val = value;
        newNode->next = NULL;
        newNode->random = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }

    /*
       Example random pointer setup:
       Each node's random pointer can be assigned
       to another node using its position.
    */

    temp = head;

    for (int i = 0; i < n; i++) {
        int position;

        printf("Enter random position for node %d (-1 for NULL): ",
               i + 1);
        scanf("%d", &position);

        if (position >= 0 && position < n) {
            struct Node *randomNode = head;

            for (int j = 0; j < position; j++)
                randomNode = randomNode->next;

            temp->random = randomNode;
        }

        temp = temp->next;
    }

    copyHead = copyRandomList(head);

    printf("\nCopied List:\n");
    display(copyHead);

    return 0;
}