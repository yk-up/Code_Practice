// //稠图 用Dijkstra
// //朴素Dijkstra n<=2000
// //全t了
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,m,s;
// const int N=1e5+66;
// struct edge
// {
//     int to,w;
// };
// int dist[N];//记录起点的距离
// vector<edge>g[N];
// bool st[N];
// void Dijkstra(int s)
// {
//     memset(dist,0x3f,sizeof dist);
//     dist[s]=0;
//     for(int i=1;i<=n;i++)
//     {
//          // 1️⃣ 在所有未确定的点中，找 dist 最小的
//         int ansnode=-1,ansdist=0x3f3f3f3f;
//         for(int j=1;j<=n;j++)
//         {
//             if(!st[j]&&dist[j]<ansdist)
//             {
//                 ansdist=dist[j];
//                 ansnode=j;
//             }
//         }
        
//         // 如果找不到可扩展的点，直接结束
//         if(ansnode==-1)break;
//         st[ansnode]=1;

//         // 3️⃣ 用 选好的点 去松弛它能到达的点

//         for(auto [v,w]:g[ansnode])
//         {
//             if(dist[v]>dist[ansnode]+w)
//             {
//                 dist[v]=dist[ansnode]+w;
//             }
//         }
//     }
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>s;
//     for(int i=1;i<=m;i++)
//     {
//         int u,v,w;cin>>u>>v>>w;
//         g[u].push_back({v,w});
//         g[v].push_back({u,w});
//     }
//     Dijkstra(s);
//     for(int i=1;i<=n;i++)
//     cout<<dist[i]<<" ";
//     return 0;
// }



// //方式 1 堆优化版本
// //小根堆保贪心，过时距离快 continue
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// bool st[N];
// struct edge
// {
//     int to,w;
// };
// int n,m,s;
// vector<edge>g[N];
// typedef pair<int,int>PII;//一维是距离 二维是另一个端点
// int dist[N];
// void Dijkstra(int x)
// {
//     memset(dist,0x3f,sizeof dist);
//     dist[s]=0;
//     priority_queue<PII,vector<PII>,greater<PII>>q;
//     q.push({0,x});
//     while(q.size())
//     {
//         auto t=q.top();q.pop();
//         int x=t.second;
//         int d=t.first;
//         if(st[x])continue;
//         st[x]=1;
//         for(auto[y,w]:g[x])
//         {
//             if(dist[y]>d+w)
//             {
//                 dist[y]=d+w;
//                 q.push({dist[y],y});
//             }
//         }
//     }
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>s;
   
//     for(int i=1;i<=m;i++)
//     {
//         int u,v,w;cin>>u>>v>>w;
//         g[u].push_back({v,w});
//         //g[]
//     }
//     Dijkstra(s);
//     for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
//     return 0;
// }

// //方式二 队列
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+11;
// struct edge
// {
//     int to,w;
// };
// vector<edge>g[N];
// bool st[N];
// int n,m,s;
// int dist[N];
// void Dijkstra(int x)
// {
//     dist[x]=0;
//     queue<int>q;
//     q.push(x);
//     while(q.size())
//     {
//         // int x=q.front();q.pop();
//         // for(auto[v,w]:g[x])
//         // {
//         //     // if(st[v])continue;
//         //     // st[v]=1;
//         //     if(dist[v]>dist[x]+w)
//         //     {
//         //         dist[v]=dist[x]+w;
//         //         q.push(v);
//         //     }
//         // }

//     int x=q.front(); q.pop();
//     st[x] = 0; // 🌟 灵魂操作：出队时注销登记，允许以后再来排队 否则会被重复压入队

//     for(auto[v,w]:g[x])
//     {
//         if(dist[v]>dist[x]+w)
//         {
//             dist[v]=dist[x]+w;
//             if(!st[v]) // 🌟 门卫：不在队伍里，才去排队
//             {
//                 q.push(v);
//                 st[v] = 1; // 登记入队
//             }
//         }
//     }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>s;
//     for(int i=0;i<m;i++)
//     {
//         int u,v,w;cin>>u>>v>>w;
//         g[u].push_back({v,w});
//     }
//     memset(dist,0x3f,sizeof dist);
//     Dijkstra(s);
//     for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
//     return 0;
// }

// //朴素 Dijkstra
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+11;
// struct edge
// {
//     int to,w;
// };
// vector<edge>g[N];
// int dist[N];
// bool st[N];
// int n,m,s;
// void Dijkstra(int x)
// {
//     dist[x]=0;
//     for(int i=1;i<=n;i++)
//     {
//         int closen=-1,closenvalue=0x3f3f3f3f;
//         for(int i=1;i<=n;i++)
//         {
//             if(!st[i]&&dist[i]<closenvalue)
//             {
//                 closen=i;
//                 closenvalue=dist[i];
//             }
//         }

//         if(closen==-1)return;
//         st[closen]=1;

//         for(auto[y,w]:g[closen])
//         {
//             if(dist[y]>dist[closen]+w)
//             {
//                 dist[y]=dist[closen]+w;
//             }
//         }

