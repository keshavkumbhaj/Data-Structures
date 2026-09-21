#include <stdio.h>

void merge(int arr[][2], int temp[][2], int count[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j][0] < arr[i][0]) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            count[arr[i][1]] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i][1]] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i][0] = temp[i][0];
        arr[i][1] = temp[i][1];
    }
}

void mergeSort(int arr[][2], int temp[][2], int count[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, temp, count, left, mid);
    mergeSort(arr, temp, count, mid + 1, right);
    merge(arr, temp, count, left, mid, right);
}

int main() {
    int nums[100], n;
    int arr[100][2], temp[100][2];
    int count[100] = {0};

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);

        arr[i][0] = nums[i];
        arr[i][1] = i;
    }

    mergeSort(arr, temp, count, 0, n - 1);

    printf("Count of smaller numbers after self:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}