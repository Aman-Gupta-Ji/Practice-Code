#include<bits/stdc++.h>
using namespace std;

int findans(vector<long long>& stall, vector<long long>& prefix, long long v, long long n) {
	long long l = stall[0], r = stall.back(), answer = -1;
    while(l <= r){
        long long mid = (l + r) / 2;
        long long left = 0, right = n - 1, ans = -1;
        while(left <= right){
            long long mid2=(left + right) / 2;
            if(stall[mid2] < mid){
                ans = mid2;
                left = mid2 + 1;
            } else {
                right = mid2 - 1;
            }
        }
        long long sum = 0;
        if(ans == -1){
            sum = mid * n;
        } else {
            sum=(n - ans - 1) * mid + prefix[ans];
        }
        
        if(sum >= v){
            r = mid - 1;
            answer = mid;
        } else {
            l = mid + 1;
        }
    }
    return answer;
}

int main(void) {
	int n;
	cin>>n;
	vector<long long> stall(n);
	for(int i = 0; i < n; i++)
		cin>>stall[i];
	sort(stall.begin(), stall.end());
	vector<long long> pre(n);
	long long sum = 0;
	for(int i = 0; i < n; i++) {
		sum += stall[i];
		pre[i] = sum;
	}
	long long q, v;
	cin>>q;
	for(int i = 0; i < q; i++) {
		cin>>v;
		cout<<findans(stall, pre, v, n)<<endl;
	}
	return 0;
}