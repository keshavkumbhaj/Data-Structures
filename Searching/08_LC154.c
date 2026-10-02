#include <stdio.h>

int main() {
    int nums[100], n;
    int left = 0, right, mid;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter rotated sorted array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    right = n - 1;

    while (left < right) {
        mid = left + (right - left) / 2;

        if (nums[mid] < nums[right]) {
            right = mid;
        }
        else if (nums[mid] > nums[right]) {
            left = mid + 1;
        }
        else {
            right--;
        }
    }

    printf("Minimum element: %d\n", nums[left]);

    return 0;
}