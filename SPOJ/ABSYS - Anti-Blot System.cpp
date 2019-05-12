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
        string s1,s2,s3;
        char c1,c2;
        int res1=0,res2=0,res3=0;
        int temp=0;
        cin>>s1>>c1>>s2>>c2>>s3;
        int n1=s1.length();
        for(int i=0;i<n1;i++)
        {
            if(isdigit(s1[i]))
            res1=res1*10+(s1[i]-'0');
            else
            {
                temp=1;
                break;
            }
        }
        int n2=s2.length();
        for(int i=0;i<n2;i++)
        {
            if(isdigit(s2[i]))
            res2=res2*10+(s2[i]-'0');
            else
            {
                temp=2;
                break;
            }
        }
        int n3=s3.length();
        for(int i=0;i<n3;i++)
        {
            if(isdigit(s3[i]))
            res3=res3*10+(s3[i]-'0');
            else
            {
                temp=3;
                break;
            }
        }
        //cout<<temp<<endl;
        if(temp==1)
        cout<<res3-res2<<" "<<c1<<" "<<res2<<" "<<c2<<" "<<res3<<endl;
        if(temp==2)
        cout<<res1<<" "<<c1<<" "<<res3-res1<<" "<<c2<<" "<<res3<<endl;
        if(temp==3)
        cout<<res1<<" "<<c1<<" "<<res2<<" "<<c2<<" "<<res2+res1<<endl;
    }
    return 0;
}
