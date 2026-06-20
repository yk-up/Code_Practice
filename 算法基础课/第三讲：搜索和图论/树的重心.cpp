// // #include <iostream>
// // #include <algorithm>
// // #include <cstring>

// // using namespace std;

// // const int N = 1e5 + 10; //数据范围是10的5次方
// // const int M = 2 * N; //以有向图的格式存储无向图，所以每个节点至多对应2n-2条边

// // int h[N]; //邻接表存储树，有n个节点，所以需要n个队列头节点
// // int e[M]; //存储元素
// // int ne[M]; //存储列表的next值
// // int idx; //单链表指针
// // int n; //题目所给的输入，n个节点
// // int ans = N; //表示重心的所有的子树中，最大的子树的结点数目

// // bool st[N]; //记录节点是否被访问过，访问过则标记为true

// // //a所对应的单链表中插入b  a作为根 
// // void add(int a, int b) {
// //     e[idx] = b, ne[idx] = h[a], h[a] = idx++;
// // }

// // // dfs 框架
// // /*
// // void dfs(int u){
// //     st[u]=true; // 标记一下，记录为已经被搜索过了，下面进行搜索过程
// //     for(int i=h[u];i!=-1;i=ne[i]){
// //         int j=e[i];
// //         if(!st[j]) {
// //             dfs(j);
// //         }
// //     }
// // }
// // */


// //size用于存储以u为根节点的树的子树（即连通图，不包含u）的最大大小，sum用于存储以u为根节点的树的节点总和


// // //返回以u为根的子树中节点的个数，包括u节点
// // int dfs(int u) {
// //     int res = 0; //存储 删掉某个节点之后，最大的连通子图节点数
// //     st[u] = true; //标记访问过u节点
// //     int sum = 1; //存储 以u为根的树 的节点数, 包括u，如图中的4号节点

// //     //访问u的每个子节点
// //     for (int i = h[u]; i != -1; i = ne[i]) {
// //         int j = e[i];
// //         //因为每个节点的编号都是不一样的，所以 用编号为下标 来标记是否被访问过
// //         if (!st[j]) {
// //             int s = dfs(j);  // u节点的单棵子树节点数 如图中的size值
// //             res = max(res, s); // 记录最大联通子图的节点数
// //             sum += s; //以j为根的树 的节点数
// //         }
// //     }

// //      //这个不太好理解！https://gemini.google.com/app/3e35d4d9bbaed405?utm_source=deepmind.google&utm_medium=referral&utm_campaign=gdm&utm_content=
// //     //n-sum 如图中的n-size值，不包括根节点4；
// //     res = max(res, n - sum); // 选择u节点为重心，最大的 连通子图节点数
// //     ans = min(res, ans); //遍历过的假设重心中，最小的最大联通子图的 节点数
// //     return sum;
// // }

// // int main() {
// //     memset(h, -1, sizeof h); //初始化h数组 -1表示尾节点
// //     cin >> n; //表示树的结点数

// //     // 题目接下来会输入，n-1行数据，
// //     // 树中是不存在环的，对于有n个节点的树，必定是n-1条边
// //     for (int i = 0; i < n - 1; i++) {
// //         int a, b;
// //         cin >> a >> b;
// //         add(a, b), add(b, a); //无向图
// //     }

// //     dfs(1); //可以任意选定一个节点开始 u<=n

// //     cout << ans << endl;

// //     return 0;
// // }

// //数组来模拟理解表，每个点背后本质上都是一个链表 数组更快相较于 vector
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// int h[N],e[N*2],ne[N*2];
// bool st[N*2];
// int n;
// int idx=0;
// int ans=0x3f3f3f3f;
// void add(int a,int b)
// {
//     e[idx]=b;
//     ne[idx]=h[a];
//     h[a]=idx;
//     idx++;
// }
// int dfs(int x)//dfs 统计以 x 为根节点的子树节点的数量
// {
//     //if(st[x])return; 能走到这一步的肯定没有访问过
//     st[x]=1;

//     int sum=1;//统计以 x 为根节点的节点数量
//     int res=0;//找u子树中最大的节点数量
//     for(int i=h[x];i!=-1;i=ne[i])
//     {
//         int j=e[i];//节点标号（不是插入次数）
//         if(st[j])continue;
//         int z=dfs(j);
//         res=max(res,z);
//         sum+=z;
//     }
//     res=max(res,n-sum);//这个地方有点抽象
//     ans=min(ans,res);
//     return sum;//
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     memset(h,-1,sizeof h);
//     for(int i=0;i<n-1;i++)
//     {
//         int a,b;cin>>a>>b;
//         add(a,b);
//         add(b,a);
//     }
//     dfs(1);
//     cout<<ans;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
vector<int>g[N];
int n;
int ans=0x3f3f3f3f;
//记录以x 为根节点的数的子节点数量
bool st[N];
int dfs(int x)
{
    int sum=1,res=0;
    for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i];
        if(st[y])continue;
        st[y]=1;
        int s=dfs(y);
        res=max(res,s);
        sum+=s;
    }
    res=max(res,n-sum);
    ans=min(ans,res);
    return sum;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    st[1]=1;
    cout<<ans;
    return 0;
}