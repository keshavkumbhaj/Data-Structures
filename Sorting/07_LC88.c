#include <stdio.h>

int main() {
    int nums1[200], nums2[100];
    int m, n;
    int i, j, k;

    printf("Enter number of elements in nums1: ");
    scanf("%d", &m);

    printf("Enter elements of nums1 in sorted order:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    printf("Enter number of elements in nums2: ");
    scanf("%d", &n);

    printf("Enter elements of nums2 in sorted order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    i = m - 1;
    j = n - 1;
    k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }

    printf("Merged array:\n");
    for (i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }

    return 0;
}