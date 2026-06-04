//逻辑对，但是 t 了
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=3e5+11;
// int a[N];
// int L,R;
// int n,m;
// int diff[N];
// struct node
// {
//     // bool s=1;//默认执行
//     int l,r;
// }t[N];

// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
   
//     //不执行某次操作？？
//     for(int i=1;i<=m;i++)
//     {
//         cin>>t[i].l>>t[i].r;
//     }

//     for(int i=1;i<=m;i++)
//     {
//         int ans=0;
//         for(int j=1;j<=n;j++)diff[j]=0,a[j]=0;

//         for(int j=1;j<=m;j++)
//         {
//             if(i==j)
//             {
//                 //不执行
//                 continue;
//             }

//             diff[t[j].l]++;
//             diff[t[j].r+1]--;
//         }
//         for(int j=1;j<=n;j++)
//         {
//             a[j]=a[j-1]+diff[j];
//             if(a[j]==0)ans++;
//         }
//         cout<<ans<<endl;
//     }
//     return 0;
// }


// //好聪明啊
//对于原本是 0 的位置： 它的值为 0，说明没有任何一个操作覆盖过这个位置。既然你要撤销的那个操作也没有覆盖它，那你撤销时根本不会对它做减法。它稳稳地保持是 0。
//对于你要撤销的区间 [l, r]： 既然这个操作真实存在，说明在全部执行完毕的数组中，
//这个区间里的每一个位置至少被加过一次（也就是你现在想要撤销的这一次）。所以，这个区间里的数字在撤销前最少也是 1。1 减去 1 刚好变成 0，绝对减不到 -1。
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 3e5 + 11;
// int diff_arr[N], a[N];
// int pref1[N]; // 用来记录 "恰好为 1" 的前缀和
// int l[N], r[N];

// signed main()
// {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     int n, m;
//     if (!(cin >> n >> m)) return 0;
   
//     // 1. 读入所有操作，并打上差分标记（全部执行）
//     for(int i = 1; i <= m; i++)
//     {
//         cin >> l[i] >> r[i];
//         diff_arr[l[i]]++;
//         diff_arr[r[i] + 1]--;
//     }

//     int base_zeros = 0;//这个好好理解一下！！！
    
//     // 2. 还原整体数组，并统计基础 0 的个数和 1 的前缀和
//     for(int i = 1; i <= n; i++)
//     {
//         a[i] = a[i-1] + diff_arr[i]; // 前缀和还原差分数组
        
//         if(a[i] == 0) {
//             base_zeros++;
//         }
        
//         // 如果这个位置恰好被覆盖 1 次，标记为 1，否则记为 0，然后求前缀和
//         pref1[i] = pref1[i-1] + (a[i] == 1 ? 1 : 0);//这个区间内 1的个数肯定是由于这次操作导致的
//     }

//     // 3. O(1) 快速回答如果撤销第 i 个操作的结果
//     for(int i = 1; i <= m; i++)
//     {
//         // 撤销 [l, r] 会产生的新 0 的个数 = 该区间内原来等于 1 的个数
//         int new_zeros = pref1[r[i]] - pref1[l[i] - 1];
        
//         cout << base_zeros + new_zeros << "\n";
//     }
    
//     return 0;
// }



// //一个很关键的点在于：数组中等于 0 的点没有被任何操作覆盖！！！
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=3e5+11;
// int a[N],prefix[N];
// int diff[N];
// int L[N],R[N];
// int n,m;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=m;i++)
//     {
//         cin>>L[i]>>R[i];
//         diff[L[i]]++;
//         diff[R[i]+1]--;
//     }
//     int base0=0;
//     for(int i=1;i<=n;i++)
//     {
//         a[i]=a[i-1]+diff[i];
//         if(a[i]==0)//说明没有任何操作覆盖这个区间
//         base0++;

//         prefix[i]=prefix[i-1]+(a[i]==1?1:0);

//     }
//     for(int i=1;i<=m;i++)
//     {
//         //撤销这次操作代表原本为1 的会变成 0
//         int new0=prefix[R[i]]-prefix[L[i]-1];
//         cout<<base0+new0<<endl;
//     }

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=3e5+11;
int L[N],R[N];
int a[N];
int diff[N];
int prefix[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>L[i]>>R[i];
        diff[L[i]]++;
        diff[R[i]+1]--;
    }
    int base0=0;
    for(int i=1;i<=n;i++)
    {
        a[i]=a[i-1]+diff[i];
        if(a[i]==0)
        {
            base0++;
        }
        prefix[i]=prefix[i-1]+(a[i]==1?1:0);//这次操作导致的 1 的数量撤销之后不就变 0 了吗
    }

    for(int i=1;i<=m;i++)
    {
        int ans1=prefix[R[i]]-prefix[L[i]-1]+base0;
        cout<<ans1<<endl;
    }

    return 0;
}