/*****************************************************
题目描述：
    输入一个整数n(2<=n<=10000),要求输出所有从1到这个整数
之间的（不包括1和这个整数）个位为1的素数，如果没有则输出-1.
输入：
    输入有多个数据。
    每组一行，输入n。
输出：
    输出所有从1到这个整数之间（不包括1和这个整数）个位为1的素数
（素数之间用空格隔开，最后一个素数后面没有空格），如果没有则输出-1。
样例输入：
100
样例输出：
11 31 41 61 71

*****************************************************/

#include<stdio.h>
int prime[10000]; //保存筛选的的素数
int primeSize; //保存素数的个数
bool mark[10001];  //若mark[x]为true,则表示这个数x已被标记为非素数
void init(){
    for(int i=1;i<=10000;i++)
        mark[i]=false;

    primeSize = 0;
    for(int i=2;i<=10000;i++){
        if(mark[i]==true) continue;  //若该数字已经被标记，则跳过
        prime[primeSize++] = i;  //否则，又得到一个新素数
        for(int j=i*i;j<=10000;j+=i)
            mark[j]=true;  //将该数的所有倍数均标记为非素数
    }
}

int main(){
    init();  //在程序一开始首先取得2到10000中所有素数
    int n;
    while(scanf("%d",&n) != EOF){
        bool isOutput = false;  //表示是否输出了符合条件的数字
        for(int i=0;i<primeSize;i++){//依次遍历得到的所有素数
            if(prime[i]<n&&prime[i]%10==1){//测试当前素数是否符合条件
                if(isOutput == false){//若当前输出为第一个输出的数字，则标记已经输出了符合条件的数字，且该数字前不输出空格
                    isOutput = true;
                    printf("%d",prime[i]);
                }
                else printf(" %d",prime[i]);
            }
        }
        if(isOutput == false)  //若始终不存在符合条件的数字
            printf("-1\n");
        printf("\n");
    }
    return 0;
}








