#include<stdio.h>

void InsertionSort(int *base,int n);
void ViewArr(int *base,int n);

int main(){
    int arr[10]={9,4,3,10,5,8,7,6,2,1};
    InsertionSort(arr,10);
    return 0;
}

void InsertionSort(int *base,int n){
    int temp,cnt;
    ViewArr(base,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(base[i]<=base[j]){
                temp=base[i];
                for(int cnt=i;j<cnt;cnt--)
                    base[cnt]=base[cnt-1];
                base[j]=temp;
                ViewArr(base,n);
            }
        }
    }
}

void ViewArr(int *base, int n){
    for(int i=0;i<n;i++)
        printf("%3d",base[i]);
    printf("\n");
}