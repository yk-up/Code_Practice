// // #include<bits/stdc++.h>
// // using namespace std;
// // const int N=1e5+66;
// // typedef long long ll;
// // const ll p=1e9+7;

// // ll n,ans,maxa,a[N],num[N];//记录长度为i木棒的个数
// // ll C(ll x,ll k)
// // {
// //     //这里只需考虑k=1和k=2的情况
// //     //因此只需写成这两种情况
// //     return (k==1ll?x:x*(x-1ll)/2ll)%p;
// // }
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n;
// //     for(int i=1;i<=n;i++)
// //     {
// //         cin>>a[i];
// //         maxa=max(a[i],maxa);
// //         num[a[i]]++;
// //     }

// //     //三条边 两条边相等(i) 另外一条边是两个木棒的和(j,i-j)
// //     for(int i=2;i<=maxa;i++)//枚举两根相等的边
// //     {
// //         if(num[i]>=2ll)
// //         {
// //             ll times=C(num[i],2ll)%p;//求组合数
// //             //注意这个j的范围j<=i/2
// //             for(int j=1;j<=i/2;j++)
// //             {
// //                 if(j!=i-j&&num[j]>=1&&num[i-j]>=1)
// //                 ans+=times*C(num[j],1)*C(num[i-j],1)%p;
// //                 if(j==i-j&&num[j]>=2)
// //                 ans+=times*C(num[j],2)%p;
// //                 ans%=p;
// //             }
// //         }
// //     }
// //     cout<<ans<<endl;
// //     return 0;
// // }



// // #include<bits/stdc++.h>
// // using namespace std;
// // const int N=1e5+66;
// // typedef long long ll;
// // ll n,ans,nums[N],max_,a[N];
// // const int p=1e9+7;
// // ll C(int n,int x)
// // {
// //     //就两种情况无非x=1和x=2
// //     return (x==1?n:(n-1)*n/2);
// // }
// // int  main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n;
// //     for(int i=1;i<=n;i++)
// //     {
// //         cin>>a[i];
// //         max_=max(max_,a[i]);//找最长的一条木棒
// //         nums[a[i]]++;
// //     }
// //     //正三角形 4根-> 两根一样长 两根较短之和=一根长
// //     for(int i=2;i<=max_;i++)
// //     {
// //         if(nums[i]>=2)
// //         {
// //             ll times=C(nums[i],2);
// //             for(int j=1;j<=i/2;j++)
// //             {
// //                 if(j!=i-j)
// //                 {
// //                     //乘法原理
// //                     if(nums[j]>=1&&nums[i-j]>=1&&i-j>=1)
// //                     {
// //                         ans+=times*(C(nums[j],1)%p*C(nums[i-j],1))%p;
// //                     }
// //                 }
// //                 else 
// //                 {
// //                     if(nums[j]>=2)
// //                     ans+=times*(C(nums[j],2));
// //                 }
// //                 ans%=p;
// //             }
// //         }
// //     }
// //     cout<<ans<<endl;
// //     return 0;
// // }


// //2025/12/17 这道题掌握的不好
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+33;
// #define int long long//要写在最前面否则这段代码中，数组num和a的类型是普通int，不是long long。
// int num[N];
// int a[N];
// int ans;
// int n;
// int maxa;
// const int p=1e9+7;
// int C(int n,int x)
// {
//     return x==1?n:n*(n-1)/2;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         num[a[i]]++;
//         maxa=max(maxa,a[i]);
//     }

//     //枚举最长的变
//     for(int i=2;i<=maxa;i++)
//     {
//         if(num[i]>=2)
//         {
//             int times=C(num[i],2);
//             for(int j=1;j<=i/2;j++)
//             {
//                 if(j!=i-j)
//                 {
//                     if(num[j]>=1&&num[i-j]>=1&&i-j>=1)
//                     {
//                         ans+=times*C(num[j],1)*C(num[i-j],1);
//                     }
//                 }
//                 else
//                 {
//                     if(num[j]>=2)
//                     {
//                         ans+=times*C(num[j],2);
//                     }
//                 }
//                 ans%=p;
//             }
//         }

//     }
//     cout<<ans;

//     return 0;
// }


