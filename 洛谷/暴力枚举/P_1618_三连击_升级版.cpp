// #include<bits/stdc++.h>
// using namespace std;
// int A,B,C;
// const int N=1e5+66; 
// int ans[5];
// void dfs(int x,int y)
// {
//     if(x>9)
//     {
//         if(B*ans[1]==A*ans[2]&&C*ans[2]==B*ans[3])
//         {
//             cout<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<endl;
//         }
//         return;
//     }

//     //分成3组 每组3个
//     for(int i=1;i<=9;i++)
//     {
//         if(!st[i])
//         {
//             if()
//         }
//     }

// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>A>>B>>C;
//     dfs(1,1);
//     return 0;
// }

// //我靠 很聪明的思路
// #include<bits/stdc++.h>
// using namespace std;
// int b[10]={0,1,2,3,4,5,6,7,8,9};
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int A,B,C;cin>>A>>B>>C;
//     int res=0;
//     do{
//         int a1=100*b[1]+10*b[2]+b[3];//第一个数
//         int b1=100*b[4]+10*b[5]+b[6];
//         int c1=100*b[7]+10*b[8]+b[9];
//         if(B*a1==A*b1&&C*b1==B*c1)
//         {
//             res++;
//             cout<<a1<<" "<<b1<<" "<<c1<<endl;
//         }
//     }
//     while(next_permutation(b+1,b+10));//全排列的框架
//     if(res==0)cout<<"No!!!";
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int a,b,c;
// int d[10]={0};
// int res=0;
// //本质就是全排列 加上一些限定条件
// bool is_ok(int d[])
// {
//     int x=100*d[1]+10*d[2]+d[3];
//     int y=100*d[4]+10*d[5]+d[6];
//     int z=100*d[7]+10*d[8]+d[9];
//     if(b*x==a*y&&c*y==b*z)
//     {
//         cout<<x<<" "<<y<<" "<<z<<endl;
//         return true;
//     }
//     return false;
// }
// bool st[10];
// void dfs(int x)
// {
//     if(x>9)
//     {
//         if(is_ok(d))
//         {
//             res++;
//         }
//       // for(int i=1;i<=9;i++)cout<<d[i];
//        // cout<<endl;
//         return;
//     }
//     for(int i=1;i<=9;i++)
//     {
//         if(!st[i])
//         {
//             d[x]=i;
//             st[i]=1;
//             dfs(x+1);

//             //恢复现场
//             d[x]=0;
//             //st[x]=0;
//             st[i]=0;
//         }
//     }

// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>a>>b>>c;
//     dfs(1);
//     if(!res)cout<<"No!!!";
//     return 0;
// }


//没问题
// #include<bits/stdc++.h>
// using namespace std;
// const int N=10;
// int a[N];
// int A,B,C;
// int AA,BB,CC;
// int ans=0;
// bool st[N];
// void dfs(int x)
// {
//     if(x>9)
//     {
//         AA=a[1]*100+a[2]*10+a[3];
//         BB=a[4]*100+a[5]*10+a[6];
//         CC=a[7]*100+a[8]*10+a[9];
//         if(AA*B==BB*A&&BB*C==CC*B)
//         {
//             ans++;
//             cout<<AA<<" "<<BB<<" "<<CC<<endl;
//         }
//     }
//     for(int i=1;i<=9;i++)
//     {
//         if(!st[i])
//         {
//             st[i]=1;
//             a[x]=i;
//             dfs(x+1);
           
//             st[i]=0;
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>A>>B>>C;
//     //全排列
//     dfs(1);
//     if(ans==0)cout<<"No!!!";
//     return 0;
// }

// //12/17

// //思路 1：全排列（公式）
// //思路二：枚举 9 个数()
// #include<bits/stdc++.h>
// using namespace std;
// int a,b,c;
// int s[10];
// bool st[10];
// int ans=0;
// void dfs(int x)
// {
//     if(x>9)
//     {
//         int A=s[1]*100+s[2]*10+s[3];
//         int B=s[4]*100+s[5]*10+s[6];
//         int C=s[7]*100+s[8]*10+s[9];
//         if(A*b==a*B&&A*c==a*C)
//         {
//             ans++;
//             cout<<A<<" "<<B<<" "<<C<<endl;
//         }
//         return;
//     }

    
//     for(int i=1;i<=9;i++)
//     {
//         if(!st[i])
//         {
//             st[i]=1;
//             s[x]=i;
//             dfs(x+1);
//             st[i]=0;
//         }
        
//     }
// }
// int main()
// {
//     cin>>a>>b>>c;
//     // for(int i=1;i<=9;i++)s[i]=i;
//     // do
//     // {
//     //     int A=s[1]*100+s[2]*10+s[3];
//     //     int B=s[4]*100+s[5]*10+s[6];
//     //     int C=s[7]*100+s[8]*10+s[9];
//     //     if(A*b==a*B&&A*c==a*C)cout<<A<<" "<<B<<" "<<C<<endl;
//     // } while (next_permutation(s+1,s+1+9));

//     dfs(1);
//     if(!ans)cout<<"No!!!";
//     return 0;
// }


