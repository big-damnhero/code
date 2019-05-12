#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int res=0;
        while(n>0&&m>0)
        {
            if(n+m<3)
            break;
            if(m>n)
            {
                m-=2;
                n--;
                res++;
            }
            else
            {
                n-=2;
                m--;
                res++;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
