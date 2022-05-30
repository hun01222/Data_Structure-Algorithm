#include<iostream>
#include<algorithm>
#include<memory.h>
#include<vector>
#include<queue>
#define MAX 52
#define INF 1e9
using namespace std;

int n, w, result=0;
char u, v;
int cap[MAX][MAX], flow[MAX][MAX], parent[MAX];
vector<int> path[MAX];

char ctoi(char temp){
	if(temp<='Z')
		return temp-'A';
	return temp-'a'+26;
}

void Ford_Fulkerson(){
	int start=ctoi('A');
	int end=ctoi('Z');
	
	while(1){
		memset(parent, -1, sizeof(parent));
		queue<int> q;
		q.push(start);
		
		while(!q.empty()){
			int curr=q.front();
			q.pop();
			if(curr==end)
				break;
			
			for(int i=0; i<path[curr].size(); i++){
				int next=path[curr][i];
				if(parent[next]==-1&&flow[curr][next]<cap[curr][next]){
					parent[next]=curr;
					q.push(next);
				}
			}
		}
		
		if(parent[end]==-1)
			break;
		
		int amount=INF;
		for(int i=end; i!=start; i=parent[i])
			amount=min(cap[parent[i]][i]-flow[parent[i]][i], amount);
			
		for(int i=end; i!=start; i=parent[i]){
			flow[parent[i]][i]+=amount;
			flow[i][parent[i]]-=amount;
		}
		result+=amount;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> u >> v >> w;
		int U=ctoi(u), V=ctoi(v);
		cap[U][V]+=w;
		cap[V][U]+=w;
		path[U].push_back(V);
		path[V].push_back(U);
	}
	
	Ford_Fulkerson();
	cout << result;
}