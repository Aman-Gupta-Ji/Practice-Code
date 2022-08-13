#include<bits/stdc++.h>
using namespace std;

int bishop(vector<vector<int>>& arr, int n, int m) {
  
  int a1,a2,ans=INT_MIN;
  for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++) {
        int s1=0;
        a1=i+1,a2=j+1;
        while(a1<n&&a2<m)
        {
            s1+=(arr[a1][a2]);
            a1++;
            a2++;
        }
        a1=i-1,a2=j-1;
        while(a1>=0&&a2>=0)
        {
            s1+=(arr[a1][a2]);
            a1--;
            a2--;
        }
        a1=i-1,a2=j+1;
        while(a1>=0&&a2<m)
        {
            s1+=(arr[a1][a2]);
            a1--;
            a2++;
        }
        a1=i+1,a2=j-1;
        while(a1<n&&a2>=0)
        {
            s1+=(arr[a1][a2]);
            a1++;
            a2--;
        }
        ans=max(ans,arr[i][j]+s1);
      }
    }
    return ans;
}


int main(void) {
  int t;
  cin>>t;
  int n, m;
  int i, j;
  while(t--) {
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int> (m));
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
        cin>>arr[i][j];
    cout<<bishop(arr,n,m)<<endl;
  }
  return 0;
}
