#include<iostream>
#define HEAP_SIZE 256
#define ARRAY_SIZE 10
using namespace std;

int heap[HEAP_SIZE];
int heapCount=0;

void push(int x){
    heap[++heapCount]=x;
    
    int child=heapCount;
    int parent=child/2;

    while(child!=1&&heap[child]>heap[parent]){
        swap(heap[child], heap[parent]);
        child=parent;
        parent=child/2;
    }
}

int pop(){
    int ret=heap[1];

    swap(heap[1], heap[heapCount]);
    heapCount--;

    int parent=1;
    int child=parent*2;

    if(child+1<=heapCount)
        child=(heap[child]>heap[child+1])?child:child+1;

    while(child<=heapCount&&heap[child]>heap[parent]){
        swap(heap[child], heap[parent]);
        parent=child;
        child=parent*2;

        if(child+1<=heapCount)
            child=(heap[child]>heap[child+1])?child:child+1;
    }
    return ret;
}

int main(){
    int a[ARRAY_SIZE]={5 ,6 ,3, 7, 9, 8, 1, 2, 4, 10};
    
    cout << "Push: ";
    for(int i=0; i<ARRAY_SIZE; i++){
        cout << a[i] << " ";
        push(a[i]);
    }
    cout << "\n";

    for(int i=0; i<ARRAY_SIZE; i++)
        cout << a[i] << " ";
    cout << "\n";

    cout << "Pop: ";
    for(int i=0; i<ARRAY_SIZE; i++)
        cout << pop() << " ";
    cout << "\n";
}