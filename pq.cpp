class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<vector<int>,vector<vector<int> >,greater<vector<int>>> pq;
        pq.push({0,0,0});
        vector<vector<int>> visited(n,vector<int>(m,1e9));
        int n=grid.size(),m=grid[0].size();
        visited[0][0]=0;
        int a[5]={1,0,-1,0,1};
        int x, i;
        while(pq.size()){
            vector<int> Ar=pq.top();
            pq.pop();
            if(Ar[2]==m-1 && Ar[1]==n-1)
                return Ar[0];
            for(i=0;i<4;i++){
                x=Ar[1]+a[i],y=Ar[2]+a[i+1];
                if(x<n && y>=0 && y<m && x>=0){
                    if(grid[x][y]==1) {
                        if((1+Ar[0]) < visited[x][y]) {
                            pq.push({1+Ar[0],x,y});
                            visited[x][y]=1+Ar[0];
                        }
                    }
                    else {
                        if(Ar[0]<visited[x][y]) {
                            pq.push({Ar[0],x,y});
                            visited[x][y]=Ar[0];
                        }
                    }
                }
            }
        }
        return -1;
    }
};