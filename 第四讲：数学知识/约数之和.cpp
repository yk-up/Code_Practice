#include <iostream>
#include <unordered_map>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    // 1. 依然是找出所有的“质因数乐高积木”及其数量
    unordered_map<int, long long> primes;

    while (n--) {
        int x;
        cin >> x;
        
        for (int i = 2; i <= x / i; i++) {
            while (x % i == 0) {
                x /= i;
                primes[i]++; 
            }
        }
        if (x > 1) {
            primes[x]++;
        }
    }

    // 2. 套用约数之和公式
    long long res = 1;
    for (auto prime : primes) {
        long long p = prime.first;  // 质因数底数
        long long c = prime.second; // 质因数的指数
        
        long long t = 1; // 用于计算 (p^0 + p^1 + ... + p^c)
        // 循环 c 次，利用 t = t * p + 1 迭代求和
        for (int i = 0; i < c; i++) {
            t = (t * p + 1) % MOD;
        }
        
        // 把每个括号的结果乘起来，记得随时取模防止溢出
        res = res * t % MOD;
    }

    cout << res << "\n";

    return 0;
}