// //这个只考虑两个非负整数相减，其他的情况可以在这个基础上改
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// bool cmp(vector<int>A,vector<int>B)
// {
//     if(A.size()!=B.size())return A.size()>B.size();
//     else
//     {
//         //位数一样，从高位判断
//         for(int i=A.size()-1;i>=0;i--)
//         {
//             if(A[i]!=B[i])
//             return A[i]>B[i];
//         }
//     }
//     //所有数字都相等
//     return true;
// }
// vector<int>sub(vector<int>A,vector<int>B)
// {
//     vector<int>C;
//     int t=0;//0 代表没有借位，1 代表有借位(当前位)
//     for(int i=0;i<A.size();i++)
//     {
//         t=A[i]-t;//t 用的很妙
//         if(i<B.size())t-=B[i];

//         C.push_back((t+10)%10);// if t>=0 A[i]-B[i]-t >0 说明这一位不用接位（t），else   需要借位（t+10） 两个可以共同表示为(t+10)%10
//         if(t<0)t=1;//当前位
//         else t=0;
//     }
//     //删去前导 0
//     while(C.size()>1&&C.back()==0)C.pop_back();
//     return C;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     string a,b;cin>>a>>b;
//     vector<int>A,B;
//     for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
//     for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');

//     vector<int>C;
//     if(cmp(A,B))//得判断A 是否大于等于 B
//     {
//         C=sub(A,B);
//         for(int i=C.size()-1;i>=0;i--)cout<<C[i];
//     }
//     else
//     {
//         C=sub(B,A);
//         cout<<"-";
//         for(int i=C.size()-1;i>=0;i--)cout<<C[i];
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
bool cmp(string a,string b)
{
    if(a.size()!=b.size())return a.size()>b.size();

    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])return a[i]>b[i];
    }
    return true;
}
vector<int>sub(vector<int>&A,vector<int>&B)
{
    vector<int>C;
    int t=0;//1 代表有借位
    for(int i=0;i<A.size();i++)
    {
        t=A[i]-t;
        if(i<B.size())t-=B[i];

        C.push_back((t+10)%10);//借和不借位合并了
        if(t<0)t=1;//
        else t=0;
    }
    while(C.size()>1&&C.back()==0)C.pop_back();
    return C;
}
int main()
{
    string a,b;cin>>a>>b;
    vector<int>A,B;
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');
    vector<int>C;
    //判断是否a>b
    if(cmp(a,b))
    {
        C=sub(A,B);
        for(int i=C.size()-1;i>=0;i--)cout<<C[i];
    }
    else 
    {
        C=sub(B,A);
        cout<<"-";
        for(int i=C.size()-1;i>=0;i--)cout<<C[i];
    }
    return 0;
}