#include<bits/stdc++.h> 
using namespace std;

int res, k; 
int moves[] = {3, 5, 10};

void dfs(int target, int b) { 
	if(target == 0) {
		res++;
		return;
	} 

	for(int i = b; i < 3 && target>= moves[i]; i++) 
		dfs(target moves[i], i);
}

int main(void) { 
	cin>>k;
	res = 0;
	dfs(k, 0); 
	cout<<res<<endl;
	return 0;
}