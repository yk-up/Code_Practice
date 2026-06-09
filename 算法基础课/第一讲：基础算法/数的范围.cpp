// //二分的下标！！！
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e6+11;
// int a[N];
// int n,q;
// bool check1(int idx,int x)
// {
//     if(a[idx]<x)return true;
//     return false;
// }
// bool check2(int idx,int x)
// {
//     if(a[idx]<=x)return true;
//     return false;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>q;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     while(q--)
//     {
//         int x;cin>>x;

//         //方法一
//         // // 1| 2 2| 3 4
//         // // 1 2 3 4 5
//         // int l=0,r=n+1;
//         // while(l+1!=r)
//         // {
//         //     int mid=(l+r)/2;
//         //     if(check1(mid,x))l=mid;
//         //     else r=mid;
//         // }
//         // int pos1=r;

//         // l=0,r=n+1;
//         // while(l+1!=r)
//         // {
//         //     int mid=(l+r)/2;
//         //     if(check2(mid,x))l=mid;
//         //     else r=mid;
//         // }
//         // int pos2=l;
//         // if(pos2-pos1+1>0)cout<<pos1-1<<" "<<pos2-1<<endl;
//         // else cout<<"-1 -1\n";

//         //方法二
//         // 1. 查找范围是 a+1 到 a+n+1（左闭右开）
//         // 减去 a 得到的是 1-based 数组下标 (1 到 n)
//         int id1 = lower_bound(a + 1, a + 1 + n, x) - a;
//         int id2 = upper_bound(a + 1, a + 1 + n, x) - a;

//         // 2. 检查是否真的找到了元素 x
//         // id1 <= n 防止越界（当查找的数比数组中所有数都大时，id1 会等于 n+1）
//         // a[id1] == x 确保找到了相等的数，而不是仅仅找到了第一个大于 x 的数
//         if (id1 <= n && a[id1] == x) 
//         {
//             // 3. 转换为题目要求的 0-based 索引并输出
//             // 起点：真实下标 id1 减 1
//             // 终点：由于 id2 是第一个 >x 的下标，最后一个 =x 的真实下标是 id2 - 1。转换为 0-based 再减 1，即 id2 - 2
//             cout << (id1 - 1) << " " << (id2 - 2) << "\n";
//         } 
//         else 
//         {
//             cout << "-1 -1\n";
//         }
//     }
    
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+11;
int a[N];
int n,q;
int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    while(q--)
    {
        int x;cin>>x;
        int id1=upper_bound(a+1,a+1+n,x)-a;
        int id2=lower_bound(a+1,a+1+n,x)-a;
        if(a[id1-1]==x&&a[id2]==x)
        {
            cout<<id2-1<<" "<<id1-2<<endl;
        }
        //if(id2<=n&&a[id2]==x)cout<<id2-1<<" "<<id1-2<<endl;
        
        else cout<<"-1 -1\n";
    }
    return 0;
}