// // //重点看一下
// // //注意是如何巧妙的计算除 i 之外的其他项的乘积的
// // #include<bits/stdc++.h>
// // using namespace std;
// // const int N=1e5+11;
// // const int p=10007;
// // int a[N];//a[i],第i个对应的里面对应的常数
// // int pre[N];     // 前缀积
// // int suf[N];     // 后缀积
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     string s;cin>>s;
// //     //提取出x 前面的数字 提取出 d
// //     //这道题简单，不用提x 前面的数字都是 1
// //     int num=s.size()/5;//一共有几项
// //     int idx=0;
// //     for(int i=2;i<s.size();)
// //     {
// //         int x=stoi(s.substr(i,2));
// //         a[++idx]=x;
// //         i+=5;
// //     }
    
    
// //     //选num-1项，并计算的乘积 卡到这里了 

// //     //$x^1$的系数 = (所有常数的乘积 / $c_1$) + (所有常数的乘积 / $c_2$) + ... + (所有常数的乘积 / $c_n$)
// //     //但在算法竞赛中，带取模的除法非常麻烦（需要算乘法逆元）
    
// //     //技巧
// //     //除了第 $i$ 个数以外，其他所有数的乘积”，其实就等于：
// // //第 $i$ 个数前面的所有数的乘积) $\times$ (第 $i$ 个数后面的所有数的乘积
// //     //除掉自己 = 自己的前缀积 $\times$ 自己的后缀积
// //     //我靠牛逼啊
    


// //     // 1. 预处理前缀积 (前 0 项乘积视为 1)
// //     pre[0] = 1;
// //     for(int i = 1; i <= num; i++) {
// //         // 注意：计算过程直接取模防溢出
// //         pre[i] = (pre[i - 1] * a[i]) % p;
// //     }
    
// //     // 2. 预处理后缀积 (第 num+1 项往后的乘积视为 1)
// //     suf[num + 1] = 1;
// //     for(int i = num; i >= 1; i--) {
// //         suf[i] = (suf[i + 1] * a[i]) % p;
// //     }
    
// //     // 3. 计算答案：累加 (前 i-1 项的乘积 * 后 i+1 项的乘积)
// //     int ans = 0;
// //     for(int i = 1; i <= num; i++)
// //     {
// //         int term = (pre[i - 1] * suf[i + 1]) % p;
// //         ans = (ans + term) % p;
// //     }
    
// //     // 4. 处理 C++ 中负数取模的终极奥义
// //     ans = (ans % p + p) % p;
    
// //     cout << ans << "\n";
// //     return 0;
// // }

// #include<bits/stdc++.h>
// using namespace std;
// const int p=10007;
// const int N=1e5+11;
// int idx=0;
// int a[N];
// int suf[N],prefix[N];
// int ans;
// int main()
// {
//     string s;cin>>s;
//     for(int i=2;i<s.size();)
//     {
//         a[++idx]=stoi(s.substr(i,2));
//         i+=5;
//     }
//     //对于i 项x的常数项为其他 所有项常数 的乘积 也就是 prefix[i-1]*suf[i+1]//前缀的乘积和后缀的乘积
//     prefix[0]=1;
//     suf[idx+1]=1;

//     //注意里面的取模有可能是负数，所以+p
//     for(int i=1;i<=idx;i++)
//     {
//         prefix[i]=(prefix[i-1]*a[i]+(p))%p;
//     }

//     for(int i=idx;i>=1;i--)
//     {
//         /
//         suf[i]=(suf[i+1]*a[i]+(p))%p;//注意这里是 a[i]
//     }

//     for(int i=1;i<=idx;i++)
//     {
//         ans=(ans+prefix[i-1]*suf[i+1]+(p))%p;
//     }
//     cout<<ans;

//     return 0;
// }

//每一步都不能少，注意取模
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
const int p=10007;
int prefix[N],sub[N];
int idx=0;
int a[N];
int ans;
int main()
{
    string s;cin>>s;
    for(int i=2;i<s.size();)
    {
        if(i>=s.size())break;
        int x=stoi(s.substr(i,2));
        a[++idx]=x;
        i+=5;
    }
    prefix[0]=1,sub[idx+1]=1;
    for(int i=1;i<=idx;i++)
    {
        prefix[i]=prefix[i-1]*a[i]%p;
    }

    for(int i=idx;i>=1;i--)
    {
        sub[i]=sub[i+1]*a[i];
    }
    for(int i=1;i<=idx;i++)
    {
        ans=(ans+prefix[i-1]*sub[i+1]+p)%p;
    }
    cout<<ans;
    return 0;
}