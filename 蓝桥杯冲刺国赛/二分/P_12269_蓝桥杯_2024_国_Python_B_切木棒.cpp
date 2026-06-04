// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // const int N=5002;
// // int a[N];
// // int n,m;
// // //如果我要求切完后最长的木棒长度不能超过 $x$，我手中的 $m$ 次切割机会够用吗？
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n>>m;
// //     for(int i=1;i<=n;i++)cin>>a[i];
// //     //被切成两段的木棍也可以被选择继续切成两段。？？？
// //     sort(a+1,a+1+n);
// //    //假设我们当前猜的最大长度是 $x$。对于一根长度为 $L$ 的木棒，我们需要切多少次才能保证每一段都不超过 $x$ 呢？
// //     //2 2 2 3
// //     //2 2 2 2
// //     //1 2 3 4
// //     return 0;
// // }

// //二分又有点不熟了
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=3e5+11;
// int a[N];
// int n,m;
// bool check(int x)
// {
//     int ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(a[i]>x)
//         {
//             ans+=(a[i]-1)/x;//计算切割的次数
//         }
//     }
//     //次数多
//     if(ans>m)return true;
//     return false;

//     // 1 2 ｜3 4 5 长度 枚举那个那个就是单调的
//     // 5 5 ｜3 3 2 次数
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     int maxlen=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         maxlen=max(a[i],maxlen);
//     }
//     sort(a+1,a+1+n);
//     //枚举切割的最长长度
//     //int l=1,r=0x3f3f3f3f;
//     //为了让 while(l+1 != r) 模板不漏掉 1 这个合法答案，你必须给 l 设置一个“绝对不可能达到、彻头彻尾的非法值”。
//     int l=0,r=maxlen+1;
//     while(l+1!=r)
//     {
//         int mid=(l+r)/2;
//         // if(check(mid))l=mid;
//         // else r=mid;
//         if(check(mid))l=mid;
//         else r=mid;
//     }
//     cout<<r;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+11;
int a[N];
int n,m;

bool check(int x)
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>x)
        {
            cnt+=(a[i]-1)/x;
        }
    }
    if(cnt>m)return true;
    return false;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    //枚举最长的木根长度
    int l=0,r=0x3f3f3f3f;
    // 1 ｜2 3 4 5 //长度
    // 5 ｜4 4 3 2  //次数 
    while(l+1!=r)
    {
        int mid=(l+r)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    cout<<r;
    return 0;
}