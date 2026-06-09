// //本质上就是归并排序
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e6+11;
// int a[N];
// int temp[N];
// int n;
// int ans=0;
// void merge_sort(int l,int r)
// {
//     if(l>=r)return ;

//     int mid=(l+r)/2;
//     merge_sort(l,mid);merge_sort(mid+1,r);
//     int k=0,i=l,j=mid+1;
//     while(i<=mid&&j<=r)
//     {
//         if(a[i]<=a[j])temp[k++]=a[i++];
//         else
//         {
//             //ans++;
//             //此时 a[i]>a[j]
//             ans+=(mid-i+1);
//             temp[k++]=a[j++];
//         }
//     }
//     while(i<=mid)temp[k++]=a[i++];
//     while(j<=r)temp[k++]=a[j++];

//     //注意⚠️i 从 l 开始的
//     for(int i=l,j=0;i<=r;i++,j++)//a[i++]=temp[j++];
//     a[i]=temp[j];
//     return;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     merge_sort(1,n);
//     cout<<ans;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+11;
int a[N];
int temp[N];
int n;
int ans=0;
void mergesort(int l,int r)
{
    if(l==r)return ;
    int mid=l+r>>1;
    mergesort(l,mid);mergesort(mid+1,r);

    int i=l,j=mid+1;int k=0;
    //到这里 l,mid 和 mid+1,r 这两个区间已经是有序的了
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j])temp[k++]=a[i++];
        else 
        {
            ans+=(mid-i+1);
            temp[k++]=a[j++];
        }
    }
    while(i<=mid)temp[k++]=a[i++];
    while(j<=r)temp[k++]=a[j++];

    for(int i=l,j=0;i<=r;i++,j++)a[i]=temp[j];
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    mergesort(1,n);
    cout<<ans;
    return 0;
}