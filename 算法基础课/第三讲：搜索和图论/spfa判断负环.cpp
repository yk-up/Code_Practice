// // 不管dist数组的初值是多少，都是可以的。因为只要有负环存在，就必然有某些点的距离是负无穷，所以不管距离被初始化成何值，都一定严格大于负无穷，所以一定会被无限更新。
// //spfa 判断环，注意和前面 spfa 的区别，dist 数组不用初始化,一开始所有元素都加入队列
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2002;
// typedef pair<int,int>PII;
// vector<PII>g[N];
// int cnt[N];
// int dist[N];
// bool st[N];
// int n,m;
// bool spfa()
// {
//     queue<int>q;
//     for(int i=1;i<=n;i++)
//     {
//         q.push(i);
//         st[i]=1;
//     }
//     while(q.size())
//     {
//         int x=q.front();q.pop();
//         st[x]=false;
//         for(auto[y,w]:g[x])
//         {
//             if(dist[y]>dist[x]+w)
//             {
//                 dist[y]=dist[x]+w;
//                 cnt[y]=cnt[x]+1;//到 y 用了多少边

//                 if(cnt[y]>=n)return true;
//                 if(!st[y])
//                 {
//                     st[y]=1;
//                     q.push(y);
//                 }
//             }
//         }
//     }
//     return false;
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
//     if(spfa())cout<<"Yes\n";
//     else cout<<"No\n";
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+11;
typedef pair<int,int>PII;
vector<PII>g[N];
int dist[N];
int n,m;
int cnt[N];
bool st[N];
bool spfa()
{
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        q.push(i);
        st[i]=1;
    }
    while(q.size())
    {
        int x=q.front();q.pop();
        st[x]=false;
        for(const auto&[y,w]:g[x])//注意这个能压缩时间
        {
            if(dist[y]>dist[x]+w)
            {
                dist[y]=dist[x]+w;
                cnt[y]=cnt[x]+1;
                if(cnt[y]>=n)return true;
                if(!st[y])
                {
                    st[y]=1;
                    q.push(y);
                }
            }
        }
    }
    return false;
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
    if(spfa())cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}