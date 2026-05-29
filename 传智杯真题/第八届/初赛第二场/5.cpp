// //环？ 不会啊
// //当时考试的时候一点不会，现在也是
// #include <iostream>
// #include <string>
// #include <algorithm>

// using namespace std;

// int main() {
//     string s;
//     if (!(cin >> s)) return 0;
//     int n = s.size();

//     // 破环成链：处理环形最简单的办法是复制一份
//     string ss = s + s; 
    
//     int max_len = 0; // 统一用这个名字
// int current_len = 0;

// for (int i = 0; i < ss.size(); i++) {
//     if (i > 0 && ss[i] == ss[i - 1]) {
//         current_len++;
//     } else {
//         current_len = 1;
//     }
//     // 修正：确保函数内的变量名与定义的变量名一致
//     max_len = max(max_len, current_len); 
    
//     if (max_len >= n) {
//         max_len = n;
//         break; 
//     }
// }

//     cout << max_len << endl;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;cin>>s;
    int n=s.size();
    s=s+s;
    int maxlen=-1;
    int currlen=0;
    for(int i=0;i<s.size();i++)
    {
        if(i-1>0&&s[i-1]==s[i])
        {
            currlen++;
        }
        else currlen=1;
        maxlen=max(maxlen,currlen);
        if(maxlen>n)
        {
            cout<<n;
            return 0;
        }
    }
    cout<<maxlen<<endl;
    return 0;
}