// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,k;
// const int N=1e6+11;
// int a[N];
// int quick_select(int l,int r,int k)
// {
//     //k 永远在 l,r之间 l==r 说明就是我们要的结果
//     if(l==r)return a[l];

//     int x=a[(l+r)/2],i=l-1,j=r+1;
//     while(i<j)
//     {
//         do i++;while(a[i]<x);
//         do j--;while(a[j]>x);

//         if(i<j)swap(a[i],a[j]);
//     }
//     int sk=j-l+1;//左边面的数字
//     if(k<=sk)return quick_select(l,j,k);
//     else return quick_select(j+1,r,k-sk);//注意这里


// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>k;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     cout<<quick_select(1,n,k);
//     return 0;
// }





#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=1e6+11;
int a[N];
int quick_select(int l,int r,int k)
{
    if(l==r)return a[l];
    int x=a[(l+r)>>1];
    int i=l-1,j=r+1;
    while(i<j)
    {
        do i++;while(a[i]<x);
        do j--;while(a[j]>x);
        if(i<j)swap(a[i],a[j]);
    }
    if(j-l+1>=k) return quick_select(l,j,k);
    else  return quick_select(j+1,r,k-(j-l+1));//!!!
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    cout<<quick_select(1,n,k);
    //for(int i=1;i<=n;i++)cout<<a[i]<<" ";    
}

