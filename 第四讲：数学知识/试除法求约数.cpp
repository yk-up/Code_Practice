#include<bits/stdc++.h>
using namespace std;
int n;

//有点笨
// void get_yueshu(int x)
// {
//     vector<int>ans;
//     for(int i=1;i<=x/i;i++)
//     {
//         if(x%i==0)
//         {
//             ans.push_back(i);
//             ans.push_back(x/i);
//         }
//     }
//     sort(ans.begin(),ans.end());
//     ans.erase(unique(ans.begin(),ans.end()),ans.end());
//     for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
//     cout<<endl;
// }


void get_divisor(int x)
{
    vector<int>ans;
    for(int i=1;i<=x/i;i++)
    {
        if(x%i==0)
        {
            ans.push_back(i);
            if(i!=x/i)ans.push_back(x/i);//防止加入重复元素
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        //get_yueshu(x);
        get_divisor(x);
    }
    
    
    return 0;
}