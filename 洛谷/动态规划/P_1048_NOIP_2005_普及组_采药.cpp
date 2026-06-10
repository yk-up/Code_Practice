// //每个药只能采一次->0/1背包问题
// #include<bits/stdc++.h>
// using namespace std;
// //dp[j] = 在“总时间不超过 j”的情况下，能获得的最大价值
// const int N=1003;
// //int dp[N][N];//dp[i][j] = 只考虑前 i 株草药，时间不超过 j 的最大价值->可以优化成1为数组
// int dp[N];
// int T,M;
// int t[N],m[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>T>>M;
//     for(int i=1;i<=M;i++)
//     {
//         cin>>t[i]>>m[i];
//     }
//     // dp[0][0]=1;不对 dp[0][0]=0


//     // for(int i=1;i<=M;i++)
//     // {
//     //     for(int j=0;j<=T;j++)
//     //     {
//     //         if(j<t[i])dp[i][j]=dp[i-1][j];
//     //         else dp[i][j]=max(dp[i-1][j],dp[i-1][j-t[i]]+m[i]);
//     //     }
//     // }
//     // cout<<dp[M][T];

//     for(int i=1;i<=M;i++)
//     {
//         //从大到小遍历 j，可以保证：dp[j - t] 一定还停留在“上一轮（没用当前草药）”的状态
//         for(int j=T;j>=0;j--)//从大到小，才能保证每株草药只用一次
//         {
//             if(j>=t[i])
//             dp[j]=max(dp[j],dp[j-t[i]]+m[i]);
//         }
//     }
//     cout<<dp[T];
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int t,m;
// const int N=2000;
// int w[N],v[N];
// int dp[N][N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>t>>m;
//     //0，1背包
//     for(int i=1;i<=m;i++)cin>>w[i]>>v[i];

//     // for(int i=1;i<=m;i++)
//     // {
//     //     for(int j=t;j>=0;j--)
//     //     {
//     //         if(j>=w[i])
//     //         {
//     //             dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
//     //         }
//     //     }
//     // }
//     // cout<<dp[t];

//     for(int i=1;i<=m;i++)
//     {
//         for(int j=0;j<=t;j++)
//         {
//             dp[i][j]=dp[i-1][j];
//             if(j>=w[i])
//             dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
//         }
//     }
//     cout<<dp[m][t];
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=102;
int t[N],m[N];
int dp[N];
int T,M;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T>>M;
    for(int i=1;i<=M;i++)cin>>t[i]>>m[i];
    for(int i=1;i<=M;i++)
    {
        for(int j=T;j>=0;j--)
        {
            if(j>=t[i])
            {
                dp[j]=max(dp[j],dp[j-t[i]]+m[i]);
            }
        }
    }
    cout<<dp[T];
    return 0;
}