#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(void) {
    int n;
    cin>>n;
    vector<int> arr(n);
    int i;
    for(i=0;i<n;i++)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    int maxsize=1;
    int cursize=0;
    int last=arr[i];
    for(i=0;i<n;i++) {
        if(i+1<n&&arr[i]==arr[i+1] and arr[i]-last<2) {
            cursize++;
            for(;arr[i]==arr[i+1]&&i<n-1;i++) {
                cursize++;
            }
            last=arr[i-1];
        }
        else if(cursize>0) {
            if(arr[i]-last<2)
                cursize++;
            maxsize=max(maxsize,cursize);
            // cout<<i<<" "<<arr[i]<<" "<<cursize<<endl;
            last=arr[i];
            i--;
            cursize=0;
        }
    }
    maxsize=max(maxsize,cursize);
    cout<<maxsize<<endl;
    return 0;
}