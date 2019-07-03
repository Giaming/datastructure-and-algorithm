/***************************************************************
题目描述：
    输入一个正整数N,输出N的阶乘。
输入：
    正整数N(0<=N<=1000)
输出：
    输入可能包含多组数据，对于每一组数据，输出N的阶乘。
样例输入：
4
5
15
样例输出：
24
120
1307674368000


**************************************************************/
//本题涉及高精度乘法
#include<stdio.h>
#include<string.h>
struct bigInteger{
    int digit[1000];
    int size;
    void init(){
        for(int i=0;i<1000;i++) digit[i]=0;
        size = 0;
    }
    void set(int x){//用一个小整数设置高精度整数
        init();
        do{//对小整数4位为一个单位分解依次存入digit当中
            digit[size++] = x%10000;
            x /= 10000;
        }while(x!=0);
    }
    void output(){
        for(int i=size-1;i>=0;i--){
            if(i!=size-1) printf("%04d",digit[i]);
            else printf("%d",digit[i]);
        }
        printf("\n");
    }
    bigInteger operator * (int x) const{
        bigInteger ret; //将要返回的高精度整数
        ret.init();
        int carry = 0; //进位初始值
        for(int i=0;i<size;i++){
            int tmp = x*digit[i] + carry;//用小整数x乘以当前位数字并加上来自低位的进位
            carry = tmp/10000; //计算进位
            tmp %= 10000;  //去除进位部分
            ret.digit[ret.size++] = tmp;//保存该数字
        }
        if(carry!=0){//若最高位有进位
            ret.digit[ret.size++] = carry; //保存该进位
        }
        return ret; //返回结果
    }
}a;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        a.init();
        a.set(1);//a初始值为1
        for(int i=1;i<=n;i++)
            a=a*i;  //依次乘上每一个整数
        a.output();
    }
    return 0;
}



