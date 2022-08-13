#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void segment(int x, int y) {
    int sqr = sqrt(y);
    int start, end, mid;
    for(int i = 1; i <= sqr; i++) {
        start = i;
        end = y / i;
        mid = x / 2;
        if(x & 1) {
            if((mid > end || mid < start) && 
                (mid + 1 > end || mid + 1 < start)) {
                cout<<start<<" "<<end<<endl;
                cout<<mid<<" "<<mid+1<<endl;
                return;
            }
        }
        else {
            if(mid > end || mid < start) {
                cout<<start<<" "<<end<<endl;
                cout<<mid<<" "<<mid<<endl;
                return;
            }
        }
    }
    cout<<"-1"<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int x, y;
        cin>>x>>y;
        segment(x, y);
    }
    return 0;
}
