#include<bits/stdc++.h>
using namespace std;
#define has(s,key) s.find(key)!=s.end()

int siz;

int minimumSub(int changes, int i, int seb, vector<int>& seq, bool last) {
	if(i==n)
		return seb;
	if(seq[i]%2==0) {
		if(!last) {
			// if(seq[i]==0)
				// return minimumSub(changes,i+1,seb-1,);
			return minimumSub(changes,i+1,seb+1,seq,last);
		}
	}
	if(seq[i]&1) {

	}
}

pair<int,int> makeGood(int n, string bi) {
	int changes=0;
	int st=bi[0];
	int count=0;
	int sub=1;
	for(int i=0;i<n;i++) {
		if(bi[i]==st)
			count++;
		else {
			if(count&1) {
				changes++;
				if(i+1<n)
					st=bi[i+1];
				count=0;
			}
			else {
				sub++;
				st=bi[i];
				count=1;
			}
		}
	}
	if(changes==0)
		return {changes,sub};
	vector<int> seq;
	count=0;
	st=bi[0];
	for(int i=0;i<n;i++) {
		if(st==bi[i])
			count++;
		else {
			seq.push_back(count);
			count=1;
			st=bi[i];
		}
	}
	seq.push_back(count);
	siz=seq.size();
	int s=minimumSub(changes,0,0,seq,false);
	return {changes, s};
}

int main(void) {
	int t;
	cin>>t;
	int n;
	string bi;
	while(t--) {
		cin>>n;
		cin>>bi;
		pair<int,int> ans=makeGood(n,bi);
		cout<<ans.first<<" "<<ans.second<<endl;
	}
	return 0;
}