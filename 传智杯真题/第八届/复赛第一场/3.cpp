// #include<bits/stdc++.h>
// using namespace std;
// const int p=1e9+7;
// const int N=1e9+1;
// int t;
// int dp[N];
// // int m[N],v[N];
// //这范围也太大了吧
// //完全背包 也不是背包问题
// int main()
// {
//     cin>>t;
//     while(t--)
//     {
//         int n,m;cin>>n>>m;
//     }
//     return 0;
// }


//

// 既然要让总价格 $\sum 2^{x_i}$ 最小，且 $\sum x_i = m$，
// 根据凸函数（$2^x$ 是严格增且下凸的）的性质：当所有的 $x_i$ 越接近时，总和最小。
// 分配基础重量：每个物品分配 $q = \lfloor m / n \rfloor$ 的重量。分配剩余重量：还剩下 $r = m \pmod n$ 的重量，将这 $r$ 个重量分别加到前 $r$ 个物品上。结果：有 $n - r$ 个物品，重量为 $q$。有 $r$ 个物品，重量为 $q + 1$。

// #include <iostream>
// using namespace std;

// long long power(long long base, long long exp) {
//     long long res = 1;
//     base %= 1000000007;
//     while (exp > 0) {
//         if (exp % 2 == 1) res = (res * base) % 1000000007;
//         base = (base * base) % 1000000007;
//         exp /= 2;
//     }
//     return res;
// }

// void solve() {
//     long long n, m;
//     cin >> n >> m;
//     // 如果重量比数量少，每个物品选重量 1 即可（题目说物品重量 i 是正整数，最小为 1）
//     if (m <= n) {
//         cout << (m * 2) % 1000000007 << endl;
//         return;
//     }
//     long long q = m / n;
//     long long r = m % n;
    
//     long long p_q = power(2, q);
//     long long p_q1 = (p_q * 2) % 1000000007;
    
//     long long ans = ((n - r) % 1000000007 * p_q) % 1000000007;
//     ans = (ans + (r % 1000000007 * p_q1) % 1000000007) % 1000000007;
    
//     cout << ans << endl;
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) solve();
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
const int p = 1e9 + 7;
#define int long long
int t;
//pow  命名冲突风险：pow 函数 std 命名空间里已经有一个处理浮点数的 pow(double, double)。
int qpow(int base, int exp) {
    int res = 1;
    while (exp) {
        //如果指数当前为1
        if (exp & 1)res = res * base % p;
        base = base * base % p;
        exp >>= 1;
    }
    return res;
}
void solve() {
    int n, m;
    cin >> n >> m;
    if (m <= n) {
        //全选重量为1的选m个
        cout << 2 * m % p << endl;
    } else {
        int q = m / n; //基础重量
        int r = m % n; //多出来的重量加到前r项，每一项+1
        //总价钱 (n-r)*(2^q)+r*(2^(q+1));

        int p_q = qpow(2, q);
        int p_q1 = (p_q) * 2 % p;
        int ans = ((n - r) % p) * p_q % p;
        ans = (ans + r * p_q1 % p) % p;
        cout << ans << endl;
    }
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--)solve();
    return 0;
}