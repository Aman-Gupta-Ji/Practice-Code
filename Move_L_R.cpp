class Solution {
public:
    bool canChange(string start, string target) {
        int i=0,r=0;
        int n=start.size()-1;
        set<int> left;
        set<int> right;
        for(int i=0;i<=n;i++){
            if(start[i]=='L'){
                left.insert(i);
            }else if(start[i]=='R'){
                right.insert(i);
            }
        }
        for(int i=0;i<=n;i++){
            if(start[i]==target[i]){
                continue;
            }
            if(target[i]=='L'&&start[i]=='_'){
                // cout<<i<<endl;
                if(left.size()==0)return false;
                int lefts=lower_bound(left.begin(),left.end(),i)==left.end()?n+1:*lower_bound(left.begin(),left.end(),i);
            int rights=lower_bound(right.begin(),right.end(),i)==right.end()?n+1:*lower_bound(right.begin(),right.end(),i);
                
                if(lefts>rights||lefts==n+1){
                    return false;
                }
                swap(start[i],start[lefts]);
                left.erase(lefts);
                left.insert(i);
            }
            
            
            // left.erase(i);
            
        }
        set<int> lef,righ;
        for(auto it=left.begin();it!=left.end();it++){
            lef.insert(-1*(*it));
        }
        for(auto it=right.begin();it!=right.end();it++){
            righ.insert(-1*(*it));
        }
        for(int i=n;i>=0;i--){
            if(target[i]=='R'&&start[i]=='_'){
                // cout<<i<<endl;
                // if(right.size())return 0;
    int rights=lower_bound(righ.begin(),righ.end(),-1*i)==righ.end()?-n-1:*lower_bound(right.begin(),right.end(),-1*i);
              int lefts=lower_bound(lef.begin(),lef.end(),-1*i)==lef.end()?-n-1:*lower_bound(left.begin(),left.end(),-1*i);
                if(lefts>rights||rights==-n-1)return false;
                swap(start[i],start[rights]);
                right.erase(rights);
                right.insert(-1*i);
            }
        }
        // cout<<"ok"<<endl;
        return start==target;
        // return true;
    }
};