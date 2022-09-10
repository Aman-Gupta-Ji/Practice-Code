void solve(){
    int n;
    cin>>n;
    int l=1,r=n;
    // int ans=0;
    while(l<r){
        int mid=(l+r)/2;
        cout<<"?"<<" "<<l<<" "<<mid<<endl;
        int size=mid-l+1;
        int ok=0;
        for(int i=0;i<size;i++){
            int a;cin>>a;
            if(a>=l&&a<=mid)
                ++ok;
        }
        if(ok%2)
            r=mid;
        else 
            l=mid+1;
    }
    cout<<"!"<<" "<<l<<endl;
}