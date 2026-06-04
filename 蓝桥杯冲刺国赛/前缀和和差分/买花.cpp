// //很久很久之前做过的题还是不行啊
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// int m,n;
// char s[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>m>>n;
//     //
//     for(int i=1;i<=n;i++)cin>>s[i];
//     return 0;
// }


// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// int main() {
//     // 优化输入输出流
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int n, k;
//     if (!(cin >> n >> k)) return 0;
//     string s;
//     cin >> s;
    
//     long long ans = 0;
    
//     // 枚举花束中可能包含的鲜花种类数 d (最多 26 种)
//     for (int d = 1; d <= 26; d++) {
//         int window_size = d * k;
        
//         // 如果窗口大小超过了总花数，直接结束循环
//         if (window_size > n) {
//             break;
//         }
        
//         vector<int> cnt(26, 0);
//         int valid_count = 0; // 记录出现次数恰好等于 k 的字母种类数
        
//         // 1. 初始化第一个滑动窗口
//         for (int i = 0; i < window_size; i++) {
//             int c = s[i] - 'a';
//             // 状态变更前，如果原本刚好是 k，现在要增加，合法数量减 1
//             if (cnt[c] == k) valid_count--;
//             cnt[c]++;
//             // 状态变更后，如果变成 k 了，合法数量加 1
//             if (cnt[c] == k) valid_count++;
//         }
        
//         // 检查第一个窗口是否合法
//         if (valid_count == d) {
//             ans++;
//         }
        
//         // 2. 窗口开始向右滑动
//         for (int i = window_size; i < n; i++) {
//             int in_c = s[i] - 'a';             // 滑入窗口的新字母
//             int out_c = s[i - window_size] - 'a'; // 滑出窗口的老字母
            
//             // 处理滑入的字母
//             if (cnt[in_c] == k) valid_count--;
//             cnt[in_c]++;
//             if (cnt[in_c] == k) valid_count++;
            
//             // 处理滑出的字母
//             if (cnt[out_c] == k) valid_count--;
//             cnt[out_c]--;
//             if (cnt[out_c] == k) valid_count++;
            
//             // 检查当前窗口是否合法
//             if (valid_count == d) {
//                 ans++;
//             }
//         }
//     }
    
//     cout << ans << "\n";
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,k;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>k;
//     string s;cin>>s;
//     int n=s.size();
//     // vector<int>cnt(26,0);//每个字母出现的次数

//     //int valid=0;//窗口内=k的种类数

//     int ans=0;
//     for(int d=1;d<=26;d++)//枚举窗口的东西总类数
//     {
//         //注意这二行代码的初始化位置，每次窗口大小变化的时候，要初始化
//         vector<int>cnt(26,0);//每个字母出现的次数
//         int valid=0;
        
//         int window_size=d*k;
        
//         if(window_size>n)
//         {
//             break;
//         }

//         //初始化第一个窗口
//         for(int i=0;i<window_size;i++)
//         {
//             char in_c=s[i];
//             if(cnt[in_c-'a']==k)valid--;
//             cnt[in_c-'a']++;

//             if(cnt[in_c-'a']==k)valid++;
//         }
//         if(valid==d)
//         {
//             ans++;
//         }

//         //移动窗口
//         for(int i=window_size;i<n;i++)
//         {
//             int in_c=s[i]-'a';//新进的字母
//             int out_c=s[i-window_size]-'a';

//             if(cnt[in_c]==k)valid--;
//             cnt[in_c]++;
//             if(cnt[in_c]==k)valid++;

//             if(cnt[out_c]==k)valid--;
//             cnt[out_c]--;
//             if(cnt[out_c]==k)valid++;

//             if(valid==d)
//             {
//                 ans++;
//             }
//         }

//     }
//     cout<<ans;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    string s;cin>>s;
    int ans=0;
    for(int d=1;d<=26;d++)
    {
        int window_size=d*k;

        if(window_size>n)
        {
            break;//!!!
        }
        vector<int>cnt(26,0);
        int valid=0;//等于k的数量

        for(int i=0;i<window_size;i++)
        {
            int in_c=s[i]-'a';
            if(cnt[in_c]==k)valid--;
            cnt[in_c]++;
            if(cnt[in_c]==k)valid++;
        }
        if(valid==d)ans++;

        for(int i=window_size;i<s.size();i++)
        {
            int in_c=s[i]-'a';
            if(cnt[in_c]==k)valid--;
            cnt[in_c]++;
            if(cnt[in_c]==k)valid++;

            int out_c=s[i-window_size]-'a';
            if(cnt[out_c]==k)valid--;
            cnt[out_c]--;
            if(cnt[out_c]==k)valid++;

            if(valid==d)ans++;
        }
    }
    cout<<ans;
    return 0;
}