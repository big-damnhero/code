#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll ar[100];
    ar[0]=ar[1]=1;
    int i=2;
    while(true)
    {
        ar[i]=ar[i-1]+ar[i-2];
        if(ar[i]>1000000000000000)
        break;
        i++;
    }
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll res=0;
        while(n)
        {
            if(n==1)
            {
                res+=2;
                break;
            }
            for(int j=0;j<=i;j++)
            {
                if(ar[j]==n)
                {
                    res+=ar[j+1];
                    n-=ar[j];
                    break;
                }
                if(ar[j]>n)
                {
                    res+=ar[j];
                    n-=ar[j-1];
                    break;
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
