    #include <bits/stdc++.h>
    #define MAX 100010
    #define pb push_back
    #define ll long long
    using namespace std;
     
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int n;
            cin>>n;
            ll ar[n];
            for(int i=0;i<n;i++)
            {
                cin>>ar[i];
            }
            ll cnt[1005];
            memset(cnt,0,sizeof(cnt));
            cnt[ar[0]]++;
            string ans="YES";
            for(int i=1;i<n;i++)
            {
                if(ar[i]==ar[i-1])
                {
                    cnt[ar[i]]++;
                }
                else
                {
                    if(cnt[ar[i]]!=0)
                    {
                        ans="NO";
                        break;
                    }
                    else
                    {
                        cnt[ar[i]]++;
                    }
                }
            }
            set<ll> myset;
            ll x=0;
            for(int i=0;i<1005;i++)
            {
                if(cnt[i])
                {
                    myset.insert(cnt[i]);
                    x++;

                }
            }
            //cout<<x<<endl;
            if(x!=myset.size())
                ans="NO";
            cout<<ans<<endl;
        }
        
        
        return 0;
    }
