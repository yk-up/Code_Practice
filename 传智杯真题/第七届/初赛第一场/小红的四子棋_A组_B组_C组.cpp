// // //还可以，100多行的代码直接写出来 不过还是有几个问题：斜着不代表仅仅就是主副对角线，而且判断的下标也得注意一下，尤其是从右上到左下
// // //这道题得复习一下
// // #include<bits/stdc++.h>
// // using namespace std;
// // const int N=102;
// // char a[N][N];
// // int n,m;
// // char s[N];
// // bool flg;
// // void judge(char x)
// // {
// //     //检查横着的
// //     for(int i=1;i<=n;i++)
// //     {
// //         for(int j=1;j<=m-3;j++)
// //         {
// //             //i,j-i,j+3
// //             bool f=1;
// //             //for(int k=0;k<4;k++) a[i][k+j]//这样写会更加清晰
// //             for(int k=j;k<j+4;k++)
// //             {
// //                 if(a[i][k]==x)continue;
// //                 f=0;
// //                 break;
// //             }
// //             if(f)
// //             {
// //                 flg=1;
// //                 return;
// //             }
// //         }
// //     }

// //     //检查竖的
// //     for(int j=1;j<=m;j++)
// //     {
// //         for(int i=1;i<=n-3;i++)
// //         {
// //             //i,j,i+3,j
// //             bool f=1;
// //             for(int k=i;k<=i+3;k++)
// //             {
// //                 if(a[k][j]==x)continue;
// //                 f=0;
// //                 break;
// //             }
// //             if(f)
// //             {
// //                 flg=1;
// //                 return;
// //             }
// //         }
// //     }

// //     //不一定是主或者副对角形，是斜的就行
// //     // //检查主对角线
// //     // for(int i=1;i<=n-3;i++)
// //     // {
// //     //     //i,i-i+3,i+3
// //     //     bool f=1;
// //     //     for(int k=i;k<=i+3;k++)
// //     //     {
// //     //         if(a[k][k]==x)continue;
// //     //         f=0;
// //     //         break;
// //     //     }
// //     //     if(f)
// //     //     {
// //     //         flg=1;
// //     //         return;
// //     //     }
// //     // }

// //     // for(int i=1;i<=n-3;i++)
// //     // {
// //     //     //1,n-n,1
// //     //     bool f=1;//判断这一行符合不符合
// //     //     for(int k=i;k<=i+3;k++)
// //     //     {
// //     //         if(a[k][n+1-k]==x)continue;
// //     //         f=0;
// //     //         break;
// //     //     }
// //     //     if(f)
// //     //     {
// //     //         flg=1;
// //     //         return ;
// //     //     }
// //     // }

// //     //这里的下标注意一下
// //     //从左上到右下
// //     for(int i=1;i<=n-3;i++)
// //     {
// //         for(int j=1;j<=m-3;j++)
// //         {
// //             //i,j,i+3,j+3
// //             bool f=1;
// //             for(int k=0;k<4;k++)
// //             {
// //                 if(a[i+k][j+k]==x)continue;
// //                 f=0;
// //                 break;
// //             }
// //             if(f)
// //             {
// //                 flg=1;
// //                 return;
// //             }
// //         }
// //     }

// //     //从右上到左下 注意这里的循环起始坐标
// //     for(int i=1;i<=n-3;i++)
// //     {
// //         //for(int j=m;j>=4;j--)
// //         for(int j=4;j<=m;j++)
// //         {
// //             //i,j-i+3,j-3
// //             bool f=1;
// //             for(int k=0;k<4;k++)
// //             {
// //                 if(a[i+k][j-k]==x)continue;
// //                 f=0;
// //                 break;
// //             }

// //             if(f)
// //             {
// //                 flg=1;
// //                 return;
// //             }
// //         }
// //     }
// // }
// // int main()
// // {
// //     cin>>n>>m;
// //     for(int i=1;i<=n;i++)
// //     {
// //         for(int j=1;j<=m;j++)cin>>a[i][j];
// //     }

// //     s[0]='r',s[1]='p';//这个挺聪明的
// //     for(int i=0;i<2;i++)
// //     {
// //         flg=0;
// //         judge(s[i]);//判断逻辑一模一样就集成一个函数
// //         if(flg)
// //         {
// //             if(i==1)cout<<"yukari\n";
// //             else cout<<"kou\n";
// //             return 0;
// //         }
// //     }
// //     cout<<"to be continued";
// //     return 0;
// // }


// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e2+11;
// int n,m;
// char a[N][N];
// char s[2];
// bool flg;
// void judge(char x)
// {
//     //检查行
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m-3;j++)
//         {
//             //i,j~i,j+3
//             bool f=1;
//             for(int k=0;k<4;k++)
//             {
//                 if(a[i][j+k]==x)continue;
//                 f=0;
//                 break;
//             }
//             if(f)
//             {
//                 flg=1;
//                 return;
//             }
//         }
//     }

//     //检查列
//     for(int j=1;j<=m;j++)
//     {
//         for(int i=1;i<=n-3;i++)
//         {
//             //i,j~i,j+3
//             bool f=1;
//             for(int k=0;k<4;k++)
//             {
//                 if(a[i+k][j]==x)continue;
//                 f=0;
//                 break;
//             }
//             if(f)
//             {
//                 flg=1;
//                 return;
//             }
//         }
//     }

//     //检查左上到右下
//     for(int i=1;i<=n-3;i++)
//     {
//         for(int j=1;j<=m-3;j++)
//         {
//             bool f=1;
//             for(int k=0;k<4;k++)
//             {
//                 if(a[i+k][j+k]==x)continue;
//                 f=0;
//                 break;
//             }
//             if(f)
//             {
//                 flg=1;
//                 return;
//             }
//         }
//     }

//     //右上到左下
//     for(int i=1;i<=n-3;i++)
//     {
//         for(int j=4;j<=m;j++)
//         {
//             bool f=1;
//             for(int k=0;k<4;k++)
//             {
//                 if(a[i+k][j-k]==x)continue;
//                 f=0;
//                 break;
//             }
//             if(f)
//             {
//                 flg=1;
//                 return;
//             }
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++)cin>>a[i][j];
//     }

//     s[0]='r',s[1]='p';
//     for(int i=0;i<2;i++)
//     {
//         flg=0;
//         judge(s[i]);
//         if(flg)
//         {
//             if(i==0)cout<<"kou\n";
//             else cout<<"yukari\n";
//             return 0;
//         }
       
//     }
//             cout<<"to be continued";
    
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
const int N=102;
char a[N][N];
int n,m;
int s[3];
bool flg1,flg2;//分别表示小红和小紫胜利了
bool judge(char x)
{
    //检查
    for(int i=1;i<=n;i++)
    {
        
        for(int j=1;j<=m;j++)
        {
            bool flg=1;
            //i,j,
            for(int k=0;k<4;k++)
            {
                if(a[i][k+j]==x)continue;
                flg=0;
                break;
            }
            if(flg)
            {
                return true;
            }
        }
        // if(flg)
        // {
        //     return true;
        // }
    }

    //检查竖着的
    for(int j=1;j<=m;j++)
    {
        
        for(int i=1;i<=n;i++)
        {
            bool flg=1;
            for(int k=0;k<4;k++)
            {
                if(a[i+k][j]==x)continue;
                flg=0;
                break;
            }
             if(flg)return true;
        }
       
    }


    //检查写着的

    for(int i=1;i<=n-3;i++)
    {
        
        for(int j=1;j<=m-3;j++)
        {
            bool flg=1;
            for(int k=0;k<4;k++)
            {
                if(a[i+k][j+k]==x)continue;
                flg=0;
                break;
            }
            if(flg)return true;
        }
    }

    for(int i=1;i<=n-3;i++)
    {
        
        for(int j=4;j<=m;j++)
        {
            bool flg=1;
            for(int k=0;k<4;k++)
            {
                if(a[i+k][j-k]==x)continue;
                flg=0;
                break;
            }
            if(flg)return true;
        }
    }
    return false;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)cin>>a[i][j];
    }
    s[0]='r',s[1]='p';
    for(int i=0;i<2;i++)
    {
        if(judge(s[i]))
        {
            if(i==0)flg1=1;
            else flg2=1;
        }

    }
    if(flg1)cout<<"kou\n";
    else if(flg2)cout<<"yukari\n";
    else cout<<"to be continued";
    return 0;
}