// // // #include<bits/stdc++.h>
// // // using namespace std;
// // // #define int long long
// // // int t;
// // // int b[4];
// // // int cnta,cntb;
// // // int va,vb;
// // // signed main()
// // // {
// // //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// // //     cin>>t;
// // //     while(t--)
// // //     {
// // //         cin>>b[1]>>b[2]>>b[3];
// // //         cin>>cnta>>cntb;
// // //         cin>>va>>vb;
// // //         if(va>vb)swap(va,vb);//让 va 是占体积小的那个 这个会导致对应的关系出错
// // //         //想要放下尽可能多的积木，那不是优先放 小的吗 
// // //         int max_1=b[1]/va;
// // //         int max_2=b[2]/va;
// // //         int max_3=b[3]/va;
// // //         if(max_1+max_2+max_3<=cnta)//全放 A
// // //         {
// // //             cout<<max_1+max_2+max_3<<endl;
// // //         }
// // //         else//a 不够放
// // //         {   
// // //             //三个区间 <max_1,>max1_&<max_2,<max_3
// // //             int needa=0;
// // //             int needb=0;
// // //             if(cnta<=max_1)
// // //             {
// // //                 needa=cnta;
// // //                 needb=((b[1]-cnta*va)+(b[2])+(b[3]))/vb;
// // //                 if(needb<=cntb)continue;
// // //                 needb=cntb;
// // //             }
// // //             else if(cnta>max_1&&cnta<=max_2)
// // //             {
// // //                 //第一个背包用完了，第二个背包剩下一部分
// // //                 needb+=b[3]/vb;
                
// // //                 cnta-=max_1;
// // //                 b[2]-=cnta*va;//第二个背包剩下的体积
// // //                 needb+=b[2]/vb;
// // //             }
// // //             else 
// // //             {
// // //                 //第二个背包用完了，第三个背包剩下一部分
// // //                 cnta-=max_1;
// // //                 cnta-=max_2;

// // //                 b[3]-=cnta*va;
// // //                 needb=b[3]/vb;
// // //             }
// // //             cout<<needa+needb<<endl;
// // //         }
// // //     }
// // //     return 0;
// // // }


// // // //看到完整的题目后，我们需要修正一个非常关键的认知：这道题不能用贪心算法，之前的贪心思路在逻辑上是根本错误的。
// // // #include<bits/stdc++.h>
// // // using namespace std;
// // // #define int long long
// // // struct node
// // // {
// // //     int cnt;
// // //     int v;
// // //     bool operator<(const node&u)
// // //     {
// // //         return v<u.v;
// // //     }
// // // }dat[3];//存物体
// // // int b1,b2,b3;
// // // int t;
// // // signed main()
// // // {
// // //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// // //     cin>>t;
// // //     while(t--)
// // //     {
// // //         cin>>b1>>b2>>b3;
// // //         cin>>dat[1].cnt>>dat[2].cnt;
// // //         cin>>dat[1].v>>dat[2].v;
// // //         sort(dat+1,dat+1+2);

// // //         //先处理体积小的
// // //         int max_1=b1/dat[1].v;
// // //         int max_2=b2/dat[1].v;
// // //         int max_3=b3/dat[1].v;

// // //         int A=0;
// // //         int B=0;
// // //         if(max_1+max_2+max_3<=dat[1].cnt)//全放第一个,足够
// // //         {
// // //             cout<<max_1+max_2+max_3<<endl;
// // //             continue;
// // //         }
// // //         else if(dat[1].cnt<=max_1)
// // //         {
// // //             A=dat[1].cnt;
// // //             //第一个背包没有用完
// // //             b1-=dat[1].v*dat[1].cnt;
// // //             B+=b1/dat[2].v;
// // //             B+=b2/dat[2].v;
// // //             B+=b3/dat[2].v;
            
// // //             //cout<<A+B<<endl;
// // //         }  
// // //         else if(dat[1].cnt<=max_2+max_1)
// // //         {
// // //             A=dat[1].cnt;
// // //             //第一个背包用完了，第二个背包还有剩余
// // //             dat[1].cnt-=max_1;
// // //             b2-=dat[1].cnt*dat[1].v;

// // //             B+=(b3+b2)/dat[2].v;
// // //         }

// // //         else 
// // //         {
// // //             //前两个背包用完了，第三个背包还剩一点
// // //             A=dat[1].cnt;
// // //             dat[1].cnt-=(max_1+max_2);
// // //             b3-=dat[1].cnt*dat[1].v;
// // //             B+=(b3)/dat[2].v;
// // //             B=min(B,dat[2].cnt);//!!!
// // //         }
// // //         cout<<A+B<<endl;
// // //         //cout<<dat[1].cnt+B<<endl;
// // //     }
// // //     return 0;
// // // }


