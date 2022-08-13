#include<bits/stdc++.h>
using namespace std;

typedef signed long long ll;

#undef _P
#define P(...) (void)printf(VA_ARGS_)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define F first
#define S second
#define pb push_back


int main(void) {
	string S;
	cin>>S;
	int K;
	cin>>K;
	deque<int> zero;
	int res = 0;
	int zerosub;
	int l, r, len = S.length();
	for(l=0, r=0; r < len; r++) {
		if(S[r] == '0')
			zero.push_back(r);
		if(!zero.empty()) {
			do {
				zerosub = zero.back() - zero.front() + 1;
				if(zerosub > K) {
					if(S[l] == '0')
						zero.pop_front();
					l++;
				}
			} while(zerosub > K);
		}
		res = max(res, r - l + 1);
	}
	cout<<res<<endl;
	return 0;
}