#include <stdio.h>

int isMinHeap(int arr[], int n) {
    int i;
    for (i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[i] > arr[left])
            return 0;

        if (right < n && arr[i] > arr[right])
            return 0;
    }
    return 1;
}

int main() {
    int n, i;
    scanf("%d", &n);

    int arr[1000];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isMinHeap(arr, n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
