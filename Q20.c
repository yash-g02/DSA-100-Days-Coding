#include <stdio.h>
#include <stdlib.h>

#define MAX 200000

typedef struct {
    int key;
    int count;
} Hash;

Hash hashTable[MAX];

int hashIndex(int key) {
    return abs(key) % MAX;
}

int find(int key) {
    int idx = hashIndex(key);
    while (hashTable[idx].count != 0 && hashTable[idx].key != key) {
        idx = (idx + 1) % MAX;
    }
    return idx;
}

int main() {
    int n, i;
    scanf("%d", &n);

    int arr[100000];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long prefixSum = 0, result = 0;

    int idx = find(0);
    hashTable[idx].key = 0;
    hashTable[idx].count = 1;

    for (i = 0; i < n; i++) {
        prefixSum += arr[i];

        idx = find(prefixSum);

        result += hashTable[idx].count;

        hashTable[idx].key = prefixSum;
        hashTable[idx].count++;
    }

    printf("%lld\n", result);
    return 0;
}
