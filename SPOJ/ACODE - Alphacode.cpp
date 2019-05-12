#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    while(true)
    {
        if(s[0]=='0')
        break;
 
        int n=s.length();
        //cout<<n<<endl;
        ll dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(s[i-1]=='0')
            dp[i]+=dp[i-2];
            else if(((s[i-2]-'0')*10+s[i-1]-'0')>=11&&((s[i-2]-'0')*10+s[i-1]-'0')<=26)
            dp[i]+=(dp[i-1]+dp[i-2]);
            else
            dp[i]+=dp[i-1];
        }
        cout<<dp[n]<<endl;
        cin>>s;
 
    }
 
    return 0;
}
