// // #include <iostream>
// // #include <vector>
// // #include <queue>
// // #include <algorithm>
// // using namespace std;

// // const int MAXN = 5e5 + 10;
// // const int LOG = 20;  // 2^20 ≈ 1e6 > 5e5，足够覆盖最大深度

// // vector<int> g[MAXN];  // 邻接表存树
// // int depth[MAXN];      // 节点深度
// // int fa[MAXN][LOG];    // fa[u][k]：u的2^k级祖先

// // // BFS预处理depth和fa（避免递归DFS栈溢出）
// // void bfs(int root) {
// //     queue<int> q;
// //     q.push(root);
// //     depth[root] = 1;
// //     fa[root][0] = 0;  // 根节点的父节点设为0（无意义）
// //     while (!q.empty()) {
// //         int u = q.front();
// //         q.pop();
// //         for (int v : g[u]) {
// //             if (v != fa[u][0]) {  // 避免走回父节点
// //                 depth[v] = depth[u] + 1;
// //                 fa[v][0] = u;
// //                 // 递推计算2^k级祖先
// //                 for (int k = 1; k < LOG; k++) {
// //                     fa[v][k] = fa[fa[v][k-1]][k-1];
// //                 }
// //                 q.push(v);
// //             }
// //         }
// //     }
// // }

// // // 查询a和b的LCA
// // int lca(int a, int b) {
// //     // 保证a的深度 >= b的深度
// //     if (depth[a] < depth[b]) swap(a, b);
    
// //     // 第一步：将a跳到与b相同深度
// //     for (int k = LOG - 1; k >= 0; k--) {
// //         if (depth[fa[a][k]] >= depth[b]) {
// //             a = fa[a][k];
// //         }
// //     }
    
// //     // 若a和b重合，直接返回
// //     if (a == b) return a;
    
// //     // 第二步：同时向上跳，直到祖先相同
// //     for (int k = LOG - 1; k >= 0; k--) {
// //         if (fa[a][k] != fa[b][k]) {
// //             a = fa[a][k];
// //             b = fa[b][k];
// //         }
// //     }
    
// //     // 最终a和b的父节点就是LCA
// //     return fa[a][0];
// // }

// // int main() {
// //     ios::sync_with_stdio(false);
// //     cin.tie(0);  // 关闭同步，加速输入输出
    
// //     int N, M, S;
// //     cin >> N >> M >> S;
    
// //     // 建边（无向树，双向加边）
// //     for (int i = 0; i < N - 1; i++) {
// //         int x, y;
// //         cin >> x >> y;
// //         g[x].push_back(y);
// //         g[y].push_back(x);
// //     }
    
// //     // 预处理
// //     bfs(S);
    
// //     // 处理查询
// //     while (M--) {
// //         int a, b;
// //         cin >> a >> b;
// //         cout << lca(a, b) << '\n';
// //     }
    
// //     return 0;
// // }





// #include<bits/stdc++.h>
// using namespace std;
// int n,m,s;
// const int N=5e5+11;
// vector<int>g[N];
// int depth[N];
// const int Max=21;//2^20>5e5;
// int fa[N][Max];//0~2

// //bfs预处理fa和depth
// void bfs(int u)
// {
//     fa[u][0]=0;//可有可无！还是写上吧更加严谨一点，但注意不能赋值成负数
//     depth[u]=1;
//     queue<int>q;
//     q.push(u);
//     while(q.size())
//     {
//         int u=q.front();q.pop();
//         for(int i=0;i<g[u].size();i++)
//         {
//             int v=g[u][i];
//             if(v!=fa[u][0])//注意这里，容易写成v!=u
//             {
//                 fa[v][0]=u;
//                 depth[v]=depth[u]+1;

//                 //注意这里也容易忘记写，而且范围别超—~Max-1
//                 for(int k=1;k<Max;k++)
//                 {
//                     fa[v][k]=fa[fa[v][k-1]][k-1];
//                 }
//                 q.push(v);
//             }
//         }
//     }
// }
// int lca(int x,int y)
// {
//     if(depth[x]<depth[y])swap(x,y);

