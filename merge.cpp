#include <bits/stdc++.h>

using namespace std;

int ar[100];

void merg(int low,int mid,int high)
{
    int l1=mid-low+1,l2=high-mid;
    int left[l1],right[l2];
    for(int i=0;i<l1;i++)
    {
        left[i]=ar[low+i];
    }
     for(int i=0;i<l2;i++)
    {
        right[i]=ar[1+i+mid];
    }
    int l=0,k=low,r=0;
    while(l<l1&&r<l2)
    {
        if(left[l]<=right[r])
        {
            ar[k]=left[l];
            l++;
            k++;
        }
        else
        {
            ar[k]=right[r];
            r++;
            k++;
        }
    }
    while(l<l1)
    {
        ar[k]=left[l];
        k++;
        l++;
    }
    while(r<l2)
    {
        ar[k]=right[r];
        r++;
        k++;
    }

}

void merge_sort(int start,int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        merge_sort(start,mid);
        merge_sort(mid+1,end);
        merg(start,mid,end);
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    cin>>ar[i];
    }

    merge_sort(0,n-1);
    
    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
    return 0;
}
