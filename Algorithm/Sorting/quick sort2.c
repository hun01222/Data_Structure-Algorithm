#include <stdio.h>
#define SWAP(a, b) \
    {              \
        int t;     \
        t = a;     \
        a = b;     \
        b = t;     \
    }

int *origin;

void QuickSort(int *base, int n);
void ViewArr(int *arr, int n);
void PrintSpace(int n);

int main(void)
{
    int arr[10] = {9, 4, 3, 10, 5, 8, 7, 6, 2, 1};
    origin = arr;
    QuickSort(arr, 10);
    ViewArr(arr, 10);
    return 0;
}

void QuickSort(int *base, int n)
{
    int pivot = 0;
    int left = 0, right = n;

    if (n <= 1)
    {
        return;
    }

    while (1)
    {
        for (left++; (left < n) && (base[0] >= base[left]); left++)
            ;
        for (right--; (right > 0) && (base[0] < base[right]); right--)
            ;
        if (left < right)
        {
            SWAP(base[left], base[right]);
        }
        else
        {
            break;
        }
    }
    SWAP(base[0], base[right]);

    QuickSort(base, right);
    QuickSort(base + left, n - left);
}

void ViewArr(int *arr, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%2d ", arr[i]);
    }
    printf("\n");
}