#include <bits/stdc++.h>
#define MAX 100010
#define pb push_back
#define ll long long
using namespace std;


ll t,h,c;

ll ar[500002];

double f(ll m1)
{
    return abs(t-(((m1+1)/2)*(h*1.0)+(m1/2)*(c*1.0))/m1);
}

ll ternary_s(ll l,ll r)
{

    while(r-l>3)
    {
        //cout<<r<<" "<<l<<endl;
        ll m1=l+((r-l)/3);
        ll m2=r-((r-l)/3);
        double f1=f(ar[m1]);
        double f2=f(ar[m2]);
        //cout<<f1<<" "<<f2<<endl;
        if(f1<f2)
        {
            r=m2;
            
        }
        else
        {
            l=m1;
        }

    }
    ll ans=l;
    //cout<<ans<<endl;
    for(int i=l;i<=r;i++)
    {
        if(f(ar[i])<f(ar[ans]))
            ans=i;
    }
    //cout<<ans<<endl;
    return ar[ans];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x=1;
    cin>>x;
    
    ll j=1;
    for(int i=0;i<500002;i++)
    {
        ar[i]=j;
        j+=2;
    }
    while(x--)
    {

    
        cin>>h>>c>>t;
        ll val=ternary_s(0,500001);
        ll val2=f(2);
        if(val2<f(val))
            val=2;
        cout<<val<<endl;


    }


    return 0;
}