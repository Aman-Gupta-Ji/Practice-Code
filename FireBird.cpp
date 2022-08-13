#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define has(s,key) s.find(key)!=s.end()

int main(void) {
	int n,k;
	cin>>n>>k;
	vector<int> days(n);
	for(int i=0;i<n;i++)
		cin>>days[i];
	int count=0;
	int i, rem;
	i=n-1;
	while(i>=0) {
		while(i>=0) {
			if(days[i]!=-1)
				break;
			i--;
		}
		if(i>=0)
			rem=days[i];
		for(rem--,i--;i>=0&&rem>=0;rem--,i--)
			days[i]=rem;
	}
	// for(i=0;i<n;i++)
	// 	cout<<days[i]<<" ";
	// cout<<endl;
	i=0;
	while(i<n) {
		if(days[i]!=-1) {
			rem=days[i];
			for(;rem<=k&&i<n;i++,rem++) {
				days[i]=rem;
			}
		}
		i++;
	}
	rem=0;
	for(i=0;i<n;i++,rem--) {
		if(days[i]==0) {
			count++;
			rem=k+1;
		}
		else if(days[i]==-1&&rem<=0) {
			// cout<<i<<" ";
			if(i+k<n) {
				if(days[i+k]==-1) {
					count++;
					rem=k+1;
				}
			}
			else {
				bool pre=true;
				for(int j=i+1;j<n;j++)
					if(days[i]!=-1) {
						pre=false;
						break;
					}
				if(pre) {
					count++;
					rem=k+1;
				}
			}
		}
	}
	// for(i=0;i<n;i++)
	// 	cout<<days[i]<<" ";
	// cout<<endl;
	cout<<count<<endl;
	return 0;
}