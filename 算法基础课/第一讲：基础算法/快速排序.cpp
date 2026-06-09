// #include<bits/stdc++.h>
// using namespace std;
// #define int long long 
// int n;
// const int N=1e6+11;
// int a[N];
// void quick_sort(int a[],int l,int r)
// {
//     if(l>=r)return;//没有元素或者只有一个元素的话就结束

//     //数据加强后，取左端点、右端点、中点都会超时，只有随机取才不会超时。。。
//     int x=a[(l+r)/2],i=l-1,j=r+1;
//     while(i<j)
//     {
//         do i++;while(a[i]<x);
//         do j--;while(a[j]>x);
//         if(i<j)swap(a[j],a[i]);
//     }

//     //递归
//     quick_sort(a,l,j);
//     quick_sort(a,j+1,r);//这个范围要记录 使用 j 吧，否则可能会导致一系列问题
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)cin>>a[i];

//     quick_sort(a,1,n);
//     for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+11;
int a[N];
int n;
void quicksort(int a[],int l,int r)
{
    if(l==r)return;
    int x=a[(l+r)/2],i=l-1,j=r+1;
    while(i<j)
    {
        do i++;while(a[i]<x);//必须是严格小于，严格符号让数组内部等于 $x$ 的元素自动充当了停止指针的哨兵。
        do j--;while(a[j]>x);
        if(i<j)swap(a[i],a[j]);
    }

    quicksort(a,l,j);
    quicksort(a,j+1,r);
    return ;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    quicksort(a,1,n);
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    return 0;
}