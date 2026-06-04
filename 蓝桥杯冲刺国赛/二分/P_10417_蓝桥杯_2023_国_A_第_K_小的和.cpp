// // //总感觉这道题很熟悉，还是不会写
// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // const int N=1e5+11;
// // int n,m,k;
// // int a[N],b[N];
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n>>m>>k;
// //     for(int i=1;i<=n;i++)cin>>a[i];
// //     for(int i=1;i<=m;i++)cin>>b[i];
// //     sort(a+1,a+1+n);
// //     sort(b+1,b+1+m);
    
// //     int i=1,j=1;
// //     priority_queue<int,vector<int>,greater<int>>q;
// //     while(q.size()<k)
// //     {
// //         int x1=a[i]+b[j];
// //         q.push(x1);
// //         cout<<x1<<endl;
        
// //         //下一个数
// //         // 发现问题了吗？你顺着一条路走下去了，却把其他分支给遗忘了！
// //         int next_1=a[i]+b[j+1];
// //         int next_2=a[i+1]+b[j];
// //         if(next_1<=next_2&&j+1<=m)
// //         {
// //             j++;
// //         }
// //         else 
// //         {
// //             i++;
// //         }
// //     }
// //     //cout<<q.top();
// //     return 0;
// // }



//还是 t 了 这个思路也得掌握

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// int n, m, k;
// int a[N], b[N];

// // 自定义一个结构体，用来打包存放：和的值、所在的行i、所在的列j
// struct Node {
//     int sum, i, j;
//     // 重载大于号，让 priority_queue 变成小根堆 (把小的放顶上)
//     bool operator>(const Node& other) const {
//         return sum > other.sum;
//     }
// };

// signed main()
// {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     if(!(cin >> n >> m >> k)) return 0;
    
//     for(int i = 1; i <= n; i++) cin >> a[i];
//     for(int i = 1; i <= m; i++) cin >> b[i];
    
//     // 必须要排序！保证矩阵的每一行从左到右是递增的
//     sort(a + 1, a + 1 + n);
//     sort(b + 1, b + 1 + m);
    
//     priority_queue<Node, vector<Node>, greater<Node>> q;
    
//     // 1. 初始化：把每一行的第一个元素（也就是每一行的最小值）放进堆里
//     // 优化小技巧：前 K 小的数，最多只会牵扯到 a 数组的前 K 个元素，所以只 push min(n, k) 即可
//     for(int i = 1; i <= min(n, k); i++) {
//         q.push({a[i] + b[1], i, 1});
//     }
    
//     //2. 依次弹出 K 个最小值
//     while(k--) {
//         Node curr = q.top();
//         q.pop();
        
//         if(k==1)
//         cout << curr.sum << " ";
        
//         // 3. 把弹出元素所在行的 "下一个元素" 放进堆里打擂台
//         if(curr.j + 1 <= m) {
//             q.push({a[curr.i] + b[curr.j + 1], curr.i, curr.j + 1});
//         }
//     }
    
//     // cout << "\n";
//     return 0;
// }

// 1 2 |3 4 5
// 2 3 |4 4 5

// #include <bits/stdc++.h>
// using namespace std;

// // 数据极大，必须开 long long，否则统计数量和求和时必爆 int
// #define int long long

// const int N = 1e5 + 11;
// int a[N], b[N];
// int n, m, k;
// // 如果我猜第 $K$ 小的数是 $X$，我怎么验证它猜得偏大还是偏小？
// // 我们只需要统计：在所有 $A_i + B_j$ 的组合中，有多少个和是 $\le X$ 的？
// // 如果统计出 $\le X$ 的数量 $\ge K$ 个，说明 $X$ 可能刚好是我们要找的数，但也可能猜大了（比如有很多重复的数），
// // 我们需要记录它，并尝试往小了猜。
// // 如果统计出 $\le X$ 的数量 $< K$ 个，说明 $X$ 绝对猜小了，连前 $K$ 的名额都凑不齐，必须往大了猜。

// // check 函数：统计有多少对 (a[i] + b[j]) <= x
// bool check(int x) {
//     int cnt = 0;
//     for (int i = 1; i <= n; i++) {
//         // 目标是找 b 中有多少个数 <= x - a[i]
//         int target = x - a[i];
        
//         // upper_bound 返回的是第一个 > target 的元素的迭代器
//         // 减去起始地址 (b + 1)，刚好就是 <= target 的元素个数！
//         int count_b = upper_bound(b + 1, b + 1 + m, target) - (b + 1);
//         cnt += count_b;
//     }
    
//     // 如果 <= x 的对数达到了 k 个，说明 x 足够大，返回 true
//     return cnt >= k;
// }

// signed main() {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     if (!(cin >> n >> m >> k)) return 0;
    
//     for (int i = 1; i <= n; i++) cin >> a[i];
//     for (int i = 1; i <= m; i++) cin >> b[i];
    
//     // 必须排序！
//     sort(a + 1, a + 1 + n);
//     sort(b + 1, b + 1 + m);
    
//     // 确定二分的左右边界
//     int l = a[1] + b[1];         // 最小可能的和
//     int r = a[n] + b[m];         // 最大可能的和
//     int ans = r;                 // 记录最终合法答案
    
//     // 经典闭区间二分模板：求满足条件的最小值 (F F F T T T)
//     while (l <= r) {
//         int mid = l + (r - l) / 2;
        
//         if (check(mid)) {
//             ans = mid;           // 达到 K 个了，记下它
//             r = mid - 1;         // 贪心，尝试找更小的和
//         } else {
//             l = mid + 1;         // 不够 K 个，必须找更大的和
//         }
//     }
    
//     cout << ans << "\n";
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,m,k;
// const int N=1e5+11;
// int a[N],b[N];
// bool check(int x)
// {
//     int cnt=0;
//     for(int i=1;i<=n;i++)
//     {
//         //目标是找b中有多少满足 <=x-a[i];
//         int target=x-a[i];
//         int idx=upper_bound(b+1,b+1+m,target)-(b+1);
//         cnt+=idx;
//     }
//     //>=k 是满足的有可能是我们要找的数字 但 <肯定不可能 （好好理解一下）！！！理解为什么<=k 不行（重复数字）
//     if(cnt>=k)//x 可以小一点
//     return true;
//     return false;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>k;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     for(int i=1;i<=m;i++)cin>>b[i];
//     sort(a+1,a+1+n);
//     sort(b+1,b+1+m);

//     //枚举第k 个小的是 x
//     // 1 2 3 4 5 6
//     // 1 2 3 3 4 5    比 x 小的数字
//     int l=0,r=2e18;//r的范围！！！！！ 0x3f3f3f3f 有点小
//     while(l+1!=r)
//     {
//         int mid=(l+r)/2;
//         if(check(mid))r=mid;
//         else l=mid;
//     }
//     cout<<r;
//     return 0;
// }

