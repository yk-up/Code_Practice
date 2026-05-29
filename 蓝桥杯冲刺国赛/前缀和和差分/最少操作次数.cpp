// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // const int N=1e5+11;
// // int a[N];
// // int n;
// // siged main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n;
// //     int ans=0;
// //     for(int i=1;i<=n;i++)cin>>a[i];
// //     //找右边第一个大于 a[i]的数字 只有比大大的还剩，比 a[i]就直接到 1 了
// //     for(int i=1;i<=n;i++)
// //     {
// //         if(a[i]==1)continue;
// //         for(int j=i+1;j<=n;j++)
// //         {
// //             if(a[i])
// //         }
// //     }
// //     return 0;
// // }


//md 真的好巧妙啊
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long

// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;
//     if(!(cin >> n)) return 0;
    
//     int ans = 0;
//     int prev = 1; // 假想在数组最前面有一个值为 1 的数字作为地基
    
//     for(int i = 1; i <= n; i++)
//     {
//         int curr;
//         cin >> curr;
        
//         // 如果当前数字比前一个大，说明前一个数字的操作区间“覆盖不到”现在这么高
//         // 必须为多出来的这部分高度增加操作次数
//         if(curr > prev)
//         {
//             ans += (curr - prev);
//         }
        
//         // 更新 prev，继续看下一个数字
//         prev = curr;
//     }
    
//     cout << ans << "\n";
//     return 0;
// }


//z
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
int a[N];
int n;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    //for(int i=1;i<=n;i++)cin>>a[i];

    int curr=0;
    int prev=1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>curr;

        if(curr>prev)
        {
            ans+=curr-prev;//前一个高的地方的操作区间覆盖不了这里
        }
        prev=curr;
    }
    cout<<ans;
    return 0;
}