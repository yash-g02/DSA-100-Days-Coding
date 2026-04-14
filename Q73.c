#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int freq[26] = {0};
    int i, len;

    // Input string
    scanf("%s", s);

    len = strlen(s);

    // Count frequency
    for (i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }

    // Find first non-repeating character
    for (i = 0; i < len; i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    // If none found
    printf("$\n");

    return 0;
}
