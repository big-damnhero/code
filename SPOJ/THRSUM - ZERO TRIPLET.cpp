#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
        sort(ar,ar+n);
//        for(int i=0;i<n;i++)
//        cout<<ar[i]<<" ";
//        cout<<endl;
        int pos[n],zero[n],neg[n];
        int i,j,k;
        for(i=0;i<n;i++)
        {
            if(ar[i]>=0)
            break;
            neg[i]=ar[i];
        }
        int size_neg=i;
        for(j=i;j<n;j++)
        {

            if(ar[j]>0)
            break;
            zero[j-i]=ar[j];

        }
        int size_zero=j-size_neg;
        for(k=j;k<n;k++)
        {
            pos[k-j]=ar[k];

        }
        int size_pos=n-j;
        map<pair<int,pair<int,int> >,int> mymap;

        if(size_zero)
        {
            for(int i=0;i<size_neg;i++)
            {
                if(binary_search(pos,pos+size_pos,-1*neg[i]))
                mymap[{neg[i],{0,-1*neg[i]}}]=0;
            }
        }
        if(size_zero>=3)
        mymap[{0,{0,0}}]=0;

        for(int i=0;i<size_pos-1;i++)
        {
            for(int j=i+1;j<size_pos;j++)
            {
                if(binary_search(neg,neg+size_neg,-1*(pos[i]+pos[j])))
                mymap[{-1*(pos[i]+pos[j]),{pos[i],pos[j]}}]=0;
            }
        }

        for(int i=0;i<size_neg-1;i++)
        {
            for(int j=i+1;j<size_neg;j++)
            {
                if(binary_search(pos,pos+size_pos,-1*(neg[i]+neg[j])))
                mymap[{(neg[i]),{neg[j],-1*(neg[i]+neg[j])}}]=0;
            }
        }

        cout<<mymap.size()<<endl;
        for(auto &a:mymap)
        {
            cout<<a.first.first<<" "<<a.first.second.first<<" "<<a.first.second.second<<endl;
        }

    }
    return 0;
}
