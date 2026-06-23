// // //这道题考察的是数论中最基础、但也最重要的定理之一：算术基本定理（唯一分解定理）。

// // // 通俗地讲，这道题的任务是：把一个大整数，像拆积木一样，全部拆成“质数”的乘积，并统计每个质数出现了几次。
// // //结论：一个正整数 $N$，最多只包含一个大于 $\sqrt{N}$ 的质因子。
// // #include <iostream>

// // using namespace std;

// // // 分解质因数的函数
// // void divide(int n) {
// //     // 从 2 遍历到 sqrt(n)
// //     for (int i = 2; i <= n / i; i++) {
// //         if (n % i == 0) { // 发现了一个质因子 i
// //             int s = 0; // s 用来记录指数
// //             while (n % i == 0) { // 只要还能被 i 整除，就一直除（榨干它）
// //                 n /= i;
// //                 s++;
// //             }
// //             cout << i << " " << s << "\n"; // 输出底数和指数
// //         }
// //     }
// //     //如 33=3X11
// //     // 处理终极漏网之鱼（关键！）： 当循环结束时，如果 $N$ 依然大于 $1$，说明剩下的这个 $N$ 就是那个唯一大于 $\sqrt{N}$ 的质因子，直接输出它，指数为 1 即可。
// //     // 关键收尾：如果最后剩下的 n > 1，说明它是一个大于当初 sqrt(n) 的大质数
// //     if (n > 1) {
// //         cout << n << " 1\n";
// //     }
// //     cout << "\n"; // 每个数字处理完后输出一个空行，符合题目格式要求
// // }

// // int main() {
// //     // 提升 cin/cout 读写速度
// //     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
// //     int n;
// //     cin >> n;
    
// //     while (n--) {
// //         int a;
// //         cin >> a;
// //         divide(a);
// //     }
    
// //     return 0;
// // }

// #include<bits/stdc++.h>
// using namespace std;
// // #define int long long
// int n;
// void divid(int x)
// {
//     //x 不可能小于 2 因为最小的质因数都是 2
//     for(int i=2;i<=x/i;i++)
//     {
//         if(x%i==0)
//         {
//             int s=0;//记录质因数的质数
//             while(x%i==0)
//             {
//                 x/=i;
//                 s++;
//             }
//             cout<<i<<" "<<s<<endl;
//         }
        
//     }
//     //写 > 1 的核心目的，是为了无死角兜底“所有的质数”。在数学定义中，最小的质数就是 2。
//     if(x>1)cout<<x<<" "<<1<<endl;
//     cout<<endl;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         int x;cin>>x;
//         divid(x);
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
void divid(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            int s=0;
            while(x%i==0)
            {
                x/=i;
                s++;
            }
            cout<<i<<" "<<s<<endl;
        }
    }
    if(x>1)//说明自己就是那个>sqrt(x)的质数
    cout<<x<<" "<<1<<endl;
    cout<<endl;
}
int main()
{
    int n;cin>>n;
    while(n--)
    {
        int x;cin>>x;
        divid(x);
    }
    return 0;
}