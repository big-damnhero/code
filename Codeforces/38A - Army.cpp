#include <bits/stdc++.h>
#define ll long long

using namespace std;




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    int t;
//    cin>>t;
//    while(t--)
    {
       int n;
       cin>>n;
       int ar[n+1];
       for(int i=1;i<n;i++)
       {
        cin>>ar[i];
       }
       int x,y;
       cin>>x>>y;
       ll res=0;
       for(int i=x;i<y;i++)
       {
            res+=ar[i];

       }
       cout<<res<<endl;

    }
    return 0;
}
