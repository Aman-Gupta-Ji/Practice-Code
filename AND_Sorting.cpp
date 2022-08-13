#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define has(s,key) s.find(key)!=s.end()

int sorted(vector<int>& arr, int n) {
   vector<int> hash(n);
   vector<int> srt(arr.begin(),arr.end());
   sort(srt.begin(),srt.end());
   for(int i=0;i<n;i++)
       hash[srt[i]]=i;
   int ans=0;
   int first=true;
   for(int i=0;i<n;i++) {
       if(arr[i]!=srt[i]) {
           if(first) {
           	   first=false;
               ans=arr[i]&(hash[arr[i]]);
           }
           else
               ans=ans&(arr[i]&hash[arr[i]]);
       }
   }
   return ans;
}

int main(void) {
	int t, n;
	cin>>t;
	while(t--) {
		cin>>n;
		vector<int> ar(n);
		for(int i=0;i<n;i++)
			cin>>ar[i];
		int res=sorted(ar,n);
		cout<<res<<endl;
	}
	return 0;
}