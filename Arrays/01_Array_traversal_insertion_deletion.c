/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main() {
    int arr[100], n, choice, pos, value, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\n--- Array Operations ---\n");
        printf("1. Traversal\n");
        printf("2. Insertion\n");
        printf("3. Deletion\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Array elements: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 2:
                if (n == 100) {
                    printf("Array is full!\n");
                    break;
                }

                printf("Enter position (1 to %d): ", n + 1);
                scanf("%d", &pos);

                printf("Enter value: ");
                scanf("%d", &value);

                if (pos < 1 || pos > n + 1) {
                    printf("Invalid position!\n");
                    break;
                }

                for (i = n; i >= pos; i--) {
                    arr[i] = arr[i - 1];
                }

                arr[pos - 1] = value;
                n++;

                printf("Element inserted successfully.\n");
                break;

            case 3:
                if (n == 0) {
                    printf("Array is empty!\n");
                    break;
                }

                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &pos);

                if (pos < 1 || pos > n) {
                    printf("Invalid position!\n");
                    break;
                }

                for (i = pos - 1; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }

                n--;

                printf("Element deleted successfully.\n");
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}