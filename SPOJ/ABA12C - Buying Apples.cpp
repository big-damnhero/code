    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
     
    ll dp[105][105],n,k,inf=100000000,ar[105];
     
    ll f(int cnt,int kg)
    {
        //cout<<kg<<" "<<k<<endl;
        if(cnt>n||kg>k)
        return inf;
        if(kg==k)
        return 0;
        //cout<<dp[cnt][kg]<<endl;
        if(dp[cnt][kg]!=inf)
        return dp[cnt][kg];
            for(int i=1;i<=k;i++)
            {
                if(ar[i]!=-1)
                dp[cnt][kg]=min(dp[cnt][kg],ar[i]+f(cnt+1,kg+i));
                //cout<<dp[cnt][kg]<<endl;
     
            }
     
            return dp[cnt][kg];
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
            cin>>n>>k;
            for(int i=1;i<=k;i++)
            cin>>ar[i];
            for(int i=0;i<=n;i++)
            {
                for(int j=0;j<=k;j++)
                dp[i][j]=inf;
            }
            ll res=f(0,0);
            if(res>=inf)
            cout<<"-1"<<endl;
            else
            cout<<res<<endl;
     
        }
     
        return 0;
    }
     
