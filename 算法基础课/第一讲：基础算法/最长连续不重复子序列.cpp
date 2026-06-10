// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// int a[N];
// signed main()
// {
//     int n;cin>>n;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     int i=1,j=i+1;
//     int maxlen=1;
//     for(int j=2;i<=n;i++)
//     {
//         while(a[j]!=a[i])
//         {
//             maxlen=max(maxlen,j-i+1);
//             j++;
//         }

//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// int s[N];//判断这个区间呢的数字出现了几次
// int a[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     for(int i=0;i<n;i++)cin>>a[i];
//     int res=0;
//     for(int i=0,j=0;i<n;i++)
//     {
//         s[a[i]]++;
        
//         // while(j<=i)
//         while(s[a[i]]>1)
//         {
//             s[a[j]]--;
//             j++;
//         }
//         res=max(res,i-j+1);
//     }
//     cout<<res;
//     return 0;
// }

//好巧妙
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
int a[N];
int s[N];//判断每个数字出现的次数(窗口内)
int n;
int ans=0;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1,j=1;i<=n;i++)
    {
        s[a[i]]++;
        while(s[a[i]]>1)
        {
            s[a[j]]--;
            j++;
        }
        ans=max(ans,i-j+1);
    }
    cout<<ans;
    return 0;
}