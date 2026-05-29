//还是没思路 这道题也不会
#include <iostream>
#include <vector>

using namespace std;

/**
 * 软工建议：
 * 1. 使用 long long 防止加法溢出。
 * 2. 预分配空间避免 vector 频繁扩容。
 */
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
long long dp[MAXN][2];

int main() {
    int n;
    if (!(cin >> n)) return 0;

    // 基础边界情况
    if (n >= 1) dp[1][0] = 1; // 第一步跳 1 级（左）
    if (n >= 2) {
        dp[2][0] = 0;         // 2 是偶数，不能作为奇数步结尾
        dp[2][1] = 1;         // 第一步跳 2 级（右）
    }

    // 线性递推
    for (int i = 3; i <= n; i++) {
        // 到达 i 且最后是奇数步 = 上一步是偶数结尾(i-1, i-3...) + 奇数项基础步
        // 简化后：
        dp[i][0] = (dp[i-1][1] + dp[i-2][0]) % MOD;
        // 到达 i 且最后是偶数步 = 上一步是奇数结尾(i-2, i-4...) + 偶数项基础步
        // 简化后：
        dp[i][1] = (dp[i-2][0] + dp[i-2][1]) % MOD;
    }

    long long ans = (dp[n][0] + dp[n][1]) % MOD;
    cout << ans << endl;

    return 0;
}