// //2025/12/18
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n;
// const int p=1e9+7;
// const int N=1e5+11;
// int a[N];
// int nums[N];
// int C(int n,int x)
// {
//     return (x==1?n:n*(n-1)/2);
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     int maxa=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         nums[a[i]]++;
//         maxa=max(a[i],maxa);
//     }
//     int ans=0;

//     //四根两个一样长的，然后其余的两个之和等于这一根
//     for(int i=2;i<=maxa;i++)//枚举长边
//     {
//         if(nums[i]>=2)
//         {
//             int times=C(nums[i],2);
//             for(int j=1;j<=i/2;j++)
//             {
//                 int k=i-j;
//                 if(j!=k)
//                 {
//                     if(nums[j]>=1&&nums[k]>=1)
//                     {
//                         ans+=times*C(nums[j],1)*C(nums[k],1);
//                     }
//                 }
//                 else
//                 {
//                     if(nums[j]>=2)
//                     ans+=times*C(nums[j],2);
//                 }
//             }
//             ans%=p;
//         }
//     }
//     cout<<ans;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int p=1e9+7;
// int n;
// const int N=1e5+11;
// int ans;
// int C(int n,int m)
// {
//     //一个条件都不能拉下
//     if(m>n)return 0;
//     if(m==0||m==n)return 1;
//     if(n-m<m)m=n-m;
//     return C(n-1,m-1)+C(n-1,m);
//     //C(n,m)=C(n,n-m);
//     //return (m==1)?n:(n-1)*n/2;
// }
// int nums[N];//存不同长度的木棍
// signed main()
// {
//     cin>>n;
//     int maxlen=-1;
//     for(int i=1;i<=n;i++)
//     {
//         int x;cin>>x;
//         nums[x]++;
//         maxlen=max(maxlen,x);
//     }
//     // //其中有两个的和等于另外一边的长度(枚举这两个较短的一根)
//     // for(int i=1;i<=maxlen/2;i++)
//     // {
//     //     int l=i;
//     //     if(nums[l]&&num[i-i])
//     //     {
//     //         if()
//     //     }
//     // }
//     //枚举三角形的边长感觉会更好一点

//     for(int l=2;l<=maxlen;l++)
//     {
//         if(nums[l]>=2)
//         {
//             int temp1=C(nums[l],2);
//             for(int i=1;i<=l/2;i++)//两个棍
//             {
//                 int a=i,b=l-i;
//                 if(a!=b)
//                 {
//                     if(nums[a]&&nums[b])
//                     {
//                         ans+=temp1*(C(nums[a],1)*C(nums[b],1))%p;
//                     }
//                 }
//                 else ans+=(temp1*(C(nums[a],2)))%p;
//             }
//             //ans=(ans+temp)%p;//这样写的不对有可能temp就是最上面的C(nums[l],2)即使没找到短的两条边，也会加上
//             ans%=p;
//         }
        
//     }
//     cout<<ans;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
const int p=1e9+7;
int a[N];
int cnt[N];//长度为i的木棍有多少
int n; 
int C(int n,int m)
{
    if(m>n)return 0;
    if(n==m||m==0)return 1;
    if(n-m<m)m=n-m;
    return C(n-1,m-1)+C(n-1,m);
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    int maxlen=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
        maxlen=max(maxlen,a[i]);
    }
    int ans=0;
    //首先选两个长度一样的，其次就是选择两个木棒的和=长的木棍
    for(int i=1;i<=maxlen;i++)
    {
        if(cnt[i]>=2)
        {
            //选择两个短的
            int temp=C(cnt[i],2)%p;
            //不相等的情况
            //for(int k=1;k<i/2;k++)//比如5/2 =2 k<2 会漏掉k=2这种情况
            for(int k=1;2*k<i;k++)
            {
                if(cnt[k]&&cnt[i-k])
                {
                    ans=(ans+(temp)*(C(cnt[k],1)*C(cnt[i-k],1)%p)%p)%p;
                }
            }

            //相等的情况
            if(i%2==0&&cnt[i/2]>=2)
            {
                ans=(ans+temp*C(cnt[i/2],2)%p)%p;
            }
        }
    }
    cout<<ans%p;
    return 0;
}