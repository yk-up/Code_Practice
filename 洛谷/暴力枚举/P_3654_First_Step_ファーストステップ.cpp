// #include<bits/stdc++.h>
// using namespace std;
// const int N=105;
// char a[N][N];
// int r,c,k;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>r>>c>>k;
//     for(int i=1;i<=r;i++)
//     {
//         for(int j=1;j<=c;j++)cin>>a[i][j];
//     }
//     bool f=1;
//     int ans=0;
//     for(int i=1;i<=r;i++)//横向搜索
//     {
//         for(int j=1;j<=c;j++)
//         {
//             f=1;
//             for(int s=0;s<k;s++)
//             {
//                 if(a[i+s][j]!='.')
//                 {
//                     f=0;
//                     break;
//                 }
//             }
//             if(f)ans++;
//         }
//     }
//     for(int i=1;i<=r;i++)
//     {
//         for(int j=1;j<=c;j++)
//         {
//             f=1;
//             for(int s=0;s<k;s++)
//             {
//                 if(a[i][j+s]!='.')
//                 {
//                     f=0;
//                     break;
//                 }
//             }
//             if(f)ans++;
//         }
//     }
//     //!!! 因为k==1的时候横向和纵向一样 算了两次 因此需要减一次
//     if(k==1)
//     cout<<ans/2;
//     else cout<<ans;
//     return 0;
// }


// ////2025/12/16
// #include<bits/stdc++.h>
// using namespace std;
// int r,c,k;
// const int N=205;
// char g[N][N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>r>>c>>k;
//     for(int i=1;i<=r;i++)
//     {
//         for(int j=1;j<=c;j++)cin>>g[i][j];
//     }
//     int ans=0;

//     for(int i=1;i<=r;i++)//shu着搜索
//     {
//         for(int j=1;j<=c;j++)
//         {
//             bool f=1;
//             for(int s=0;s<k;s++)
//             {
//                 if(g[i+s][j]!='.')f=0;
//             }
//             if(f)ans++;
//         }
//     }
//     for(int i=1;i<=r;i++)
//     {
//         for(int j=1;j<=c;j++)
//         {
//             bool f=1;
//             for(int s=0;s<k;s++)
//             {
//                 if(g[i][j+s]!='.')f=0;
//             }
//             if(f)ans++;
//         }
//     }
//     //这个很容易错！
//     if(k==1)cout<<ans/2;
//     else cout<<ans;
//     return 0;
// }


// //思路横着搜索，竖着搜索
// #include<bits/stdc++.h>
// using namespace std;
// int r,c,k;
// const int N=102;
// char g[N][N];
// int main()
// {
//     cin>>r>>c>>k;
//     for(int i=1;i<=r;i++)
//     {
//         for(int j=1;j<=c;j++)cin>>g[i][j];
//     }

//     int ans=0;
//     //横着搜索
//     for(int i=1;i<=r;i++)
//     {
//         for(int j=1;j<=c;j++)
//         {
//             //这种写太复杂了，上面的写的简单，没有判断越界
//             if(j>c-k+1)break;
//             bool f=1;
//              for(int l=j;l<=j+k-1;l++)
//              {
//                 if(g[i][l]=='.')continue;
//                 f=0;
//                 break;
//              }
//              if(f)ans++;
//         }
//     }

//     for(int j=1;j<=c;j++)
//     {
//         for(int i=1;i<=r;i++)
//         {
//             if(i>r-k+1)break;
//             bool f=1;
//             for(int l=i;l<=i+k-1;l++)
//             {
//                 if(g[l][j]=='.')continue;
//                 f=0;
//                 break;
//             }
//             if(f)ans++;
//         }
//     }
//     if(k==1)ans/=2;//这个极易出错
//     cout<<ans;
//     return 0;
// }

