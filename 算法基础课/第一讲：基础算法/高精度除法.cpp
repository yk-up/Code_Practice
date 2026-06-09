// //这个模版是一个大整数/一个小整数
// #include<bits/stdc++.h>
// using namespace std;
// vector<int>div(vector<int>&A,int d,int &r)
// {
//     int t=0;
//     vector<int>C;
//     //从高位开始，这是和之前所有的不一样的地方，
//     for(int i=A.size()-1;i>=0;i--)
//     {
//         r=r*10+A[i];
//         C.push_back(r/d);
//         r%=d;//余数
//     }

//     reverse(C.begin(),C.end());
//     while(C.size()>1&&C.back()==0)C.pop_back();
//     return C;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     string a;int d;cin>>a>>d;
//     vector<int>A;
//     int r=0;
//     for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
//     vector<int>C=div(A,d,r);
//     //为了和前面的模板保持一致还是保持这种
//     for(int i=C.size()-1;i>=0;i--)cout<<C[i];
//     cout<<endl;
//     cout<<r;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
string a;int b;
int d=0;//除数
int r=0;//余数
vector<int>div(vector<int>A,int b)
{
    vector<int>C;
    //除法得从高位开始
    reverse(A.begin(),A.end());
    
    for(int i=0;i<A.size();i++)
    {
        d=(r*10+A[i])/b;
        C.push_back(d);
        r=(r*10+A[i])%b;
    }
    //现在是高位在前
    reverse(C.begin(),C.end());
    while(C.size()>1&&C.back()==0)C.pop_back();
    return C;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    vector<int>A;
    cin>>a>>b;
    for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
    vector<int>C=div(A,b);
    
    for(int i=C.size()-1;i>=0;i--)cout<<C[i];
    cout<<endl;
    cout<<r;
    return 0;
}