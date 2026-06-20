// // //朴素 Dijkstra NB 一把过
// // #include<bits/stdc++.h>
// // using namespace std;
// // const int N=1000;
// // int dist[N];;//距离起点的距离
// // bool st[N];
// // int n,m;
// // vector<pair<int,int>>g[N];
// // void Dijkstra()
// // {
// //     dist[1]=0;
// //     for(int i=1;i<=n;i++)
// //     {
// //         int ansnode=-1,anssum=0x3f3f3f3f;
// //         for(int j=1;j<=n;j++)
// //         {
// //             if(dist[j]<anssum&&!st[j])
// //             {
// //                 anssum=dist[j];
// //                 ansnode=j;
// //             }
// //         }
// //         if(ansnode==-1)return;
// //         st[ansnode]=1;
// //         for(auto t:g[ansnode])
// //         {
// //             int y=t.first,d=t.second;
// //             if(dist[y]>dist[ansnode]+d)
// //             {
// //                 dist[y]=dist[ansnode]+d;
// //             }
// //         }
// //     }
// // }
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n>>m;
// //     memset(dist,0x3f,sizeof dist);
// //     for(int i=1;i<=m;i++)
// //     {
// //         int x,y,z;cin>>x>>y>>z;
// //         g[x].push_back({y,z});
// //         //g[y].push_back({x,z});
// //     }
// //     Dijkstra();
// //     if(dist[n]>1e9)cout<<-1;
// //     else cout<<dist[n];
// //     return 0;
// // }

// //堆优化 1e5
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// typedef pair<int,int>PII;//第一维距离（到这个点）第二 点
// int n,m;
// vector<PII>g[N];
// int dist[N];
// bool st[N];
// void Dijkstra()
// {
//     //priority_queue<PII>q;
//     //注意默认是大根堆要使用小根堆
//     priority_queue<PII,vector<PII>,greater<PII>>q;
//     dist[1]=0;
//     q.push({0,1});
//     //只有当一个点从优先队列中弹出来（pop）的那一刻，它才是真正的“最短距离已确定”，此时才能标记 st[x] = 1。
//     //这和 bfs 不一样，bfs 是入队即标记
//     //st[1]=1;

//     //当发现更短的路径时（比如 dist[y] > d + w），堆不支持直接去队列内部把原来的那个距离改小。所以我们只能把新的更优状态作为一个新元素强行塞进堆里。

//     // 这就导致了一个问题：堆里可能同时存在好几个代表同一个节点的元素（例如 {10, 节点3} 和 {5, 节点3} 同时在堆里）。

//     // 这就是为什么你注释里写的 if(st[x]) continue; 极其关键！ {5, 节点3} 会先弹出，我们处理它并标记 st[3] = 1。等到以后 {10, 节点3} 这个过时的“历史遗留记录”弹出时，st[3] 会把它拦住，直接丢弃。
//     while(q.size())
//     {
//         int d=q.top().first,x=q.top().second;q.pop();
//         if(st[x])continue;
//         st[x]=1;//这里在理解一下
//         for(auto t:g[x])
//         {
//             int y=t.first,w=t.second;
//             if(dist[y]>d+w)
//             {
//                 dist[y]=d+w;
//                 //st[y]=1;
//                 q.push({dist[y],y});
//             }
//         }
//     }
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     memset(dist,0x3f,sizeof dist);
    
//     while(m--)
//     {
//         int a,b,c;cin>>a>>b>>c;
//         g[a].push_back({b,c});
//     }
//     Dijkstra();
//     if(dist[n]>1e9)cout<<-1;
//     else cout<<dist[n];
//    // for(int i=1;i<=n;i++)cout<<"DIST"<<dist[i]<<endl;
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
#define  int long long
typedef pair<int,int>PII;
const int N=1e5+11;
bool st[N];
vector<PII>g[N];
int dist[N];
int n,m;
// void Dijkstra()
// {
//     memset(dist,0x3f,sizeof dist);
//     dist[1]=0;
//     for(int i=1;i<=n;i++)
//     {
//         int ansnode=-1,anssum=0x3f3f3f3f;
//         for(int j=1;j<=n;j++)
//         {
//             if(!st[j]&&dist[j]<anssum)
//             {
//                 //dist[j]=anssum;
//                 anssum=dist[j];
//                 ansnode=j;
//             }
//         }

//         if(ansnode==-1)return;
//         st[ansnode]=1;

//         for(auto[y,w]:g[ansnode])
//         {
//             if(dist[y]>dist[ansnode]+w)
//             {
//                 dist[y]=dist[ansnode]+w;
//             }
//         }
//     }
// }
void Dijkstra()
{
    //第一维是距离
    priority_queue<PII,vector<PII>,greater<PII>>q;
    //q.push(1);
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    q.push({0,1});
    while(q.size())
    {
        int d=q.top().first,x=q.top().second;q.pop();
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
    cin>>n>>m;
    while(m--)
    {
        int x,y,z;cin>>x>>y>>z;
        g[x].push_back({y,z});
    }
    Dijkstra();
    if(dist[n]>1e9)cout<<-1;
    else cout<<dist[n];
    return 0;
}































