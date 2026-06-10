// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// // int a[N];
// int n,m;
// vector<int>a;
// int discretize(int x)
// {
//     return lower_bound(a+1,a+1+n,x)-a;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=0;i<n;i++)
//     {
//         int x;cin>>x;
//         a.push_back(x);
//     }
//     sort(a.begin(),a.end());
//     a.erase(unique(a.begin(),a.end()),a.end());

//     return 0;
// }


// //不太理解

// #include <bits/stdc++.h>
// using namespace std;

// // 空间大小计算：n次添加操作有10^5个坐标，m次查询有2*10^5个坐标
// // 最多有 3*10^5 个不同坐标，所以数组开到 300010
// const int N = 300010;

// int a[N]; // 离散化后，存储每个坐标上加的值
// int s[N]; // a数组的前缀和

// vector<int> alls; // 存储所有待离散化的坐标
// vector<pair<int, int>> add, query;

// // 二分查找求离散化后的新坐标（返回 1-based 索引，方便求前缀和）
// // int find(int x) {
// //     int l = 0, r = alls.size() - 1;
// //     while (l < r) {
// //         int mid = (l + r) / 2;
// //         if (alls[mid] >= x) r = mid;
// //         else l = mid + 1;
// //     }
// //     return r + 1; // 返回 1 到 alls.size() 的下标
// // }

// int find(int x) {
//     // 找到第一个 >= x 的迭代器，减去起点迭代器得到 0-based 索引，再 +1 变成 1-based 索引
//     return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
// }

// int main() {
//     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
//     int n, m;
//     cin >> n >> m;
    
//     // 1. 读取所有加法操作
//     for (int i = 0; i < n; i++) {
//         int x, c;
//         cin >> x >> c;
//         add.push_back({x, c});
//         alls.push_back(x); // 把坐标 x 收集起来
//     }
    
//     // 2. 读取所有查询操作
//     for (int i = 0; i < m; i++) {
//         int l, r;
//         cin >> l >> r;
//         query.push_back({l, r});
//         alls.push_back(l); // 收集查询区间的左右端点
//         alls.push_back(r); 
//     }
    
//     // 3. 对坐标进行排序和去重（离散化的核心）
//     sort(alls.begin(), alls.end());
//     alls.erase(unique(alls.begin(), alls.end()), alls.end());
    
//     // 4. 执行加法操作
//     for (auto item : add) {
//         int x = find(item.first); // 找到原来的 x 映射后的新下标
//         a[x] += item.second;
//     }
    
//     // 5. 预处理前缀和
//     for (int i = 1; i <= alls.size(); i++) {
//         s[i] = s[i - 1] + a[i];
//     }
    
//     // 6. 处理查询
//     for (auto item : query) {
//         int l = find(item.first);  // 离散化后的左端点
//         int r = find(item.second); // 离散化后的右端点
//         cout << s[r] - s[l - 1] << "\n";
//     }
    
//     return 0;
// }



//本质上就是把所有和坐标相关的都放到一个数组做映射
//离散化+前缀和
#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> PII;
int n,m;
vector<int>all;
vector<PII>query;
vector<PII>add;
const int N=3e5+11;//注意这里的数组大小
int a[N];//映射后的新坐标
int prefix[N];
int find(int x)
{
    return lower_bound(all.begin(),all.end(),x)-all.begin()+1;//1-based
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x,c;cin>>x>>c;
        all.push_back(x);
        add.push_back({x,c});
    }
    for(int i=1;i<=m;i++)
    {
        int l,r;cin>>l>>r;
        all.push_back(l);
        all.push_back(r);
        query.push_back({l,r});
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());

    for(auto item:add)
    {
        int x=find(item.first);
        a[x]+=item.second;
    }
    for(int i=1;i<=all.size();i++)
    {
        prefix[i]=prefix[i-1]+a[i];
    }

    for(auto item:query)
    {
        int x=find(item.first),y=find(item.second);//离散后的坐标
        cout<<prefix[y]-prefix[x-1]<<endl;
    }
    return 0;
}