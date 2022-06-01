#include<iostream>
#include<stack>
#include<algorithm>
#define MAX 100002
typedef long long ll;
using namespace std;

struct Info{
	ll x, y;
	ll p, q;
	Info(ll x1=0, ll y1=0) : x(x1), y(y1), p(1), q(0) {} // x(x1)이면 x를 x1으로 초기화
};

bool cmp(const Info &A, const Info &B){
	if(1LL*A.q*B.p!=1LL*A.p*B.q)
		return 1LL*A.q*B.p<1LL*A.p*B.q;
	if(A.y!=B.y)
		return A.y<B.y;
	return A.x<B.x;
}

ll ccw(const Info &A, const Info &B, const Info &C){
	return 1LL*(A.x*B.y+B.x*C.y+C.x*A.y-(B.x*A.y+C.x*B.y+A.x*C.y));
}

Info poll[MAX];

ll Graham_scan(ll n){
	sort(poll, poll+n, cmp);
	for(ll i=1; i<n; i++){
		poll[i].p=poll[i].x-poll[0].x;
		poll[i].q=poll[i].y-poll[0].y;
	}
	sort(poll+1, poll+n, cmp);
	
	stack<ll> s;
	s.push(0);
	s.push(1);
	
	ll next=2;
	while(next<n){
		while(s.size()>=2){
			ll first, second;
			second=s.top();
			s.pop();
			first=s.top();
			
			if(ccw(poll[first], poll[second], poll[next])>0){
				s.push(second);
				break;
			}
		}
		s.push(next++);
	}
	return s.size();
}

int main(){
	ll n;
	cin >> n;
	for(ll i=0; i<n; i++){
		ll x, y;
		cin >> x >> y;
		poll[i]=Info(x, y);
	}
	
	cout << Graham_scan(n);
}