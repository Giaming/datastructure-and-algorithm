/************************************************************
题目描述：
    给定一个数n，要求判断其是否为素数(0,1，负数都是非素数)
输入：
    测试数据有多组，每组输入一个数n
输出：
    对于每组输入，若是素数则输出yes，否则输出no
样例输入：
13
样例输出：
yes

***********************************************************/
#include<stdio.h>
#include<math.h>
bool judge(int x){//判断一个数是否为素数
    if(x<=1) return false;
    int bound = (int)sqrt(x)+1;//计算枚举上界，为防止double值带来的精度损失
    for(int i=2;i<bound;i++)
        if(x%i==0) return false;
    return true;
}

int main(){
    int x;
    while(scanf("%d",&x)!=EOF)
        puts(judge(x)?"yes":"no");
    return 0;
}


