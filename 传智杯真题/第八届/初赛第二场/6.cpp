// //不会不知道从哪入手

// //好好理解一下
//如果 G 能整除两个数，那么它一定也能整除这两个数的 差值
// #include <iostream>
// #include <vector>
// #include <numeric>
// #include <algorithm>

// using namespace std;

// typedef long long ll;

// // 标准辗转相除法求 GCD
// ll gcd(ll a, ll b) {
//     return b == 0 ? a : gcd(b, a % b);
// }

// int main() {
//     ios::sync_with_stdio(0); cin.tie(0);

//     int n;
//     if (!(cin >> n)) return 0;

//     vector<ll> a(n);
//     for (int i = 0; i < n; i++) cin >> a[i];

//     // 1. 求出所有差值的 GCD
//     ll D = 0;
//     for (int i = 1; i < n; i++) {
//         D = gcd(D, abs(a[i] - a[0]));
//     }

//     // 2. 根据 D 计算最小的 k
//     // 注意：题目保证至少有两个不相同的数，所以 D 绝不会是 0
//     ll k = (D - (a[0] % D)) % D;

//     cout << D << " " << k << endl;

//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100002;
int a[N];
signed main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int g=0;
    for(int i=1;i<=n;i++)
    {
        g=__gcd(g,abs(a[i]-a[1]));
    }

    //(a[i]+k)%mod=g;
    //k=(g-a[i]%g)%g;
    int k=(g-a[1]%g)%g;
    cout<<g<<" "<<k<<endl;
}