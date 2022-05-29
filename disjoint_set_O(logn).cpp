#include<iostream>
using namespace std;

int parent[10];

int find(int x){
	if(x==parent[x]) return x;
	return parent[x]=find(parent[x]);
}

void Union(int x, int y){
	x=find(x);
	y=find(y);
	
	if(x<y)
		parent[y]=x;
	else
		parent[x]=y;
}

int main(){
	for(int i=1; i<=10; i++)
		parent[i]=i;
	
	int two_parent=find(2);
	
	Union(2, 3);
	Union(3, 1);
	
	int new_two_parent=find(2);
	cout << two_parent << ' ' << new_two_parent;
}