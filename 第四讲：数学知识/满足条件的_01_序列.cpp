// // // //没思路

// // // #include <iostream>
// // // using namespace std;

// // // typedef long long LL;
// // // const int p = 1e9 + 7;

// // // // 快速幂求逆元
// // // int qmi(int a, int k, int p) {
// // //     int res = 1;
// // //     while (k) {
// // //         if (k & 1) res = (LL)res * a % p;
// // //         a = (LL)a * a % p;
// // //         k >>= 1;
// // //     }
// // //     return res;
// // // }

// // // int main() {
// // //     // 依然加上快读优化
// // //     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
// // //     int n;
// // //     cin >> n;
    
// // //     int res = 1;
// // //     // 1. 计算组合数 C(2n, n)
// // //     // 分子从 2n 往下减，分母从 1 往上加，和之前一模一样！
// // //     for (int i = 1, j = 2 * n; i <= n; i++, j--) {
// // //         res = (LL)res * j % p;                  // 乘分子
// // //         res = (LL)res * qmi(i, p - 2, p) % p;   // 乘分母的逆元
// // //     }
    
// // //     // 2. 根据卡特兰数公式，最后还要除以 (n + 1)
// // //     // 也就是乘以 (n + 1) 的逆元
// // //     res = (LL)res * qmi(n + 1, p - 2, p) % p;
    
// // //     cout << res << '\n';
    
// // //     return 0;
// // // }

// // //C(2n,n)
// // //2n*...n+1/1*2*3*...*n
// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // const int p=1e9+7;
// // int n;
// // int qmi(int base,int exp,int p)
// // {
// //     int res=1;
// //     base=base%p;
// //     while(exp)
// //     {
// //         if(exp&1)res=res*base%p;//别忘记 p
// //         base=base*base%p;
// //         exp>>=1;
// //     }
// //     return res;
// // }

// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n;
// //     int res=1;
// //     for(int i=1,j=2*n;i<=n;i++,j--)
// //     {
// //         res=res*j%p;
// //         res=res*qmi(i,p-2,p)%p;
// //     }
// //     res=res*qmi(n+1,p-2,p)%p;
// //     cout<<res;
// //     return 0;
// // }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int p=1e9+7;
// int qmi(int base,int exp,int p)
// {
//     int res=1;
//     base=base%p;
//     while(exp)
//     {
//         if(exp&1)res=res*base%p;
//         base=base*base%p;
//         exp>>=1;
//     }
//     return res;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     //int res=C(2n,n);
//     int res=1;
//     for(int i=1,j=2*n;i<=n;i++,j--)
//     {
//         res=res*j%p;
//         res=res*qmi(i,p-2,p)%p;
//     }
//     res=res*qmi(n+1,p-2,p)%p;
//     cout<<res;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=1e9+7;
int n;
int qmi(int base,int exp,int p)
{
    int res=1;
    base=base%p;
    while(exp)
    {
        if(exp&1)res=res*base%p;
        base=base*base%p;
        exp>>=1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    int res=1;
    for(int i=1,j=2*n;i<=n;i++,j--)
    {
        res=res*j%p;
        res=res*qmi(i,p-2,p)%p;
    }
    res=res*qmi(n+1,p-2,p)%p;
    cout<<res;
    return 0;
}