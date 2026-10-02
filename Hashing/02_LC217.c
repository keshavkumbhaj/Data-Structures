#include <stdio.h>

int main() {
    int nums[100], n;
    int duplicate = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                duplicate = 1;
                break;
            }
        }

        if (duplicate)
            break;
    }

    if (duplicate)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}