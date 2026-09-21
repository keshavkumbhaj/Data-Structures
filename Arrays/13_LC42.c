#include <stdio.h>

int main() {
    int height[100], n;
    int left = 0, right;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter heights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }

    right = n - 1;

    while (left < right) {
        if (height[left] <= height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                water += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                water += rightMax - height[right];
            }
            right--;
        }
    }

    printf("Trapped Rain Water: %d\n", water);

    return 0;
}