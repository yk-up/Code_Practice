// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// long long ans1,ans2;//矩形个数，正方形个数
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             ans1+=i*j;
//             ans2+=min(i,j);
//         }
//     }
//     cout<<ans2<<" "<<ans1-ans2<<endl;
//     return 0;
// }


//2025/12/16 
//没写出来
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,m;cin>>n>>m;

//     int ans1=0,ans2=0;
//     for(int i=1;i<=min(n,m);i++)
//     ans1+=n/i;
//     return 0;
// }

//如果你确定了矩形的右下角是 (i, j)，那么这个矩形的左上角可以是 $(1, 1)$ 到 $(i, j)$ 区域内的任意一个点。

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m;cin>>n>>m;
//     long long ans1=0,ans2=0;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             ans1+=min(i,j);
//             ans2+=i*j;
//         }
//     }
//     cout<<ans1<<" "<<ans2-ans1<<endl;
// }

//好好理解一下，理解了好大一会
//不重不漏地逐个检查所有的右下角位置。当我们把右下角固定在坐标 (i, j) 时，我们加上去的 min(i, j) 个正方形，它们的右下角全部都是 (i, j)
// //代码里的 i 和 j 不是尺子上的“刻度线”，而是网格里的“格子编号”。两个编号重合，代表你只圈中了这 1 个格子，而 1 个格子本身就是一个 1x1 的正方形！现在这个逻辑能顺利闭
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int ans1,ans2;
// signed main()
// {
//     int n,m;cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             ans1+=min(i,j);
//             ans2+=i*j;
//         }
//     }
//     cout<<ans1<<" "<<ans2-ans1;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5004;
int n,m;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ans1+=min(i,j);
            ans2+=j*i;
        }
    }
    cout<<ans1<<" "<<ans2-ans1<<endl;
    return 0;
}