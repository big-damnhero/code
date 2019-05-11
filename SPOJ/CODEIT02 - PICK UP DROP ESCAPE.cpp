#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n,k,ar[20];

int f(int cnt_k,int idx,int val)
{
    if(cnt_k==k)
    return val;
    if(idx>=n)
    return 0;

    return max(f(cnt_k,idx+1,val),f(cnt_k+1,idx+1,val^ar[idx]));
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        cout<<f(0,0,0)<<endl;
    }
    return 0;
}
