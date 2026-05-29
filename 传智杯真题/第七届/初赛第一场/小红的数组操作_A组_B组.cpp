// // //每次都对最大值进行操作？
// // //思路一个是没有问题的，超时了
// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // const int N=1e5+11;
// // int a[N];
// // int n,k,x;
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n>>k>>x;
// //     priority_queue<int>q;
// //     for(int i=1;i<=n;i++)
// //     {
// //         cin>>a[i];
// //         q.push(a[i]);
// //     }
// //     int cnt=0;

// //     while(k--)
// //     {
// //         for(int i=1;i<=n;i++)
// //         {
// //             if(a[i]==q.top())
// //             {
// //                 q.pop();
// //                 a[i]-=x;
// //                 q.push(a[i]);
// //                 break;//进行下一次循环
// //             }
// //     }
// //     }
// //     for(int i=1;i<=n;i++)
// //     {
// //         if(a[i]==q.top())
// //         {
// //             cout<<a[i];
// //             break;
// //         }
// //     }
    
// //     //for(int i=1;i<=n;i++)cout<<a[i]<<" ";
// //    //cout<<*max_element(a+1,a+1+n);
// //     return 0;
// // }





//这个题不难 但是有几个点比较恶心，对时间卡的比较严 还有就是二分枚举的边界

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long // 开启全员 long long，防止溢出

// const int N = 1e5 + 11;
// int a[N];
// int n, k, x;

// // 验证函数：判断如果把所有数都削到 <= mid，需要的操作次数是否 <= k
// bool check(int mid) {
//     int need_ops = 0;
//     for(int i = 1; i <= n; i++) {
//         if(a[i] > mid) {
//             // 计算 a[i] 减到 mid 及以下需要几次操作（向上取整）
//             // 公式：(被除数 + 除数 - 1) / 除数
//             need_ops += (a[i] - mid + x - 1) / x;
            
//             // 剪枝优化：如果需要的次数已经超过 k，直接返回 false，防止 need_ops 溢出
//             if(need_ops > k) return false;
//         }
//     }
//     return need_ops <= k;
// }

// signed main() {
//     // 优化输入输出
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
//     if (!(cin >> n >> k >> x)) return 0;
    
//     int max_val = -2e18; // 记录初始最大值
//     for(int i = 1; i <= n; i++) {
//         cin >> a[i];
//         max_val = max(max_val, a[i]);
//     }
    
//     // 二分范围的确定
//     // right: 最好情况也就是一次都不操作，最大值就是原数组最大值
//     // left: 最坏情况，k 次操作全砸在一个数上，答案可能是负的天文数字 (10^9 * 10^9 = 10^18)
//     int l = -2e18, r = max_val;
//     int ans = r; // 记录最终答案
    
//     // 开始二分答案
//     while(l <= r) {
//         // 防止负数相加溢出，标准的求中点写法
//         int mid = l + (r - l) / 2; 
        
//         if(check(mid)) {
//             ans = mid;    // mid 达成了！记录下来
//             r = mid - 1;  // 尝试找有没有更小的答案
//         } else {
//             l = mid + 1;  // mid 太小了达不成，只能往大了找
//         }
//     }
    
//     cout << ans << "\n";
    
// //     return 0;
// // }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,k,x;
// const int N=1e5+11;
// int a[N];
// bool check(int max_)
// {
//     int cnt=0;
//     for(int i=1;i<=n;i++)
//     {                               
//         if(a[i]>max_)
//         {
//             cnt+=(a[i]-max_+(x-1))/x;//注意这个的计算方法 向上取整

//             //剪枝
//             //if(cnt>k)return true;// 【重要修复 1】增加剪枝，防止 cnt 在累加过程中爆 long long 变成负数
//         }
//     }
//     if(cnt>k)return true;
//     return false;
// }
// signed main()
// {
//     cin>>n>>k>>x;
//     for(int i=1;i<=n;i++)cin>>a[i];

//     sort(a+1,a+1+n);
//     //枚举最大值 
//     int l=-2e18,r=1e9;
//     // 1 |2 3 4
//     // 4 |3 3 2
//     while(l+1!=r)
//     {
//         int mid=(l+r)/2;
//         if(check(mid))l=mid;
//         else r=mid;
//     }
//     cout<<r;
//     return 0;
// }

//二分
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
int a[N];
int n,k,x;

bool check(int mid)
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>mid)
        {
            cnt+=(a[i]-mid+(x-1))/x;
            if(cnt>k)return true;//必须有否则可能溢出
        }
    }
    if(cnt>k)return true;
    return false;
}
signed main()
{
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    //数组的最大值尽可能小
    //枚举最大的数
    //1 |2 3 |4 5
    //4 |3 3 |2 1  次数
    int l=-2e18,r=0x3f3f3f3f;
    while(l+1!=r)
    {
        int mid=(l+r)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    cout<<r;
    return 0;
}