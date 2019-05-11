#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,res=0,lo=0,hi=0;
    cin>>n;
    vector <ll> v(n),v1,v2;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                v1.push_back(v[i]*v[j]+v[k]);
            }
        }
    }
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(v[k]==0)
                    continue;
                v2.push_back((v[i]+v[j])*v[k]);
            }
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for (int i=0;i<v1.size();i++)
    {
        lo=lower_bound(v2.begin(),v2.end(),v1[i])-v2.begin();
        hi=upper_bound(v2.begin(),v2.end(),v1[i])-v2.begin();
        res+=(hi-lo);
    }
    cout<<res<<endl;
 
 
}
