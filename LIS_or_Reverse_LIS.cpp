#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define has(s,key) s.find(key)!=s.end()

int LIS(vector<int>& arr, int n) {
   sort(arr.begin(),arr.end());
   int res=0;
   map<int,int> value;
   for(int i=0;i<n;i++)
        value[arr[i]]++;
   bool unique=true;
   for(int i=1;i<n;i++){
       if(arr[i]==arr[i-1]){
           unique=false;
           break;
       }
   }
   if(unique)
   		return n/2;
   vector<int> uniq;
   for(auto it=value.begin();it!=value.end();it++){
       if(it->second==1)
           uniq.push_back(it->first);
       else
           res++;
   }
   return res+uniq.size()/2;
}

int main(void) {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int out=LIS(arr,n);
		cout<<out<<endl;
	}
	return 0;
}