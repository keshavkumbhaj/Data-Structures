#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node *next;
};

void insert(struct Node **head, int coefficient, int exponent) {
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        temp = *head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

struct Node *addPolynomials(struct Node *p1, struct Node *p2) {
    struct Node *result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exponent == p2->exponent) {
            insert(&result,
                   p1->coefficient + p2->coefficient,
                   p1->exponent);

            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exponent > p2->exponent) {
            insert(&result, p1->coefficient, p1->exponent);
            p1 = p1->next;
        }
        else {
            insert(&result, p2->coefficient, p2->exponent);
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        insert(&result, p1->coefficient, p1->exponent);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insert(&result, p2->coefficient, p2->exponent);
        p2 = p2->next;
    }

    return result;
}

void display(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%dx^%d", temp->coefficient, temp->exponent);

        if (temp->next != NULL) {
            printf(" + ");
        }

        temp = temp->next;
    }

    printf("\n");
}

int main() {
    struct Node *p1 = NULL;
    struct Node *p2 = NULL;
    struct Node *result;

    int n1, n2;
    int coefficient, exponent;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);

    printf("Enter coefficient and exponent:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d %d", &coefficient, &exponent);
        insert(&p1, coefficient, exponent);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);

    printf("Enter coefficient and exponent:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d %d", &coefficient, &exponent);
        insert(&p2, coefficient, exponent);
    }

    result = addPolynomials(p1, p2);

    printf("First Polynomial: ");
    display(p1);

    printf("Second Polynomial: ");
    display(p2);

    printf("Sum: ");
    display(result);

    return 0;
}