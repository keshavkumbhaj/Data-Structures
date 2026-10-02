#include <stdio.h>

int main() {
    int a[100], b[100], merged[200];
    int n, m, i = 0, j = 0, k = 0;
    double median;

    printf("Enter size of first sorted array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int x = 0; x < n; x++) {
        scanf("%d", &a[x]);
    }

    printf("Enter size of second sorted array: ");
    scanf("%d", &m);

    printf("Enter elements:\n");
    for (int x = 0; x < m; x++) {
        scanf("%d", &b[x]);
    }

    // Merge the two sorted arrays
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            merged[k++] = a[i++];
        } else {
            merged[k++] = b[j++];
        }
    }

    while (i < n) {
        merged[k++] = a[i++];
    }

    while (j < m) {
        merged[k++] = b[j++];
    }

    // Find median
    if (k % 2 == 0) {
        median = (merged[k / 2 - 1] + merged[k / 2]) / 2.0;
    } else {
        median = merged[k / 2];
    }

    printf("Median: %.2f\n", median);

    return 0;
}