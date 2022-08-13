class Solution {
public:
    int min_deviation(vector<int>&cookies, int k, int child, int alloted, int mid, int bcha){
        if(alloted==pow(2,cookies.size())-1)
            return 1;
        if(child>k)
            return 0;
        int b=alloted;
        int sum=0;
        bool ans=false;
        for(int i=0;i<cookies.size();i++){
            if((alloted&(1<<i))==0&&sum+cookies[i]<=bcha){
                ans=ans||min_deviation(cookies,k,child,alloted|1<<i,mid,bcha-cookies[i]);
                ans=ans||min_deviation(cookies,k,child+1,alloted|1<<i,mid,mid);
            }
            
        }
        ans=ans||min_deviation(cookies,k,child+1,alloted,mid,bcha);
        return ans;
        
    }
    int distributeCookies(vector<int>& cookies, int k) {
        if(k==cookies.size())
            return *max_element(cookies.begin(),cookies.end());
        int l=*max_element(cookies.begin(),cookies.end()),r=0,ans=-1;
        for(int a:cookies)
            r+=a;
        while(l<=r){
            int mid=(l+r)/2;
            if(min_deviation(cookies,k,1,0, mid,mid)) {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
    
};