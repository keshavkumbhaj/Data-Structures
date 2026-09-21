#include <stdio.h>

int main() {
    int nums[100];
    int n, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    for (i = 1; i < n; i++) {
        nums[i] = nums[i] + nums[i - 1];
    }

    printf("Running sum: ");
    for (i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    printf("\n");

    return 0;
}