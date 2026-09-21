#include <stdio.h>

int main() {
    int nums[100], n, i, j, temp;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Place each positive number at its correct index
    for (i = 0; i < n; i++) {
        while (nums[i] > 0 && nums[i] <= n &&
               nums[nums[i] - 1] != nums[i]) {

            j = nums[i] - 1;

            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }

    // Find the first index with an incorrect value
    for (i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            printf("First missing positive: %d\n", i + 1);
            return 0;
        }
    }

    printf("First missing positive: %d\n", n + 1);

    return 0;
}
