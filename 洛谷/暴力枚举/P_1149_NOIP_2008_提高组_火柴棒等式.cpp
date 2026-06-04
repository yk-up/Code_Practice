// //到达是哪里有问题啊
// #include<bits/stdc++.h>
// using namespace std;

// int ans=0;
// int sum=0;//需要的全部火柴数
// int n;
// const int N=1e4+33;
// int huo[N]={6,2,5,5,4,5,6,3,7,6};
// int a[4];
// int getneed(int x)
// {
//     int need=0;
//     if(x==0)return huo[0];
//     while(x)
//     {
//         need+=huo[x%10];
//         x/=10;
//     }
//     return need;
// }
// void dfs(int x)
// {
//     if(sum>n)return;
//     if(x>3)
//     {
//         if(sum==n)
//         {
//             if(a[1]+a[2]==a[3])ans++;
//         }
//         return;
//     }
//     //指数枚举型
//     for(int i=0;i<=1000;i++)
//     {
//         a[x]=i;
//         sum+=getneed(a[x]);
//         dfs(x+1);
//         sum-=getneed(a[x]);
//     }
//     return;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     n-=4;
//     dfs(1);
//     cout<<ans;
//     return 0;
// }




//这个是正确的
// #include<bits/stdc++.h>
// using namespace std;

// int n;
// int ans=0;
// int need[10]={6,2,5,5,4,5,6,3,7,6};
// int a[4];
// int getneed(int x)
// {
//     int need_=0;
//     if(x==0)return need[0];
//     while(x)
//     {
//         need_+=need[(x%10)];
//         x/=10;
//     }
//     return need_;
// }
// int sum=0;
// void dfs(int x)
// {
//     //指数型枚举
//     if(sum>n)return;
//     if(x>3)
//     {
//         if(sum==n&&a[1]+a[2]==a[3])ans++;
//         return;
//     }

//     for(int i=0;i<=1000;i++)
//     {
//         a[x]=i;
//         sum+=getneed(a[x]);
//         dfs(x+1);

//         sum-=getneed(a[x]);
//         a[x]=-1;
//     }

// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     n-=4;
//     dfs(1);
//     cout<<ans;
//     return 0;
// }


// //2025/12/16 这道题也掌握的不是很好
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// int nums[10]={6,2,5,5,4,5,6,3,7,6};
// int a[4];
// int ans=0;
// int getmany(int x)
// {
//     //这行代码很细节
//     if(x==0)return nums[0];
//     int need=0;
//     while(x)
//     {
//         need+=nums[x%10];
//         x/=10;
//     }
//     return need;
// }
// void dfs(int x,int sum)
// {
//     if(sum>n)return;//这个剪枝很细节也很关键
//     if(x>3)
//     {
//         if(sum==n)
//         {
//             if(a[1]+a[2]==a[3])ans++;
//         }
//         return;
//     }

//     //这里有从0开始
//     for(int i=0;i<1000;i++)
//     {
//         a[x]=i;
//         int need=getmany(a[x]);
//         dfs(x+1,sum+need);
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     n-=4;
//     //指数型枚举
//     dfs(1,0);
//     cout<<ans;
//     return 0;
// }

// //指数型枚举
// #include<bits/stdc++.h>
// using namespace std;
// int b[4];
// int num[]={6,2,5,5,4,5,6,3,7,6};
// int n;
// int ans;
// int getneed(int x)
// {
//     if(x==0)return num[0];
//     int temp=0;
//     while(x)
//     {
//         temp+=num[x%10];
//         x/=10;
//     }
//     return temp;
// }
// void dfs(int x,int cnt)
// {
//     if(cnt>n)return;//这个剪纸是必须的
//     if(x>3)
//     {
//         if(b[1]+b[2]==b[3]&&cnt==n)
//         {
//             ans++;
//         }
//         return;
//     }

//     // for(int i=0;i<=9;i++)
//     // {
//     //     b[x]=i;
//     //     dfs(x+1);
//     // }
//     for(int i=0;i<=1000;i++)
//     {
//         b[x]=i;
//         int need_=getneed(i);
//         dfs(x+1,cnt+need_);
//     }
// }
// int main()
// {
//     cin>>n;
//     n-=4;
//     dfs(1,0);
//     cout<<ans;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[]={6,2,5,5,4,5,6,3,7,6};
int b[4];
bool st[10002];//标记哪个数字是是否被选择了
int ans=0;
//选3个数字呗
int getsum(int x)
{
    if(x==0)return 6;
    int temp=0;
    while(x)
    {
        temp+=a[x%10];
        x/=10;
    }
    return temp;
}
void dfs(int x,int cnt)
{
    if(cnt>n)return;
    if(x>3)//我靠这里写的是3不是n啊
    {
        if(cnt==n)
        {
            if(b[1]+b[2]==b[3])
            ans++;
        }
        return ;
    }
    for(int i=0;i<=1000;i++)
    {
        // if(!st[i])
        // {
        //     st[i]=1;
        //     b[x]=i;
        //     dfs(x+1,cnt+getsum(i));
        //     st[i]=0;
        // }

        st[i]=1;
        b[x]=i;
        dfs(x+1,cnt+getsum(i));
        st[i]=0;
    }

}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    n-=4;
    dfs(1,0);
    cout<<ans;
    return 0;
}