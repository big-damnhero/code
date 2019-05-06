#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll  ar[100000+5];
vector<ll> tree[4*100005];

void build_tree(int start,int end,int node)
{
    if(start==end)
    {
    tree[node].push_back(ar[start]);
    return ;
    }
    else{
    int mid=(start+end)/2;
    build_tree(start,mid,2*node);
    build_tree(mid+1,end,2*node+1);
    int n=tree[2*node].size();
    int m=tree[2*node+1].size();
    tree[node].resize(n+m);
    int i=0,j=0,k=0;
    while(i<n&&j<m)
    {
        if(tree[2*node][i]<tree[2*node+1][j])
        {
            tree[node][k]=tree[2*node][i];
            k++;
            i++;
        }
        else
        {
            tree[node][k]=tree[2*node+1][j];
            k++;
            j++;
        }

    }
    while(i<n)
    {
            tree[node][k]=tree[2*node][i];
            k++;
            i++;
    }
    while(j<m)
    {
            tree[node][k]=tree[2*node+1][j];
            k++;
            j++;
    }
    return ;

    }
}

int query(int start,int end,int node,int x,int y,int val)
{
    if(start>y||end<x)
    return 0;
    if(start>=x&&end<=y)
    return upper_bound(tree[node].begin(),tree[node].end(),val)-tree[node].begin();
    else
    {
        int mid=(start+end)/2;
        return query(start,mid,2*node,x,y,val)+query(mid+1,end,2*node+1,x,y,val);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    build_tree(1,n,1);
    sort(ar+1,ar+n+1);
    while(q--)
    {
        int x,y,val;
        cin>>x>>y>>val;
        int low=1,high=n,mid,idx;
        while(low<=high)
        {
            mid=(low+high)/2;
            int temp=query(1,n,1,x,y,ar[mid]);
            if(temp>=val)
            {
            idx = mid;
            high=mid-1;
            }
            else
            low=mid+1;
        }
        cout<<ar[idx]<<endl;
    }
    return 0;
}
