//还不太了解
// #include <iostream>
// #include <cstring>
// #include <algorithm>

// using namespace std;

// const int N = 510, M = 10010;

// // 极其简单粗暴的存边方式：存下所有的边
// struct Edge {
//     int a, b, w;
// } edges[M];

// int dist[N];
// int backup[N]; // 备份数组（关键细节，见下方解释）
// int n, m, k;   // n个点，m条边

// void bellman_ford() {
//     memset(dist, 0x3f, sizeof dist);
//     dist[1] = 0;

//     // 进行 k 次松弛（如果要找纯粹的最短路，这里循环 n-1 次即可）
//     // 有些题目会限制“最多经过 k 条边的最短路”，这也是 Bellman-Ford 的专长
//     for (int i = 0; i < k; i++) {
//         // 核心细节：备份上一次的 dist 数组
//         // 防止在同一次遍历中，发生了类似“串联”的更新（即用本次刚更新的值去更新别人）
//         memcpy(backup, dist, sizeof dist);
        
//         for (int j = 0; j < m; j++) {
//             int a = edges[j].a;
//             int b = edges[j].b;
//             int w = edges[j].w;
//             // 使用备份的 dist[a] 来更新，确保每次循环严格代表“多走一条边”
//             if (dist[b] > backup[a] + w) {
//                 dist[b] = backup[a] + w;
//             }
//         }
//     }
// }

// int main() {
//     cin >> n >> m >> k; // 寻找最多经过 k 条边的最短路
    
//     for (int i = 0; i < m; i++) {
//         cin >> edges[i].a >> edges[i].b >> edges[i].w;
//     }

//     bellman_ford();

//     // 为什么判断条件是 > 0x3f3f3f3f / 2？
//     // 因为如果有负权边，无穷大节点加上一个负权边，会变得比 0x3f3f3f3f 稍微小一点
//     if (dist[n] > 0x3f3f3f3f / 2) cout << "impossible" << endl;
//     else cout << dist[n] << endl;

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1002;
const int M=10002;
int dist[N];
int backup[N];
int n,m,k;
struct node
{
    int x,y,z;
}edge[M];
void Bellman_ford()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    for(int i=0;i<k;i++)
    {
        memcpy(backup,dist,sizeof dist);
        for(int j=1;j<=m;j++)
        {
            int x=edge[j].x,y=edge[j].y,z=edge[j].z;
            if(dist[y]>backup[x]+z)
            {
                dist[y]=backup[x]+z;
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>edge[i].x>>edge[i].y>>edge[i].z;
    }
    Bellman_ford();
    if(dist[n]>1e9/2)cout<<"impossible\n";
    else cout<<dist[n]<<endl;
    return 0;
}