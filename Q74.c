#include <stdio.h>
#include <string.h>

#define MAX 1000
#define NAME_LEN 100

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][NAME_LEN];
    char unique[MAX][NAME_LEN];
    int count[MAX] = {0};
    int uniqueCount = 0;

    int i, j; // declare here (important for C90)

    // Read names
    for (i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    // Count votes
    for (i = 0; i < n; i++) {
        int found = -1;

        for (j = 0; j < uniqueCount; j++) {
            if (strcmp(names[i], unique[j]) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            count[found]++;
        } else {
            strcpy(unique[uniqueCount], names[i]);
            count[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    // Find winner
    int maxVotes = 0;
    char winner[NAME_LEN] = "";

    for (i = 0; i < uniqueCount; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        } 
        else if (count[i] == maxVotes) {
            if (strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    // Output result
    printf("%s %d\n", winner, maxVotes);

    return 0;
}
