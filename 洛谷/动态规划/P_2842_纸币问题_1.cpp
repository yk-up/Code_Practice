// //第一想法是暴力dfs
//t了几个点
// #include<bits/stdc++.h>
// using namespace std;
// int n,w;
// const int N=1e3+11;
// int a[N];
// int ans=0x3f3f3f3f;
// bool st[N];
// void dfs(int x,int cnt,int sum)
// {
//     if(sum>w||cnt>ans)return;
//     if(x>n)
//     {
//         if(sum==w)
//         {
//             ans=min(ans,cnt);
//         }
//         return ;
//     }

//     st[x]=1;
//     dfs(x,cnt+1,sum+a[x]);//注意这里，题目中说的是每一张纸币有无限张，因此下一次还可以选

//     st[x]=0;
//     dfs(x+1,cnt,sum);
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>w;
//     for(int i=1;i<=n;i++)cin>>a[i];
    
//     dfs(1,0,0);
//     cout<<ans;
//     return 0;
// }


//不会写
// #include<bits/stdc++.h>
// using namespace std;
// int n,w;
// const int N=1e4+11;
// const int M=1e3+11;
// int a[N];
// int dp[M][N];//dp[i][j]选i个j元的方案树
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>w;
//     for(int i=1;i<=n;i++)cin>>a[i];

//     return 0;
// }


// //经典的完全背包（最少硬币数）问题
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e4+11;
// int dp[N];//dp[j]=凑出金额j所需的最少纸币数
// int a[N];
// int n,w;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>w;
//     memset(dp,0x3f,sizeof dp);
//     dp[0]=0;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=a[i];j<=w;j++)
//         dp[j]=min(dp[j],dp[j-a[i]]+1);
//         //dp[j - a[i]]：先凑出 j - a[i],再用一张 a[i] 的纸币,所以张数 +1
//     }
//     cout<<dp[w]<<"\n";
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// int n,w;
// const int N=1e4+11;
// int a[N];
// int dp[N];//dp[i]凑够i元使用的最少纸币数量
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>w;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     memset(dp,0x3f,sizeof dp);
//     dp[0]=0;
//     //dp[0]=1;//dp[0]=0因为凑出 0 元一张纸币都不需要。


//     // for(int i=1;i<=w;i++)
//     // {
//     //     for(int j=1;j<=n;j++)
//     //     {
//     //         dp[i]=dp[]
//     //     }
//     // }

//     for(int i=1;i<=n;i++)
//     {
//         for(int j=a[i];j<=w;j++)
//         {
//             dp[j]=min(dp[j],dp[j-a[i]]+1);
//         }
//     }
//     cout<<dp[w];
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e3+11;
// int a[N];
// //int dp[N];
// int dp[N][10002];
// int n,w;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>w;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     memset(dp,0x3f,sizeof dp);
//     //dp[0]=0;
//     // for(int i=1;i<=n;i++)
//     // {
//     //     for(int j=0;j<=w;j++)
//     //     {
//     //         if(j>=a[i])
//     //         dp[j]=min(dp[j],dp[j-a[i]]+1);
//     //     }
//     // }
//     // cout<<dp[w];
//     for(int i=0;i<=n;i++)
//     {
//         dp[i][0]=0;
//     }

//      //这是标准的0/1背包问题 而这道题是完全背包
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=0;j<=w;j++)
//         {
//             if(j>=a[i])
//             {
//                 dp[i][j]=min(dp[i-1][j],dp[i-1][j-a[i]]+1);
//             }
//             else dp[i][j]=dp[i-1][j];
//         }
//     }
//     cout<<dp[n][w];
//     return 0;
// }

//二维的方法
// #include<bits/stdc++.h>
// using namespace std;

// const int INF = 0x3f3f3f3f;
// int dp[1005][10005];
// int a[1005];

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int n,w;
//     cin>>n>>w;
//     for(int i=1;i<=n;i++) cin>>a[i];

//     memset(dp,0x3f,sizeof dp);

//     for(int i=0;i<=n;i++)
//         dp[i][0]=0;   // 凑0元需要0张

//     for(int i=1;i<=n;i++)
//     {
//         for(int j=0;j<=w;j++)
//         {
//             dp[i][j]=dp[i-1][j];   // 不选

//             if(j>=a[i])
//             {
//                 dp[i][j]=min(dp[i][j],//注意这里写到是i不是i-1
//                              dp[i][j-a[i]]+1); // 关键！
//             }
//         }
//     }

//     cout<<dp[n][w];
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+11;
int n,w;
int a[N];
int dp[N];//达到i元最少需要几张纸币
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>w;
    memset(dp,0x3f,sizeof dp);
    dp[0]=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(j>=a[i])
            {
                dp[j]=min(dp[j],dp[j-a[i]]+1);
            }
        }
    }
    cout<<dp[w];
    return 0;
}