//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     memset(dist,0x3f,sizeof dist);
//     cin>>n>>m>>s;
//     for(int i=0;i<m;i++)
//     {
//         int u,v,w;cin>>u>>v>>w;
//         g[u].push_back({v,w});
//     }
//     Dijkstra(s);
//     for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// struct edge
// {
//     int to,w;
// };
// vector<edge>g[N];
// bool st[N];
// int dist[N];
// int n,m,s;
// // void Dijkstra(int x)
// // {
// //     memset(dist,0x3f,sizeof dist);
// //     dist[x]=0;
// //     for(int i=1;i<=n;i++)
// //     {
// //         int chosen=-1,chosenvalue=0x3f3f3f3f;
// //         for(int j=1;j<=n;j++)
// //         {
// //             if(dist[j]<0x3f3f3f3f&&!st[j])
// //             {
// //                 chosen=j;
// //                 chosenvalue=dist[j];
// //             }
// //         }
// //         if(chosen==-1)return;

// //         st[chosen]=1;
// //         for(auto[x,w]:g[chosen])
// //         {
// //             if(dist[x]>dist[chosen]+w)
// //             {
// //                 dist[x]=dist[chosen]+w;
// //             }
// //         }
// //     }
// // }

// // void Dijkstra(int x)
// // {
// //     memset(dist,0x3f,sizeof dist);
// //     queue<int>q;
// //     q.push(x);
// //     dist[x]=0;
// //     while(q.size())
// //     {
// //         int x=q.front();q.pop();
// //         st[x]=0;//这个不熟
// //         for(auto[y,w]:g[x])
// //         {
// //             if(dist[y]>dist[x]+w)
// //             {
// //                 dist[y]=dist[x]+w;
// //                  if(!st[y])
// //                  {
// //                     q.push(y);//这个不熟
// //                     st[y]=1;
// //                  }
// //             }
// //         }
// //     }
// // }

// typedef pair<int,int>PII;//距离 点

// void Dijkstra(int x)
// {
//     priority_queue<PII,vector<PII>,greater<PII>>q;
//     memset(dist,0x3f,sizeof dist);
//     q.push({0,x});
//     dist[x]=0;
//     while(q.size())
//     {
//         auto t=q.top();q.pop();
//         int d=t.first,x=t.second;
//         if(st[x])continue;
//         st[x]=1;
//         for(auto[y,w]:g[x])
//         {
//             if(dist[y]>d+w)
//             {
//                 dist[y]=d+w;
//                 q.push({dist[y],y});
//             }
//         }
//     }
// }
// signed main()
// {
//     cin>>n>>m>>s;
//     for(int i=0;i<m;i++)
//     {
//         int u,v,w;cin>>u>>v>>w;
//         g[u].push_back({v,w});
//         //g[v].push_back({u,w}); 注意题目中的是有向图
//     }
//     Dijkstra(s);
//     for(int i=1;i<=n;i++)
//     {
//         if(i>1)cout<<" ";
//         cout<<dist[i];
//     }
//     return 0;
// }

//超时
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// struct node
// {
//     int to,w;
// };
// int n,m,s;
// vector<node>g[N];
// bool st[N];
// int dist[N];
// void Dijkstra(int s)
// {
//     memset(dist,0x3f,sizeof dist);
//     dist[s]=0;
//     for(int i=1;i<=n;i++)
//     {
//         int ansdist=0x3f3f3f3f,ansnode=-1;
//         for(int j=1;j<=n;j++)
//         {
//             if(!st[j]&&dist[j]<ansdist)
//             {
//                 ansdist=dist[j];
//                 ansnode=j;
//             }
//         }
//         if(ansnode==-1)
//         return ;
//         st[ansnode]=1;

//         for(auto[v,w]:g[ansnode])
//         {
//             if(dist[v]>dist[ansnode]+w)
//             {
//                 dist[v]=dist[ansnode]+w;
//             }
//         }
//     }
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>s;
//     for(int i=1;i<=m;i++)
//     {
//         int u,v,w;cin>>u>>v>>w;
//         g[u].push_back({v,w});
//     }
//     Dijkstra(s);
//     for(int i=1;i<=n;i++)
//     {
//         cout<<dist[i]<<" ";
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
int dist[N];
typedef pair<int,int>PII;//第一维是距离
bool st[N];
struct node
{
    int to,w;
};
int n,m,s;
vector<node>g[N];
void Dijkstra(int s)
{
    memset(dist,0x3f,sizeof dist);
    dist[s]=0;
    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,s});

    while(q.size())
    {
        int d=q.top().first;
        int x=q.top().second;q.pop();

        if(st[x])continue;
        st[x]=1;
        for(auto[y,w]:g[x])
        {
            if(dist[y]>d+w)
            {
                dist[y]=d+w;
                q.push({dist[y],y});
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    cin>>n>>m>>s;
    for(int i=0;i<m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    Dijkstra(s);
    for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
    return 0;
}