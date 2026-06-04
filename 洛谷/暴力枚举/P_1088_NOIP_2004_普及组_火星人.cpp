// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e4+11;
// int Mar[N];//火星人的初始排列
// int final[N];//最终结果
// int res=0;
// int n,m; 

// bool st[N];
// void dfs(int x)
// {
//     if(x>n)
//     {
//         res++;
//         if(res==m+1)
//         {
//             for(int i=1;i<=n;i++)
//             {
//                 if(i==1)cout<<final[i];
//                 else cout<<" "<<final[i];
//             }
//             cout<<endl;
//             exit(0);
//         }
//         return;
//     }
//     //这个很重要
//     //保证从给定的顺序向后找
//     for(int i=1;i<=n;i++)
//     {
//         if(!res)i=Mar[x];//!!!
//         if(!st[i])
//         {
//             st[i]=1;
//             //final[x]=Mar[i];
//             final[x]=i;
//             dfs(x+1);

//             st[i]=0;
//         }
//     }

// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>Mar[i];
//     dfs(1);
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//     int n, m; cin >> n >> m;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++) cin >> a[i];
//     while (m--) next_permutation(a.begin(), a.end());
//     for (int i = 0; i < n; i++) cout << a[i] << (i == n-1 ? "\n" : " ");
//     return 0;
// }


//2025/12/16 这道题掌握的并不好

//错误的
// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// const int N=10002;
// bool st[N];
// int Mar[N];
// int a[N];
// int res=0;
// void dfs(int x,int start)
// {
//     if(x>n)
//     {
//         res++;
//         if(res==m+1)
//         {
//             for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//             cout<<endl;
//         }
//         return ;
//     }

//     if(res==0)
//     {
//         for(int i=start;i<=n;i++)
//         {
//             i=Mar[x];
//             dfs(x+1,i+1);
//         }
//     }
//     else
//     {
//         for(int i=start;i<=n;i++)
//         {
//             if(!st[i])
//             {
//                 st[i]=1;
//                 a[x]=i;
//                 dfs(x+1,i+1);
                
//                 st[i]=0;
//             }
//         }
//     }

// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>Mar[i];
//     dfs(1,1);
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// bool st[30];
// int a[30];
// int Mar[30];
// int res=0;
// void dfs(int x)
// {
//     if(x>n)
//     {
//         res++;
//         if(res==m+1)
//         {
//             for(int i=1;i<=n;i++)
//             {
//                 if(i==1)cout<<a[i];
//                 else cout<<" "<<a[i];
//             }
//             exit(0);
//         }
    
//         return;
//     }
//     //这里容易写错
//     for(int i=1;i<=n;i++)
//     {
//         if(res==0)i=Mar[x];
//         // else
//         // {
//         //     if(!st[i])
//         //     {
//         //         st[i]=1;
//         //         a[x]=i;
//         //         dfs(x+1);

//         //         st[i]=0;
//         //     }
//         // }

//         if(!st[i])
//         {
//             st[i]=1;
//             a[x]=i;

//             dfs(x+1);
//             st[i]=0;
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>Mar[i];

//     dfs(1);
//     return 0;
// }


// //这个方法吊
// #include<bits/stdc++.h>
// using namespace std;
// const int M=10002;
// int a[M];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,m;cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     while(m--)next_permutation(a+1,a+1+n);
//     for(int i=1;i<=n;i++)
//     {
//         if(i==1)cout<<a[i];
//         else cout<<" "<<a[i];
//     }
//     return 0;
// }


// //全排列，正确的做法是直接从给定的排列作为起点,注意这个是如何通过算法来实现的
// #include<bits/stdc++.h>
// using namespace std;
// const int N=10002;
// bool st[N];
// int a[N];
// int n,m;
// int res=0;
// void dfs(int x)
// {
//     if(x>n)
//     {
//         res++;
//         if(res==m+1)
//         {
//             for(int i=1;i<=n;i++)
//             {
//                 if(i>1)cout<<" ";
//                 cout<<a[i];
//             }
//         }
//         return;
//     }

//     for(int i=1;i<=n;i++)
//     {
//         if(!res)i=a[x];
//         //注意这里千万不能写成 else 否则死循环不会往下递归
//         if(!st[i])
//         {
//             st[i]=1;
//             a[x]=i;
//             dfs(x+1);
//             st[i]=0;
//         }
           
//     }
    
// }
// int main()
// {
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     dfs(1);
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
#define  int long long
int n,m;
const int N=10002;
int Mar[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>Mar[i];
    while(m--)
    {
        next_permutation(Mar+1,Mar+1+n);
    }

    for(int i=1;i<=n;i++)cout<<Mar[i]<<" ";
    return 0;
}