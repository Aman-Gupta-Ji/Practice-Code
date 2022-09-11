#include<bits/stdc++.h>
using namespace std;
int doInOrDe(vector<int>& arr_a, vector<int>& arr_b, int n, int m) {
    int min=*min_element(arr_a.begin(),arr_a.end());
    int max=*max_element(arr_b.begin(),arr_b.end());
    int countmin=count(arr_a.begin(),arr_a.end(),min);
    int countmax=count(arr_b.begin(),arr_b.end(),max);
    int moves=0, i;
    int diff=max-min;
    if(countmin<=countmax) {
        for(i=0;i<n&&countmin;i++) {
            if(arr_a[i]==min) {
                moves++;
                countmin--;
                arr_a[i]++;
            }
        }
    }
    else {
        for(i=0;i<m&&countmax;i++) {
            if(arr_b[i]==max) {
                moves++;
                countmax--;
                arr_b[i]--;
            }
        }
    }
    return moves;
}
int getMinimumMoves(vector<int>& arr_a, vector<int>& arr_b) {
    int moves=0, n=arr_a.size(), m=arr_b.size();
    while(*min_element(arr_a.begin(),arr_a.end())<*max_element(arr_b.begin(),arr_b.end())) {
        moves+=doInOrDe(arr_a,arr_b,n,m);
    }
    return moves;
}
using namespace std;
int main(void) {
    int n, m, i;
    cin>>n;
    vector<int> ar_a(n);
    for(i=0;i<n;i++)
        cin>>ar_a[i];
    cin>>m;
    vector<int> ar_b(m);
    for(i=0;i<m;i++)
        cin>>ar_b[i];
    cout<<endl<<getMinimumMoves(ar_a,ar_b)<<endl;
    return 0;
}