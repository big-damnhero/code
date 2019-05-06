#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll  ar[1000000+5];
struct st
{
   ll val,lev;
}tree[1000005];

void build_tree(int start,int end,int node)
{
    if(start==end)
    {
    tree[node].val=ar[start];
    tree[node].lev=0;
    return ;
    }
    else{
    int mid=(start+end)/2;
    build_tree(start,mid,2*node);
    build_tree(mid+1,end,2*node+1);
    tree[node].lev=tree[2*node].lev+1;
    if(tree[node].lev%2==1)
    tree[node].val=tree[2*node].val|tree[2*node+1].val;
    else
    tree[node].val=tree[2*node].val^tree[2*node+1].val;
    return ;

    }
}

void update_tree(int start,int end,int node,int x,int y)
{
    if(start==end)
    {
    tree[node].val=y;
    return ;
    }
    else
    {
        int mid=(start+end)/2;
        if(mid>=x)
        update_tree(start,mid,2*node,x,y);
        else
        update_tree(mid+1,end,2*node+1,x,y);
        if(tree[node].lev%2==1)
        tree[node].val=tree[2*node].val|tree[2*node+1].val;
        else
        tree[node].val=tree[2*node].val^tree[2*node+1].val;
        return;

    }

}

int main()
{
    int n,q;
    cin>>n>>q;
    n=pow(2,n);
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    build_tree(1,n,1);
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        update_tree(1,n,1,x,y);
        cout<<tree[1].val<<endl;
    }
    return 0;
}
