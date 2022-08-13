#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define has(s,key) s.find(key)!=s.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve(int n, vector<int>& arr) {
	int cur, next, i;
	priority_queue<int,vector<int>,greater<int> > pq;
	for(i=1;i<=n;i++)
    	pq.push(i);
  	for(i=0;i<n-2;i++) {
	    if(pq.top()!=arr[i]) {
	    	arr[i]=pq.top();
	      	pq.pop();
	    }
	    else {
	      	cur=pq.top();
	      	pq.pop();
	      	arr[i]=pq.top();
	      	pq.pop();
	      	pq.push(cur);
	    }
	}
	cur=pq.top();
	pq.pop();
	next=pq.top();
	if(cur==arr[i]) {
		arr[i]=next;
		arr[i+1]=cur;
	}
	else if(next==arr[i+1]) {
		arr[i]=next;
		arr[i+1]=cur;
	}
	else {
		arr[i]=cur;
		arr[i+1]=next;
	}
}

int main(void) {
	int t;
	cin>>t;
	int n;
	while(t--) {
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		if(n==1) {
			cout<<-1<<endl;
			continue;
		}
		solve(n,arr);
		for(int i=0;i<n-1;i++)
			cout<<arr[i]<<" ";
		cout<<arr[n-1]<<endl;
	}
	return 0;
}