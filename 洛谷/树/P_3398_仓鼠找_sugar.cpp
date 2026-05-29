// // ✔ 如果两条路径相交
// // ✔ 那么 至少有一条路径的 LCA 在另一条路径上
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 100000 + 5;
// const int LOG = 20;
// #define int long long
// vector<int> g[N];
// int fa[N][LOG], depth[N];
// int n, q;

// void dfs(int u, int p)
// {
//     fa[u][0] = p;
//     depth[u] = depth[p] + 1;

//     for (int k = 1; k < LOG; k++)
//         fa[u][k] = fa[fa[u][k - 1]][k - 1];

//     for (int v : g[u])
//         if (v != p)
//             dfs(v, u);
// }

// int lca(int x, int y)
// {
//     if (depth[x] < depth[y]) swap(x, y);

//     for (int k = LOG - 1; k >= 0; k--)
//         if (depth[fa[x][k]] >= depth[y])
//             x = fa[x][k];

//     if (x == y) return x;

//     for (int k = LOG - 1; k >= 0; k--)
//         if (fa[x][k] != fa[y][k])
//             x = fa[x][k], y = fa[y][k];

//     return fa[x][0];
// }

// int dist(int x, int y)
// {
//     int z = lca(x, y);
//     return depth[x] + depth[y] - 2 * depth[z];
// }

// bool on_path(int x, int u, int v)
// {
//     return dist(u, x) + dist(x, v) == dist(u, v);
// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> n >> q;
//     for (int i = 1; i < n; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     dfs(1, 0);

//     //这个判断是错误的
//     1
//     |
//     2
//    / \
//   3   4
//      / \
//     5   6
//比如3->6  5->4 端点不一定在这个路径上
//     // while (q--)
//     // {
//     //     int a, b, c, d;
//     //     cin >> a >> b >> c >> d;

//     //     if (on_path(a, c, d) ||
//     //         on_path(b, c, d) ||
//     //         on_path(c, a, b) ||
//     //         on_path(d, a, b))
//     //         cout << "Y\n";
//     //     else
//     //         cout << "N\n";
//     // }
//     while (q--)
// {
//     int a, b, c, d;
//     cin >> a >> b >> c >> d;

//     int x = lca(a, b);
//     int y = lca(c, d);

//     if (on_path(x, c, d) || on_path(y, a, b))
//         cout << "Y\n";
//     else
//         cout << "N\n";
// }

// }



// #include<bits/stdc++.h>
// using namespace std;
// int n,q;
// const int N=1e5+22;
// const int Log=21;
// vector<int>g[N];
// int depth[N];
// int fa[N][Log];
// void bfs(int x)
// {
//     depth[x]=1;
//     fa[x][0]=0;
//     queue<int>q;
//     q.push(x);
//     while(q.size())
//     {
//         int u=q.front();q.pop();
//         for(int i=0;i<g[u].size();i++)
//         {
//             int v=g[u][i];
//             if(v!=fa[u][0])
//             {
//                 depth[v]=depth[u]+1;
//                 fa[v][0]=u;
                
//                 for(int i=1;i<=Log-1;i++)
//                 {
//                     fa[v][i]=fa[fa[v][i-1]][i-1];
//                 }
//                 q.push(v);
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

//     if(x==y)return y;

//     for(int i=Log-1;i>=0;i--)
//     {
//         if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
//     }
//     return fa[x][0];
// }
// int dist(int x,int y)
// {
//     int z=lca(x,y);
//     return depth[x]+depth[y]-2*depth[z];
// }
// bool on_path(int x,int a,int b )
// {
//     if(dist(a,x)+dist(x,b)==dist(a,b))return true;
//     return false;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>q;
//     for(int i=0;i<n-1;i++)
//     {
//         int u,v;cin>>u>>v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//     bfs(1);
//     while(q--)
//     {
//         int a,b,c,d;cin>>a>>b>>c>>d;
//         int x=lca(a,b);
//         int y=lca(c,d);
//         if(on_path(x,c,d)||on_path(y,a,b))cout<<"Y\n";
//         else cout<<"N\n";
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
int n,q;
const int Log=21;
int fa[N][Log];
int depth[N];
vector<int>g[N];
void bfs(int x)
{
    queue<int>q;
    q.push(x);
    depth[x]=1;
    fa[x][0]=0;
    while(q.size())
    {
        int x=q.front();q.pop();
        for(int i=0;i<g[x].size();i++)
        {
            int y=g[x][i];
            if(y!=fa[x][0])
            {
                fa[y][0]=x;
                depth[y]=depth[x]+1;
                for(int i=1;i<=Log-1;i++)
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
    if(depth[x]<depth[y])swap(x,y);

    for(int i=Log-1;i>=0;i--)
    {
        if(depth[fa[x][i]]>=depth[y])x=fa[x][i];
    }

    if(x==y)return x;
    for(int i=Log-1;i>=0;i--)
    {
        if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
    }
    return fa[x][0];
}
int dist(int x,int y)
{
    int z=lca(x,y);
    return depth[x]+depth[y]-2*depth[z];
}
bool on_path(int x,int a,int b)
{
    if(dist(a,x)+dist(b,x)==dist(a,b))return true;
    return false;
}
int main()
{
    cin>>n>>q;
    for(int i=0;i<n-1;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);
    while(q--)
    {
        int a,b,c,d;cin>>a>>b>>c>>d;
        //注意这个是如何判断的
        int x=lca(a,b);
        int y=lca(c,d);
        if(on_path(x,c,d)||on_path(y,a,b))cout<<"Y\n";
        else cout<<"N\n";
    }
    return 0;
}