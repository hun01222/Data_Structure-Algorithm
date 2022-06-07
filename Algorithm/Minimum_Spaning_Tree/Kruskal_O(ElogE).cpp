#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#define MAX 10001
using namespace std;

int parent[MAX];
bool check;

int find(int x){
	if(x==parent[x]) return x;
	return parent[x]=find(parent[x]);
}

void Union(int x, int y){
	check=false;
	
	x=find(x);
	y=find(y);
	
	if(x==y)
		return;
	else{
		parent[x]=y;
		check=true;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int v, e, a, b, c;
	long long ans=0;
	vector<tuple<int, int, int>> graph;
	cin >> v >> e;
	for(int i=0; i<e; i++){
		cin >> a >> b >> c;
		graph.push_back(make_tuple(c, a, b));
	}
	sort(graph.begin(), graph.end());
	
	for(int i=1; i<=v; i++)
		parent[i]=i;
	
	for(int i=0; i<e; i++){
		Union(get<1>(graph[i]), get<2>(graph[i]));
		if(check)
			ans+=get<0>(graph[i]);
	}
	
	cout << ans;
}