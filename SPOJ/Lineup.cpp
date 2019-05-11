#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        n=11;
        int ar[n][n];
        ll dp[1<<n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cin>>ar[i][j];
        }
        memset(dp,-10000000,sizeof(dp));
        dp[0]=0;
        //cout<<f(0,0)<<endl;
       for(int mask=0;mask<(1<<n);mask++)
        {
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                if(mask&(1<<i))
                cnt++;
            }
            for(int j=0;j<n;j++)
            {
                if((!(mask&(1<<j)))&&ar[cnt][j])
                dp[mask|(1<<j)]=max(dp[mask|(1<<j)],dp[mask]+ar[cnt][j]);
            }
        }
        cout<<dp[(1<<n)-1]<<endl;
    }
    return 0;
}
