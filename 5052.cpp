#include<iostream>
#include<string>
using namespace std;

struct Trie{
	Trie* ch[10];
	bool end;
	
	Trie(){
		end=false;
		for(int i=0; i<10; i++)
			ch[i]=NULL;
	}
	~Trie(){
		for(int i=0; i<10; i++){
			if(ch[i])
				delete ch[i];
		}
	}
	
	void insert(const char* s){
		if(!*s){
			this->end=true;
			return;
		}
		int now=*s-'0';
		if(!ch[now])
			ch[now]=new Trie;
		ch[now]->insert(s+1);
	}
};

int main(){
	int t, n;
	cin >> t;
	whlie(t--){
		int >> n;
		while(n--){
			Trie* root=new Trie;
			string s;
			root->insert(s.c_str());
		}
		delete root;
	}
}