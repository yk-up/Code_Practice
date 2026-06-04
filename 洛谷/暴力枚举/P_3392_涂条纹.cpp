// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// const int N=100;
// char g[N][N];

// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)cin>>g[i][j];
//     }
//     int w=0,r=0,b=0;
//     int ans=0;

//     for(int j=1;j<=m;j++)
//     {
//         if(g[1][j]!='w')ans++;
//         g[1][j]='w';//第一行必须是w
//     }
//     for(int j=1;j<=m;j++)
//     {
//         if(g[n][j]!='r')ans++;
//         g[n][j]='r';//最后一行必须是r
//     }
//     bool blue=0;//蓝色必须有一行
//     int Maxb=-1;//记录b一行最多的个数
//     int that_r=0,that_w=0;//这一行的r和w
//     int I=-1;//对应的行
//     for(int i=2;i<=n-1;i++)
//     {
//         char s=g[i-1][1];
//         r=0,w=0,b=0;
//         for(int j=1;j<=m;j++)
//         {
//             if(g[i][j]=='r')r++;
//             else if(g[i][j]=='w')w++;
//             else b++;
//         }
//         if(b>Maxb)
//         {
//             that_w=w;
//             that_r=r;
//             Maxb=b;
//             I=i;   
//         }
//         if(s=='w')
//         {
//             //这一行得是白色
//             if(w>b){
//             ans+=r+b;
//             for(int j=1;j<=m;j++)g[i][j]='w';
//             }
//             else
//             {
//                 ans+=w+r;
//                 for(int j=1;j<=m;j++)g[i][j]='b';
//                 blue=1;
//             }
//         }
//         else if(s=='b')
//         {
//             if(b>r)
//             {
//                 ans+=w+r;
//                 for(int j=1;j<=m;j++)g[i][j]='b';
//                 blue=1;
//             }
//             else 
//             {
//                 ans+=w+b;
//                 for(int j=1;j<=m;j++)g[i][j]='r';
//             }
//         }
//         //如果上一行是红色那么之后的就必须全部是红色
//         else if(s=='r')
//         {
//             for(int j=1;j<=m;j++)
//             {
//                 if(g[i][j]!='r')
//                 {
//                     ans++;
//                     g[i][j]='r';
//                 }
//             }
//         }
//     }
//     if(blue)cout<<ans<<endl;
//     else
//     {
//         for(int j=1;j<=m;j++)
//         {
//             g[I][j]='b';
//         }
//         if(that_r>that_w)
//         {
//             //说明当时变成了r
//             ans-=(m-that_r);
//         }
//         else ans-=(m-that_w);
//         ans+=(m-Maxb);
//         cout<<ans<<endl;
//     }
// }


// #include<bits/stdc++.h>
// using namespace std;
// const int N=100;
// char g[N][N];
// int n,m;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)cin>>g[i][j];
//     }
//     //白与蓝的界限 因为蓝和红至少有一行(白的下限)
//     int ans=0x3f3f3f3f;//最少的
//     for(int i=1;i<=n-2;i++)
//     {
//         //蓝红的界限(蓝的下限)
//         for(int j=i+1;j<=n-1;j++)
//         {
//             int res=0;
//             for(int k=1;k<=i;k++)
//                 for(int v=1;v<=m;v++)if(g[k][v]!='W')res++;
//             for(int k=i+1;k<=j;k++)
//                 for(int v=1;v<=m;v++)if(g[k][v]!='B')res++;
//             for(int k=j+1;k<=n;k++)
//                 for(int v=1;v<=m;v++)if(g[k][v]!='R')res++;
//             ans=min(ans,res);
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }


// //大体思路是对的 但是存在细节问题，比如变量重复j  变量的声明位置
// #include<bits/stdc++.h>
// using namespace std;
// const int N=102;
// char g[N][N];
// int n,m;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)
//         {
//             cin>>g[i][j];
//         }
//     }
//     int ans=0x3f3f3f3f;
//     //枚举白蓝边界  蓝红边界
//     for(int i=1;i<=n-2;i++)
//     {
//         // int temp=0;
//         // for(int k=1;k<=i;k++)
//         // {
//         //     for(int j=1;j<=m;j++)
//         //     {
//         //         if(g[k][j]!='W')temp++;
//         //     }
//         // }
//         for(int j=i+1;j<=n-1;j++)
//         {

//             int temp=0;
//         for(int k=1;k<=i;k++)
//         {
//             for(int v=1;v<=m;v++)
//             {
//                 if(g[k][v]!='W')temp++;
//             }
//         }
//             for(int k=i+1;k<=j;k++)
//             {
//                 for(int v=1;v<=m;v++)
//                 {
//                     if(g[k][v]!='B')temp++;
//                 }
//             }
//             for(int k=j+1;k<=n;k++)
//             {
//                 for(int v=1;v<=m;v++)
//                 {
//                     if(g[k][v]!='R')temp++;
//                 }
//             }
//             ans=min(ans,temp);
//         }
//     }
//     cout<<ans;
//     return 0;
// }




#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100;
char a[N][N];
int n,m;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)cin>>a[i][j];
    }
    int ans=0x3f3f3f3f;
    //枚举白色下界  红下界
    for(int i=1;i<=n-2;i++)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            int temp=0;//注意这个的初始化位置
            //1-i，白色
            for(int k=1;k<=i;k++)
            {
                for(int z=1;z<=m;z++)if(a[k][z]!='W')temp++;
            }
            //i+1,j
            for(int k=i+1;k<=j;k++)
            {
                for(int z=1;z<=m;z++)if(a[k][z]!='B')temp++;
            }

            for(int k=j+1;k<=n;k++)
            {
                for(int z=1;z<=m;z++)if(a[k][z]!='R')temp++;
            }
            ans=min(ans,temp);
        }
    }
    cout<<ans;
    return 0;
}