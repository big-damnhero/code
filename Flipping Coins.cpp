#include <bits/stdc++.h>

using namespace std;

int tree[4*100005],lazy[4*100005];

void update_tree(int start,int end,int node,int x,int y)
{
    if(lazy[node])
    {
        tree[node]=(end-start+1)-tree[node];
        if(start!=end)
        {
            lazy[2*node+1]=1-lazy[2*node+1];
            lazy[2*node+2]=1-lazy[2*node+2];

        }
        lazy[node]=0;
    }
    if(start>end||start>y||end<x)
    return;
    if(start>=x&&y>=end)
    {
        tree[node]=(end-start+1)-tree[node];
        if(start!=end)
        {
            lazy[2*node+1]=1-lazy[2*node+1];
            lazy[2*node+2]=1-lazy[2*node+2];

        }
        return;
    }
    int mid=(start+end)/2;
    update_tree(start,mid,2*node+1,x,y);
    update_tree(mid+1,end,2*node+2,x,y);
    tree[node]=tree[2*node+1]+tree[2*node+2];
}

int query(int start,int end,int node,int x,int y)
{
    if(lazy[node])
    {
        tree[node]=(end-start+1)-tree[node];
        if(start!=end)
        {
            lazy[2*node+1]=1-lazy[2*node+1];
            lazy[2*node+2]=1-lazy[2*node+2];

        }
        lazy[node]=0;
    }
    if(start>end||start>y||end<x)
    return 0;
    if(start>=x&&y>=end)
    {
        return tree[node];
    }
    int mid=(start+end)/2;
    return query(start,mid,2*node+1,x,y)+query(mid+1,end,2*node+2,x,y);

}

int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=0;i<q;i++)
    {
        int temp,x,y;
        cin>>temp>>x>>y;
        if(temp)
        {
            cout<<query(0,n-1,0,x,y)<<endl;
        }
        else
        {
            update_tree(0,n-1,0,x,y);
        }

    }
    return 0;
}
