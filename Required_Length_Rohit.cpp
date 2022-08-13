#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define has(s,key) s.find(key)!=s.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int aman() {
	return 1;
}

ll bfs(ll n, ll m) {
    queue<pair<ll,int> > q;
   	unordered_set<string> f;
    q.push(make_pair(m,0));
   	if(m==1&&n!=1)
    	return -1;
   	pair<ll,int> front_node;
    while(q.size()>0){
    	aman();
        front_node=q.front();
        string s=to_string(front_node.first);
        q.pop();
        if(s.size()==n)
        	return front_node.second;
        if(s.size()<n){
            sort(s.begin(),s.end());
            for(int i=s.size()-1;i>=0&&s[i]>'1';i--) {
                string p=to_string(front_node.first*(ll)(s[i]-'0'));
                if(f.find(p)==f.end()) {
                	q.push(make_pair(front_node.first*(ll)(s[i]-'0'),front_node.second+1));
                	f.insert(p);
                }
            }
        }
    }
    return -1;
}

int main(void) {
	ll n, x;
	cout<<bfs(n,x)<<endl;
	return 0;
}