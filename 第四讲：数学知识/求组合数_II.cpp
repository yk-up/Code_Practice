// // //a,b<=10000  预处理只能
// // //利用阶乘公式预处理
// // #include<bits/stdc++.h>
// // using namespace std;

// // const int p = 1e9+7;
// // const int N = 1e5+5;

// // long long fact[N], infact[N]; // 阶乘数组 和 阶乘的逆元数组

// // // 快速幂求 a^k % p
// // long long qmi(long long a, long long k, long long p) {
// //     long long res = 1;
// //     while (k) {
// //         if (k & 1) res = res * a % p;
// //         a = a * a % p;
// //         k >>= 1;
// //     }
// //     return res;
// // }

// // int main() {
// //     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
// //     // 预处理阶乘和阶乘的逆元
// //     fact[0] = infact[0] = 1;
// //     for (int i = 1; i < N; i++) {
// //         fact[i] = fact[i - 1] * i % p;
// //         infact[i] = infact[i - 1] * qmi(i, p - 2, p) % p;
// //     }
// //     //a的逆元就是 a^(p-2)
// //     int n;
// //     cin >> n;
// //     while (n--) {
// //         int a, b;
// //         cin >> a >> b;
// //         // 如果 b > a，组合数不合法，应当输出 0
// //         if(b > a) {
// //             cout << 0 << '\n';
// //         } else {
// //             // C(a, b) = a! / (b! * (a-b)!) % p
// //             long long res = fact[a] * infact[b] % p * infact[a - b] % p;
// //             cout << res << '\n';
// //         }
// //     }
// //     return 0;
// // }


// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // const int N=1e5+11;//范围不是n的的大小给看a,b
// // const int p=1e9+7;
// // int fact[N];
// // int infact[N];
// // int n;
// // int qmi(int base,int exp,int p)
// // {
// //     int res=1;
// //     while(exp)
// //     {
// //         if(exp&1)res=res*base%p;
// //         base=base*base%p;
// //         exp>>=1;
// //     }
// //     return res;
// // }
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n;
// //     fact[0]=infact[0]=1;//记住这个初始化
// //     for(int i=1;i<N;i++)
// //     {
// //         fact[i]=fact[i-1]*i%p;
// //         infact[i]=infact[i-1]*qmi(i,p-2,p)%p;
// //     }
// //     while(n--)
// //     {
// //         int a,b;cin>>a>>b;//看下面的细节，有多个取余
// //         cout<<fact[a]*infact[b]%p*infact[a-b]%p<<endl;
// //     }
// //     return 0;
// // }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int p=1e9+7;
// const int N=1e5+11;
// int fact[N],infact[N];
// int qmi(int base,int exp,int p)
// {
//     int res=1;
//     base%=p;
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
//     //C(a,b)=a!/(a-b)!*b!==(a*(a-1)*(a-2)...(a-b+1).)/1*2*3*4*b
//     //预处理
//     fact[0]=infact[0]=1;
//     for(int i=1;i<N;i++)
//     {
//         fact[i]=fact[i-1]*i%p;
//         infact[i]=infact[i-1]*qmi(i,p-2,p)%p;
//     }
//     int n;cin>>n;
//     while(n--)
//     {
//         int a,b;cin>>a>>b;
//         cout<<(fact[a]%p*infact[b]%p*infact[a-b]%p)%p<<endl;;//注意这里的取模
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=1e9+7;
const int N=1e5+11;
int fact[N],infact[N];
int qmi(int base,int exp,int p)
{
    int res=1;
    base=base%p;
    while(exp)
    {
        if(exp&1)res=res*base%p;
        exp>>=1;
        base=base*base%p;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    fact[0]=infact[0]=1;
    for(int i=1;i<N;i++)
    {
        fact[i]=fact[i-1]*i%p;
        infact[i]=infact[i-1]*qmi(i,p-2,p)%p;
    }
    while(n--)
    {
        int a,b;cin>>a>>b;
        cout<<fact[a]%p*infact[a-b]%p*infact[b]%p<<endl;
    }
    return 0;
}