#include<bits>/stdc++.h>

vector<int> balanceOrNot(vector<string>& expressions, vector<int> maxReplacements) {
    int n = expressions.size();
    vector<int> res(n);
    for(int i = 0; i < n; i++) {
        string exp = expressions[i];
        int maxR = maxReplacements[i];
        int o = 0, e = 0;
        for(char ch: exp) {
            if(ch == '<')
                o++;
            else if(o)
                o--;
            else
                e++;
        }
        res[i] = o == 0 && e < maxR;
    }
    return res;
}