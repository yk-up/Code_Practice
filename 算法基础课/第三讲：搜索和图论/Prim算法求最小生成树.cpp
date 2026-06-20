// //不太熟
// #include<bits/stdc++.h>
// using namespace std;
// //#define int long long  这个和下面判断有冲突 longlong8 字节，int 4 字节
// #define INF 0x3f3f3f3f
// const int N=505;
// bool st[N];
// int g[N][N];
// int dist[N];
// int n,m;
// int prim()
// {
//     memset(dist,0x3f,sizeof dist);
//     int res=0;
//     dist[1]=0;
//     for(int i=0;i<n;i++)
//     {
//         int t=-1;
//         for(int j=1;j<=n;j++)
//         {
//             if(!st[j]&&(t==-1||dist[t]>dist[j]))
//             {
//                 t=j;
//             }
//         }
//         if(dist[t]==INF)return INF;

//         if(i>0)res+=dist[t];
//         st[t]=1;

//         //把刚刚选择的t 去更新剩下的点
//         for(int j=1;j<=n;j++)
//         {
//             dist[j]=min(dist[j],g[t][j]);//距离集合中最近的点
//         }
//     }
//     return res;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     memset(g,0x3f,sizeof g);
//     for(int i=1;i<=n;i++)g[i][i]=0;
//     while(m--)
//     {
//         int u,v,w;cin>>u>>v>>w;
//         g[u][v]=g[v][u]=min(g[u][v],w);
//     }
//     int ans=prim();
//     if(ans==INF)cout<<"impossible\n";
//     else cout<<ans<<"\n";
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// const int N=1000;
// bool st[N];//判断这个点是不是在集合中
// int g[N][N];//两点之间的距离
// int dist[N];//距离这个树的距离
// int n,m;
// int prim()
// {
//     int res=0;
//     memset(dist,0x3f,sizeof dist);
//     dist[1]=0;
//     for(int i=0;i<n;i++)
//     {
//         int t=-1;
//         for(int j=1;j<=n;j++)
//         {
//             if(!st[j]&&(t==-1||dist[t]>dist[j]))
//             {
//                 t=j;
//             }
//         }
//         if(dist[t]==0x3f3f3f3f)return 0x3f3f3f3f;

//         res+=dist[t];
//         st[t]=1;
//         for(int j=1;j<=n;j++)
//         {
//             dist[j]=min(dist[j],g[t][j]);
//         }
//     }
//     return res;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     memset(g,0x3f,sizeof g);
//     for(int i=1; i<=n; i++) g[i][i] = 0; // 这是一个非常推荐的图论防坑习惯
//     while(m--)
//     {
//         int x,y,z;cin>>x>>y>>z;
//         g[x][y]=g[y][x]=min(g[x][y],z);
//     }
//     int ans=prim();
//     if(ans==0x3f3f3f3f)cout<<"impossible\n";
//     else cout<<ans<<endl;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
const int N=1e3+11;
int g[N][N];
int dist[N];//距离🌳的距离
bool st[N];
int n,m;
int prim()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    queue<int>q;
    q.push(1);
    int res=0;
    for(int i=0;i<n;i++)
    {
        int t=-1;
        for(int j=1;j<=n;j++)
        {
            if(!st[j]&&(t==-1||dist[t]>dist[j]))
            {
                t=j;
            }
        }
        if(dist[t]>1e9)return 0x3f3f3f3f;
        
        st[t]=1;
        res+=dist[t];
        //更新它周围的点
        for(int j=1;j<=n;j++)
        {
            if(!st[j])
            {
                dist[j]=min(dist[j],g[t][j]);
            }
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    memset(g,0x3f,sizeof g);
    for(int i=1;i<=n;i++)g[i][i]=0;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        g[u][v]=g[v][u]=min(g[u][v],w);
    }
    int ans=prim();
    if(ans>1e9)cout<<"impossible\n";
    else cout<<ans;
    
    return 0;
}