#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define has(s,key) s.find(key)!=s.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve();

int main(){
    fast;
    int t=1;
    cin>>t;
    while (t--) {  
        solve();
    }
    return 0;
}
int dfs(vector<vector<int> >& arr,int node,vector<int>& count){
    for(int child: arr[node])
        count[node]+=1+dfs(arr,child,count);
     return count[node];
}

int saveChild(vector<int>& count, int node, vector<vector<int>>& arr) {
    int maxsub=-1, maxc=-1;
    for(int child: arr[node]) {
        if(maxsub<=count[child]) {
            maxsub=count[child];
            maxc=child;
        }
    }
    if(maxc==-1)
        return 0;
    int saved=maxsub;
    for(int child: arr[node]) {
        if(child!=maxc)
            saved+=saveChild(count,child,arr);
    }
    return saved;
}

void solve(){
   int n;
   cin>>n;
   int a, b;
   vector<vector<int> > arr(n+1);
   for(int i=0;i<n-1;i++){
        cin>>a>>b;
        arr[a].push_back(b);
   }
   vector<int> count(n+1,0);
   dfs(arr,1,count);
   int ans=saveChild(count,1,arr);
   cout<<ans<<endl;
}