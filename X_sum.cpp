#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define has(s,key) s.find(key)!=s.end()

int bishop(vector<vector<int>>& arr, int n, int m) {
	int maxc=0;
	vector<int> rightD;
	vector<int> leftD;
	map<pair<int,int>,int> rD;
	map<pair<int,int>,int> lD;
	int i, j, r, c, l;
	int sum;
	for(c=0;c<m;c++) {
		i=0;
		j=c;
		sum=0;
		l=rightD.size();
		while(i<n&&j>=0) {
			sum+=arr[i][j];
			rD[{i,j}]=l;
			i++;
			j--;
		}
		rightD.push_back(sum);
	}
	for(r=1;r<n;r++) {
		i=r;
		j=m-1;
		sum=0;
		l=rightD.size();
		while(i<n&&j>=0) {
			sum+=arr[i][j];
			rD[{i,j}]=l;
			i++;
			j--;
		}
		rightD.push_back(sum);
	}
	for(c=m-1;c>=0;c--) {
		i=0;
		j=c;
		sum=0;
		l=leftD.size();
		while(i<n&&j<m) {
			sum+=arr[i][j];
			lD[{i,j}]=l;
			i++;
			j++;
		}
		leftD.push_back(sum);
	}
	for(r=1;r<n;r++) {
		i=r;
		j=0;
		sum=0;
		l=leftD.size();
		while(i<n&&j>=0) {
			sum+=arr[i][j];
			lD[{i,j}]=l;
			i++;
			j++;
		}
		leftD.push_back(sum);
	}
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			sum=rightD[rD[{i,j}]]+leftD[lD[{i,j}]];
			sum-=arr[i][j];
			maxc=max(sum,maxc);
		}
	}
	return maxc;
}

int main(void) {
	int t;
	cin>>t;
	int n, m;
	int i, j;
	while(t--) {
		cin>>n>>m;
		vector<vector<int>> arr(n,vector<int> (m));
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				cin>>arr[i][j];
		cout<<bishop(arr,n,m)<<endl;
	}
	return 0;
}