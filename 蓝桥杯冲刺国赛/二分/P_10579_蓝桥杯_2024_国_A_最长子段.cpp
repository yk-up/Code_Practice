//暴力 50%
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,a,b,c;
// const int N=3e5+11;
// int s[N];
// int prefix[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>a>>b>>c;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>s[i];
//         prefix[i]=prefix[i-1]+s[i];
//     }
//     int ans=0;
//     //暴力
//     for(int i=1;i<=n;i++)
//     {
//         //i-j
//         for(int j=1;j<=n;j++)
//         {
//             int sum1=prefix[j]-prefix[i-1];
//             int sum2=a*(b*j-c*i);
//             if(sum1>sum2)
//             {
//                 ans=max(ans,j-i+1);
//             }
//         }
//     }
//     cout<<ans;
//     return 0;
// }

//没理解
//遇到“不等式中左右两端点 $L$ 和 $R$ 互相干扰”的题目，分离变量是第一直觉。
#include <bits/stdc++.h>
using namespace std;

// 数据可能很大，开 long long 保平安，防止前缀和和乘法溢出
#define int long long

const int MAXN = 3e5 + 11;
int s[MAXN];
int P[MAXN];
int A[MAXN];
int B[MAXN];
int min_B[MAXN];

signed main() {
    // 优化输入输出
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, a, b, c;
    if (!(cin >> n >> a >> b >> c)) return 0;
    
    // 1. 读入数据并计算前缀和
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        P[i] = P[i - 1] + s[i];
    }
    
    // 2. 构造 A 数组、 B 数组和前缀最小值数组 min_B
    for (int i = 1; i <= n; i++) {
        A[i] = P[i] - a * b * i;
    }
    
    for (int j = 0; j < n; j++) {
        B[j] = P[j] - a * c * (j + 1);
        if (j == 0) {
            min_B[j] = B[j];
        } else {
            min_B[j] = min(min_B[j - 1], B[j]); // 维护前缀最小值
        }
    }
    
    int ans = 0;
    
    // 3. 遍历右端点，二分查找最优的左端点
    for (int i = 1; i <= n; i++) {
        int l = 0, r = i - 1;
        int best_j = -1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            // 因为 min_B 是非递增的，遇到满足条件的，我们尝试去左半区找更小的下标
            if (min_B[mid] < A[i]) {
                best_j = mid;
                r = mid - 1; 
            } else {
                l = mid + 1;
            }
        }
        
        // 如果找到了合法的起点，更新最长长度
        if (best_j != -1) {
            ans = max(ans, i - best_j);
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}