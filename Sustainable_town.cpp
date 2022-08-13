#include<bits/stdc++.h>
using namespace std;

int dp[502][251];
bool findans(int n,int index,int last,vector<long long>& arr,int m){
    if(index>=n){
        return true;
    }
    if(dp[index][m]!=-1){
        return dp[index][m];
    }
    int next=arr[index+1]<n?arr[index+1]:0;
    int next_next=arr[index+2]<n?arr[index+2]:0;
    int value=arr[index];
    int sum=next+next_next+value;
    if(arr[index]>arr[last]){
        
        bool ans=findans(n,index+1,index,arr,m);
        if(index+2<n&&m){
            arr[index+2]=sum;
            ans=ans||findans(n,index+2,last,arr,m-1);
            arr[index+2]=next_next;
        }
        return dp[index][m]=ans;
    }
    else{
        
        if(m==0||index+2>=n){
            return false;
        }
        bool ans=false;
        arr[index+2]=sum;
        if(sum>arr[last])
            ans=ans||findans(n,index+3,index+2,arr,m-1);
        ans=ans||findans(n,index+2,last,arr,m-1);
        arr[index+2]=next_next;
        return dp[index][m]=ans;
    }
    // return dp[index][m]=false;
    
}

int Possibility (int n, int m, vector<long long>& A) {
    bool anss=true;
   for(int i=1;i<n;i++){
       if(A[i]<=A[i-1]){
           anss=false;
           break;
       }
   }
   if(anss)return true;
   memset(dp,-1,sizeof(dp));
   vector<long long> all;
   all.push_back(0);
   for(int a:A){
       all.push_back(a);
   }
   bool ans=findans(n+1,1,0,all,m);
   return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        int M;
        cin >> M;
        vector<long long> A(N);
        for(int i_A = 0; i_A < N; i_A++)
        {
        	cin >> A[i_A];
        }

        int out_;
        out_ = Possibility(N, M, A);
        cout << out_;
        cout << "\n";
    }
}