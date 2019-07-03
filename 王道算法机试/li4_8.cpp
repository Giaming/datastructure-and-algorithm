/******************************************************
题目描述：
    求正整数N(N>1)的质因数的个数。
    相同的质因数需要重复计算。如：120=2*2*2*3*5,共有5个质因数。
输入：
    可能有多组测试数据，每组测试数据的输入是一个正整数N,(1<N<10^9)
输出：
    对于每组数据，输出N的质因数的个数。
样例输入：
120
样例输出：
5
注意：
1不是N的质因数；若N为质数，N是N的质因数。


*****************************************************/
#include<stdio.h>
bool mark[10000];
int prime[10001];
int primeSize;

void init(){//初始化，标记出素数
    primeSize = 0;
    for(int i=2;i<=10000;i++){
        if(mark[i]==true) continue;
        prime[primeSize++]=i;
        if(i>=1000) continue;
        for(int j=i*i;j<=10000;j+=i)
            mark[j]=true;
    }
}

int main(){
    init();
    int n;
    while(scanf("%d",&n)!=EOF){
        int ansPrime[30]; //按顺序保存分解出的素因素
        int ansSize=0;  //分解出素因素的个数
        int ansNum[30];  //保存分解出的素因数对应的幂指数
        for(int i=0;i<primeSize;i++){//依次测试每一个素数
            if(n%prime[i]==0){//若该素数能整除被分解数
                ansPrime[ansSize] = prime[i];//则该素数为其素因数
                ansNum[ansSize] = 0;//初始化幂指数为0
                while(n%prime[i]==0){//从被测试数中将该素数分解出来，并统计其幂指数
                    ansNum[ansSize]++;
                    n/=prime[i];
                }
                ansSize++;//素因数个数加一
                if(n==1) break;  //若已经被分解为1，则分解提前终止
            }
        }
        if(n!=1){//若测试完2到10000内所有素因数，n仍未被分解至1，则剩余的因数一定是n一个大于100000的素因数
             ansPrime[ansSize]=n;  //记录大于因数
             ansNum[ansSize++] = 1;//其幂指数只能为1
        }
        int ans = 0;
        for(int i=0;i<ansSize;i++){
            ans += ansNum[i];  //统计个素因数的幂指数
        }
        printf("%d\n",ans);
    }

    return 0;
}





