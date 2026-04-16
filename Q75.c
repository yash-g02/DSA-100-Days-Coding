#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    int value;
    struct Node* next;
};

#define SIZE 1000

struct Node* hashTable[SIZE];

// Hash function
int hash(int key) {
    if (key < 0) key = -key;
    return key % SIZE;
}

// Insert into hash table
void insert(int key, int value) {
    int index = hash(key);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Search in hash table
int search(int key) {
    int index = hash(key);
    struct Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->key == key)
            return temp->value;
        temp = temp->next;
    }
    return -1;
}

int maxLen(int arr[], int n) {
    int sum = 0, max_length = 0;
    int i;

    // Initialize hash table
    for (i = 0; i < SIZE; i++)
        hashTable[i] = NULL;

    for (i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0)
            max_length = i + 1;

        {
            int prev_index = search(sum);

            if (prev_index != -1) {
                int length = i - prev_index;
                if (length > max_length)
                    max_length = length;
            } else {
                insert(sum, i);
            }
        }
    }

    return max_length;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n));

    return 0;
}
