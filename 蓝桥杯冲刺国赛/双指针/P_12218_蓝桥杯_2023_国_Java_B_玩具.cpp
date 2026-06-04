// //虽然做对了但不知为什么
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=2e5+11;//数组至少得两倍
// int a[N];
// int n;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     //最大和最小匹配吗
//     cin>>n;
//     int ans=0;
//     for(int i=1;i<=2*n;i++)cin>>a[i];
//     sort(a+1,a+1+2*n);//注意现在是 2*n
//     for(int i=1;i<=n;i++)
//     {
//         ans+=a[i]*a[2*n+1-i];
//     }
//     cout<<ans;
//     return 0;
// }


