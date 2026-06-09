// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     double n;cin>>n;
//     double l=-10000,r=10000;
//     while(r-l>1e-8)
//     {
//         double mid=(r+l)/2;
//         if(mid*mid*mid>=n)//说明 x在左边
//         r=mid;
//         else l=mid;
//     }
//     cout<<fixed<<setprecision(6)<<r;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
double n;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    double l=-10000,r=10000;
    while(r-l>1e-8)
    {
        double mid=(l+r)/2;
        if(mid*mid*mid>n)r=mid;
        else l=mid;
    
    }
    cout<<fixed<<setprecision(6)<<l;
    return 0;

}