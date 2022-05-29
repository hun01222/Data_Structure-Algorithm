#include<iostream>
#include<algorithm>
#define max 101
using namespace std;

int n;
int graph[max][max]={0, };

void floyd_warshall(){
	for(int via=1; via<=n; via++){
		for(int from=1; from<=n; from++){
			if(!graph[from][via])
				continue;
			for(int to=1; to<=n; to++){
				if(!graph[via][to]||from==to)
					continue;
				if(!graph[from][to]||(graph[from][to]>graph[from][via]+graph[via][to]))
					graph[from][to]=graph[from][via]+graph[via][to];
			}
		}
	}
}

int main(){
	int m;
	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		int from, to, cost;
		cin >> from >> to >> cost;
		
		if(!graph[from][to])
			graph[from][to]=cost;
		else
			graph[from][to]=min(graph[from][to], cost); // 이미 경로가 있는 경우
	}
	
	floyd_warshall();
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)
			cout << graph[i][j] << ' ';
		cout << "\n";
	}
}