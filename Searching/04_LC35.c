#include <stdio.h>

int main() {
    int nums[100], n, target;
    int left = 0, right, mid;
    int result;

    printf("Enter size of sorted array: ");
    scanf("%d", &n);

    printf("Enter elements in sorted order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter target element: ");
    scanf("%d", &target);

    right = n - 1;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result = mid;
            printf("Insert position: %d\n", result);
            return 0;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    result = left;

    printf("Insert position: %d\n", result);

    return 0;
}