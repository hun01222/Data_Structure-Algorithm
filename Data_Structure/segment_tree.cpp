#include<iostream>
#include<cmath>
#include<vector>
typedef long long ll;
using namespace std;

ll init(vector<ll> &a, vector<ll> &tree, int node, int start, int end){
	if(start==end)
		return tree[node]=a[start]; // leaf node 인 경우
	else
		return tree[node]=init(a, tree, node*2, start, (start+end)/2)+init(a, tree, node*2+1, (start+end)/2+1, end);
}

void update(vector<ll> &tree, int node, int start, int end, int index, ll diff){
	if(index<start||index>end)
		return;
	tree[node]+=diff;
	if(start!=end){ // leaf node가 아니면 자식까지 변경
		update(tree, node*2, start, (start+end)/2, index, diff);
		update(tree, node*2+1, (start+end)/2+1, end, index, diff);
	}
}

// node가 담당하고 있는 구간 [start, end], 합을 구해야하는 구간 [left, right]
ll sum(vector<ll> &tree, int node, int start, int end, int left, int right){
	if(left>end||right<start)
		return 0; // [left, right]와 [start, end]가 완전히 겹치지 않는 경우
	if(left<=start&&end<=right)
		return tree[node]; // [left, right]가 [start, end]를 완전히 포함하는 경우
	return sum(tree, node*2, start, (start+end)/2, left, right)+sum(tree, node*2+1, (start+end)/2+1, end, left, right);
	// [start, end]가 [left, right]를 완전히 포함하는 경우
	// [left, right]와 [start, end]가 겹쳐져 있는 경우
}

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n);
	int h=(int)ceil(log2(n));
	int tree_size=(1<<(h+1));
	vector<ll> tree(tree_size);
	m+=k;
	for(int i=0; i<n; i++)
		cin >> a[i];
	init(a, tree, 1, 0, n-1);
	
	while(m--){
		int t1;
		cin >> t1;
		if(t1==1){
			int t2;
			ll t3;
			cin >> t2 >> t3;
			t2-=1;
			ll diff=t3-a[t2];
			a[t2]=t3;
			update(tree, 1, 0, n-1, t2, diff);
		}
		else if(t1==2){
			int t2, t3;
			cin >> t2 >> t3;
			cout << sum(tree, 1, 0, n-1, t2-1, t3-1) << "\n";
		}
	}
}