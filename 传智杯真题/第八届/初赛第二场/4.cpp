// //自己写的太麻烦了 统计二进制的数量
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int t;cin>>t;
//     while(t--)
//     {
//         string s;cin>>s;
//         for(int i=0;i<s.size();i++)
//         {
//             int p=i+1;
//             //转为二进制
//             //vecctor<int>ans;
//             string temp="";
//             while(p)
//             {
//                 temp+=p%2+'0';
//                 p/=2;
//             }
//             int cnt1=0;
//             for(int i=0;i<temp.size();i++)
//             {
//                 if(temp[i]=='1')cnt1++;
//             }
//             if(cnt1%2==1)cout<<char(toupper(s[i]));
//             else cout<<char(s[i]);
//         }
//         cout<<endl;
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>
// //Brian Kernighan 算法
// int count_binary(int n);
// int main() {
//     int t;
//     scanf("%d",&t);
//     getchar();
//     for(int i = 0;i < t;i++){
//         char str[502];
//         scanf("%s",str);
//         int len = strlen(str);
//         for(int j = 0;j < len;j++){
//             if(count_binary(j+1)%2==1) str[j] = str[j]-'a'+'A';
//         }
//         printf("%s\n",str);
//     }
//     return 0;
// }
// //注意这个！！！
// int count_binary(int n){
//     int count = 0;
//     while(n > 0){
//         n = n & n-1;
//         count++;
//     }
//     return count;
// }


#include<bits/stdc++.h>
using namespace std;
int count_binary(int n)
{
    int cnt=0;
    while(n)
    {
        n=n&n-1;
        cnt++;
    }
    return cnt;
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        string s;cin>>s;
        for(int i=0;i<s.size();i++)
        {
            if(count_binary(i+1)%2==1)s[i]=toupper(s[i]);
        }
        cout<<s<<endl;
    }
    return 0;
}
