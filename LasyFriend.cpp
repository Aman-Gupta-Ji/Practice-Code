#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(void) {
    int t;
    cin>>t;
    int n, lower, left, newrow, r, c, result;
    while(t--) {
        cin>>n;
        lower=sqrt(n);
        left=n-lower*lower;
        newrow=left/lower+((left%lower>0)?1:0);
        r=lower+newrow;
        c=lower;
        result=2*r+2*c;
        cout<<result<<endl;
    }
    return 0;
}