#include <stdio.h>

int main() {
    int nums[100], n, k;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    int used[100] = {0};
    int values[100];
    int frequency[100];
    int count = 0;

    for (int i = 0; i < n; i++) {
        int already = 0;

        for (int j = 0; j < count; j++) {
            if (values[j] == nums[i]) {
                frequency[j]++;
                already = 1;
                break;
            }
        }

        if (!already) {
            values[count] = nums[i];
            frequency[count] = 1;
            count++;
        }
    }

    /* Sort by frequency in descending order */
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (frequency[i] < frequency[j]) {
                int temp = frequency[i];
                frequency[i] = frequency[j];
                frequency[j] = temp;

                temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }

    printf("Top %d frequent elements: ", k);

    for (int i = 0; i < k && i < count; i++)
        printf("%d ", values[i]);

    printf("\n");

    return 0;
}
