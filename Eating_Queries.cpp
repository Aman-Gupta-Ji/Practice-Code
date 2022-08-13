#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int Query(vector<int>& arr, int x, int n) {
  int i=0;
  int j=n-1;
  int ans=-1;
  while(i<=j){
    int mid=i+(j-i)/2;
    if(arr[mid]>=x) {
      ans=mid+1;
      j=mid-1;
    }
    else
      i=mid+1;
  }
  return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int n,m;
      cin>>n>>m;
      vector<int> arr(n);
      int sum=0;
      for(int i=0;i<n;i++)
        cin>>arr[i];
      sort(arr.begin(),arr.end(),greater<int>());
      vector<int> pfsum(n);
      pfsum[0]=arr[0];
      for(int i=1;i<n;i++)
        pfsum[i]=pfsum[i-1]+arr[i];
      while(m--) {
        int x;
        cin>>x;
        int ans=Query(pfsum,x,n);
        cout<<ans<<endl;
      }
    }
}