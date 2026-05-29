#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    string a="g";
    a+='_';
    a+="z";
    while((int)a.size()<n)a+="a";
    cout<<a;
    return 0;
}