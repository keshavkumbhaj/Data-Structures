#include <stdio.h>

int main() {
    int nums[100], result[100];
    int n, i, prefix = 1, suffix = 1;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Product of all elements to the left
    for (i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    // Product of all elements to the right
    for (i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    printf("Product of array except self:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");

    return 0;
}