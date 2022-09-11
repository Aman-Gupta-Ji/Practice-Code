#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int solve(int N, vector<int>& S, int Q, vector<vector<int> > work) {
    vector<int> done = workdone(work,N);
    sort(done.begin(),done.end(),greater<int>());
    sort(S.begin(),S.end(),greater<int>());
    int res=0, dop=0;
    for(i=0;i<n;i++) {
        if(S[i]<=done[dop]) {
            dop++;
            res++;
        }
    }
    return res; // or you could return dop also
}
void print(vector<int>& v) {
    for(int el: v)
        cout<<el<<" ";
    cout<<endl;
}
vector<int> workdone(vector<vector<int> >& people, int n) {
    vector<int> done(n,0);
    int s, e, x;
    for(vector<int> qu: people) {
        // print(qu);
        s=qu[0], e=qu[1], x=qu[2];
        done[s-1]+=x;
        if(e<n)
            done[e]-=x;
    }
    for(int i=1;i<n;i++)
        done[i]+=done[i-1];
    return done;
}
int main(void) {
    int n, q;
    cin>>n;
    vector<int> task(n);
    int i, temp;
    for(i=0;i<n;i++) {
        cin>>temp;
        task[i]=temp;
    }
    // print(task);
    cin>>q;
    vector<vector<int> > people(q);
    int s, e, x;
    for(i=0;i<q;i++) {
        cin>>s>>e>>x;
        people[i]={s,e,x};
    }
    vector<int> done = workdone(people,n);
    // print(done);
    sort(done.begin(),done.end(),greater<int>());
    sort(task.begin(),task.end(),greater<int>());
    // print(done);
    // print(task);
    int res=0, dop=0;
    for(i=0;i<n;i++) {
        if(task[i]<=done[dop]) {
            dop++;
            res++;
        }
    }
    cout<<res;
    return 0;
}
/*
INPUT :- 
6
17 21 10 12 11 23
5
3 5 5
1 2 13
4 5 3
2 3 6
6 6 15
*/