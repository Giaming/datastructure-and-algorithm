/***************************************************
题目描述：
    实现一个加法器，使其能够输出a+b的值
输入：
    输入包括两个数a和b，其中a和b的尾数不超过1000位。
输出：
    可能有多组测试数据，对于每组数据，输出a+b的值。
样例输出：


样例输出：
2 6
8
100000000000000 1000000000000000000000000000000
1000000000000000100000000000000

**************************************************/
#include<stdio.h>
#include<string.h>

struct bigInteger{//高精度整数结构体
    int digit[1000];//按四位数一个单位保存数值
    int size;  //下一个我们未使用的数组单元
    void init(){
        for(int i=0;i<1000;i++) digit[i]=0;//所有位清0
        size = 0;
    }
    void set(char str[]){//从字符串中提取整数
        init();
        int L = strlen(str);
        //从最后一个字符开始倒序遍历字符串，
        //j控制每4个字符转换为一个数字存入数组，
        //t临时保存字符转换为数字的中间值，
        //c表示当前位的权重，按1,10,100,1000顺序变化
        for(int i=L-1,j=0,t=0,c=1;i>=0;i--){
            t += (str[i]-'0')*c;  //计算这四位数中当前字符代表的数字，即数字乘以当前位权重
            j++;//当前转换字符数增加
            c*=10;  //计算下一位权重
            if(j==4 || i==0){  //若已经连续转换四个字符，或则已经到达最后一个字符
                digit[size++]=t;  //将这四个字符代表的四位数存入数组，size移动到下一个数组单位
                j = 0;  //重新计算下4个字符
                t = 0;//临时变量清零
                c = 1;  //权重为1
            }
        }
    }
    void output(){//将该高精度整数输出
        for(int i=size-1;i>=0;i--){
            if(i!=size-1) printf("%04d",digit[i]);//若当前输出的数字不是最高位数字，用%04的输出前导0，即当前数字不足4位的时候有0补充，
            else printf("%d",digit[i]);//若是最高位，则无需输出前导零
        }
        printf("\n");
    }
    bigInteger operator + (const bigInteger &A) const{
        bigInteger ret;  //返回值，即两数相加的结果
        ret.init();
        int carry = 0; //进位，初始值为0
        for(int i=0;i<A.size || i<size;i++){
            int tmp = A.digit[i]+digit[i]+carry;//计算两个整数当前位以及来自低位的进位和
            carry = tmp / 1000;  //计算该位的进位
            tmp %= 10000;  //去除进位部分，取后四位
            ret.digit[ret.size++]=tmp;//保存该位结果
        }
        if(carry!=0){//计算结束后的最高位有进位
                ret.digit[ret.size++] = carry;  //保存该进位

        }
    return ret;
    }
}a,b,c;

char str1[1002],str2[1002];
int main(){
    while(scanf("%s%s",str1,str2)!=EOF){
        a.set(str1);b.set(str2);
        c=a+b;
        c.output();
    }
    return 0;
}





