// // // //方法也不是是对的 ，就是 mle
// // // //注意不是背包问题，题目中说只能选一种
// // // #include<bits/stdc++.h>
// // // using namespace std;
// // // const int N=1e8+11;
// // // int n;
// // // int a[N],b[N];
// // // int dp[N];
// // // int main()
// // // {
// // //     //背包问题吧
// // //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// // //     cin>>n;
// // //     //for(int i=1;i<=n;i++)cin>>a[i];
// // //     for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
// // //     int q;cin>>q;
// // //     while(q--)
// // //     {
// // //         int x;cin>>x;
// // //         memset(dp,0,sizeof dp);
// // //         for(int i=1;i<=n;i++)
// // //         {
// // //             for(int j=x;j>=a[i];j--)
// // //             dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
// // //         }
// // //         if(dp[n]==0)cout<<-1<<endl;
// // //         else cout<<dp[n]<<endl;
// // //     }
// // //     return 0;
// // // }



// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+11;
// int n;

// struct node
// {
//     int a,b;
//     // 加上 const 是良好习惯，保证在 sort 内部调用时不会报错
//     bool operator<(const node&u) const
//     {
//         if(a!=u.a) return a<u.a;
//         else return b>u.b;
//     }
// } dat[N];

// int max_[N];

// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         cin>>dat[i].a>>dat[i].b;
//     }

//     // 1. 先排序
//     sort(dat+1,dat+1+n);

//     // 2. 排序之后，再计算前缀最大值！
//     max_[0] = 0; // 初始化边界
//     for(int i=1;i<=n;i++){
//         max_[i] = max(max_[i-1], dat[i].b);
//     }

//     int q;
//     cin>>q;
//     while(q--)
//     {
//         int x;
//         cin>>x;
//         int l=0, r=n+1; // l 维护合法边界，r 维护非法边界
        
//         while(l+1 != r)
//         {
//             int mid=(l+r)/2;
//             if(dat[mid].a <= x) l=mid; 
//             else r=mid;
//         }
        
//         // 3. 处理找不到的情况，并记得换行
//         if(l == 0) {
//             cout << -1 << "\n";
//         } else {
//             // 输出前 l 个药品中的最大功效
//             cout << max_[l] << "\n"; 
//         }
//     }

//     return 0;
// }



// // #include<bits/stdc++.h>
// // using namespace std;

// // // 定义一个结构体存药品
// // struct Med {
// //     int a; // 疼痛程度
// //     int b; // 功效值
    
// //     // 排序规则：优先按疼痛程度从小到大排。
// //     // 如果疼痛程度一样，就把功效大的排前面。
// //     bool operator<(const Med& other) const {
// //         if(a != other.a) return a < other.a;
// //         return b > other.b;
// //     }
// // };

// // int main() {
// //     // 快读优化
// //     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
// //     int n;
// //     if (!(cin >> n)) return 0;
    
// //     vector<Med> meds(n);
// //     for(int i = 0; i < n; i++) {
// //         cin >> meds[i].a >> meds[i].b;
// //     }
    
// //     // 1. 按疼痛值排序
// //     sort(meds.begin(), meds.end());
    
// //     // 2. 预处理：分离出单独的疼痛值数组 (方便二分)，并计算前缀最大功效
// //     vector<int> pain(n);      // 只存疼痛值
// //     vector<int> max_b(n);     // max_b[i] 表示前 i 个药里最大的功效
    
// //     pain[0] = meds[0].a;
// //     max_b[0] = meds[0].b;
    
// //     for(int i = 1; i < n; i++) {
// //         pain[i] = meds[i].a;
// //         // 当前位置的最大功效 = max(前面的最大功效, 当前药的功效)
// //         max_b[i] = max(max_b[i-1], meds[i].b); 
// //     }
    
// //     // 3. 处理询问
// //     int q;
// //     cin >> q;
// //     while(q--) {
// //         int x;
// //         cin >> x;
        
// //         // upper_bound 找第一个 > x 的位置
// //         auto it = upper_bound(pain.begin(), pain.end(), x);
        
// //         // 如果迭代器还在开头，说明连最轻微的痛都忍不了 (所有药的疼痛值都 > x)
// //         if(it == pain.begin()) {
// //             cout << -1 << "\n"; // 注意：大量输出时使用 \n 代替 endl 防止超时
// //         } else {
// //             // 退后一步，就是最后一个 <= x 的药品位置
// //             int idx = distance(pain.begin(), it) - 1;
// //             cout << max_b[idx] << "\n";
// //         }
// //     }
    
// //     return 0;
// // }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
int n;
struct node
{
    int a,b;
    bool operator<(const node&u)
    {
        if(a!=u.a)return a<u.a;
        return b>u.b;
    }
}dat[N];
int max_[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>dat[i].a>>dat[i].b;

    sort(dat+1,dat+1+n);
    //因为不是单调的，功效并不会随着药品的疼痛值增大，因此用一个数组记录前i 中功效的最大值
   for(int i=1;i<=n;i++)
   {
        max_[i]=max(max_[i-1],dat[i].b);
   }
   
    int q;cin>>q;
    while(q--)
    {
        int x;cin>>x;
        //枚举下标，找第一个大于
        //1 2 ｜3 4
        int l=0,r=n+1;
        while(l+1!=r)
        {
            int mid=(l+r)/2;
            if(dat[mid].a<=x)l=mid;
            else r=mid;
        }
        if(l==0)cout<<-1<<endl;
        else cout<<max_[l]<<endl;
    }
    return 0;
}