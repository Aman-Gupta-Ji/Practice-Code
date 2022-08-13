#include<bits/stdc++.h>
using namespace std;

int find_animal(vector<pair<unordered_map<char,int>,int>>& data, char animal, int cur) { // dfs
   if(cur<0)
      return 0;
   if(data[cur].first.find(animal)!=data[cur].first.end())
      return data[cur].first[animal];
   return find_animal(data,animal,data[cur].second);
}

vector<int> solve (int N, vector<string> command) {
   vector<pair<unordered_map<char,int>,int>> data; // animals, parent
   vector<int> res;
   stack<int> parent;
   parent.push(0);
   data.push_back(make_pair(unordered_map<char,int>(),-1));
   char cmd, animal;
   int val,len;
   for(int i=0;i<N;i++) {
      cmd=command[i][0];
      switch(cmd) {

         case 'a':
            animal=command[i][7];
             val=0;
             len=command[i].length();
            for(int j=9;j<len;j++)
            {
               val=val*10+command[i][j]-'0';
            }
            data[parent.top()].first[animal]=val;
            break;
         case 'p':
            animal=command[i][6];
            res.push_back(find_animal(data,animal,parent.top()));
            break;
         case '{':
            data.push_back(make_pair(unordered_map<char,int>(),parent.top()));
            parent.push(data.size()-1);
            break;
         case '}':
            parent.pop();
            break;
      }
   }
   return res;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> command(N);
    for(int i_command = 0; i_command < N; i_command++)
    {
       getline(cin,command[i_command]);
    }

    vector<int> out_;
    out_ = solve(N, command);
    for(int i_out_ = 0; i_out_ < out_.size(); i_out_++)
    {
      if(out_[i_out_])
    	    cout << "\n" << out_[i_out_];
      else
         cout<<"\n"<<"undefined";
    }
}