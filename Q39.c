#include <stdio.h>
#include <string.h>

#define MAX 100000

int heap[MAX];
int size = 0;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int i)
{
    int parent;
    while (i > 0)
    {
        parent = (i - 1) / 2;
        if (heap[parent] > heap[i])
        {
            swap(&heap[parent], &heap[i]);
            i = parent;
        }
        else
            break;
    }
}

void heapifyDown(int i)
{
    int left, right, smallest;

    while (1)
    {
        left = 2 * i + 1;
        right = 2 * i + 2;
        smallest = i;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i)
        {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        }
        else
            break;
    }
}

void insert(int x)
{
    heap[size] = x;
    heapifyUp(size);
    size++;
}

int extractMin()
{
    int root;

    if (size == 0)
        return -1;

    root = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);

    return root;
}

int peek()
{
    if (size == 0)
        return -1;
    return heap[0];
}

int main()
{
    int n, i, x;
    char op[20];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0)
        {
            scanf("%d", &x);
            insert(x);
        }
        else if (strcmp(op, "extractMin") == 0)
        {
            printf("%d\n", extractMin());
        }
        else if (strcmp(op, "peek") == 0)
        {
            printf("%d\n", peek());
        }
    }

    return 0;
}
