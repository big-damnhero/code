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
        cin>>n;
        int ar[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>ar[i][j];
            }
        }
        ll x=pow(2,n);
        ll dp[x];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int mask=0;mask<x;mask++)
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
                dp[mask|(1<<j)]+=dp[mask];
            }
        }
        cout<<dp[x-1]<<endl;
    }
    return 0;
}
