// // //模板
// //有点抽象
// // #include <iostream>
// // #include <string>
// // #include <stack>
// // #include <unordered_map>

// // using namespace std;

// // stack<char> op;
// // stack<int> num;
// // unordered_map<char, int> pr = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

// // void eval()
// // {
// //     int b = num.top(); num.pop();
// //     int a = num.top(); num.pop();
// //     char c = op.top(); op.pop();

// //     int x;
// //     if(c == '+') x = a + b;
// //     else if(c == '-') x = a - b;
// //     else if(c == '*') x = a * b;
// //     else x = a / b;

// //     num.push(x);
// // }

// // int main()
// // {
// //     string s;
// //     cin >> s;

// //     for(int i = 0; i < s.size(); i++)
// //     {
// //         char c = s[i];
// //         if(isdigit(c))
// //         {
// //             int x = 0, j = i;
// //             while(j < s.size() && isdigit(s[j])) x = 10 * x + s[j++] - '0';
// //             i = j - 1;//细节
// //             num.push(x);
// //         }
// //         else if(c == '(') op.push(c);
// //         else if(c == ')')
// //         {
// //             while(op.size() && op.top() != '(') eval();
// //             op.pop();
// //         }
// //         else
// //         {
// //             while(op.size() && pr[op.top()] >= pr[c]) eval();
// //             op.push(c);
// //         }
// //     }
// //     while(op.size()) eval();
// //     cout << num.top() << endl;

// //     return 0;
// // }



// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// string s;
// unordered_map<char, int> pr = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
// stack<int>num;
// stack<int>op;
// void eval()
// {
//     int b=num.top();num.pop();
//     int a=num.top();num.pop();
//     char c=op.top();op.pop();
//     if(c=='+')num.push(a+b);
//     else if(c=='-')num.push(a-b);
//     else if(c=='*')num.push(a*b);
//     else if(c=='/')num.push(a/b);
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>s;
//     for(int i=0;i<s.size();i++)
//     {
//         char c=s[i];
        
//         int j=i;
//         int x=0;
//         if(isdigit(s[i]))
//         {
//             while(j<s.size()&&isdigit(s[j]))x=x*10+s[j++]-'0';
//             i=j-1;
//             num.push(x);
//         }
//         else if(s[i]=='(')op.push(s[i]);
//         else if(s[i]==')')
//         {
//             while(op.size()&&op.top()!='(')eval();
//             op.pop();
//         }
//         else
//         {
//             //看是向下走还是向上走 如果当前的符号＜=之前的符号那么就是往上走
//             while(op.size()&&pr[op.top()]>=pr[c])eval();
//            // num.push(c);
//            op.push(c);
//         }
//     }
//     //当主循环 for(int i=0; i<s.size(); i++) 结束时，整个字符串虽然遍历完了，但 op 栈中大概率还有未处理的运算符
//     while(op.size())eval();
//     cout<<num.top();
//     return 0;
// }


//还是有点不熟
#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
//typedef pair<char,int>PII;
unordered_map<char,int>pr={{'+',1},{'-',1},{'*',2},{'/',2}};
stack<int>nums;
stack<char>op;
void eval()
{
    int b=nums.top();nums.pop();
    int a=nums.top();nums.pop();
    char s=op.top();op.pop();
    if(s=='+')nums.push(a+b);
    else if(s=='-')nums.push(a-b);
    else if(s=='*')nums.push(a*b);
    else if(s=='/')nums.push(a/b);
    //cout<<"A="<<a<<"B="<<b;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        
        if(isdigit(s[i]))
        {
            int j=i;
            int x=0;
            while(isdigit(s[j]))x=x*10+s[j++]-'0';
            nums.push(x);
            i=j-1;
        }
        else if(s[i]=='(')
        {
            op.push('(');
        }
        else if(s[i]==')')
        {
            while(op.top()!='(')eval();
            op.pop();
        }
        else//+-*/
        {
            //当前字符的优先级小于上一个字符的优先级，肯定得先把之前的数字算完
            while(op.size()&&pr[op.top()]>=pr[s[i]])eval();
            op.push(s[i]);
        }
    }
    //可能还有操作符
    while(op.size())eval();
    cout<<nums.top();
    return 0;
}
