// //思路有问题啊
// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // const int N=302;
// // int n,m,c;
// // int origin[N][N];
// // int a[N][N];
// // int diff[N][N];
// // int prefix[N][N];
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n>>m>>c;
// //     for(int i=1;i<=n;i++)
// //     {
// //         for(int j=1;j<=m;j++)cin>>origin[i][j];
// //     }
// //     int t;cin>>t;
// //     while(t--)
// //     {
// //         for(int i=1;i<=n;i++)
// //         {
// //             for(int j=1;j<=m;j++)a[i][j]=origin[i][j];
// //         }  
        
// //         //不能一到切吧，相当于个循环，按的次数多的话，就会回到原始的值，再接着往下减
// //         int x1,y1,x2,y2,k;cin>>x1>>y1>>x2>>y2>>k;
// //         diff[x1][y1]-=k;
// //         diff[x2+1][y2+1]-=k;
// //         diff[x1][y2+1]+=k;
// //         diff[x2+1][y1]+=k;

// //         for(int i=1;i<=n;i++)
// //         {
// //             for(int j=1;j<=m;j++)
// //             {
// //                 a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+diff[i][j];
                
// //                 //if(a[i][j]<=origin[i][j]-c)cout<<origin[i][j]-c<<" ";
// //                 //else cout<<a[i][j]<<" ";
// //                 if(a[i][j]<=origin[i][j]-c)a[i][j]=origin[i][j]-c;
// //                 prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+a[i][j];
// //             }
// //             cout<<endl;
// //         }
// //         cout<<prefix[x2][y2]+prefix[x1-1][y1-1]+prefix[x1-1][y2]+prefix[x2][y2-1]<<" ";
// //     }
// //     return 0;


// // }


// //想成差分了，想的复杂了，差分的特点是每次操作的x，y 值不一样，但这样对一个区间进行k 次操作
// //正确答案
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long

// const int N = 305;
// int a[N][N];
// int sum[N][N]; // 二维前缀和数组，记录初始亮度

// signed main() {
//     // 优化输入输出
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
//     int n, m, c;
//     if (!(cin >> n >> m >> c)) return 0;
    
//     // 1. 读入初始亮度，并同时构建二维前缀和
//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= m; j++) {
//             cin >> a[i][j];
//             // 标准的二维前缀和构建公式
//             sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
//         }
//     }
    
//     int t;
//     cin >> t;
    
//     // 2. 独立处理每一次询问 (时间复杂度降为 O(1) !)
//     while(t--) {
//         int x1, y1, x2, y2, k;
//         cin >> x1 >> y1 >> x2 >> y2 >> k;
        
//         // 计算这个矩形里一共有多少盏灯
//         int count = (x2 - x1 + 1) * (y2 - y1 + 1);
        
//         // 计算周期内的有效减少量
//         int d = k % (c + 1);
        
//         // 利用二维前缀和，O(1) 算出该矩形的初始总亮度
//         int original_sum = sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
        
//         // 最终总亮度 = 初始总亮度 - 减少的总量
//         int ans = original_sum - (count * d);
        
//         cout << ans << "\n";
//     }
    
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c;
const int N=302;
int a[N][N];
int sum[N][N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>c;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        }
    }
    int t;cin>>t;
    while(t--)
    {
        int x1,y1,x2,y2,k;cin>>x1>>y1>>x2>>y2>>k;
        int d=(k)%(c+1);//!!!这个很重要，可以通过例子试出来
        int origin_sum=(sum[x2][y2]+sum[x1-1][y1-1]-sum[x2][y1-1]-sum[x1-1][y2]);
        int ans=origin_sum-(d)*(x2-x1+1)*(y2-y1+1);
        cout<<ans<<endl;
    }
    return  0;
}