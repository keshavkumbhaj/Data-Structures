#include <stdio.h>

int main() {
    int nums[100], ans[100];
    int n, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter permutation array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    for (i = 0; i < n; i++) {
        ans[i] = nums[nums[i]];
    }

    printf("Result: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }

    printf("\n");

    return 0;
}