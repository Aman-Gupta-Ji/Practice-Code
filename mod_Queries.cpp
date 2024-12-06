#include<bits/stdc++.h>
using namespace std;

int main(void) {
	int N, M, Q;
	cin>>N>>M;
	vector<int> Arr(N), mod(M, 0);
	for(int i = 0; i < N; i++) {
		cin>>Arr[i];
		mod[Arr[i] % M]++;
	}
	cin>>Q;
	int t, ind, A, X;
	for(int i = 0; i < Q; i++) {
		cin>>t;
		switch(t) {
			case 1:
				cin>>ind>>A;
				ind--;
				mod[Arr[ind] % M]--;
				Arr[ind] = A;
				mod[Arr[ind] % M]++;
				break;
			case 2:
				cin>>X;
				cout<<mod[X]<<endl;
				break;
		}
	}
	return 0;
}