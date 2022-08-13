#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define has(s,key) s.find(key)!=s.end()
#define ll long long int
#define ull unsigned long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

string multiply(const string& num, int k) {
	string res="";
	int carry=0;
	int x, sum;
	for(int i=num.length()-1;i>=0||carry>0;i--) {
		x=i<0?0:num[i]-'0';
		sum=x*k+carry;
		res.push_back(sum%10+'0');
		carry=sum/10;
	}
	reverse(res.begin(),res.end());
	return res;
}
int bfs(int n, string x) {
	int moves=0;
	queue<string> q;
	q.push(x);
	string ret;
	int size, len, k;
	int feq[10];
	while(!q.empty()) {
		size=q.size();
		while(size--) {
			x=q.front();
			q.pop();
			len=x.length();
			if(len==n)
				return moves;
			if(len>n)
				continue;
			memset(feq,0,sizeof(feq));
			for(char dig: x)
				feq[dig-'0']++;
			for(k=2;k<10;k++)
				if(feq[k]) {
					ret=multiply(x,k);
					if(ret.length()<=n)
						q.push(ret);
				}

		}
		moves++;
	}
	return -1;
}
int main(void) {
	fast;
	int n, x;
	cin>>n>>x;
	cout<<bfs(n,to_string(x));
	return 0;
}