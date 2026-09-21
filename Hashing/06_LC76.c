#include <stdio.h>
#include <string.h>

int main() {
    char s[1000], t[1000];

    printf("Enter string s: ");
    scanf("%s", s);

    printf("Enter string t: ");
    scanf("%s", t);

    int sLen = strlen(s);
    int tLen = strlen(t);

    if (tLen > sLen) {
        printf("Minimum Window: \"\"\n");
        return 0;
    }

    int need[256] = {0};
    int window[256] = {0};

    for (int i = 0; i < tLen; i++)
        need[(unsigned char)t[i]]++;

    int left = 0;
    int right = 0;
    int formed = 0;
    int required = tLen;

    int minLen = sLen + 1;
    int minStart = 0;

    while (right < sLen) {
        unsigned char ch = s[right];

        window[ch]++;

        if (need[ch] > 0 && window[ch] <= need[ch])
            formed++;

        while (formed == required) {
            int currentLen = right - left + 1;

            if (currentLen < minLen) {
                minLen = currentLen;
                minStart = left;
            }

            unsigned char leftChar = s[left];

            window[leftChar]--;

            if (need[leftChar] > 0 &&
                window[leftChar] < need[leftChar]) {
                formed--;
            }

            left++;
        }

        right++;
    }

    if (minLen == sLen + 1) {
        printf("Minimum Window: \"\"\n");
    } else {
        printf("Minimum Window: \"");

        for (int i = minStart; i < minStart + minLen; i++)
            printf("%c", s[i]);

        printf("\"\n");
    }

    return 0;
}