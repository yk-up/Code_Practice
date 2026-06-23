// // // #include <iostream>
// // // using namespace std;

// // // typedef long long LL;

// // // // 1. 快速幂求逆元 (用于计算除法取模)
// // // int qmi(int a, int k, int p) {
// // //     int res = 1;
// // //     while (k) {
// // //         if (k & 1) res = (LL)res * a % p;
// // //         a = (LL)a * a % p;
// // //         k >>= 1;
// // //     }
// // //     return res;
// // // }

// // // // 2. 计算小范围的组合数 C(a, b) % p
// // // int C(int a, int b, int p) {
// // //     if (b > a) return 0;
// // //     int res = 1;
// // //     // 根据组合数定义求：a! / (b! * (a-b)!) = (a * a-1 * ... * a-b+1) / (1 * 2 * ... * b)
// // //     //分子从 a 向下减，分母从1 往上加
// // //     for (int i = 1, j = a; i <= b; i++, j--) {
// // //         res = (LL)res * j % p;                  // 乘分子
// // //         res = (LL)res * qmi(i, p - 2, p) % p;   // 乘分母的逆元
// // //     }
// // //     return res;
// // // }

// // // // 3. 卢卡斯定理核心递归
// // // // int lucas(LL a, LL b, int p) {
// // // //     if (a < p && b < p) return C(a, b, p); // 边界：如果 a 和 b 都比 p 小，直接算
// // // //     // 递归公式
// // // //     return (LL)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
// // // // }

// // // //等价的
// // // // int lucas(LL a, LL b, int p) {
// // // //     if (a < p && b < p) return C(a, b, p); 
// // // //     // 左右两边都调用 lucas
// // // //     return (LL)lucas(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
// // // // }

// // // int main() {
// // //     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// // //     int n;
// // //     cin >> n;
// // //     while (n--) {
// // //         LL a, b;
// // //         int p;
// // //         cin >> a >> b >> p;
// // //         cout << lucas(a, b, p) << '\n';
// // //     }
// // //     return 0;
// // // }

// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // int qmi(int base,int exp,int p)
// // {
// //     int res=1;
// //     base=base%p;
// //     while(exp)
// //     {
// //         if(exp&1)res=res*base%p;
// //         base=base*base%p;
// //         exp>>=1;
// //     }
// //     return res;
// // }
// // int C(int a,int b,int p)
// // {
// //     if(b>a)return 0;
// //     int res=1;
// //     for(int i=1,j=a;i<=b;i++,j--)//这里的 j--别忘记就行
// //     {
// //         res=res*j%p;
// //         res=res*qmi(i,p-2,p)%p;
// //     }
// //     return res;
// // }
// // int lucas(int a,int b,int p)
// // {

// //     if(a<p&&b<p)return C(a,b,p);
// //     return lucas(a%p,b%p,p)%p*lucas(a/p,b/p,p)%p;//注意是乘法 别忘记取模
// // }
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     int n;cin>>n;
// //     while(n--)
// //     {
// //         int a,b,p;cin>>a>>b>>p;
// //         cout<<lucas(a,b,p)%p<<endl;//这里也得 mod
// //     }
// //     return 0;
// // }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int a,b,p;
// int qmi(int base,int exp,int q)
// {
//     int res=1;
//     base%=p;
//     while(exp)
//     {
//         if(exp&1)
//         res=res*base%p;
//         base=base*base%p;
//         exp>>=1;
//     }
//     return res;
// }
// int C(int a,int b,int p)
// {
//     if(b>a)return 0;
//     int res=1;
//     //a*(a-1)*...*(a-b+1)/1*2*3*...*b;
//     for(int i=1,j=a;i<=b;i++,j--)
//     {
//         res=res*j%p;//注意这里是j
//         res=res*qmi(i,p-2,p)%p;
//     }
//     return res;//!!!
// }

// int lucas(int a,int b,int p)
// {
//     if(a<p&&b<p)return C(a,b,p);
//     return (lucas(a%p,b%p,p)*lucas(a/p,b/p,p))%p;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     while(n--)
//     {
//         cin>>a>>b>>p;
//         cout<<lucas(a,b,p)%p<<endl;
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
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
int C(int a,int b,int p)
{
    int res=1;
    for(int i=1,j=a;i<=b;i++,j--)
    {
        res=res*j%p;
        res=res*qmi(i,p-2,p)%p;
    }
    return res;
}
int lucas(int a,int b,int p)
{
    if(a<p&&b<p)return C(a,b,p);
    return C(a%p,b%p,p)%p*lucas(a/p,b/p,p)%p;//!!!%p
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    while(n--)
    {
        int a,b,p;cin>>a>>b>>p;
        cout<<lucas(a,b,p)%p<<endl;
    }
    return 0;
}