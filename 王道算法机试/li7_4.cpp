/**************************************************
题目描述：
    Find a longest common subsequence of two strings.
输入：
    First and second line of each input case contain two strings of lowercase character a...z.
There are no spaces before, inside or after the srings. Lengths of strings do not exceed 100.
输出：
    For each case, output k-the length of a longest common subsquence in one line.
样例输入和输出：
abcd
cxbydz
2
输出矩阵：
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 1 1 1 1
0 1 1 1 1 1 1
0 1 1 1 1 2 2

算法原理：
dp[0][j](0<=j<=m)=0;
dp[i][0](0<=i<=n)=0;
dp[i][j]=dp[i-1][j-1]+1;  (S1[i]==S2[j])
dp[i][j]=max(dp[i-1,j],dp[i][j-1]);  (S1[i]!=S2[j])


**************************************************/
#include<stdio.h>
#include<string.h>
int dp[101][101];
int max(int a, int b){return a>b?a:b;}
int main(){
    char S1[101],S2[101];
    while(scanf("%s%s",S1,S2)!=EOF){
        int L1 = strlen(S1);
        int L2 = strlen(S2);
        for(int i=0;i<=L1;i++) dp[i][0] = 0;
        for(int j=0;j<=L2;j++) dp[0][j] = 0;    //初始值
        for(int i=1;i<=L1;i++){
            for(int j=1;j<=L2;j++){   //二重循环依次求得每个dp[i][j]值
                if(S1[i-1]!=S2[j-1]){//因为字符串数组下标从0开始，所以第i个字符位置为S1[i-1],若当两个字符不相等
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
                else
                    dp[i][j] = dp[i-1][j-1]+1;
            }
        }
        printf("%d\n",dp[L1][L2]);
        for(int i=0;i<=L1;i++){
            for(int j=0;j<=L2;j++)
                printf("%d ",dp[i][j]);
            printf("\n");
        }
    }
    return 0;
}





