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

    
        ll n,m,x,y;
        cin>>n>>m>>x>>y;
        ll cost;
        if(2*x<=y)
            cost=2*x;
        else
            cost=y;
        char ch[n][m];
        ll res=0;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<m;j++)
            {
                cin>>ch[i][j];
                if(ch[i][j]=='*')
                {

                    res+=(cnt/2)*cost;
                    res+=(cnt&1)*x;
                    cnt=0;
                    
                }
                else
                    cnt++;
                
                //cout<<ch[i][j]<<" ";//<<endl;
            }
            //cout<<endl;
            if(cnt)
            {
                res+=(cnt/2)*cost;
                res+=(cnt&1)*x;
            }
        }
        cout<<res<<endl;



    }


    return 0;
}