    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    int main()
    {
     ll i=1;
     while(true)
        {
          ll n;
          cin >>n;
          if(n==0)
             return 0;
          ll a[n][3];
          for (int i=0;i<n;i++)
             cin >>a[i][0]>>a[i][1]>>a[i][2];
          if(n==1)
             cout<<i<<". "<<a[0][1]<<endl;
      else {
     
       a[1][0] += a[0][1];
       a[0][2] += a[0][1];
       a[1][1] += min(min(a[1][0],a[0][1]),a[0][2]);
       a[1][2] += min(min(a[0][2],a[0][1]),a[1][1]);
     
     
     
       for(int i  = 2 ; i<n;i++)
       {
        a[i][0] += min(a[i-1][0],a[i-1][1]);
        a[i][1] += min(min(min(a[i][0],a[i-1][0]),a[i-1][1]),a[i-1][2]);
        a[i][2] += min(min(a[i][1],a[i-1][1]),a[i-1][2]);
       }
       cout <<i<<". "<<a[n-1][1]<<endl;
       i++;
      }
     }
    return 0;
    }
     
