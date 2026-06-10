// #include<bits/stdc++.h>
// using anmespace std;
// const int N=205;
// vector<int>g[N];
// int n,m;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=0;i<m;i++)
//     {
//         int x,y;cin>>x>>y;
//         g[x].push_back(y);
//     }

//     return 0;
// // }

// //题目的转化我靠！！！

// // 能确定排名 ⇔
// // 这个人和“所有其他人”的胜负关系都已知

// // 而“已知 / 可推出”，
// // 靠的就是 Floyd 求传递闭包。
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 105;
// bool win[N][N];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m;
//     cin >> n >> m;

//     for (int i = 0; i < m; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         win[a][b] = true; // a 比 b 强
//     }

//     // Floyd 传递闭包
//     for (int k = 1; k <= n; k++)
//         for (int i = 1; i <= n; i++)
//             for (int j = 1; j <= n; j++)
//                 if (win[i][k] && win[k][j])
//                     win[i][j] = true;

//     int ans = 0;

//     // 判断哪些奶牛排名可确定
//     for (int i = 1; i <= n; i++)
//     {
//         int cnt = 0;
//         for (int j = 1; j <= n; j++)
//         {
//             if (i == j) continue;
//             if (win[i][j] || win[j][i])
//                 cnt++;
//         }
//         if (cnt == n - 1)
//             ans++;
//     }

//     cout << ans << "\n";
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e2+22;
// int win[N][N];
// int n,m;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=0;i<m;i++)
//     {
//         int a,b;cin>>a>>b;
//         win[a][b]=1;
//     }
//     for(int k=1;k<=n;k++)
//     {
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=n;j++)
//             {
//                 //这个和那个p1037一样容易写错，有好几种写法
//                 win[i][j]|=win[i][k]&&win[k][j];
//             }
//         }
//     }
//     int ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         int cnt=0;
//         for(int j=1;j<=n;j++)
//         {
//             if(i==j)continue;//更加严谨
//             if(win[i][j]||win[j][i])
//             {
//                 cnt++;
//             }
//         }
//         if(cnt==n-1)ans++;
//     }
//     cout<<ans;
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// const int N=200;
// int win[N][N];
// int n,m;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=0;i<m;i++)
//     {
//         int a,b;cin>>a>>b;
//         win[a][b]=1;
//     }
//     for(int k=1;k<=n;k++)
//     {
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=n;j++)
//             win[i][j]|=win[i][k]&&win[k][j];
//         }
//     }

//     int ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         int cnt=0;
//         for(int j=1;j<=n;j++)
//         {
//             if(win[i][j]||win[j][i])cnt++;
//         }
//         if(cnt==n-1)ans++;
//     }
//     cout<<ans;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=102;
bool win[N][N];
int n,m;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;cin>>a>>b;
        win[a][b]=1;
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                win[i][j]|=(win[i][k]&&win[k][j]);
            }
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(i==j)continue;
            if(win[i][j]||win[j][i])cnt++;
        }
        if(cnt==n-1)ans++;
    }
    //cout<<cnt;
    cout<<ans;
    return 0;
}