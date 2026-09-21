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

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }

        temp = newNode;
    }

    return head;
}

struct Node *mergeLists(struct Node *list1, struct Node *list2) {
    struct Node dummy;
    struct Node *temp = &dummy;

    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }

        temp = temp->next;
    }

    if (list1 != NULL)
        temp->next = list1;
    else
        temp->next = list2;

    return dummy.next;
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int main() {
    int n1, n2;
    struct Node *list1, *list2, *result;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n1);

    printf("Enter elements in sorted order:\n");
    list1 = createList(n1);

    printf("Enter number of nodes in second list: ");
    scanf("%d", &n2);

    printf("Enter elements in sorted order:\n");
    list2 = createList(n2);

    result = mergeLists(list1, list2);

    printf("Merged Linked List:\n");
    display(result);

    return 0;
}