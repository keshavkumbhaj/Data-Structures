#include <stdio.h>

int main() {
    int nums[100], n;
    int low = 0, mid = 0, high;
    int temp;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements (0, 1, 2):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    high = n - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;

            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else {
            temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;

            high--;
        }
    }

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}