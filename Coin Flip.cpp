#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int g;
        cin>>g;
        while(g--)
        {
            int l,n,q,heads,tails;
            cin>>l>>n>>q;
            if(n%2==0)
                cout<<n/2<<endl;
            else{
                if(l==1)
                {
                heads=n/2;
                tails=n/2+1;

                }
                else
                {
                heads=n/2+1;
                tails=n/2;
                }
                if(q==1)
                {
                cout<<heads<<endl;
                }
                else
                cout<<tails<<endl;
            }
        }
    }
    return 0;
}
