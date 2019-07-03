/***********************************************
题目大意:
    有一堆柑橘，重量为0到2000，总重量不大于2000.要求我们从中取出两堆放在扁担的两头且两头的重量相等，问符合条件的每堆的重量最大为多少。
没有符合条件的分堆方式则输出-1.
输入：
    The first line of input contains a number t,which means there are t cases of the test data.for each test case, the fisrt line contain a number n,
indicate the weight of each orange. n is between 1 and 100, inclusive. Wi is between 0 and 2000,inclusive. the sum of Wi is equal or less than 2000.
输出：
    For each test case,output the maximum weight in one side of Carrying pole. If you can't carry any orange ,output -1.
Output format is shown in Sample Ouput.
样例输入输出：


***********************************************/
#include<stdio.h>
#define OFFSET  2000   //因为柑橘的重量差存在负数的情况，即第一堆比第二堆轻，所以在计算重量差对应数组下标时加上该偏移值，时每个重量差对应合法的数组下标
int dp[101][4001];  //保存状态
int list[101];  //保存柑橘数量
#define INF 0x7fffff;
int main(){
    int T;
    int cas = 0;  //处理的Case数，以便输出
    scanf("%d",&T);  //输入要处理的数据组成
    while(T--!=0){
        int n;
        scanf("%d",&n);
        bool HaveZero = false;   //统计是否存在重量为0的柑橘
        int cnt = 0; //计数器，记录共有多少个重量非零的柑橘
        for(int i=1;i<=n;i++){//输入n个柑橘重量
            if(list[cnt]==0){
                cnt--;
                HaveZero = true;  //并记录重量为0的柑橘
            }
        }
        n = cnt;
        for(int i=-2000;i<=2000;i++){
            dp[0][i+OFFSET] = -INF;
        }  //初始化，所有dp[0][i]为负无穷
        dp[0][0+OFFSET] = 0;//dp[0][0]为无穷
        for(int i=1;i<=n;i++){
            for(int j=-2000;j<=2000;j++){
                int tmp1 = -INF,tmp2 = -INF;
                if(j+list[i]<=2000 && dp[i-1][j+list[i]+OFFSET]!=-INF){
                    tmp1 = dp[i-1][j+list[i]+OFFSET]+list[j];
                }
                if(tmp1<tmp2){
                    tmp1=tmp2;
                }//取两者中较大的那个，保存至tmp1
                if(tmp1<dp[i-1][j+OFFSET]){//将tmp1与当前柑橘不放入任何堆即状态差不发生改变的原状态值比较，取较大的值保存至tmp1
                    tmp1 = dp[i-1][j+OFFSET];
                }
                dp[i][j+OFFSET] = tmp1;  //当前状态保存为三个转移来源转移得到新值中最大的那个
            }
        }
        printf("Case %d:",++cas);  //按题目输出要求输出
        if(dp[n][0+OFFSET]==0){//dp[n][0]为0
            puts(HaveZero==true?"0":"-1");
        }
        else printf("%d\n",dp[n][0+OFFSET]/2);  //否则输出dp[n][0]/2
    }
    return 0;
}