// // //方法 1
// // #include <iostream>
// // #include <vector>
// // #include <algorithm>

// // using namespace std;

// // // 题目要求空间极大，防溢出开 long long
// // #define int long long
// // // 如果当前背包放了 k 个 A，那么它剩余的容量就是 B[i] - k * VA。

// // // 这个背包剩余容量最多能塞进的 B 积木数量就是 (B[i] - k * VA) / VB。

// // //状态转移方程为：next_dp[j + k] = max(next_dp[j + k], dp[j] + 当前背包放的B数量)
// // void solve() {
// //     int B[4];
// //     // 读取三个背包的容量
// //     cin >> B[1] >> B[2] >> B[3];
// //     int cntA, cntB;
// //     cin >> cntA >> cntB;
// //     int VA, VB;
// //     cin >> VA >> VB;

// //     // 定义二维 dp 数组：dp[4][cntA + 1]
// //     // dp[i][j] 表示前 i 个背包装了 j 个 A 积木时，最多能装多少个 B 积木
// //     // 初始化全为 -1，表示不可达状态
// //     vector<vector<int>> dp(4, vector<int>(cntA + 1, -1));
    
// //     // 初始状态：前 0 个背包，装了 0 个 A 积木，自然能装 0 个 B 积木
// //     dp[0][0] = 0; 

// //     // 第一层循环：依次处理 3 个背包 (阶段)
// //     for (int i = 1; i <= 3; ++i) {
        
// //         // 第二层循环：枚举前 i-1 个背包一共装了多少个 A 积木 (状态)
// //         for (int j = 0; j <= cntA; ++j) {
            
// //             // 如果前 i-1 个背包装 j 个 A 的状态不可达，直接跳过
// //             if (dp[i - 1][j] == -1) continue; 
            
// //             // 第三层循环：枚举当前第 i 个背包打算放入 k 个 A 积木 (决策)
// //             // 限制条件1: 放的 A 积木总数不能超过 cntA，即 j + k <= cntA
// //             for (int k = 0; k <= cntA - j; ++k) {
                
// //                 // 限制条件2: 当前背包得能装得下 k 个 A 积木
// //                 if (k * VA <= B[i]) {
// //                     // 计算当前背包剩下的体积
// //                     int rem_space = B[i] - k * VA; 
// //                     // 剩下的体积全用来装 B 积木
// //                     int b_fit = rem_space / VB;   
                    
// //                     // 状态转移：前 i 个背包一共装了 j+k 个 A 积木
// //                     dp[i][j + k] = max(dp[i][j + k], dp[i - 1][j] + b_fit);
// //                 } else {
// //                     // 如果连 k 个 A 都装不下，k 更大的情况肯定也装不下，直接 break 剪枝
// //                     break; 
// //                 }
// //             }
// //         }
// //     }

// //     // 统计最终答案
// //     int max_total = 0;
    
// //     // 遍历所有可能的 A 积木放入数量 (前 3 个背包)
// //     for (int j = 0; j <= cntA; ++j) {
// //         if (dp[3][j] != -1) {
// //             // 注意：计算出来的 B 积木数量不能超过商场的实际库存 cntB
// //             int b_taken = min(cntB, dp[3][j]);
// //             // 更新最大总积木数 (A 的数量 + B 的数量)
// //             max_total = max(max_total, j + b_taken);
// //         }
// //     }
    
// //     cout << max_total << "\n";
// // }

// // signed main() {
// //     // 优化 C++ 的输入输出流速度
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);
    
// //     int t;
// //     if (cin >> t) {
// //         while (t--) {
// //             solve();
// //         }
// //     }
// //     return 0;
// // }


// // //方法 2

// // #include<bits/stdc++.h>
// // using namespace std;
// // int t,bags[5],va,vb,a,b,ans=INT_MIN;

// // signed main()
// // {
// // 	cin>>t;
// // 	while(t--)
// // 	{
// // 		ans=INT_MIN;//多测要清空
// // 		cin>>bags[1]>>bags[2]>>bags[3]>>a>>b>>va>>vb;
// //         //首先枚举 A，我们依次枚举第一个背包、第二个背包、第三个背包中分别装入多少个 A。
// // 		for(int i=0;i<=a&&i*va<=bags[1];i++)//第一层枚举 
// // 		{
// //         	int b1=min(b,(bags[1]-i*va)/vb);
// //         	for(int j=0;j<=a-i&&j*va<=bags[2];j++) //第二层枚举 
// // 			{
// //         	    int b2=min(b-b1,(bags[2]-j*va)/vb);
// //         	    for(int k=0;k<=a-i-j&&k*va<=bags[3];k++) //第三层枚举 
// // 				{
// //         	        int b3=min(b-b1-b2,(bags[3]-k*va)/vb);
// //         	        int cnt=(i+j+k)+(b1+b2+b3);
// //         	        ans=max(ans,cnt);
// //         	    }
// //         	}
// //     	}
// // 		cout<<ans<<'\n';
// // 	}
// // 	return 0;//完结撒花
// // }

// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // int b1,b2,b3;
// // int cnta,cntb;
// // int va,vb;
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     int t;cin>>t;
// //     while(t--){
// //     cin>>b1>>b2>>b3>>cnta>>cntb>>va>>vb;
// //     int ans=1;
// //     //枚举三个背包中A的数量
// //     for(int i=0;i<=cnta&&i*va<=b1;i++)
// //     {
// //         int bb1=min(cntb,(b1-i*va)/vb);//注意这个min很关键

// //         for(int j=0;i+j<=cnta&&(j)*va<=b2;j++)
// //         {
// //             int bb2=min(cntb-bb1,(b2-j*va)/vb);

// //             for(int k=0;i+j+k<=cnta&&k*va<=b3;k++)
// //             {
// //                 int bb3=min(cntb-bb1-bb2,(b3-k*va)/vb);
// //                 ans=max(ans,(i+j+k)+(bb1+bb2+bb3));
// //             }
// //         }
// //     }
// //     cout<<ans<<endl;
// //     }
// //     return 0;
// // }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1002;
// int t;
// int dp[4][N];//取前i个背包放A个物品最大B的数量
// int b[4];
// int cnta,cntb;
// int va,vb;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>t;
//     while(t--)
//     {
//         for(int i=0;i<4;i++)
//         {
//             for(int j=0;j<N;j++)dp[i][j]=-1;
//         }

//         cin>>b[1]>>b[2]>>b[3];
//         cin>>cnta>>cntb;
//         cin>>va>>vb;

//         dp[0][0]=0;
//         for(int i=1;i<=3;i++)
//         {
//             //枚举(i-1)中A物体的数量
//             for(int j=0;j<=cnta;j++)
//             {
//                 //检查上一层（i-1)的状态是否合法
//                 if(dp[i-1][j]==-1)continue;

//                 for(int k=0;k<=cnta-j;k++)
//                 {
//                    //首先得可以装下k个A
//                    if(k*va<=b[i])
//                    {
//                     int res=b[i]-k*va;
//                     int B=res/vb;//在这里不能限制会导致结果出错
//                     dp[i][j+k]=max(dp[i][j+k],dp[i-1][j]+B);
//                    }
//                    else break;
//                 }
//             }
//         }

//         //在装填背包的过程中（也就是那几层 for 循环里），我们只计算“最大物理空间”的累加。物理空间是可以无限累加的，不管你有没有那么多实体物品。
//         //只有在所有背包的空间都分配完毕，求最终答案时，我们才把“空间的容量”和“实体的库存（cntb）”进行对比（取最小值）。
//         int max_=0;
//         for(int j=0;j<=cnta;j++)
//         {
//             if(dp[3][j]!=-1)
//             {
//                 int realb=min(cntb,dp[3][j]);//注意这里
//                 max_=max(max_,j+realb);
//             }
//         }
//         cout<<max_<<endl;
//     }
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1002;
int dp[4][N];
int b[4];
int t;
int cnta,cntb,va,vb;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--)
    {
       for(int i=1;i<=3;i++)cin>>b[i];
       cin>>cnta>>cntb>>va>>vb;
       for(int i=0;i<=3;i++)// i 必须从 0 开始初始化否则会导致错误
        {
            for(int j=0;j<=cnta;j++)dp[i][j]=-1;
        }

        dp[0][0]=0;

        for(int i=1;i<=3;i++)
        {
            //前i-1 个中放的A 背包的数量
            for(int j=0;j<=cnta;j++)
            {
                if(dp[i-1][j]==-1)continue;
                //枚举第 i 个背包中 A 的数量
                for(int k=0;k<=cnta-j;k++)
                {
                    if(k*va<=b[i])//首先得装下 A
                    {
                        int res=b[i]-k*va;
                        dp[i][j+k]=max(dp[i][j+k],dp[i-1][j]+res/vb);
                    }
                }
            }
        }

        int max_=0;
        for(int j=0;j<=cnta;j++)
        {
            if(dp[3][j]!=-1)
            {
                int real_b=min(cntb,dp[3][j]);
                max_=max(max_,real_b+j);
            }
        }
        cout<<max_<<endl;
    }
    return 0;
}