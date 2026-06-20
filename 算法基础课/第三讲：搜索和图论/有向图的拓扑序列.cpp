// //没有判断环，还是有点不熟
// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // int n,m;
// // const int N=1e5+11;
// // vector<int>g[N];
// // int in_degree[N];
// // int out_degree[N];//入度和出度
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n>>m;
// //     while(m--)
// //     {
// //         int x,y;cin>>x>>y;
// //         g[x].push_back(y);
// //         in_degree[y]++;
// //         out_degree[x]++;
// //     }
// //     queue<int>q;
// //     //入度为 0 的点压入对
// //     for(int i=1;i<=n;i++)
// //     {
// //         if(in_degree[i]==0)q.push(i);
// //     }
// //     while(q.size())
// //     {
// //         int x=q.front();q.pop();
// //         cout<<x<<" ";
// //         for(int i=0;i<g[x].size();i++)
// //         {
// //             int y=g[x][i];
// //             in_degree[y]--;
// //             out_degree[x]--;
// //             if(in_degree[y]==0)q.push(y);
// //         }
// //     }
// //     return 0;
// // }



// //入度管的是“我能不能开始”（受制于人），出度管的是“我还能去哪”（向外辐射）以及“我是不是穷途末路了”。
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long

// int n, m;
// const int N = 1e5 + 11;
// vector<int> g[N];
// int in_degree[N];

// signed main()
// {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     cin >> n >> m;
    
//     while(m--)
//     {
//         int x, y; 
//         cin >> x >> y;
//         g[x].push_back(y);
//         in_degree[y]++; 
//         // out_degree[x]++; 去掉了没用的出度统计
//     }
    
//     queue<int> q;
//     vector<int> ans; // 用来存拓扑排序的结果
    
//     // 修复 1：把入度为 0 的点压入队列
//     for(int i = 1; i <= n; i++)
//     {
//         if(in_degree[i] == 0) q.push(i);
//     }
    
//     while(q.size())
//     {
//         int x = q.front(); 
//         q.pop();
//         ans.push_back(x); // 放进答案数组
        
//         for(int i = 0; i < g[x].size(); i++)
//         {
//             int y = g[x][i];
//             in_degree[y]--;
//             // 如果拆掉这条边后，y 的入度变成 0，就入队
//             if(in_degree[y] == 0) q.push(y);
//         }
//     }
    
//     // 修复 3：判断是否有环（能不能排完 n 个点）
//     if (ans.size() == n) {
//         for (int i = 0; i < n; i++) {
//             // 修复 2：输出记得加空格
//             cout << ans[i] << (i == n - 1 ? "" : " "); 
//         }
//         cout << "\n";
//     } else {
//         // 图中有环，不是有向无环图 (DAG)，无法完成拓扑排序
//         cout << "-1\n"; // 具体输出什么看题目要求
//     }
    
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
vector<int>g[N];
int in_degree[N];
int n,m;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    while(m--)
    {
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        in_degree[y]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(in_degree[i]==0)q.push(i);
    }
    vector<int>ans;
    while(q.size())
    {
        int x=q.front();q.pop();
        //cout<<x<<" ";
        ans.push_back(x);
        for(int y:g[x])
        {
            in_degree[y]--;
            if(in_degree[y]==0)
            {
                q.push(y);
            }
        }
    }
    if(ans.size()!=n)cout<<-1;
    else
    {
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}