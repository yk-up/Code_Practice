// //允许c++允许右上角，cph会显示超时
// //590
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// //这个判断的有点蠢
// // bool judge(int x)
// // {
// //     //怎么拆数字
// //     //拆分两个
// //     //直接枚举 一个数字是i另一个是x/i
// //     //在判断是否符合其他的条件

// //     string xx=to_string(x);
// //     map<char,int>mp1;
// //     map<char,int>mp2;
// //     for(int i=0;i<xx.size();i++)mp1[xx[i]]++;
// //     for(int i=1;i<=sqrt(x);i++)
// //     {
// //         mp2.clear();//注意这个
// //         int j=x/i;
// //         if(i*j==x)
// //         {
// //             string min_=to_string(i);
    
// //             string max_=to_string(j);
// //             //map<char,int>mp2;
// //             for(int k=0;k<min_.size();k++)
// //             {
// //                 mp2[min_[k]]++;
// //             }
// //             for(int k=0;k<max_.size();k++)
// //             {
// //                 mp2[max_[k]]++;
// //             }
// //         }
// //         //这样比较可能会漏数字
// //         //  for(int i=0;i<xx.size();i++)
// //         // {
// //         //     if(mp1[xx[i]]!=mp2[xx[i]])continue;
// //         //     return true;
// //         // }
// //         if(mp1==mp2)return true;//只有有一对符合就行了
// //     }
// //     return false;
// // }
// bool judge(int x)
// {
//     string X=to_string(x);
//     sort(X.begin(),X.end());
//     for(int i=1;i<=sqrt(x);i++)
//     {
//         string I=to_string(i);
//         //sort(I.begin(),I.end());    
//         if(x%i==0)
//         {
//             int j=x/i;
//             string J=to_string(j);
//             //sort(J.begin(),J.end());

//             string ans=I+J;
//             sort(ans.begin(),ans.end());//最后排序
//             if(ans==X)
//             {
//                 return true;
//             }

//         }
//     }
//     return false;
// }
// signed main()
// {
//     int cnt=0;
//     for(int i=1;i<=1000000;i++)
//     {
//         if(judge(i))cnt++;
//     }
//     cout<<cnt;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans=0;
bool judge(int x)
{
    string X=to_string(x);
    sort(X.begin(),X.end());
    for(int i=1;i<=x/i;i++)
    {
        if(x%i==0)
        {
            int j=x/i;
            string a=to_string(i);
            string b=to_string(j);
            string aa=a+b;

            sort(aa.begin(),aa.end());
            if(aa==X)
            {
                return true;
            }
        }
    }
    return false;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    for(int i=1;i<=1000000;i++)
    {
        if(judge(i))
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}