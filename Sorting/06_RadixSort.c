#include <stdio.h>

int getMax(int arr[], int n) {
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

void countingSort(int arr[], int n, int place) {
    int output[100];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / place) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(arr, n, place);
    }
}

int main() {
    int arr[100], n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter non-negative integers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    radixSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}