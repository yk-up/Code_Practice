// //秒了
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,m;
// const int N=1e5+11;
// vector<int>g[N];
// int dist[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     memset(dist,-1,sizeof dist);
//     while(m--)
//     {
//         int x,y;cin>>x>>y;
//         g[x].push_back(y);
//     }
//     dist[1]=0;
//     queue<int>q;
//     q.push(1);
//     while(q.size())
//     {
//         int x=q.front();q.pop();
//         for(int i=0;i<g[x].size();i++)
//         {
//             int y=g[x][i];
//             if(dist[y]==-1)
//             {
//                 dist[y]=dist[x]+1;
//                 q.push(y);
//             }
//         }
//     }
//     cout<<dist[n];
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
vector<int>g[N];
int dist[N];
bool st[N];
int n,m;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    while(m--)
    {
        int a,b;cin>>a>>b;
        g[a].push_back(b);
    }
    queue<int>q;
    q.push(1);
    st[1]=1;
    while(q.size())
    {
        int x=q.front();q.pop();
        if(x==n)
        {
            cout<<dist[n];
            return 0;
        }
        for(int y:g[x])
        {
            if(!st[y])
            {
                dist[y]=dist[x]+1;
                q.push(y);
                st[y]=1;
            }
        }
    }
    cout<<-1;
    return 0;
}