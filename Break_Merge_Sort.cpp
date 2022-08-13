#include<bits/stdc++.h>
using namespace std;

int moves(vector<vector<int>>& arr) {
  priority_queue<int,vector<int>, greater<int>> pq;
  int moves = 0;
  for(auto row: arr) {
    int n = row.size();
    int l = 0, r = n - 1;
    int left = 0, right = 0;
    for(int i = 0 ; i < n - 1 ; i++) {
      if(row[i] > row[i + 1]) {
        pq.push(i + 1 - l);
        left += min(i + 1 - l, n - i - 1);
        l = i + 1;
      }
    }
    pq.push(n - l);
    for(int i = n - 1 ; i > 0 ; i--) {
      if(row[i] < row[i - 1]) {
        right += min(i, r - i + 1);
        r = i;
      }
    }
    moves += min(left, right);
  }
  while(pq.size() > 1) {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    moves += a + b;
    pq.push(a + b);
  }
  return moves;
}

int main(void) {
  int t;
  cin>>t;
  while(t--) {
    int n;
    cin>>n;
    vector<vector<int>> arr(n);
    for(int i = 0 ; i < n; i++) {
      int size;
      cin>>size;
      vector<int> row(size);
      for(int i = 0; i < size; i++)
        cin>>row[i];
      arr[i] = row;
    }
    cout<<moves(arr)<<endl;
  }
}