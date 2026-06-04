// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// int l[N],r[N];
// int L[N],R[N];
// int n,m;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>l[i]>>r[i];
//     for(int i=1;i<=m;i++)cin>>L[i]>>R[i];

  
//     for(int i=1;i<=m;i++)
//     {
//         int cnt=0;
//         for(int j=1;j<=n;j++)
//         {
//             //区间有交点
//             int LL=max(L[i],l[j]);
//             int RR=min(R[i],r[j]);

//             if(LL<=RR)
//             {
//                 // int len=RR-LL+1;//线段在区间内的长度
//                 // int all_len=r[j]-l[j]+1;
//                 // //if(1.0*len>=1.0*all_len/2)cnt++;
//                 // //if(len>all_len/2)cnt++;//为什么是这个
//                 // if(len*2>all_len)cnt++;
                

//                 //注意点数和线段常数
//                 int len=RR-LL;
//                 int all_len=r[j]-l[j];
//                 if(len*2>=all_len)cnt++;//这个好聪明的技巧，两边同时✖️2 避免浮点数
//             }
//         }
//         cout<<cnt<<endl;
//     }
    
//     return 0;
// }



// //max(ri-li)<=min(ri-li)
// // 这句话翻译成人话就是：所有的“框”（查询区间），都比所有的“娃娃”（线段）要长。

// // 既然“框”比“娃娃”长，那么用框去套娃娃时，绝对不可能出现“娃娃两头都露在框外面”的情况。
// // 它只能是下面三种情况之一：

// // 娃娃完全在框里。

// // 娃娃左边露出去一点，右边被框住。

// // 娃娃右边露出去一点，左边被框住。

// // 在数学上，既然框足够长，那么“娃娃至少有一半被框住”的充要条件，其实就是：“娃娃的中点，必须落在框里面”！


// //对于每一条线段，我们只需要算出它的特征值 $P = l+r$。对于每一个框 $[L, R]$，我们只需要看有多少个特征值 $P$ 落在 $[2L, 2R]$ 这个范围内！

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N = 1e5 + 11;

// int mid_pts[N]; // 存放每条线段两端点之和 (相当于两倍的中点)

// signed main()
// {
//     // 必须加的 I/O 优化，防止数据量大时 cin/cout 超时
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
//     int n, m;
//     if (!(cin >> n >> m)) return 0;
    
//     // 1. 读入线段，只存它们的 "两端点之和"
//     for(int i = 1; i <= n; i++)
//     {
//         int l, r;
//         cin >> l >> r;
//         mid_pts[i] = l + r; 
//     }
    
//     // 2. 将所有的中点值排序，为二分查找做准备 (时间复杂度 O(N log N))
//     sort(mid_pts + 1, mid_pts + n + 1);
    
//     // 3. 处理每个查询
//     for(int i = 1; i <= m; i++)
//     {
//         int L, R;
//         cin >> L >> R;
        
//         // 我们要找的值的有效范围是 [2*L, 2*R]
//         int target_min = 2 * L;
//         int target_max = 2 * R;
        
//         // upper_bound 找到第一个 严格大于 target_max 的迭代器位置
//         // lower_bound 找到第一个 大于等于 target_min 的迭代器位置
//         int right_idx = upper_bound(mid_pts + 1, mid_pts + n + 1, target_max) - mid_pts;
//         int left_idx = lower_bound(mid_pts + 1, mid_pts + n + 1, target_min) - mid_pts;
        
//         // 两个下标相减，刚好就是落在该范围内的元素个数！ (时间复杂度 O(log N))
//         cout << right_idx - left_idx << "\n";
//     }
    
//     return 0;
// }



//理解的还不是非常透彻
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
int n,m;
int mid[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //只要保证中点在区间内，就代表至少一半的长度被包含在某个区间
    cin>>n>>m;
    //(l+r)/2 在 [L,R]等价于(l+r)在[2L,2R]内
    for(int i=1;i<=n;i++)
    {
        int l,r;cin>>l>>r;
        mid[i]=(l+r);
    }

    sort(mid+1,mid+1+n);
    for(int i=1;i<=m;i++)
    {
        int L,R;cin>>L>>R;
        //在 判断落入 2L，2R 个个数有多少个
        int target_min=2*L;
        int target_max=2*R;
        int left_=lower_bound(mid+1,mid+1+n,target_min)-mid;
        int right_=upper_bound(mid+1,mid+1+n,target_max)-mid;//注意这里是减 mid，（-(mid+1)+1）化简后
        cout<<right_-left_<<endl;
    }
    return 0;
}