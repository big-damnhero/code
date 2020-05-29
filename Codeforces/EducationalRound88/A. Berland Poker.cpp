#include <bits/stdc++.h>
#define MAX 100010
#define pb push_back
#define ll long long
using namespace std;

ll ar[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
    {

    
        ll n,m,k;
        cin>>n>>m>>k;
        ll no=n/k;
        //cout<<n<<" "<<m<<" "<<k<<endl;
        if(no>=m)
        {
        	cout<<m<<endl;
            //cout<<m<<endl;
            continue;
        }
        m-=no;
        ll i=1;
        while(true)
        {
            if((k-1)*i>=m)
            {
                cout<<no-i<<endl;
                break;
            }
            i++;
            //cout<<i<<endl;
        }




    }


    return 0;
}