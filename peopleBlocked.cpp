#include<bits/stdc++.h>
using namespace std;

int MaximumBarrier(int n, int input[][3]) {
	#include<algorithm>
	// sort(barrier, barrier + n);
	int ans=input[0][2]+1;
	int last_distance=input[0][2]+input[0][0];
	for(int i=1;i<n;i++){
		if(input[i][0]>last_distance){
			ans+=input[i][2]+1;
			last_distance=input[i][0]+input[i][2];
		}else if(last_distance>=input[i][0]+input[i][2]){
			continue;
		}else{
			ans+=(input[i][0]-last_distance)+input[i][2];
			last_distance=input[i][0]+input[i][2];
		}
	}
	return ans;
}

int main(void) {
	int n;
	cin>>n;
	int barrier[n][3];
	int x, y, d;
	for(int i = 0; i < n; i++) {
		cin>>x>>y>>d;
		barrier[i][0] = x;
		barrier[i][1] = y;
		barrier[i][2] = d;
	}
	cout<<MaximumBarrier(n, barrier)<<endl;
	return 0;
}