// #include<bits/stdc++.h>
// using namespace std;
// int n;
// int res=0;//方案数
// const int N=1e5+44;
// int a[N][12];//前面是对应的方案数 后一维度对应的是可能的情况
// int b[12];
// void dfs(int x,int ans)//美味程度
// {
//     if(x>10)
//     {
//         if(ans==n){
//         res++;
//         //需要先将结果存起来 才能满足题目要求的输出顺序
//         for(int i=1;i<=10;i++)
//         a[res][i]=b[i];
//         }
//         return ;
//     }
//     for(int i=1;i<=3;i++)
//     {   
//         b[x]=i;
//         dfs(x+1,ans+i);
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     dfs(1,0);
//     cout<<res<<endl;
//     for(int i=1;i<=res;i++)
//     {
//         for(int j=1;j<=10;j++)
//         {
//             if(j==1)
//             cout<<a[i][j];
//             else cout<<" "<<a[i][j];
//         }
//         cout<<endl;
//     }
//     return 0;
// }


// //2025/12/16 问题不大 但还有一些细节问题
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// int ans=0;
// const int N=1e5+11;
// int a[N][11];
// int b[11];

// void dfs(int x,int sum)
// {
//     //这种写法是错误的 和下面的对比一下 有什么区别
//     // if(x>10&&sum==n)
//     // {
//     //     ans++;
//     //     for(int i=1;i<=n;i++)a[ans][i]=b[i];
//     //     return;
//     // }

//     if(x>10)
//     {
//         if(sum==n)
//         {
//             ans++;
//             //这里容易写错成 for(int i=1;i<=n;i++)
//             for(int i=1;i<=10;i++)a[ans][i]=b[i];
//         }
//         return;
//     }
//     for(int i=1;i<=3;i++)
//     {
//         b[x]=i;
//         dfs(x+1,sum+i);
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     dfs(1,0);
//     cout<<ans<<endl;
//     for(int i=1;i<=ans;i++)
//     {
//         for(int j=1;j<=10;j++)cout<<a[i][j]<<" ";
//         cout<<endl;
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+11;
int a[12];
vector<int>ans[N];
int res=0;
int n;
void dfs(int x,int sum)
{
    if(sum>n)return;
    if(x>10)
    {
        if(sum==n)
        {
            res++;
            for(int i=1;i<=10;i++)
            {
                ans[res].push_back(a[i]);
            }
        }
        return;//!!!别忘记
    }

    for(int i=1;i<=3;i++)
    {
        a[x]=i;
        //dfs(x+1,sum+=i);///!!!!我靠 这个会影响sum的值
        //sum-=i;//需配合这个使用
        
        dfs(x+1,sum+i);//!!!
    }
    return;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    dfs(1,0);
    cout<<res<<endl;
    for(int i=1;i<=res;i++)
    {
        for(int x:ans[i])cout<<x<<" ";
        cout<<endl;
    }
    cout<<endl;
    return 0;
}