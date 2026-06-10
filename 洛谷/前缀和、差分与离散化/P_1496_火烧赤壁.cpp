// //错误思路
// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // //利用差分数组 只要是数字>0 就是着火点
// // const int N=2e4+11;
// // int diff[N];
// // bool a[N];
// // //统一向右偏移2的31次方
// // //const int p=2^31; 这个是2异或31
// // const int p=1<<31;
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     int m;cin>>m;
// //     int max_r=-1;
// //     while(m--)
// //     {
// //         int l,r;cin>>l>>r;
// //         l+=p;
// //         r+=p;
// //         max_r=max(max_r,r);
// //         diff[l]++;
// //         diff[r]--;//因为左开右闭 所以是r 正常来说是r+1
// //     }
// //     int cnt=0;
// //     //感觉有问题 因为a[i]
// //     for(int i=1;i<=max_r;i++)
// //     {
// //         a[i]=a[i-1]+diff[i];
// //         if(a[i]>0)cnt++;
// //     }
// //     cout<<cnt;
// //     return 0;
// // }


// //化本质上
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e4+11;
// #define int long long
// int a[N],b[N];//存储的是起点和终点
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
//     sort(a+1,a+1+n);
//     sort(b+1,b+1+n);

//     int l=0;
//     for(int i=1;i<=n;i++)
//     {
//         l+=b[i]-a[i];
//         if(i!=n)
//         {
//             if(b[i]>a[i+1])//这一条线和下一条线 有重合的地方
//             {
//                 l-=b[i]-a[i+1];
//             }
//         }
//     }
//     cout<<l;
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=2e4+11;
// int a[N],b[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i]>>b[i];
//     }
//     sort(a+1,a+1+n);
//     sort(b+1,b+1+n);
//     int ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         ans+=b[i]-a[i];
//         if(i!=n)
//         {
//             if(b[i]>a[i+1])
//             ans-=b[i]-a[i+1];
//         }
//     }
//     cout<<ans;
//     return 0;
// }


// //还行 再多看看 //2025/12/20
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n;
// const int N=2e4+11;
// int a[N];
// int b[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i]>>b[i];
//     }
//     sort(a+1,a+1+n);
//     sort(b+1,b+1+n);

//     int ans=0;
//     for(int i=1;i+1<=n;i++)
//     {
//         ans+=b[i]-a[i];
//         if(b[i]>a[i+1])ans-=b[i]-a[i+1];
//     }
//     ans+=b[n]-a[n];
//     cout<<ans;
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=2e4+11;
// int a[N];
// int b[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i]>>b[i];
//     }
//     sort(a+1,a+1+n);
//     sort(b+1,b+1+n);

//     int ans=0;
//     for(int i=1;i+1<=n;i++)
//     {
//         ans+=b[i]-a[i];
//         if(b[i]>a[i+1])
//         {
//             ans-=b[i]-a[i+1];
//         }
//     }
//     ans+=(b[n]-a[n]);
//     cout<<ans;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
const int N=2e4+11;
#define int long long
int a[N],b[N];
signed main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=b[i]-a[i];
        //−2 31≤a<b<2 31 b[i-1]是0 如果 a[i]是负数的话会算错
        if(i>1&&b[i-1]>a[i])
        {
            ans-=b[i-1]-a[i];
        }
    }

    // for(int i=1;i+1<=n;i++)
    // {
    //     ans+=b[i]-a[i];
    //     if(b[i]>a[i+1])ans-=b[i]-a[i+1];
    // }

    cout<<ans+b[n]-a[n];

    return 0;
}