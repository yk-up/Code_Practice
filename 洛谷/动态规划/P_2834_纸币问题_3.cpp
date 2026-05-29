// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e4+7;
// const int p=1e9+7;
// int n,w;
// int dp[N];//凑i元的方案数 与顺序无关
// int a[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>w;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     dp[0]=1;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=a[i];j<=w;j++)
//         {
//             if(j>=a[i])
//             dp[j]=(dp[j]+dp[j-a[i]])%p;
//         }
//     }
//     cout<<dp[w];
//     return 0;
// }


// //纸币1 完全背包 使用最少的硬币数
// for(int i=1;i<=n;i++)
// {
//     for(int j=a[i];j<=w;j++)
//     {
//         dp[j]=min(dp[j],dp[j-a[i]]+1);
//     }
// }
// //纸币2 完全背包 和顺序有关 多少种方案
// for(int j=1;j<=w;j++)
// {
//     for(int i=1;i<=n;i++)
//     {
//         if(j>=a[i])//👉 就是在数“最后一步是谁”，顺序天然不同
//             dp[j]=(dp[j]+dp[j-a[i]])%p;
//     }
// }
// //纸币3 完全背包  恰好凑齐面额 w 的纸币组合数量
// for(int i=1;i<=n;i++)
// {
//     for(int j=a[i];j<=w;j++)
//     {
//         if(j>=a[i])
//         dp[j]=(dp[j]+dp[j-a[i]])%p;
//     }
// }


#include<bits/stdc++.h>
using namespace std;
const int p=1e9+7;
const int N=1e5+11;
int dp[N];
int a[N];
int n,w;
int main()
{
    cin>>n>>w;
    for(int i=1;i<=n;i++)cin>>a[i];
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(j>=a[i])
            dp[j]=(dp[j]+dp[j-a[i]])%p;
        }
    }
    cout<<dp[w];
    return 0;
}