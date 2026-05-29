// #include<bits/stdc++.h>
// using namespace std;
// #define int long long

// // const int p=20240601000;
// __int128
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     //不对的，题目中没给范围，肯定算不完
//     // for(int i=10120300501;;i++)
//     // {
//     //     if(is_sqrt(n-i)&&is_sqrt(n+i))
//     // }

//     //a=sqrt(n+10120300500),b=sqrt(n-10120300500)
//     //a^2-b^2=2024060100
//     //(a-b)(a+b)=2024060100
//     //x=a-b,y=a+b;枚举两个数使其等与2024060100
//     //在解出a和b，进而等到n

//     int ans=0;
//     //x<=y
//     for(int x=1;x<=sqrt(p);x++)
//     {
//         if(p%x==0)
//         {
//             int y=p/x;
//             if((x+y)%2!=0||(y-x)%2!=0)continue;
//             int a=(x+y)/2;
//             int b=(y-x)/2;
            
//             ans+=a*a-p/2;
//         }
//     }
//     cout<<ans;
//     return 0;
// }


// //面对这种超过 $10^{18}$ 级别的乘法和累加，在 C++ 竞赛中唯一的解法就是借用 128 位整数 __int128。由于 cout 原生不支持输出 128 位数字，我们需要手写一个简单的输出函数。
// #include<bits/stdc++.h>
// using namespace std;

// // 不要在这里 define int long long，会影响 __int128 的使用，我们手动写类型更清晰
// const long long p = 20240601000LL; 

// // 手写输出 __int128 的函数
// void print(__int128 x) {
//     if (x == 0) return;
//     print(x / 10);
//     cout << (char)(x % 10 + '0');
// }

// int main()
// {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

//     // 答案必须用 __int128 来存，否则绝对会溢出
//     __int128 ans = 0;
    
//     for(long long x = 1; x <= sqrt(p); x++)
//     {
//         if(p % x == 0)
//         {
//             long long y = p / x;
            
//             // 修复 1：在计算 a 之前，校验 x 和 y 的奇偶性是否一致
//             if((x % 2) != (y % 2)) continue;//因为 a 是恰好等于(x+y)/2 if(x+y)是奇数，有向下取整导致结果出错
            
//             // 修复 2：把 a 升级为 __int128，保护后面的 a * a 不溢出
//             __int128 a = (x + y) / 2;
            
//             // 计算当前符合条件的 n
//             __int128 c = p / 2;
//             __int128 n = a * a - c;
            
//             ans += n;
//         }
//     }
    
//     // 调用专门的函数输出
//     if (ans == 0) cout << 0;
//     else print(ans);
    
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// long long int p=20240601000;
// void print(__int128 x)
// {
//     if(x==0)return;
//     print(x/10);
//     //先利用 ASCII 码的偏移量（+ '0'），把真实的数值（如 5）变成它对应的 ASCII 编号（53）。
//     //再利用 (char) 告诉 cout 编译器：“不要把这玩意当成 __int128 的数字处理，请把它当成一个普通字符打印在屏幕上！”
//     //简单来说：编译器不认识__int128
//     cout<<(char)(x%10+'0');
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     __int128 ans=0;
//     for(int x=1;x<=p/x;x++)
//     {
//         if(p%x==0)
//         {
//             __int128 y=p/x;
//             //必须是整除的，否则不符合
//             if(x%2!=y%2)continue;

//             __int128 a=(x+y)/2;
//             __int128 n=a*a-p/2;
//             ans+=n;
//         }
//     }
//     print(ans);
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
long long p=20240601000;
void print(__int128 x)
{
    if(x==0)return ;
    print(x/10);
    cout<<(char)(x%10+'0');
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    __int128 ans=0;
    for(int x=1;x<=p/x;x++)
    {
        if(p%x==0)
        {
            __int128 y=p/x;
            if(x%2==y%2)
            {
                __int128 a=(x+y)/2;
                __int128 n=a*a-p/2;

                ans+=n;
            }

        }
    }
    print(ans);
    return 0;
}