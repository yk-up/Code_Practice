// //没思路
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// void solve() {
//     int n;
//     cin >> n;
//     int m = n - 1;
//     vector<int> b(m);
//     for (int i = 0; i < m; i++) cin >> b[i];

//     if (n == 0) { cout << 0 << endl; return; }
//     if (m == 0) { cout << 1 << endl; return; }

//     // L[i] 表示以 b[i] 结尾的最长连续递增长度
//     vector<int> L(m, 1);
//     for (int i = 1; i < m; i++) {
//         if (b[i] == b[i - 1] + 1) L[i] = L[i - 1] + 1;
//     }

//     // R[i] 表示以 b[i] 开头的最长连续递增长度
//     vector<int> R(m, 1);
//     for (int i = m - 2; i >= 0; i--) {
//         if (b[i] == b[i + 1] - 1) R[i] = R[i + 1] + 1;
//     }

//     // 初始答案：任选一段延长 1
//     int max_len = 0;
//     for (int i = 0; i < m; i++) max_len = max(max_len, L[i]);
    
//     int ans = min(n, max_len + 1); // 长度不能超过原数组 n

//     // 尝试桥接两条段
//     for (int i = 0; i < m - 1; i++) {
//         if (b[i + 1] == b[i] + 2) {
//             ans = max(ans, L[i] + 1 + R[i + 1]);
//         }
//     }

//     cout << ans << endl;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--) solve();
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+11;

// int t;
// void solve()
// {
//     int n;cin>>n;
//     int m=n-1;
//     if(n==0){cout<<0<<endl;return;}
//     if(m==0){cout<<1<<endl;return;}
//     vector<int>b(m);
//     for(int i=0;i<m;i++)cin>>b[i];
//     vector<int>L(m,1);//以b[i]为终点最长递增子序列

//     int maxlen=1;
//     for(int i=1;i<m;i++)
//     {
//         if(b[i]==b[i-1]+1)L[i]=L[i-1]+1;
//         maxlen=max(maxlen,L[i]);
//     }

//     vector<int>R(m,1);//以 b[i]为起点的最长递增子序列

//     //注意这个循环的方向
//     for(int i=m-2;i>=0;i--)
//     {
//         if(b[i]==b[i+1]-1)R[i]=R[i+1]+1;
//         maxlen=max(maxlen,R[i]);
//     }

//     int ans=min(n,maxlen+1);//最长不能超过n

//     //嫁接
//     for(int i=0;i<=m-2;i++)
//     {
//         if(b[i]+2==b[i+1])
//         ans=max(ans,L[i]+1+R[i+1]);
//     }
//     cout<<ans<<endl;

// }
// int main()
// {
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int m=n-1;
        vector<int>b(m);
        for(int i=0;i<m;i++)cin>>b[i];
        vector<int>L(m,1);//以 b[i]结尾的最长连续字段
        for(int i=1;i<m;i++)
        {
            if(b[i]==b[i-1]+1)L[i]=L[i-1]+1;
        }

        vector<int>R(m,1);//以b[i]开始的最长连续字段
        for(int i=m-2;i>=0;i--)
        {
            if(b[i]==b[i+1]-1)R[i]=R[i+1]+1;
        }
        int maxlen=1;
        for(int i=0;i<m;i++)
        {
            maxlen=max(maxlen,L[i]);
        }
        
        maxlen++;
        if(maxlen>=n)
        {
            cout<<maxlen<<endl;
            continue;
        }

        //嫁接
        for(int i=0;i<m-1;i++)
        {
            if(b[i]+2==b[i+1])maxlen=max(maxlen,L[i]+1+R[i+1]);
        }
        cout<<maxlen<<endl;
    }
    return 0;
}