// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+11;
// int h[N];
// int idx=0;
// int n,m;
// void down(int u)
// {
//     int t=u;
//     //和节点中较小的数字交换
//     if(2*u<=idx&&h[2*u]<h[t])t=2*u;
//     if(2*u+1<=idx&&h[2*u+1]<h[t])t=2*u+1;
//     if(u!=t)
//     {
//         swap(h[u],h[t]);
//         down(t);
//     }
// }
// void up(int u)
// {
//     while(u/2 && h[u/2]>h[u])
//     {
//         swap(h[u/2],h[u]);
//         u/=2;
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;

//     for(int i=1;i<=n;i++)cin>>h[i];
//     idx=n;
//     for(int i=n/2;i>=1;i--)down(i);//叶子节点不用 down
//     while(m--)
//     {
//         cout<<h[1]<<" ";
//         h[1]=h[idx];
//         idx--;//删去最后一个元素
//         down(1);
//     }
//     return 0;
// }


// //不熟
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// int h[N];
// int n,m;
// int siz;
// void down(int u)
// {
//     int t=u;
//     if(2*u<=siz&&h[2*u]<h[t])t=2*u;
//     if(2*u+1<=siz&&h[2*u+1]<h[t])t=2*u+1;
//     if(u!=t)
//     {
//         swap(h[u],h[t]);
//         down(t);
//     }

// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>h[i];
//     siz=n;
//     for(int i=n/2;i>=1;i--)down(i);
//     while(m--)
//     {
//         cout<<h[1]<<" ";
//         h[1]=h[siz];//删除的思路
//         siz--;
//         down(1);//
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
int h[N];
int n,m;
int siz;
void down(int u)
{
    int t=u;
    //和小的比较
    if(2*u<=siz&&h[2*u]<h[t])t=2*u;
    if(2*u+1<=siz&&h[2*u+1]<h[t])t=2*u+1;
    if(u!=t)
    {
        swap(h[u],h[t]);
        down(t);
    }
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>h[i];
    siz=n;
    for(int i=n/2;i>=1;i--)down(i);
    while(m--)
    {
        cout<<h[1]<<" ";
        h[1]=h[siz];
        siz--;
        down(1);
    }
    return 0;
}