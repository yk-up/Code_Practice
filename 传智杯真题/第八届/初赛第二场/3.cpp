// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=200001;
// int a[N],b[N];
// int n,k;
// int suan=0x3f3f3f3f;
// int tiandu=0;
// bool st[N];
// void dfs(int x,int t,int s,int m)//选了多少个
// {
//     if(x>n)
//     {
//         if(m==k)
//         {
//             if(t>tiandu)
//             {
//                 tiandu=t;
//                 suan=s;
//             }
//             else if(t==tiandu)
//             {
//                 if(s<suan)
//                 {
//                     suan=s;
//                 }
//             }
//         }
//         return;
//     }
//     st[x]=1;
//     dfs(x+1,t+b[x],s+a[x],m+1);
//     st[x]=0;
//     dfs(x+1,t,s,m);
// }

// signed main()
// {
//     //先想一想暴力
//     cin>>n>>k;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     for(int i=1;i<=n;i++)cin>>b[i];
//     dfs(1,0,0,0);
//     cout<<suan<<" "<<tiandu;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
const int N=200001;
#define int long long
int n,k;
struct node
{
    int a,b;
    bool operator<(const node&u)
    {
        if(b!=u.b)return b>u.b;
        return a<u.a;
    }
}dat[N];
signed main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>dat[i].a;
    for(int i=1;i<=n;i++)cin>>dat[i].b;
    sort(dat+1,dat+1+n);
    int ans1=0,ans2=0;
    for(int i=1;i<=k;i++)
    {
        ans1+=dat[i].a;
        ans2+=dat[i].b;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}