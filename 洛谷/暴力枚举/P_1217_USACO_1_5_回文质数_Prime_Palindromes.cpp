// //#pragma GCC optimize(2,3,"inline") //洛谷中这行代码不能用
// //最后一个点卡了
// //不能用常规的素数判断
// //也可以在本地提前跑出来，得到结果，写出数组的形式，直接输出
// #include<bits/stdc++.h>
// using namespace std;
// bool is_prime(int x)
// {
//     if(x<=1)return false;
//     for(int i=2;i<=sqrt(x);i++)
//     {
//         if(x%i==0)return false;
//     }
//     return true;
// }
// //好聪明哈哈哈
// bool is_hui(int x)
// {
//     string s1=to_string(x);
//     string s2=s1;
//     reverse(s1.begin(),s1.end());
//     if(s1==s2)return true;
//     else return false;
// }
// const int N=7e7;

// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int a,b;cin>>a>>b;
//     for(int i=a;i<=b;i++)
//     {

//         //注意这个好细节，
//         if(i==9989900) //如果到了这个数，就break 
// 		{
// 			break;
// 		}
//         //偶数一定不是素数
//         if(i%2==0)continue;
//          if(i==1)continue;
//          if(i==2)
//          {
//             cout<<i<<endl;
//             continue;
//          }
//         if(!is_hui(i))continue;
//         if(is_prime(i))
//         {
//             cout<<i<<endl;
//         } 
        
//     }
//     return 0;
// }
       




       
//判断一个数是否是回文，只需要把数字转成字符串对比一下，计算量极小（$O(\log_{10} N)$）。
//判断一个数是否是素数，需要跑一个 $O(\sqrt{N})$ 的循环，计算量大得多。
//所以先判断是否是回文，否则会导致结果错误

#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b;
bool is_prime(int x)
{
    if(x<=1)return false;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)return false;
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>a>>b;
    int ans=0;
    
    for(int i=a;i<=b;i++)
    {

        if(i==9989900)break;
        if(i%2==0)continue;
        if(i==1)continue;
        if(i==2)
        {
            cout<<2<<endl;
            continue;
        }
        
        
        string s=to_string(i);
        string ss=s;
        reverse(ss.begin(),ss.end());
        if(ss!=s)continue;
        // int n=s.size();
        // for(int j=0;j<n/2;j++)
        // {
        //     if(s[j]==s[n-j-1])continue;
        //     flg=0;
        //     break;
        // }
        // if(flg)cout<<s<<endl;

        if(!is_prime(i))continue;

        cout<<i<<endl;
    }
    return 0;
}