#include <iostream>
 
using namespace std;
int rev(int x)
{
    int s=0;
    while(x>0)
    {
        int r=x%10;
        s=s*10+r;
        x=x/10;
    }
    return s;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int r1=rev(a);
        int r2=rev(b);
        int s1=r1+r2;
        int r3=rev(s1);
        while(r3%10==0)
        {
            r3=r3/10;
        }
        cout<<r3<<endl;
 
 
    }
    return 0;
}
