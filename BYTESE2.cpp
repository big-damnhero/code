    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    map<ll,ll> mymap;
    vector<pair<ll,ll> > v(1001+1);
     
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
     
        ll n,q,i,a,b,res=0;
    	scanf("%lld",&n);
    	vector <ll> cnt(10010,0);
    	for(i=0;i<n;i++)
    	{
    		scanf("%lld%lld",&a,&b);
    		v[i].first=a;
    		v[i].second=b;
    		mymap[a]=0;
    		mymap[b]=0;
    	}
    	i=0;
    	for(auto &x: mymap)
    		{
    		    x.second = i;
    		    i++;
            }
     
    	for(i=0;i<n;i++)
    	{
    			cnt[mymap[v[i].first]]++;
    			cnt[mymap[v[i].second]+1]--;
    	}
    	for(i=1;i<10000;i++)
    		cnt[i]+=cnt[i-1];
            cout<<*max_element(cnt.begin(),cnt.end())<<endl;
        }
        return 0;
    }
     
