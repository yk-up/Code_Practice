//你的代码只考虑了“多对1”或“1对多”的情况，完全没有处理“多对多”的合并。
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=3e5+11;
// int a[N],b[N];
// int n,m;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     for(int i=1;i<=m;i++)cin>>b[i];

//     int j=1,k=1;
//     int cnt=0;
//     while(1)
//     {
//         if(a[j]<b[k])
//         {
//             int temp=a[j];
//             int I=j;
//             while(temp<b[k])
//             {
//                 temp+=a[++I];
//             }
//             cnt+=I-j;
//             j=I;
//             j++,k++;
//         }
//         else if(a[j]>b[k])
//         {
//             int temp=b[k];
//             int I=k;
//             while(temp<a[j])
//             {
//                 temp+=b[++I];
//             }
//             cnt+=I-k;
//             k=I;
//             j++,k++;
//         }
//         else j++,k++;

//         if(j>n||k>m)break;
//     }
//     cout<<cnt;
 
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=3e5+11;
// int a[N],b[N];
// int n,m;

// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
    
//     int sumA = 0, sumB = 0;
//     for(int i=1;i<=n;i++) {
//         cin>>a[i];
//         sumA += a[i];
//     }
//     for(int i=1;i<=m;i++) {
//         cin>>b[i];
//         sumB += b[i];
//     }

//     // 1. 如果两数组总和都不相等，绝对不可能合并成功
//     if(sumA != sumB) {
//         cout << -1 << "\n"; // 根据大部分题目要求，无解输出 -1
//         return 0;
//     }

//     int j=1, k=1;
//     int cnt=0;
    
//     // 2. 双指针遍历
//     while(j <= n && k <= m)
//     {
//         if(a[j] == b[k]) {
//             // 完全匹配，指针同时后移
//             j++; 
//             k++;
//         }
//         else if(a[j] < b[k]) {
//             // a 这边比较小，把 a[j] 合并到 a[j+1] 上
//             a[j+1] += a[j]; 
//             j++; // a 的指针后移，表示消耗了一次合并
//             cnt++;
//         }
//         else {
//             // b 这边比较小，把 b[k] 合并到 b[k+1] 上
//             b[k+1] += b[k];
//             k++;
//             cnt++;
//         }
//     }
    
//     cout << cnt << "\n";
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// int a[N],b[N];
// int n,m;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     for(int i=1;i<=m;i++)cin>>b[i];

//     int i=1,j=1;
//     int ans=0;
//     while(i<=n&&j<=m)
//     {
//         if(a[i]<b[j])
//         {
//             a[i+1]+=a[i];
//             ans++;
//             i++;
//         }
//         else if(a[i]>b[j])
//         {
//             b[j+1]+=b[j];
//             ans++;
//             j++;
//         }
//         else i++,j++;
//     }
//     cout<<ans;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// int a[N];
// int b[N];
// int n,m;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     for(int i=1;i<=m;i++)cin>>b[i];
    
//     int i=1,j=1;
//     int ans=0;
//     while(i<=n&&j<=m)
//     {
//         if(a[i]<b[j])
//         {
//             a[i+1]+=a[i];
//             ans++;
//             i++;
//         }
//         else if(b[j]<a[i])
//         {
//             b[j+1]+=b[j];
//             ans++;
//             j++;
//         }
//         else
//         {
//             i++;j++;
//         }
//     }
//     cout<<ans;
//     return 0;
// }

