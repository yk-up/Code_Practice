// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+11;
// int color[N];//标记每个节点的颜色
// bool st[N];//判断这个节点是否被染过颜色了
// int n,m;
// vector<int>g[N];
// bool flg=1;
// //1 2 
// void dfs(int x,int c)
// {
//     if(!flg)return;
//     st[x]=1;
//     color[x]=c;
//     for(int i=0;i<g[x].size();i++)
//     {
//         int y=g[x][i];
//         if(st[y])
//         {
//             if(color[x]==color[y])
//             {
//                 flg=0;
//                 return ;//这个只会退出一层，并不会退出整个 dfs，因此加上最上面那行代码
//             }
//         }
//         else
//         {
//             dfs(y,!c);
//         }
//     }

// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     while(m--)
//     {
//         int u,v;cin>>u>>v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(!st[i])
//         {
//             flg=1;
//             dfs(i,1);
//             if(!flg)
//             {
//                 cout<<"No\n";
//                 return 0;
//             }
//         }
        
//     }
//     cout<<"Yes\n";
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
vector<int>g[N];
int color[N];
bool st[N];
int n,m;
bool flg;
void dfs(int x,int c)
{
    if(!flg)return;
    color[x]=c;
    st[x]=1;
    for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i];
        if(st[y])
        {
            if(color[x]==color[y])
            {
                flg=0;
                return;
            }
        }
        else dfs(y,!c); 
    }
    return;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    while(m--)
    {
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(st[i])continue;
        flg=1;
        dfs(i,1);
        if(!flg)
        {
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";
    return 0;
}