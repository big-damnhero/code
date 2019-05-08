#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mx = 400005;

ll tree[4*mx],lazy[4*mx];

void update_tree(int start,int end,int node,int x,int y,int val)
{
    //cout<<"node update : "<<node<<endl;
    if(lazy[node])
    {
        tree[node]=lazy[node];
        if(start!=end)
        {
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];

        }
        lazy[node]=0;
    }
    if(start>y||end<x)
    return;
    if(x<=start&&y>=end)
    {
        tree[node]=val;
        if(start!=end)
        {
            lazy[2*node]=val;
            lazy[2*node+1]=val;

        }
        return;
    }
    int mid=(start+end)/2;
    update_tree(start,mid,2*node,x,y,val);
    update_tree(mid+1,end,2*node+1,x,y,val);
    tree[node]=max(tree[2*node],tree[2*node+1]);
}

ll query(int start,int end,int node,int x,int y)
{
    //cout<<"node query : "<<node<<endl;
    if(lazy[node])
    {
        tree[node]=lazy[node];
        if(start!=end)
        {
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>y||end<x)
    return -1;
    if(x<=start&&y>=end)
    {
        return tree[node];
    }
    int mid=(start+end)/2;
    return max(query(start,mid,2*node,x,y),query(mid+1,end,2*node+1,x,y));
}

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
        map<ll,ll> mymap;
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        vector<pair<ll,ll> >v(n);
        for(int i=0;i<n;i++)
        {
          cin>>v[i].first>>v[i].second;
          mymap[v[i].first]=0;
          mymap[v[i].second]=0;


        }
        int i=1;
        for(map<ll,ll>::iterator it=mymap.begin();it!=mymap.end();it++)
        {
            it->second=i;
            i++;
        }
        for(int i=0;i<n;i++)
        {
            v[i].first=mymap[v[i].first];
            v[i].second=mymap[v[i].second];
        }
        for(int i=0;i<n;i++)
        {
            update_tree(1,mx,1,v[i].first,v[i].second,i+1);
        }
        set<ll> myset;
        for(int i=1;i<=4*n+1;i++)
        {
            myset.insert(query(1,mx,1,i,i));
        }
        int res=myset.size();
        if(myset.find(0)!=myset.end())
        res--;
        cout<<res<<endl;
    }
    return 0;
}
