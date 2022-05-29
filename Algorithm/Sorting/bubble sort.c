#include<stdio.h>
#define SWAP(a,b){int t; t=a; a=b; b=t;}

void BubbleSort(int *base,int n);
void ViewArr(int *base,int n);

int main(){
    int arr[10]={9,4,3,10,5,8,7,6,2,1};
    BubbleSort(arr,10);
    return 0;
}

void BubbleSort(int *base,int n){
    ViewArr(base,n);
    for(int i=n;i>1;i--){
        for(int j=1;j<i;j++){
            if(base[j-1]>base[j]){
                SWAP(base[j-1],base[j]);
                ViewArr(base,n);
            }
        }
    }
}

void ViewArr(int *base,int n){
    for(int i=0;i<n;i++)
        printf("%3d",base[i]);
    printf("\n");
}
