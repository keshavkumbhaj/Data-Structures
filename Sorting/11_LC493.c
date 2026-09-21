#include <stdio.h>

long long mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;
    long long count = 0;

    count += mergeSort(arr, left, mid);
    count += mergeSort(arr, mid + 1, right);

    int j = mid + 1;

    for (int i = left; i <= mid; i++) {
        while (j <= right && (long long)arr[i] > 2LL * arr[j]) {
            j++;
        }
        count += j - (mid + 1);
    }

    int temp[100];
    int i = left;
    j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];

    return count;
}

int main() {
    int arr[100], n;
    long long result;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    result = mergeSort(arr, 0, n - 1);

    printf("Number of reverse pairs: %lld\n", result);

    return 0;
}