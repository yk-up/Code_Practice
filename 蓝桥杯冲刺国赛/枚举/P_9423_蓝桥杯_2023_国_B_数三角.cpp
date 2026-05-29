// //暴力只能拿 20% 的分数
// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // const int N=2002;
// // int n;
// // int x[N],y[N];
// // double getdist(int i,int j)
// // {
// //     double dist=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
// //     return dist;
// // }
// // bool is_ok(double x,double y,double z)
// // {
// //     if(x+y>z&&x+z>y&&y+z>x&&abs(x-y)<z&&abs(x-z)<y&&abs(y-z)<x)
// //     return true;
// //     return false;
// // }
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n;
// //     for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
// //     //从所有的点中选 3 个点
// //     int ans=0;
// //     for(int i=1;i<=n;i++)
// //     {
// //         for(int j=i+1;j<=n;j++)
// //         {
// //             for(int k=j+1;k<=n;k++)
// //             {
// //                 double dist1=getdist(i,j);
// //                 double dist2=getdist(j,k);
// //                 double dist3=getdist(i,k);
// //                 //if((dist1==dist2||dist2==dist3||dist1==dist3)&&is_ok(dist1,dist2,dist3))
// //                 if((abs(dist1-dist2)<1e-8||abs(dist2-dist3)<1e-8||abs(dist1-dist3)<1e-8)&&is_ok(dist1,dist2,dist3))
// //                 {
// //                     ans++;
// //                 }
// //             }
// //         }
// //     }
// //     cout<<ans;
// //     return 0;
// // }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=2002;
// int n;
// int x[N],y[N];

// // 返回距离的平方，完全保留整数，完美避开浮点数精度问题
// int getdist2(int i, int j)
// {
//     int dx = x[i] - x[j];
//     int dy = y[i] - y[j];
//     return dx * dx + dy * dy;
// }

// // 利用向量叉积判断三点是否不共线（是否能构成三角形）
// bool is_triangle(int i, int j, int k)
// {
//     int dx1 = x[j] - x[i];
//     int dy1 = y[j] - y[i];
//     int dx2 = x[k] - x[i];
//     int dy2 = y[k] - y[i];
    
//     // 如果叉积不等于 0，说明不共线，即可以构成三角形
//     return (dx1 * dy2 - dx2 * dy1) != 0;
// }

// signed main()
// {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     if(!(cin >> n)) return 0;
//     for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    
//     int ans = 0;
//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = i + 1; j <= n; j++)
//         {
//             for(int k = j + 1; k <= n; k++)
//             {
//                 int dist1 = getdist2(i, j); // 距离的平方
//                 int dist2 = getdist2(j, k);
//                 int dist3 = getdist2(i, k);
                
//                 // 由于全是整数，用 == 比较现在是绝对安全的
//                 if((dist1 == dist2 || dist2 == dist3 || dist1 == dist3) && is_triangle(i, j, k))
//                 {
//                     ans++;
//                 }
//             }
//         }
//     }
//     cout << ans << "\n";
//     return 0;
// }

//还是只能过两个点
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2001;
int n;
int x[N],y[N];
int getdist(int i,int j)
{
    int dx=x[i]-x[j];
    int dy=y[i]-y[j];

    return dx*dx+dy*dy;
}
bool is_ok(int i,int j,int k)
{
    int dx1=x[j]-x[i];
    int dy1=y[j]-y[i];

    int dx2=x[k]-x[i];
    int dy2=y[k]-y[i];

    if((dx1*dy2-dx2*dy1)!=0)return true;
    return false;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                int dist1=getdist(i,j);
                int dist2=getdist(i,k);
                int dist3=getdist(j,k);

                //注意逻辑运算符的次序
                if((dist1==dist2||dist2==dist3||dist1==dist3)&&is_ok(i,j,k))
                {
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}