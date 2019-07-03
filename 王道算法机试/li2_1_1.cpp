/******************************************
题目描述：
对输入的n个数进行排序并输出。
输入：
输入的第一行包括一个整数n(1<=n<=100)。接下来的一行包括n个整数。
输出：
可能有多组测试数据，对于每组数据，将排序后的n个整数输出，每个数后面都有一个空格。每组测试数据的结果占一行。
样例输入：
4
1 4 3 2
样例输出：
1 2 3 4

********************************************/

#include<stdio.h>

int main()
{
    int n;
    int buf[100];   //定义将要使用的变量n,并用buf[100]来保存将要排序的数字
    while(scanf("%d",&n) != EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&buf[i]);    //输入待排序数字
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(buf[j]>buf[j+1]){
                    int tmp = buf[j+1];
                    buf[j+1] = buf[j];
                    buf[j] = tmp;
                }
            }
        }//冒泡排序主体
        for(int i=0;i<n;i++){
            printf("%d ",buf[i]);
        }//输出完成排序后的数字
        printf("\n");
    }
    return 0;
}
