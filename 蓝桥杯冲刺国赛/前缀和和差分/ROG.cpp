// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // int n,m;
// // const int N=2002;
// // char g[N][N];
// // const int p= 998244353;
// // signed main()
// // {
// //     ios::sycn_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n>>m;
// //     for(int i=1;i<=n;i++)
// //     {
// //         for(int j=1;j<=m;j++)cin>>g[i][j];
// //     }

// //     //暴力三重循环肯定会超时
// //     // for(int x1=1;x1<=n;x1++)
// //     // {
// //     //     for(int y1=1;y1<=)
// //     // }
// //     return 0;
// // }


// //对于任意一个 'O' $(x_2, y_2)$ 来说，'R' 必须在它的“左上方”（包含所在行和列）。同理，'G' 必须在它的“右下方”（包含所在行和列）。因此，算法的思路豁然开朗：我们枚举每一个 'O' 的位置。对于特定的一个 'O'，能和它组成 ROG 的组合数，就等于：左上角区域中 'R' 的数量 $\times$ 右下角区域中 'G' 的数量

// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// const int MOD = 998244353;
// const int MAXN = 2005;

// // 定义在全局，防止爆栈。
// // int 最大可以存 2 * 10^9，矩阵最大 2000x2000 = 4*10^6，完全够用，不需要开 long long 浪费内存
// int prefR[MAXN][MAXN];
// int suffG[MAXN][MAXN];
// string grid[MAXN];

// int main() {
//     // 优化输入输出流
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n, m;
//     if (!(cin >> n >> m)) return 0;

//     // 读入矩阵，这里把字符串前面加个空格，使其变成从下标 1 开始，方便边界处理
//     for (int i = 1; i <= n; ++i) {
//         cin >> grid[i];
//         grid[i] = " " + grid[i]; 
//     }

//     // 1. 预处理：计算左上角 'R' 的二维前缀和
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= m; ++j) {
//             prefR[i][j] = prefR[i-1][j] + prefR[i][j-1] - prefR[i-1][j-1] + (grid[i][j] == 'R' ? 1 : 0);
//         }
//     }

//     //画图好理解
//     // 2. 预处理：计算右下角 'G' 的二维后缀和 (注意循环要倒着来)
//     for (int i = n; i >= 1; --i) {
//         for (int j = m; j >= 1; --j) {
//             suffG[i][j] = suffG[i+1][j] + suffG[i][j+1] - suffG[i+1][j+1] + (grid[i][j] == 'G' ? 1 : 0);
//         }
//     }

//     long long ans = 0; // 最终答案可能很大，用 long long

//     // 3. 遍历寻找 'O'，计算乘积
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= m; ++j) {
//             if (grid[i][j] == 'O') {
//                 // 当前 'O' 能组成的 ROG 数量 = 左上角的 'R' 数量 * 右下角的 'G' 数量
//                 long long ways = (1LL * prefR[i][j] * suffG[i][j]) % MOD;
//                 ans = (ans + ways) % MOD;
//             }
//         }
//     }

//     cout << ans << "\n";
//     return 0;
// }

//暴力肯定会超时
//枚举中间等于 0 的字母，然后计算这个点前面的R 数量 和后面的G 数量 也就是前缀和和后缀和
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;
const int N=2002;
int prefix[N][N];
int suf[N][N];
char s[N][N];
const int p=998244353;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>s[i][j];
        }
    }

    //左上角 R 的数量
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+(s[i][j]=='R'?1:0);
        }
    }
    
    //右下角的G 数量 （画图容易理解）
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //     {
    //         suf[i][j]=suf[i+1][j]+suf[i][j+1]-suf[i+1][j+1]+(s[i][j]=='G'?1:0);
    //     }
    // }
    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=1;j--)
        suf[i][j]=suf[i+1][j]+suf[i][j+1]-suf[i+1][j+1]+(s[i][j]=='G'?1:0);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='O')
            {
                ans=(ans+prefix[i][j]*suf[i][j]%p)%p;
            }
        }
    }
    cout<<ans%p<<endl;
    return 0;
}