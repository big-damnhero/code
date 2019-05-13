    #include <bits/stdc++.h>
    #define ll long long
     
    using namespace std;
     
    ll costx[1005],costy[1005],res;
     
    ll f(int x1,int x2,int y1,int y2)
    {
        //cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<" "<<res<<endl;
        if(x2-x1==1&&y2-y1==1)
        return 0;
        ll idx, mx=-1;
        for(int i=x1+1;i<x2;i++)
        {
            if(costx[i]>mx)
            {
                idx=i;
                mx=costx[i];
            }
        }
        ll idy,my=-1;
        for(int i=y1+1;i<y2;i++)
        {
            if(costy[i]>my)
            {
                idy=i;
                my=costy[i];
            }
        }
        if(mx>my)
        res=f(x1,idx,y1,y2)+costx[idx]+f(idx,x2,y1,y2);
        else
        res=f(x1,x2,y1,idy)+f(x1,x2,idy,y2)+costy[idy];
        return res;
    }
     
     
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin>>t;
        while(t--)
        {
            res=0;
            int n,m;
            cin>>m>>n;
            for(int i=1;i<=m-1;i++)
            cin>>costx[i];
            for(int i=1;i<=n-1;i++)
            cin>>costy[i];
            cout<<f(0,m,0,n)<<endl;
        }
        return 0;
    }
     
