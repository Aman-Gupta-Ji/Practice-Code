#include<bits/stdc++.h>
using namespace std;

int main(void) {
	int n, q;
	cin>>n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin>>a[i];
	long long x;
	cin>>x>>q;
	vector<vector<int>> queries(q, vector<int> (2));
	for(int i = 0; i < q; i++)
		cin>>queries[i][0]>>queries[i][1];

	vector<int> res(q);


	long long sum = 0;
	sum = accumulate(a.begin(), a.end(), sum);
	for(int i = 0; i < q; i++) {
		sum += queries[i][1] - a[queries[i][0]];
		a[queries[i][1]] = queries[i][1];
		if(sum < 0)
			res[i] = 1;
		else if(sum == 0) {
			int j;
			for(j = 0; j < n; j++)
				if(a[j] != 0)
					break;
			if(j == n)
				res[i] = 0;
			else
				res[i] = 1;
		}
		else
			res[i] = ceil(sum/(double)x);

	}


	for(int i = 0; i < q; i++)
		cout<<res[i]<<" ";
	cout<<endl;

	return 0;
}