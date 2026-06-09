//这个还不熟
// //这个模板考虑的是一个大整数和一个正常的整数相乘
// #include<bits/stdc++.h>
// using namespace std;
// vector<int>mul(vector<int>&A,int b)
// {

//     //如果 A 的每一位都乘完了，但进位 t 还不是 0（
//     //比如最高位乘完后进位了 15），循环就不会停。它会继续把 15 拆开，当前位留下 5，再进位 1，直到 t 被彻底榨干变成 0 为止。这就免去了在循环外面再写一个 while(t) 来处理剩余进位的麻烦。
//     int t=0;
//     vector<int>C;
//     for(int i=0;i<A.size()||t;i++)
//     {
//         if(i<A.size())t+=A[i]*b;
//         C.push_back(t%10);
//         t/=10;
//     }
//     while(C.size()>1&&C.back()==0)C.pop_back();
//     return C;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     string a;int b;cin>>a>>b;
//     vector<int>A;
//     for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
//     vector<int>C=mul(A,b);
//     for(int i=C.size()-1;i>=0;i--)cout<<C[i];
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
string a;int b;
vector<int>A;
vector<int>mul(vector<int>&A,int b)
{
    int t=0;
    vector<int>C;

    for(int i=0;i<A.size()||t;i++)
    {
        if(i<A.size())t=A[i]*b+t;
        C.push_back(t%10);
        t/=10;
    }
    while(C.size()>1&&C.back()==0)C.pop_back();
    return C;
    
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>a>>b;
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    //for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]);
    vector<int>C=mul(A,b);

    for(int i=C.size()-1;i>=0;i--)cout<<C[i];
    return 0;
}