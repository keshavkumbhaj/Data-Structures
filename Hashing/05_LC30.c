#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    char words[50][50];
    int n;

    printf("Enter string: ");
    scanf("%s", s);

    printf("Enter number of words: ");
    scanf("%d", &n);

    printf("Enter words:\n");
    for (int i = 0; i < n; i++)
        scanf("%s", words[i]);

    int wordLen = strlen(words[0]);
    int totalLen = wordLen * n;
    int sLen = strlen(s);

    printf("Starting indices: ");

    for (int i = 0; i <= sLen - totalLen; i++) {
        int used[50] = {0};
        int found = 1;

        for (int j = 0; j < n; j++) {
            char current[50];

            strncpy(current, s + i + j * wordLen, wordLen);
            current[wordLen] = '\0';

            int matched = 0;

            for (int k = 0; k < n; k++) {
                if (!used[k] && strcmp(current, words[k]) == 0) {
                    used[k] = 1;
                    matched = 1;
                    break;
                }
            }

            if (!matched) {
                found = 0;
                break;
            }
        }

        if (found)
            printf("%d ", i);
    }

    printf("\n");

    return 0;
}