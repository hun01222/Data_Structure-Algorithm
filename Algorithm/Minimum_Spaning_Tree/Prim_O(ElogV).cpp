#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX 10001
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int v, e, a, b, c;
	long long ans=0;
	bool visited[MAX];
	vector<pair<int, int>> graph[MAX];
	priority_queue<pair<int, int>> pq;
	cin >> v >> e;
	for(int i=0; i<e; i++){
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	
	pq.push(make_pair(0, 1));
	while(!pq.empty()){
		int temp_weight=pq.top().first;
		int temp_node=pq.top().second;
		pq.pop();
		
		if(visited[temp_node]) continue;
		visited[temp_node]=true;
		ans-=temp_weight;
		
		for(int i=0; i<graph[temp_node].size(); i++){
			int next_node=graph[temp_node][i].first;
			int next_weight=graph[temp_node][i].second;
			
			pq.push(make_pair(-next_weight, next_node));
		}
	}
	
	cout << ans;
}

//https://gmlwjd9405.github.io/2018/08/28/algorithm-mst.html