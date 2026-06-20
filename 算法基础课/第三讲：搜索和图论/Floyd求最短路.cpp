// //Floyd 本质是基于动态规划的
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=202;
// int n,m,q;
// int g[N][N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>q;
//     memset(g,0x3f,sizeof g);

//     for(int i=1;i<=n;i++)g[i][i]=0;
//     while(m--)
//     {
//         int x,y,z;cin>>x>>y>>z;
//         g[x][y]=min(g[x][y],z);
//         //g[y][x]=min(g[y][x],z);
//     }
//     for(int k=1;k<=n;k++)
//     {
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=n;j++)
//             {
//                 g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
//             }
//         }
//     }
//     while(q--)
//     {
//         int x,y;cin>>x>>y;
//         if(g[x][y]>1e9)cout<<"impossible\n";
//         else cout<<g[x][y]<<endl;
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
const int N=202;
int dist[N][N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,q;cin>>n>>m>>q;
    memset(dist,0x3f,sizeof dist);
    for(int i=1;i<=n;i++)dist[i][i]=0;
    while(m--)
    {
        int x,y,z;cin>>x>>y>>z;
        dist[x][y]=min(dist[x][y],z);
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    while(q--)
    {
        int x,y;cin>>x>>y;
        if(dist[x][y]>1e9)cout<<"impossible\n";
        else cout<<dist[x][y]<<endl;
    }
    return 0;
}