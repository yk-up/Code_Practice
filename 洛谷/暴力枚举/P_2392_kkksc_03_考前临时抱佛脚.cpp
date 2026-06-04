// //读完这道题 脑子里就想到优先队列
// //想到之前写过的合并果子
//不对！！！ 思路不对 应该是分成两拨是两拨的差距最小
// #include<bits/stdc++.h>
// using namespace std;
// int a[30];
// int ans=0;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     for(int i=1;i<=4;i++)cin>>a[i];
//     for(int i=1;i<=4;i++)
//     {
//         priority_queue<int>q;
//         for(int j=1;j<=a[i];j++)
//         {
//             int x;cin>>x;
//             q.push(x);
//         }
//         while(q.size()>=2)
//         {
//             int x=q.top();q.pop();
//             int y=q.top();q.pop();
//             ans+=max(x,y);
            
//         }
//         //if(q.size()==1)ans+=q.top();
//         if(!q.empty())
//             ans += q.top();
//     }
//     cout<<ans<<endl;
//     return 0;
// }

// //贪心
// #include<bits/stdc++.h>
// using namespace std;
// int a[5],i,j,sum1,sum2,t,homework;
// int main(){
//     for(i=1;i<=4;i++)
//         cin>>a[i];//输入
//     for(i=1;i<=4;i++){
//     sum1=sum2=0;//两边脑子时间清零
//     for(j=1;j<=a[i];j++)
//         {cin>>homework;
//         if(sum1<=sum2) sum1+=homework;
//         else sum2+=homework;}//哪边时间短就加在哪边
//         t+=max(sum1,sum2);//取较长时间累加
//     }cout<<t;//输出
//     return 0;
// }

// //贪心也不对 是动态规划
// //对于每科，我们需要将题目分成两组，分别交给左右脑，使得两组的总耗时尽可能接近。
// //这样并行处理时，总时间由耗时较长的一组决定，从而最小化单科总时间。
// #include<bits/stdc++.h>
// using namespace std;
// int a[5],i,j,k,sum,t;
// int homework[30],dp[3000];
// int main()
// {
//     for( i=1;i<=4;i++)cin>>a[i];
//     for( i=1;i<=4;i++)
//     {
//         sum=0;
//         for(j=1;j<=a[i];j++)
//         {
//             cin>>homework[j];
//             sum+=homework[j];
//         }
//         for(int j=1;j<=a[i];j++)
//         {
//             for(k=sum/2;k>=homework[j];k--)
//             dp[k]=max(dp[k],dp[k-homework[j]]+homework[j]);
//         }

//         // 当前科目的最短时间 = 总时间 - 最接近sum/2的子集和
//         t+=sum-dp[sum/2];
//         for(int j=1;j<=sum/2;j++)dp[j]=0;
//     }
//     cout<<t;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// const int N=50;
// int a[5][N];//科目 习题数量
// int ans=0;
// int Left,Right;
// int s[N];
// int ans1=0x3f3f3f3f;
// void dfs(int x,int k)
// {
//     if (max(Left, Right) >= ans1) return;

//     if(k>s[x])
//     {
//         ans1=min(ans1,max(Left,Right));
//         return;
//     }

//     Left+=a[x][k];
//     dfs(x,k+1);
//     Left-=a[x][k];

//     Right+=a[x][k];
//     dfs(x,k+1);
//     Right-=a[x][k];

// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    

//     //注意这里的输入还是很绕的！！！
//     // for(int i=1;i<=4;i++)
//     // {
//     //     cin>>s[i];
//     //     for(int j=1;j<=s[i];j++)
//     //     {
//     //         int x;cin>>x;
//     //         a[i][j]=x;
//     //     }
//     // }
//     cin>>s[1]>>s[2]>>s[3]>>s[4];
//     for(int i=1;i<=4;i++)
//     {
//         for(int j=1;j<=s[i];j++)cin>>a[i][j];
//     }
//     for(int i=1;i<=4;i++)
//     {
//         ans1=0x3f3f3f3f;
//         Left=0,Right=0;
//         dfs(i,1);
//         ans+=ans1;
//     }
//     cout<<ans;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
int s[5];
int a[5][100];
int dp[1202];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>s[1]>>s[2]>>s[3]>>s[4];
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=s[i];j++)
        {
            cin>>a[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=4;i++)
    {
        memset(dp,0,sizeof dp);
        int sum=0;//找最接近sum/2的数字
        for(int j=1;j<=s[i];j++)
        {
            sum+=a[i][j];
        }
        for(int j=1;j<=s[i];j++)
        {
            for(int k=sum/2;k>=0;k--)
            {
                if(k>=a[i][j])
                {
                    dp[k]=max(dp[k],dp[k-a[i][j]]+a[i][j]);
                }
            }
        }
        ans+=(sum-dp[sum/2]);
    }
    cout<<ans;
    return 0;
}