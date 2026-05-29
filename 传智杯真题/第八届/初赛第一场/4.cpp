// //有点小问题，没考虑到重叠区间
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+11;
// int a[N];//标记是否上锁
// int prefix[N];
// int t;
// int n,m,x,y;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>t;
//     while(t--)
//     {
//         cin>>n>>m>>x>>y;
//         memset(a,0,sizeof a);

//         //超时
//         // for(int i=0;i<m;i++)
//         // {
//         //     int ans1=0,ans2=0;
//         //     int k;cin>>k;
//         //     a[k]=!a[k];//取反
//         //     //超时
//         //     for(int i=1;i<=n;i++)
//         //     {
//         //         if(i<=x)
//         //         {  
//         //         ans1+=!a[i];
//         //         }
//         //         if(i>=y)
//         //         {
//         //             ans2+=!a[i];
//         //         }
//         //     }
//         //     cout<<ans1<<" "<<ans2<<endl;
//         // }

        
//         //每次都区间不变
//         int ans1=0,ans2=0;
// //         1. 致命逻辑漏洞：重叠区间会导致“双重反转”仔细看你处理查询的代码：C++if(k<=x) {
// //     a[k]=!a[k]; // 第一次取反
// //     // ...
// // }
// // if(k>=y) {
// //     a[k]=!a[k]; // 第二次取反！
// //     // ...
// // }
// // 问题在哪？ 如果 $y \le x$，那么必然存在一些 $k$ 同时满足 k <= x 和 k >= y。当遇到这种 $k$ 时：第一个 if 会把 a[k] 取反一次（比如 0 变成 1）。第二个 if 接着又把 a[k] 取反了一次（1 又变回 0）。结果： 相当于 a[k] 的状态根本没变，但是你的 ans1 和 ans2 却基于中间错乱的状态进行了加减，导致答案彻底算错。正确的做法： 每次查询只对 a[k] 取反一次，然后再分别判断它是否在区间内并更新计数。
//         for(int i=1;i<=n;i++)
//         {
//             if(i<=x)ans1+=(a[i]==0);
//             if(i>=y)ans2+=(a[i]==0);
//         }
//         while(m--)
//         {
//             int k;cin>>k;//对a[k]的去反
//             a[k]=!a[k];
//             if(k<=x)
//             {
//                 //a[k]=!a[k];
//                 if(a[k]==0)ans1++;
//                 else ans1--;
//             }
//             if(k>=y)
//             {
//                 //a[k]=!a[k];
//                 if(a[k]==0)ans2++;
//                 else ans2--;
//             }
//             cout<<ans1<<" "<<ans2<<endl;
//         }
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+11;
int t;
int a[N];
int main()
{
    cin>>t;
    
    while(t--)
    {
        int n,m,x,y;cin>>n>>m>>x>>y;
        int ans1=0,ans2=0;
        memset(a,0,sizeof a);
        for(int i=1;i<=n;i++)
        {
            if(i<=x)
            {
                ans1++;
            }
            if(i>=y)ans2++;
        }
        while(m--)
        {
            int k;cin>>k;
            a[k]=!a[k];
            
            if(k<=x)
            {
                if(a[k]==0)
                ans1++;
                else ans1--;
            }
            if(k>=y)
            {
                if(a[k]==1)
                ans2--;
                else ans2++;
            }
            cout<<ans1<<" "<<ans2<<endl;
        }
        
    }
    return 0;
}