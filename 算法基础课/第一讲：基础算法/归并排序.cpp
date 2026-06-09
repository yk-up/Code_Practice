// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e6+11;
// int a[N];
// int n;
// int temp[N];
// void merge_sort(int l,int r)
// {
//     if(l>=r)return;
//     int mid=(l+r)/2;//注意这里的是位置，快排里面的是大小
//     merge_sort(l, mid);merge_sort(mid+1,r);

//     int k=0,i=l,j=mid+1;
//     while(i<=mid&&j<=r)
//     {
//         if(a[i]<=a[j])temp[k++]=a[i++];
//         else temp[k++]=a[j++];
//     }
//     while(i<=mid)temp[k++]=a[i++];
//     while(j<=r)temp[k++]=a[j++];

//     //复制回原数组
//     for(int i=l,j=0;i<=r;i++,j++)a[i]=temp[j];
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     merge_sort(1,n);
//     for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+11;
int a[N];
int temp[N];
int n;
void mergesort(int l,int r)
{
    if(l==r)return ;
    int mid=(l+r)/2;
    int i=l,j=mid+1;int k=0;
    mergesort(l,mid);mergesort(mid+1,r);

    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j])temp[k++]=a[i++];
        else temp[k++]=a[j++];
    }
    while(i<=mid)temp[k++]=a[i++];
    while(j<=r)temp[k++]=a[j++];
    //归并
    for(int i=l,j=0;i<=r;)a[i++]=temp[j++];
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    mergesort(1,n);
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    return 0;
}