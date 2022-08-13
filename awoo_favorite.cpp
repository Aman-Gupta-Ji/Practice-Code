#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define has(s,key) s.find(key)!=s.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

bool possible(int n, string& s, string& t) {
	if(s==t)
		return true;
	if(n==1)
		return false;
	int freq[3]={0};
	for(int i=0;i<n;i++) {
		freq[s[i]-'a']++;
		freq[t[i]-'a']--;
	}
	for(int i=0;i<3;i++)
		if(freq[i])
			return false;
	int j;
	for(int i=0;i<n;i++) {
		if(s[i]==t[i])
			continue;
		else if(s[i]!=t[i]&&i!=n-1) {
			if(s[i]=='a'&&t[i]=='b') {
				for(j=i+1;j<n&&s[j]=='a';j++);
				if(j==n||s[j]!='b')
					return false;
				s[j]='a';
			}
			else if(s[i]=='b'&&t[i]=='c') {
				for(j=i+1;j<n&&s[j]=='b';j++);
				if(j==n||s[j]!='c')
					return false;
				s[j]='b';
			}
			else
				return false;
		}
		else
			return false;

	}
	return true;
}

int main(void) {
	int q, n;
	cin>>q;
	string s, t;
	while(q--) {
		cin>>n;
		cin>>s>>t;
		if(possible(n,s,t))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}