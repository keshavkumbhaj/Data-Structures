#include <stdio.h>

void sortIntervals(int intervals[][2], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (intervals[j][0] > intervals[j + 1][0]) {
                temp = intervals[j][0];
                intervals[j][0] = intervals[j + 1][0];
                intervals[j + 1][0] = temp;

                temp = intervals[j][1];
                intervals[j][1] = intervals[j + 1][1];
                intervals[j + 1][1] = temp;
            }
        }
    }
}

int main() {
    int intervals[100][2];
    int n, i, start, end;
    int result[100][2];
    int count = 0;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    printf("Enter intervals:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    // Sort intervals by starting time
    sortIntervals(intervals, n);

    start = intervals[0][0];
    end = intervals[0][1];

    for (i = 1; i < n; i++) {
        if (intervals[i][0] <= end) {
            if (intervals[i][1] > end) {
                end = intervals[i][1];
            }
        } else {
            result[count][0] = start;
            result[count][1] = end;
            count++;

            start = intervals[i][0];
            end = intervals[i][1];
        }
    }

    result[count][0] = start;
    result[count][1] = end;
    count++;

    printf("Merged intervals:\n");
    for (i = 0; i < count; i++) {
        printf("[%d, %d] ", result[i][0], result[i][1]);
    }

    printf("\n");

    return 0;
}
