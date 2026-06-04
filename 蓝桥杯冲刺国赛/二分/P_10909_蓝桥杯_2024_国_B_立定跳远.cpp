// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,m;
// const int N=1e5+11;
// int a[N];
// bool check(int x)
// {
//     int cnt=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(a[i]-a[i-1]>x)
//         {
//             cnt+=(a[i]-a[i-1]-1)/x;
//         }
//     }
//     if(cnt>m+1)return true;
//     return false;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     //最远的最近距离
//     sort(a+1,a+1+n);
//     // 1｜2 3 4 5 距离
//     // 5｜3 3 2 1 检查点
//     //和之前不同的就是 可以有一个远距离的点 相当于m+1 个检查点吗？yes@!!!!
//     int l=0,r=0x3f3f3f3f;
//     while(l+1!=r)
//     {
//         int mid=(l+r)/2;
//         if(check(mid))l=mid;
//         else r=mid;
//     }
//     cout<<r;

//     return 0;
// }
