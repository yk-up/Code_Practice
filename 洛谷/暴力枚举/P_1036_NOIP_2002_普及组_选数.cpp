// #include<bits/stdc++.h>
// using namespace std;
// int n,k;
// const int N=100;
// int a[N];
// bool st[N];
// bool is_ok(int x)
// {
//     if(x<=1)return false;
//     for(int i=2;i<=sqrt(x);i++)
//     {
//         if(x%i==0)return false;
//     }
//     return true;
// }
// int res=0;
// void dfs(int x,int m)//m表示已经选了的数量
// {
//     if(x>n)
//     {
//         if(m==k){
//         int sum=0;
//         for(int i=1;i<=n;i++)
//         {
//             if(st[i])
//             {
//                 sum+=a[i];
//             }
//         }
//         if(is_ok(sum))res++;
//       }
//       return;
//     }
//             //x位置上的数选 不选两种情况
//             st[x]=1;
//             dfs(x+1,m+1);

//             st[x]=0;
//             dfs(x+1,m);
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>k;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     dfs(1,0);
//     cout<<res<<endl;
//     return 0;
// }


// //另一种组合型枚举的方法
// #include<bits/stdc++.h>
// using namespace std;
// int n,k;
// const int N=30;
// int a[N];
// int b[N];
// bool st[N];
// int ans=0;
// bool is_prime(int x)
// {
//     if(x<=1)return false;
//     for(int i=2;i<=sqrt(x);i++)
//     {
//         if(x%i==0)return false;
//     }
//     return true;
// }
// void dfs(int x,int start)
// {
//     if(x>k)
//     {
//         int sum=0;
//         for(int i=1;i<=k;i++)sum+=b[i];
//         if(is_prime(sum))ans++;
//         return ;
//     }
//     for(int i=start;i<=n;i++)
//     {
//             b[x]=a[i];
         
//             dfs(x+1,i+1);

         
//             b[x]=0;
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>k;
//     for(int i=1;i<=n;i++)a[i]=i;
//     dfs(1,1);
//     if(!ans)cout<<"No!!!";
//     else cout<<ans<<endl;
//     return 0;
// }


////2025/12/16
// #include<bits/stdc++.h>
// using namespace std;
// int n,k;
// const int N=30;
// int a[N];
// bool st[N];
// int ans=0;
// bool is_prime(int x)
// {
//     if(x<=1)return false;
//     for(int i=2;i*i<=x;i++)
//     {
//         if(x%i==0)return false;
//     }
//     return true;
// }
// void dfs(int x,int m)
// {
//     if(x>n)
//     {
//         if(m==k)
//         {
//             int temp=0;
//             for(int i=1;i<=n;i++)
//             {
//                 if(st[i])temp+=a[i];
//             }
//             if(is_prime(temp))ans++;
//         }
//         return ;
//     }

//     st[x]=1;
//     dfs(x+1,m+1);

//     st[x]=0;
//     dfs(x+1,m);
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>k;
//     for(int i=1;i<=n;i++)cin>>a[i];

//     dfs(1,0);
//     cout<<ans;
//     return 0;
// }

//这个方法还不是很熟练
// #include<bits/stdc++.h>
// using namespace std;
// int n,k;
// const int N=30;
// int a[N];
// int b[N];
// int ans=0;
// bool is_prime(int x)
// {
//     if(x<=1)return false;
//     for(int i=2;i*i<=x;i++)
//     {
//         if(x%i==0)return false;
//     }
//     return true;
// }
// void dfs(int x,int start)
// {
//     if(x>k)
//     {
//         int temp=0;
//         for(int i=1;i<=k;i++)temp+=b[i];
//         if(is_prime(temp))ans++;
//         return;
//     }

//     for(int i=start;i<=n;i++)
//     {
//         //这里容易写错 b[x]=a[i]
//         b[x]=a[i];
//         dfs(x+1,i+1);
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>k;
//     for(int i=1;i<=n;i++)cin>>a[i];

//     dfs(1,1);
    
//     cout<<ans;
//     return 0;
// }

//写define int long long 过不去！！！ 超时正好一个点
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=30;
int a[N];
int n,k;
int b[N];
int ans=0;
//bool st[N];
bool is_prime(int x)
{
    if(x<=1)return false;
    //for(int i=2;i<=x/i;i++)
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)return false;
    }
    return true;
}
// void dfs(int x,int start)
// {
//     if(x>k)
//     {
//         int temp=0;
//         for(int i=1;i<=k;i++)temp+=b[i];
//         if(is_prime(temp))ans++;

//         return;
//     }

//     for(int i=start;i<=n;i++)
//     {
//         // if(st[a[i]]==0)
//         // {
//         //     b[x]=a[i];
//         //     st[a[i]]=1;
//         //     dfs(x+1);

//         //     st[a[i]]=0;
//         // }

//         b[x]=a[i];
//         dfs(x+1,i+1);
//     }
// }

void dfs(int x,int start,int sum)
{
    if(x>k)
    {
        int temp=0;
        //for(int i=1;i<=k;i++)temp+=b[i];

        // if(is_prime(temp))ans++;
        if(is_prime(sum))ans++;

        return;
    }

    for(int i=start;i<=n;i++)
    {
        // if(st[a[i]]==0)
        // {
        //     b[x]=a[i];
        //     st[a[i]]=1;
        //     dfs(x+1);

        //     st[a[i]]=0;
        // }

        b[x]=a[i];
        dfs(x+1,i+1,sum+a[i]);
    }
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1,1,0);
    cout<<ans;
    return 0;
}