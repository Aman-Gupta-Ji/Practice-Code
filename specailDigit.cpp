#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	string p=to_string(n);
	string s="";
	for(int i=0;i<k;i++){
		s+=p;
	}
	int ans=0;
	for(int i=0;i<s.size();i++){
		ans+=s[i]-'0';
		if(ans<10)
			continue;
		int local_sum=0;
		while(ans>0){
			local_sum+=ans%10;
			ans/=10;
		}
		ans=local_sum;
	}
	cout<<ans<<endl;
}