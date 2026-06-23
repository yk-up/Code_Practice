// //错误思路
// // 1. 核心错误：不能“先取模，后算约数”，约数个数的计算必须基于原始的真实乘积，而不能是取模后的值。
// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // int n;

// // const int p=1e9+7;
// // void get_divisor(int x)
// // {
// //     vector<int>ans;
// //     for(int i=1;i<=x/i;i++)
// //     {
// //         if(x%i==0)
// //         {
// //             ans.push_back(i);
// //             if(i!=x/i)ans.push_back(x/i);//防止加入重复元素
// //         }
// //     }
// //     //sort(ans.begin(),ans.end());

// //     cout<<ans.size();
// //     //cout<<res<<endl;
// // }
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n;
// //     int res=1;
// //     for(int i=1;i<=n;i++)
// //     {
// //         int x;cin>>x;
// //         //get_yueshu(x);
// //         res=(res*x%p)%p;
// //     }
// //     get_divisor(res);
    
// //     return 0;
// // }

// //正确思路

// #include <iostream>
// #include <unordered_map>

// using namespace std;

// const int MOD = 1e9 + 7;

// int main() {
//     // 优化输入输出流
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     if (!(cin >> n)) return 0;

//     // 用哈希表记录每个质因数及其出现的总次数
//     unordered_map<int, long long> primes;

//     while (n--) {
//         int x;
//         cin >> x;
        
//         // 对单独的数字 x 分解质因数
//         for (int i = 2; i <= x / i; i++) {
//             while (x % i == 0) {
//                 x /= i;
//                 primes[i]++; // 质因数 i 的指数加 1
//             }
//         }
//         // 如果最后 x 还没有被除尽，说明剩下的是一个大于 sqrt(x) 的质数
//         if (x > 1) {
//             primes[x]++;
//         }
//     }

//     long long res = 1;
//     // 应用约数个数公式：(c1 + 1) * (c2 + 1) * ...
//     for (auto prime : primes) {
//         // prime.second 就是这个质因数的指数 c
//         res = res * (prime.second + 1) % MOD;
//     }

//     cout << res << "\n";

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long//注意 res
const int p=1e9+7;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    int n;cin>>n;
    unordered_map<int,int>prime;//底数，指数
    while(n--)
    {
        int x;cin>>x;
        for(int i=2;i<=x/i;i++)
        {
            if(x%i==0)
            {
                while(x%i==0)
                {
                    x/=i;
                    prime[i]++;
                }
            }
        }
        if(x>1)prime[x]++;
    }
    int res=1;
    for(auto primes:prime)
    {
        res=(res*(primes.second+1)%p)%p;
    }
    cout<<res;
}