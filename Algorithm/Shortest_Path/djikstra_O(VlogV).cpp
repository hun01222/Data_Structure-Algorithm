#include<iostream>
#include<vector>
#include<queue>
#define max 1000001
#define INF 1e9
using namespace std;

vector<pair<int, int>> graph[max];
int V, E, start;
bool visited[max];
int dist[max];

void dijkstra(int start){
    priority_queue<pair<int, int>>pq;

    pq.push({0, start});
    dist[start]=0;

    while(!pq.empty()){
        int d=-pq.top().first;
        int curr=pq.top().second;
        pq.pop();

        if(dist[curr]<d)
            continue;

        for(int i=0; i<graph[curr].size(); i++){
            int cost=d+graph[curr][i].second;
            if(cost<dist[graph[curr][i].first]){
                dist[graph[curr][i].first]=cost;
                pq.push({-cost, graph[curr][i].first});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E >> start;

    for(int i=0; i<E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    fill_n(dist, max, INF);

    dijkstra(start);

    for(int i=1; i<=V; i++){
        if(dist[i]==INF)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
}