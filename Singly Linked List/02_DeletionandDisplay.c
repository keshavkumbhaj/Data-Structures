#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *temp, *newNode;
    int n, coefficient, exponent;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coefficient, &exponent);

        newNode->coefficient = coefficient;
        newNode->exponent = exponent;
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

    printf("Polynomial: ");

    temp = head;

    while (temp != NULL) {
        printf("%dx^%d", temp->coefficient, temp->exponent);

        if (temp->next != NULL) {
            printf(" + ");
        }

        temp = temp->next;
    }

    printf("\n");

    return 0;
}