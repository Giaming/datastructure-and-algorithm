/**************************************************
题目描述：
    给定n，a求最大的k，使n！可以被a^k整除但不能被a^(k+1)整除
输入：
    两个整数n(2<=n<=1000),a(2<=a<=1000)
输出：
    一个整数
样例输入：
    6 10
样例输出：
1

**************************************************/
#include<stdio.h>
#include<string.h>

bool mark[1010];
int prime[1010];
int primeSize;

//筛选出0到1000范围内的所有素数
void init(){
    primeSize = 0;
    for(int i=2;i<=1000;i++){
        if(mark[i]) continue;
        mark[i] = true;
        prime[primeSize++] = i;
        for(int j=i*i;j<=1000;j+=i)
            mark[j]=true;
    }
}

int cnt[1010];  //cnt[i]用来表示prime[i]所保存的素数在n!中因子数，即n!分解素因数后，素因子prime[i]所对应的幂指数，可能为0
int cnt2[1010];  //cnt2[i]用来表示prime[i]所保存的素数在a中的因子数

int main(){
    int n,a;
    init();
    while(scanf("%d%d",&n,&a)==2){
        for(int i=0;i<primeSize;i++)
            cnt[i]=cnt2[i]=0;  //将两个计数器清零，为新的一次分解做准备
        for(int i=0;i<primeSize;i++){//对n!分解素因数，遍历每一个0到1000的素数
            int t=n;  //用临时变量t保存n的值
            while(t){//确定素数prime[i]在n中的因子数
                cnt[i]+=t/prime[i];
                t=t/prime[i];
            }//依次计算t/prime[i]^k,累加其值，直到t/prime[i]^k变为0
        }
        int ans = 123123123;  //答案初值为一个大整数，为取最小值做准备
        for(int i=0;i<primeSize;i++){//对a分解素因数
            while(a%prime[i]==0){//计算a中素因数prime[i]对应的幂指数
                cnt2[i]++;
                a/=prime[i];
            }
            if(cnt2[i]==0) continue;//若该素数不能从a中分解到，及其对应幂指数为0，则其不影响整体性，跳过
            if(cnt[i]/cnt2[i]<ans)  //计算素数prime[i]在两个数中因子数的商
                ans = cnt[i] / cnt2[i]; //统计这些商的最小值
        }
        printf("%d\n",ans);
    }
    return 0;
}



