// // //：如果我已经找到了一对满足 $y \ge 2x$ 的元素作为一个“小组”，此时我往这个小组里塞入任何其他元素，会破坏这个条件吗？
// // // 答案是：绝对不会！
// // 塞入一个比 $y$ 更大的数 $z$： 新的最大值变成了 $z$，既然 $z > y$，且 $y \ge 2x$，那么 $z \ge 2x$ 依然成立。
// // 塞入一个比 $x$ 更小的数 $z$： 新的最小值变成了 $z$，既然 $z < x$，且 $y \ge 2x$，那么 $y \ge 2z$ 必然成立。
// // 塞入一个介于 $x$ 和 $y$ 之间的数： 最大值和最小值都不变，条件依然成立。
// // //这道题完全等价于：在数组中寻找最多能配成多少对 $(x, y)$，使得 $y \ge 2x$。 剩下的任何没有配对的元素，都可以随意丢进已经成立的任意一个对子所在的小组中，不会造成任何影响。

// // #include <bits/stdc++.h>
// // using namespace std;

// // const int N = 1e5 + 11;
// // int a[N];
// // int n;

// // signed main() {
// //     // I/O 优化
// //     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
// //     cin >> n;
// //     for (int i = 1; i <= n; i++) {
// //         cin >> a[i];
// //     }
    
// //     // 1. 从小到大排序
// //     sort(a + 1, a + 1 + n);
    
// //     // 2. 初始化双指针
// //     int L = 1;
// //     int R = n / 2 + 1; // 右半区的起点
// //     int ans = 0;
    
// //     // 3. 开始贪心匹配
// //     while (L <= n / 2 && R <= n) {
// //         if (a[R] >= 2 * a[L]) {
// //             // 匹配成功
// //             ans++;
// //             L++;
// //             R++;
// //         } else {
// //             // 右边的数不够大，右指针单独后移去找更大的数
// //             R++;
// //         }
// //     }
    
// //     // 如果 ans 为 0，说明一对都组不成，根据题意直接输出 0
// //     cout << ans << "\n";
    
// //     return 0;
// // }


// // //就是看能找到几组 al<=ar 其他的数插进来也没关系
// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // const int N=1e5+11;
// // int a[N];
// // int n;
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n;
// //     for(int i=1;i<=n;i++)cin>>a[i];
// //     sort(a+1,a+1+n);
// //     int l=1,r=n/2+1;
// //     int ans=0;
// //     while(l<=n/2&&r<=n)
// //     {
// //         if(a[r]<2*a[l])r++;//右边的太小
// //         else
// //         {
// //             ans++;
// //             r++;
// //             l++;
// //         }
// //     }
// //     cout<<ans;
// //     return 0;
// // }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// int a[N];
// int n;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     //找有多少满足 a[l]*2<=a[r] 其他的数字随便放
//     sort(a+1,a+1+n);

//     int l=1,r=n/2+1;
//     int ans=0;
//     while(l<=n/2&&r<=n)
//     {
//         if(a[l]*2<=a[r])
//         {
//             ans++;
//             l++;
//             r++;
//         }
//         else
//         {
//             r++;
//         }
//     }
//     cout<<ans;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
int a[N];
int n;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    int l=1,r=n/2+1;
    int ans=0;
    //就是找有几队a[l]<=a[r]
    while(l<=n/2&&r<=n)
    {
        if(a[l]*2>a[r])
        {
            r++;
        }
        else
        {
            ans++;
            l++;r++;
        }
    }
    cout<<ans<<endl;
    return 0;
}