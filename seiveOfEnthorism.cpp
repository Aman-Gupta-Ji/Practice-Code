#include<bits/stdc++.h>
using namespace std;

vector<bool> seiveOfEnthorism(int n) {
    if(n <= 1)
        return {false};
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    int sqr = (int)sqrt(n);
    for(int i = 2; i <= sqr; i++) {
        if(prime[i]) {
            int j = 2;
            while(i * j <= n) {
                prime[i * j] = false;
                j++;
            }
        }
    }
    return prime;
}

int countPrimes(int n) {
    vector<bool> prime = seiveOfEnthorism(n - 1);
    int count = 0;
    for(bool b: prime) {
        if(b)
            count++;
    }
    return count;
}

int main(void) {
    int n;
    cin>>n;
    cout<<countPrimes(n)<<endl;
    return 0;
}
