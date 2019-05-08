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
        map<ll,ll> mymap;
        set<ll> myset;
        vector<pair<ll,ll> >v(n);
        for(int i=0;i<n;i++)
        {
          cin>>v[i].first>>v[i].second;
          mymap[v[i].first]=0;
          mymap[v[i].second]=0;


        }
        int i=1;
        for(map<ll,ll>::iterator it=mymap.begin();it!=mymap.end();it++)
        {
            it->second=i;
            i++;
        }
        ll mx=-1;
        for(int i=0;i<n;i++)
        {
            v[i].first=mymap[v[i].first];
            v[i].second=mymap[v[i].second];
            if(mx<v[i].first)
            mx=v[i].first;
            if(mx<v[i].second)
            mx=v[i].second;
        }
        for(int i=1;i<=mx;i++)
        {
            myset.insert(i);
        }
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            int x=v[i].first;
            int y=v[i].second;
            auto it1=myset.lower_bound(x);
            auto it2=myset.upper_bound(y);
            if(it1!=it2)
            {
                ans++;
                myset.erase(it1,it2);
            }

        }
        cout<<ans<<endl;

    }
    return 0;
}
