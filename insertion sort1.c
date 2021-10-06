#include <stdio.h>
#define SWAP(a,b)  {int t; t = a; a=b; b=t;}
 
void InsertionSort(int *base, int n);
void ViewArr(int *arr, int n);

int main(void){
    int arr[10] = { 9,4,3,10,5,8,7,6,2,1 };
    InsertionSort(arr, 10);
    return 0;
}

void InsertionSort(int *base, int n){
    int i, j;
    ViewArr(base, n);
    for (i = 1; i<n; i++){
        for (j = i; j>0; j--){
            if (base[j - 1]>base[j]){
                SWAP(base[j - 1], base[j]);
                ViewArr(base, n);
            }
            else
                break;
        }
    }
}

void ViewArr(int *arr, int n){
    for(int i = 0; i<n; i++)
        printf("%3d ", arr[i]);
    printf("\n");
}