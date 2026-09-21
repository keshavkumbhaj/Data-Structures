#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* getIntersectionNode(struct Node *headA, struct Node *headB) {
    struct Node *p = headA;
    struct Node *q = headB;

    while (p != q) {
        p = (p == NULL) ? headB : p->next;
        q = (q == NULL) ? headA : q->next;
    }

    return p;
}

int main() {
    struct Node *headA = NULL, *headB = NULL;
    struct Node *temp, *newNode;
    struct Node *intersection;
    int n1, n2, value;

    printf("Enter number of nodes in List A: ");
    scanf("%d", &n1);

    for (int i = 0; i < n1; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter value: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (headA == NULL)
            headA = newNode;
        else {
            temp = headA;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    printf("Enter number of nodes in List B: ");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter value: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (headB == NULL)
            headB = newNode;
        else {
            temp = headB;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    /*
       For an actual intersection, both lists must share
       the same node address. This can be created by
       connecting the last node of List B to a node of List A.
    */

    intersection = headA;

    if (intersection != NULL) {
        temp = headB;

        if (temp != NULL) {
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = intersection;
        }
    }

    intersection = getIntersectionNode(headA, headB);

    if (intersection != NULL)
        printf("Intersection Node: %d\n", intersection->data);
    else
        printf("No intersection.\n");

    return 0;
}