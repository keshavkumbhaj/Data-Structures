#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char words[100][100];

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter strings:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    printf("\nAnagram Groups:\n");

    int used[100] = {0};

    for (int i = 0; i < n; i++) {
        if (used[i])
            continue;

        printf("[ %s", words[i]);
        used[i] = 1;

        for (int j = i + 1; j < n; j++) {
            if (used[j])
                continue;

            int count1[26] = {0};
            int count2[26] = {0};

            for (int k = 0; words[i][k] != '\0'; k++)
                count1[words[i][k] - 'a']++;

            for (int k = 0; words[j][k] != '\0'; k++)
                count2[words[j][k] - 'a']++;

            int isAnagram = 1;

            for (int k = 0; k < 26; k++) {
                if (count1[k] != count2[k]) {
                    isAnagram = 0;
                    break;
                }
            }

            if (isAnagram) {
                printf(", %s", words[j]);
                used[j] = 1;
            }
        }

        printf(" ]\n");
    }

    return 0;
}