/*************************************************************
题目描述：
    将M进制的数X转换为N进制的数输出
输入：
    输入的第一行包括两个整数：M和N(2<=M,N<=36)
    下面的第一行输入一个数X，X是M进制的数，现在要求你将M进制的数X转换为N进制的数输出。
输出：
    输出X的N进制表示的数。
样例输入：
16 10
F
样例输出：
15
提示：
    输入时字母部分为大写，输出时为小写，并且有大数据

*************************************************************/
#include<stdio.h>
#include<string.h>
#define maxDigits 100
struct bigInteger{
    int digit[maxDigits];
    int size;
    void init(){
        for(int i=0;i<maxDigits;i++) digit[i] = 0;
        size = 0;
    }
    void set(int x){
        init();
        do{
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
        bigInteger ret;
        ret.init();
        int carry = 0;
        for(int i=0;i<size;i++){
            int tmp = x*digit[i]+carry;
            carry = tmp / 10000;
            tmp %= 10000;
            ret.digit[ret.size++]=tmp;
        }
        if(carry!=0)
            ret.digit[ret.size++] = carry;
        return ret;
    }
    bigInteger operator + (const bigInteger &A) const{
        bigInteger ret;
        ret.init();
        int carry = 0;
        for(int i=0;i<A.size || i<size;i++){
            int tmp = A.digit[i] + digit[i] + carry;
            carry = tmp / 10000;
            tmp %= 10000;
            ret.digit[ret.size++] = carry;
        }
        if(carry!=0)
            ret.digit[ret.size++]=carry;
        return ret;
    }
    bigInteger operator / (int x) const{
        bigInteger ret;
        ret.init();
        int remainder = 0; //余数
        for(int i=size-1;i>=0;i--){//从最高位至最低位依次完成运算
            int t = (remainder*10000+digit[i])/x;  //计算当前位数值加上高位剩余的余数的和对x求得的商
            int r = (remainder*10000+digit[i])%x;  //计算当前位数值加上高位剩余的余数的和对x求模后得的余数
            ret.digit[i] = t;  //保存本位的值
            remainder = r;  //保存至本位为止的余数
        }
        ret.size = 0;  //返回高精度整数的size初始值为0，即当所有位数字都为0时，digit[0]代表数字0，作为最高有效位，高精度整数即为数字0
        for(int i=0;i<maxDigits;i++){
            if(digit[i]!=0) ret.size = i;
        }
        ret.size++;  //最高有效位的下一位即为我们不曾使用的digit数组单元，确定为size的值
        return ret;
    }
    int operator % (int x) const{//高精度整数对不同整数求余数
        int remainder = 0; //余数
        for(int i=size-1;i>=0;i--){
            int t = (remainder*10000+digit[i])/x;
            int r = (remainder*10000+digit[i])%x;
            remainder = r;
        }
        return remainder;//返回余数
    }
}a,b,c;

char str[10000];
char ans[10000];
int main(){
    int n,m;
    while(scanf("%d%d",&m,&n)!=EOF){
        scanf("%s",str);  //输入m进制数
        int L = strlen(str);
        a.set(0);  //a的初始值为0，用来保存转换成10进制的m进制数
        b.set(1);   //b初始值为1，在m进制向10进制转换的过程中，依次代表每一位的权重
        for(int i=L-1;i>=0;i--){//由低位至高位转换m进制数至相应的十进制数
            int t;
            if(str[i]>='0' && str[i]<='9'){
                t = str[i]-'0';
            }
            else t = str[i]-'A'+10;
            a=a+b*t;//累加当前数字成当前位权重的积
            b=b*m;//计算下一位权重
        }
        int size = 0; //代表转换为n进制的字符个数
        do{
            int t = a%n; //求余数
            if(t>=10) ans[size++] = t - 10 + 'a';   //确定当前数位字符
            else ans[size++] = t + '0';
            a = a / n;
        }while(a.digit[0]!=0 || a.size!=1);  //当a不为0时重复
        for(int i=size-1;i>=0;i--) printf("%c",ans[i]);
        printf("\n");
    }
    return 0;
}




