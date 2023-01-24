#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;
	int z[20]={0, };
	cin >> s;
	
	int x=0, y=0;
	
	for(int i=1; i<s.size(); i++){
		if(i>y){
			int j=0;
			while(i+j<s.size()&&s[j]==s[i+j]){
				z[i]++;
				j++;
			}
		}
		else if(i+z[i-x]<=y){
			z[i]=z[i-x];
		}
		else{ // if(i+z[i-x]>y)
			z[i]=y-i+1;
			int j=y+1;
			while(j<s.size()&&s[j]==s[j-i]){
				z[i]++;
				j++;
			}
		}
		
		if(i+z[i]-1>y){
			y=i+z[i]-1;
			x=i;
		}
	}
	
	for(int i=0; i<s.size(); i++)
		cout << z[i] << ' ';
}