// //注意 st 数组写的位置，BFS 判重，入队即标记
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=102;
// int g[N][N];
// int n,m;
// int dx[]={0,0,1,-1};
// int dy[]={1,-1,0,0};
// typedef pair<int,int>PII;
// queue<PII>q;
// bool st[N][N];
// int dist[N][N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)cin>>g[i][j];
//     }
//     //int ans=0;
//     q.push({1,1});
//     st[1][1]=1;
//     //BFS 判重，入队即标记
//     while(q.size())
//     {
//         int x=q.front().first;
//         int y=q.front().second;q.pop();
//         //st[x][y]=1;
//         if(x==n&&y==m)
//         {
//             //cout<<ans;
//             cout<<dist[x][y];
//             return 0;
//         }
//         for(int i=0;i<4;i++)
//         {
//             int xx=dx[i]+x;
//             int yy=dy[i]+y;
//             //注意是 <=
//             if(xx<=0||xx>n||yy<=0||yy>m)continue;
//             if(g[xx][yy]==1||st[xx][yy])continue;
//             q.push({xx,yy});
//             st[xx][yy] = 1; // 修复 1：在入队的一瞬间，立刻标记！防止被其他节点重复放入            q.push({xx,yy});
//             dist[xx][yy]=dist[x][y]+1;
//         }
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;
const int N=102;
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
int n,m;
bool st[N][N];
int g[N][N];
int dist[N][N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)cin>>g[i][j];
    }
    queue<PII>q;
    q.push({1,1});
    st[1][1]=1;
    while(q.size())
    {
        int x=q.front().first,y=q.front().second;q.pop();
        for(int i=0;i<4;i++)
        {
            int xx=dx[i]+x;
            int yy=dy[i]+y;
            if(xx<1||xx>n||yy<1||yy>m)continue;
            if(st[xx][yy])continue;
            if(g[xx][yy]==1)continue;
            st[xx][yy]=1;
            q.push({xx,yy});
            dist[xx][yy]=dist[x][y]+1;
        }
    }
    cout<<dist[n][m];
    return 0;
}