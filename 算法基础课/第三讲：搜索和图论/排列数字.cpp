// //全排列
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=20;
// bool st[N];//标记这个数字选了没有
// int n;
// int a[N];
// void dfs(int x)
// {
//     if(x>n)
//     {
//         for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//         cout<<endl;
//         return ;
//     }

//     for(int i=1;i<=n;i++)
//     {
//         if(!st[i])
//         {
//             a[x]=i;
//             st[i]=1;
//             dfs(x+1);
//             st[i]=0;
//         }
//     }
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     dfs(1);
//     return 0;
// }

//方法二
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=20;
int a[N];
int n;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)a[i]=i;
    do
    {
        for(int i=1;i<=n;i++)cout<<a[i]<<" ";
        cout<<endl;
    } while (next_permutation(a+1,a+1+n));
    
    return 0;
}