//     //让x跳到和y相同的高度
//     for(int i=Max-1;i>=0;i--)
//     {
//         if(depth[fa[x][i]]>=depth[y])
//         {
//             x=fa[x][i];
//         }
//     }
//     //此时x和y的高度一样了
//     //这行代码很容易忽略
//     if(x==y)return x;
//     //越大越有可能 最大无非就是根节点 根节点肯定是他们的保底选择
//     //贪心
//     for(int i=Max-1;i>=0;i--)
//     {
//         if(fa[x][i]!=fa[y][i])
//         {
//             x=fa[x][i];
//             y=fa[y][i];
//         }
//     }
//     return fa[x][0];
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>s;
//     for(int i=0;i<n-1;i++)
//     {
//         int x,y;cin>>x>>y;
//         g[x].push_back(y);
//         g[y].push_back(x);
//     }
//     bfs(s);
//     while(m--)
//     {
//         int x,y;cin>>x>>y;
//         cout<<lca(x,y)<<endl;
//     }
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// int n,m,s;
// const int Log=21;
// const int N=5e5+66;
// vector<int>g[N];
// int depth[N];
// int fa[N][Log];
// void bfs(int x)
// {
//     fa[x][0]=0;
//     depth[x]=1;

//     queue<int>q;
//     q.push(x);
//     while(q.size())
//     {
//         int x=q.front();q.pop();
//         for(int i=0;i<g[x].size();i++)
//         {
//             int y=g[x][i];
//             if(y!=fa[x][0])
//             {
//                 depth[y]=depth[x]+1;
//                 fa[y][0]=x;//我靠这行代码一直忘呢
//                 for(int i=1;i<=Log-1;i++)
//                 {
//                     fa[y][i]=fa[fa[y][i-1]][i-1];
//                 }
//                 q.push(y);
//             }
//         }
//     }
// }
// int lca(int x,int y)
// {
//     if(depth[x]<depth[y])swap(x,y);

//     for(int i=Log-1;i>=0;i--)
//     {
//         if(depth[fa[x][i]]>=depth[y])x=fa[x][i];
//     }

//     if(x==y)return x;

//     for(int i=Log-1;i>=0;i--)
//     {
//         if(fa[x][i]!=fa[y][i])
//         x=fa[x][i],y=fa[y][i];
//     }
//     return fa[x][0];
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>s;
//     for(int i=0;i<n-1;i++)
//     {
//         int x,y;cin>>x>>y;
//         g[x].push_back(y);
//         g[y].push_back(x);
//     }
//     bfs(s);
//     while(m--)
//     {
//         int x,y;cin>>x>>y;
//         cout<<lca(x,y)<<endl;
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int n,m,s;
const int N=5e5+11;
const int LOG=21;
int fa[N][LOG];
int depth[N];
vector<int>g[N];

void bfs(int s)
{
    queue<int>q;
    q.push(s);
    depth[s]=1;
    fa[s][0]=0;
    while(q.size())
    {
        int x=q.front();q.pop();
        for(int i=0;i<g[x].size();i++)
        {
            int y=g[x][i];
            if(y!=fa[x][0])//不能走回头路
            {
                fa[y][0]=x;
                depth[y]=depth[x]+1;
                for(int i=1;i<LOG;i++)
                {
                    fa[y][i]=fa[fa[y][i-1]][i-1];
                }
                q.push(y);
            }
            
        }
    }
}
int lca(int x,int y)
{
    if(depth[x]<depth[y])
    {
        swap(x,y);
    }

    //if(fa[x][0]==y)return y;
    //x 向上跳和 y 一样的高度

    for(int i=LOG-1;i>=0;i--)
    {
        //if(depth[fa[x][i]]<depth[y])x=fa[x][i];
        if(depth[fa[x][i]]>=depth[y])x=fa[x][i];
    }

    if(x==y)return x;

    for(int i=LOG-1;i>=0;i--)
    {
        if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
    }
    return fa[x][0];
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>s;
    for(int i=0;i<n-1;i++)
    {
        int x,y;cin>>x>>y;
        // fa[]
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(s);
    while(m--)
    {
        int x,y;cin>>x>>y;
        cout<<lca(x,y)<<endl;
    }
    return 0;
}