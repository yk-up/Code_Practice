// #include<bits/stdc++.h>
// using namespace std;
// int n,r;
// const int N=30;
// bool st[N];
// void dfs(int x,int k)
// {
//     if(x>n)
//     {
//         if(k==r)
//         {
//             for(int i=1;i<=n;i++)if(st[i])cout<<setw(3)<<i;
//             cout<<endl;
//         }
//         return ;
//     }
//     st[x]=1;
//     dfs(x+1,k+1);

//     st[x]=0;
//     dfs(x+1,k);
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>r;
//     dfs(1,0);
//     return 0;
// }

// //方法2

// #include<bits/stdc++.h>
// using namespace std;
// int n,r;
// int b[30];
// void dfs(int x,int start)
// {
//     if(x>r)
//     {
//         for(int i=1;i<=r;i++)
//         {
//             cout<<setw(3)<<b[i];
//         }
//         cout<<endl;
//         return;
//     }

//     for(int i=start;i<=n;i++)
//     {
//         b[x]=i;
//         dfs(x+1,i+1);
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>r;
//     dfs(1,1);
//     return 0;
// }
