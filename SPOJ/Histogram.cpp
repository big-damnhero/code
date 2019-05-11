#include <bits/stdc++.h>
#define ll long long

using namespace std;

int dp[1<<15][15];
ll cnt[1<<15][15];
int ar[15],n;

int f(int mask,int idx)
{
    if(mask==(1<<n)-1)
    {
        cnt[mask][idx]=1;
        return ar[idx];
    }
    if(idx>=n)
    {
        return 0;
    }
    if(dp[mask][idx]!=-1)
    {
        return dp[mask][idx];
    }
    int res=0,val;
    for(int i=0;i<n;i++)
    {
        if(mask&(1<<i))
        continue;
        else
        {
            val=f(mask|(1<<i),i)+abs(ar[i]-ar[idx]);
            if(val>res)
            {
                res=val;
                cnt[mask][idx]=0;
            }
            if(val==res)
            {
                cnt[mask][idx]+=cnt[mask|(1<<i)][i];
            }

        }
    }
    return dp[mask][idx]=res;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        memset(dp,-1,sizeof(dp));
        int mx=0;
        ll cnt_mx=0;
        for(int i=0;i<n;i++)
        {
            int val=f(1<<i,i)+ar[i];
            if(val>mx)
            {
                mx=val;
                cnt_mx=0;
            }
            if(val==mx)
            {
                cnt_mx+=cnt[1<<i][i];
            }
        }
        mx+=(n<<1);
        cout<<mx<<" "<<cnt_mx<<endl;
        cin>>n;
    }
    return 0;
}
