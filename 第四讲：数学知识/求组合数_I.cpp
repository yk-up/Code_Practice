//超时
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int p=1e9+7;
// int C(int n,int m)
// {
//     if(m>n)return 0;
//     if(n==m||m==0)return 1;
//     if(n-m<m)m=n-m;
//     return (C(n-1,m)+C(n-1,m-1))%p;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     while(n--)
//     {
//         int a,b;cin>>a>>b;
//         cout<<C(a,b)<<endl;
//     }
//     return 0;
// }

//一堆问题
// #include<bits/stdc++.h>
// using namespace std;
// const int p=1e9+7;
// const int N=1e4+1;
// int C[N][N];
// int n;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=0;i<N;i++)C[i][0]=1;
//     C[0][0]=0;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
//         }
//     }
//     while(n--)
//     {
//         int a,b;cin>>a>>b;
//         cout<<C[a][b]<<endl;
//     }
//     return 0;
// }

// //注意 C[0][0]=1！！！
// //只适用 a,b<=2000
// #include<bits/stdc++.h>
// using namespace std;

// const int p = 1e9+7;
// const int N = 2005; // 假设最大查询的 a 不超过 2000
// int C[N][N];

// int main() {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
//     // 1. 独立于询问次数 n，先预处理出所有可能用到的组合数
//     for(int i = 0; i < N; i++) {
//         C[i][0] = 1; // 初始化 C(i, 0) = 1
//         for(int j = 1; j <= i; j++) { // 优化：j 最多循环到 i 即可
//             C[i][j] = (C[i-1][j] + C[i-1][j-1]) % p;
//         }
//     }
    
//     int n;
//     cin >> n;
//     while(n--) {
//         int a, b;
//         cin >> a >> b;
//         cout << C[a][b] << '\n'; // 使用 '\n' 替代 endl
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=1e9+7;
int n;
const int N=2e3+11;
int C[N][N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    C[0][0]=1;
    for(int i=1;i<N;i++)
    {
        C[i][0]=1;
        // for(int j=1;j<N;j++)
        for(int j=1;j<=i;j++)//优化
        {
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
        }
    }
    while(n--)
    {
        int a,b;cin>>a>>b;
        cout<<C[a][b]<<endl;
    }
    return 0;
}