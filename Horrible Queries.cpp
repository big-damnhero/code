#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll tree[4*100005],lazy[4*100005];

void update_tree(ll start,ll end,ll node,ll x,ll y,ll val)
{
    if(lazy[node]!=0)
    {
        tree[node]+=(end-start+1)*lazy[node];
        if(start!=end)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];

        }
        lazy[node]=0;
    }
    if(end<x||start>y||start>end)
        return;
    if(x<=start&&y>=end)
    {
        tree[node]+=(end-start+1)*val;
        if(start!=end)
        {
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return ;
    }
    ll mid=(start+end)/2;
    update_tree(start,mid,2*node,x,y,val);
    update_tree(mid+1,end,2*node+1,x,y,val);
    tree[node]=tree[2*node]+tree[2*node+1];
}

ll query(ll start,ll end,ll node,ll x,ll y)
{
    if(lazy[node]!=0)
    {
        tree[node]+=(end-start+1)*lazy[node];
        if(start!=end)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];

        }
        lazy[node]=0;
    }
    if(end<x||start>y||start>end)
        return 0;
    if(x<=start&&y>=end)
     return tree[node];
    ll mid=(start+end)/2;
    ll q1=query(start,mid,2*node,x,y);
    ll q2=query(mid+1,end,2*node+1,x,y);
    return q1+q2;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        ll n,q;
        cin>>n>>q;
        while(q--)
        {
            ll temp;
            cin>>temp;
            if(temp==0)
            {
                ll x,y,val;
                cin>>x>>y>>val;
                update_tree(1,n,1,x,y,val);
            }
            else
            {
                ll x,y;
                cin>>x>>y;
                cout<<query(1,n,1,x,y)<<endl;
            }

        }
    }
    return 0;
}
