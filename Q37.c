#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int index)
{
    int parent = (index - 1) / 2;

    while (index > 0 && heap[index] < heap[parent])
    {
        swap(&heap[index], &heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void heapifyDown(int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index)
    {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void insert(int value)
{
    heap[size] = value;
    heapifyUp(size);
    size++;
}

void deleteMin()
{
    if (size == 0)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

void peek()
{
    if (size == 0)
        printf("-1\n");
    else
        printf("%d\n", heap[0]);
}

int main()
{
    int n, i, x;
    char op[10];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%s", op);

        if (op[0] == 'i')  // insert
        {
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'd')  // delete
        {
            deleteMin();
        }
        else if (op[0] == 'p')  // peek
        {
            peek();
        }
    }

    return 0;
}
