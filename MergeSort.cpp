#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr, int l, int mid, int r) {
    vector<int> copy(arr.begin()+l,arr.begin()+mid+1);
    int n=copy.size();
    int i=0, j=mid+1;
    while(i<n&&j<=r) {
        if(copy[i]<=arr[j])
            arr[l++]=copy[i++];
        else if(copy[i]>arr[j])
            arr[l++]=arr[j++];
    }
    while(i<n)
        arr[l++]=copy[i++];
    while(j<=r)
        arr[l++]=arr[j++];
}
void mergeSort(vector<int>& arr, int l, int r) {
    if(l<r) {
        // int mid=(l+r)/2;
        int mid=l+(r-l)/2;
        // int mid=r-(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main(void) {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<endl<<"Sorted Array"<<endl;
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}