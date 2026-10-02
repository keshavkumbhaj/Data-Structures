#include <stdio.h>

int main() {
    int nums[100], n, target;
    int left = 0, right, mid;
    int result = -1;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter rotated sorted array:\n");
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
            break;
        }

        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    printf("Result: %d\n", result);

    return 0;
}