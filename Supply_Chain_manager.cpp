#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    for (auto interval : intervals) {
        if (merged.empty() || merged.back()[1] < interval[0])
            merged.push_back(interval);
        else
            merged.back()[1] = max(merged.back()[1], interval[1]);
    }
    return merged;
}

int main(void) {
	int n;
	cin>>n;
	vector<vector<int>> inte(n);
	for(int i = 0; i < n; i++) {
		int s, e;
		cin>>s>>e;
		inte[i] = {s, e};
	}

	vector<vector<int>> merged = merge(inte);

	for(auto el: merged) {
		cout<<el[0]<<" "<<el[1]<<endl;
	}
	return 0;
}