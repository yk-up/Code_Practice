// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int get_sum(int h)
// {
//     //三个面每个面其实都是一个等差数列 1 2 3 4 5 
//      //不对！！！金字塔内部还有点
//     int sum1=(h+1)*h/2*3;//三个面

//     //多算了3条边
//     sum1-=h*3;//一条边的弹珠为h
//     return sum1+1;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     for(int h=1;;h++)
//     {
//         if(get_sum(h)<=20230610&&get_sum(h+1)>20230610)
//         {
//             cout<<h;
//             return 0;
//         }
//     }
//     //cout<<get_sum(3);
//     return 0;
// }

// //一行一行的看比一面一面的看更容易理解

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int get_sum(int h)
// {
//     //一层一层的看
//     int ans=0;
//     for(int i=1;i<=h;i++)
//     {
//         //每一层都是一个从1到i到等差数列
//         ans+=(i+1)*i/2;
//     }
//     return ans;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     for(int h=1;;h++)
//     {
//         if(get_sum(h)<=20230610&&get_sum(h+1)>20230610)
//         {
//             cout<<h;
//             return 0;
//         }
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
int h;

int getsum(int h)
{
    int ans=0;
    for(int i=1;i<=h;i++)
    {
        ans+=(1+i)*i/2;
    }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    for(int i=1;;i++)
    {
        if(getsum(i)<=20230610&&getsum(i+1)>20230610)
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}