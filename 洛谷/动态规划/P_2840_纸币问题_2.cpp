// // //顺序怎么解决，还有就是怎样用暴力dfs
// // #include<bits/stdc++.h>
// // using namespace std;
// // int n,w;
// // const int p=1e9+7;
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n>>w;

// //     return 0;
// // }

// | 题目        | 问什么          | 顺序是否区分          |
// | --------- | ------------ | --------------- |
// | P2842     | 最少用多少张       | ❌ 不关心顺序         |
// | P2840     | 有多少种支付方式    | ✅ 顺序不同算不同方案  |


// //dp[j]=凑出金额j的方案数
// //👉 金额在外层循环，纸币在内层循环
// #include <bits/stdc++.h>
// using namespace std;

// static const int MOD = 1e9 + 7;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, w;
//     cin >> n >> w;

//     vector<int> a(n);
//     for (int i = 0; i < n; i++) cin >> a[i];

//     vector<int> dp(w + 1, 0);
//     dp[0] = 1;

//     for (int j = 1; j <= w; j++) {
//         for (int i = 0; i < n; i++) {
//             if (j >= a[i]) {
//                 dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
//             }
//         }
//     }
//
//     cout << dp[w] << "\n";
//     return 0;
// }

//dp[j] 表示：所有“顺序不同都算”的、凑出 j 的方案数,不是组合，不是集合，是序列。
// dp[j]
// ├── dp[j-1] + 1
// ├── dp[j-2] + 2
// ├── dp[j-5] + 5
// └── ...

// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e4+66;
// int a[N];
// int n,w;
// const int p=1e9+7;
// int dp[N];//dp[i]凑出金额为j元的方案数
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>w;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     dp[0]=1;
//     for(int j=1;j<=w;j++)
//     {
//         for(int i=1;i<=n;i++)
//         {
//             if(j>=a[i])//👉 就是在数“最后一步是谁”，顺序天然不同
//             dp[j]=(dp[j]+dp[j-a[i]])%p;
//         }
//     }
//     cout<<dp[w];
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e4+11;
// const int p=1e9+7;
// int a[N];
// int dp[N];//以 i 结尾的方案数量
// int n,w;
// int main()
// {
//     cin>>n>>w;
//     for(int i=1;i<=n;i++)cin>>a[i];

//     dp[0]=1;
//     for(int j=1;j<=w;j++)
//     {
//         for(int i=1;i<=n;i++)
//         {
//             if(j>=a[i])
//             dp[j]=(dp[j]+dp[j-a[i]])%p;
//         }
//     }
//     cout<<dp[w];
    
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=1e9+7;
const int N=1e4+11;
int n,w;
int dp[N];
int a[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>w;
    for(int i=1;i<=n;i++)cin>>a[i];
    dp[0]=1;
    for(int j=0;j<=w;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(j>=a[i])
            {
                // dp[j]+=dp[j-a[i]];
                dp[j]=(dp[j]+dp[j-a[i]])%p;
            }
        }
    }
    cout<<dp[w];
    
    return 0;
}