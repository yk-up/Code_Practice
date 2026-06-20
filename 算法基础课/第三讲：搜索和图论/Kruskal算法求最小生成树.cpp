// //并查集
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+11;
// int fa[N];
// int n,m;
// int find(int x)
// {
//     if(fa[x]==x)return x;
//     return fa[x]=find(fa[x]);
// }
// void merge(int x,int y)
// {
//     int xx=find(x),yy=find(y);
//     if(xx==yy)return ;
//     fa[yy]=xx;
// }
// struct node
// {
//     int u,v,w;
//     bool operator<(const node&u)
//     {
//         return w<u.w;
//     }
// };
// vector<node>edge;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)fa[i]=i;
//     while(m--)
//     {
//         int u,v,w;cin>>u>>v>>w;
//         edge.push_back({u,v,w});
//     }
//     sort(edge.begin(),edge.end());
//     int res=0,cnt=0;
//     for(int i=0;i<edge.size();i++)
//     {
//         int u=edge[i].u,v=edge[i].v,w=edge[i].w;
//         if(find(u)==find(v))continue;
//         merge(find(u),find(v));
//         cnt++;
//         res+=w;
//     }
//     if(cnt<n-1)cout<<"impossible\n";//这个不太规范看下面写的
//     else cout<<res;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+11;
struct node
{
    int u,v,w;
    bool operator<(const node&u)
    {
        return w<u.w;
    }
}edge[N];
int fa[N];
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int xx=find(x),yy=find(y);
    if(xx==yy)return;
    fa[yy]=xx;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)cin>>edge[i].u>>edge[i].v>>edge[i].w;
    sort(edge+1,edge+1+m);
    int cnt=0,ans=0;
    for(int i=1;i<=m;i++)
    {
        int u=edge[i].u,v=edge[i].v,w=edge[i].w;
        if(find(u)==find(v))continue;
        merge(u,v);
        cnt++;
        ans+=w;
    }
    if(cnt==n-1)cout<<ans<<endl;//注意这个
    else cout<<"impossible\n";
}