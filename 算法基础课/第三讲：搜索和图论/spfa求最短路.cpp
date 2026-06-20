// //思路就是：用更新的点去更新它的相邻点
// //本质上是对 Bellman-ford 算法的改进
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+11;
// typedef pair<int,int>PII;
// vector<PII>g[N];
// bool st[N];//判断一个元素是否在队列!!! 注意和 Dijkstra 和 bfs的 st 数组进行区别
// int n,m;
// int dist[N];
// void spfa()
// {
//     memset(dist,0x3f,sizeof dist);
//     dist[1]=0;
//     queue<int>q;
//     q.push(1);
//     st[1]=0;
//     while(q.size())
//     {
//         int x=q.front();q.pop();
//         st[x]=0;//!!!
//         for(auto[y,w]:g[x])
//         {
//             if(dist[y]>dist[x]+w)
//             {
//                 dist[y]=dist[x]+w;
//                 if(!st[y])
//                 {
//                     q.push(y);//防止重复压入队列
//                 }
//             }
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     while(m--)
//     {
//         int x,y,z;cin>>x>>y>>z;
//         g[x].push_back({y,z});
//     }
//     spfa();
//     if(dist[n]>1e9/2)cout<<"impossible\n";
//     else cout<<dist[n];
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;
const int N=1e5+11;
int n,m;
vector<PII>g[N];
int dist[N];
bool st[N];
void spfa()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    queue<int>q;
    q.push(1);
    while(q.size())
    {
        int x=q.front();q.pop();
        st[x]=0;
        for(auto[y,w]:g[x])
        {
            if(dist[y]>dist[x]+w)
            {
                dist[y]=dist[x]+w;
                if(!st[y])q.push(y);
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
    spfa();
    if(dist[n]>1e9)cout<<"impossible\n";
    else cout<<dist[n]<<endl;
    return 0;
}