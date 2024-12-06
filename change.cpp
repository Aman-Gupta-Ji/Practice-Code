#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int n;

int powmod(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = (1LL * res * x) % mod;
        x = (1LL * x * x) % mod;
        y >>= 1;
    }
    return res;
}

int main() {
    cin >> n;
    cout << (powmod(2, n - 1) + mod - 1) % mod << endl;
    return 0;
}



