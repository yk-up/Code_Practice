// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=2e5+11;
// int a[N],prefix[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         prefix[i]=prefix[i-1]+a[i];
//     }

//     int ans=0;
//     for(int i=2;i<=n-2;i++)
//     {
//         for(int j=i;j<=n-1;j++)
//         {
//             int ans1=prefix[i-1]-prefix[0];
//             int ans2=prefix[j]-prefix[i-1];
//             int ans3=prefix[n]-prefix[j];

//             if(ans1==ans2&&ans2==ans3)ans++;
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=2e5+11;
// int a[N],prefix[N];

// signed main()
// {
//     // 优化输入输出流
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
//     int n;
//     if (!(cin >> n)) return 0; // 防止无输入的情况
    
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         prefix[i]=prefix[i-1]+a[i];
//     }

//     // 1. 如果总和不能被 3 整除，直接输出 0
//     if(prefix[n] % 3 != 0) {
//         cout << 0 << "\n";
//         return 0;
//     }

//     int S = prefix[n] / 3;
//     int ans = 0;
//     int count_S = 0;

//     // 2. 只需要遍历到 n-1，保证第三段非空 (至少包含 a[n])
//     for(int i=1;i<=n-1;i++)
//     {
//         // 遇到 2S，说明可以作为第二刀。前面有多少个 S，就有多少种合法切法
//         if(prefix[i] == 2 * S) {
//             ans += count_S;
//         }
        
//         // 遇到 S，累加第一刀的候选位置数量
//         // 注意：先判断 2S 再判断 S，可以完美避开 S=0 时第一刀和第二刀切在同一个位置的Bug
//         if(prefix[i] == S) {
//             count_S++;
//         }
//     }
    
//     cout << ans << "\n";
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int N=2e5+11;
int prefix[N];
//找等于prefix[i]==s的点的数量 再找prefix[i]==2*s的点 方案数量+=count(prefix[i]==s)
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        prefix[i]=prefix[i-1]+x;
    }

    if(prefix[n]%3!=0)
    {
        //那肯定分不成相等的3段
        cout<<0;
        return 0;
    }
    int s=prefix[n]/3;
    int count_=0;//prefix[i]==s;
    int ans=0;//方案数
    for(int i=1;i<=n-1;i++)//等三段得保证为空，所以最多枚举到N-1
    {
        if(prefix[i]==2*s)ans+=count_;

        if(prefix[i]==s)
        {
            count_++;
        }
    }
    cout<<ans;
    return 0;
}