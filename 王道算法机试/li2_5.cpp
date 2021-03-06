/*******************************************
题目描述：
  读入N名学生的成绩，将获得某一给定分数的学生人数输出。
输入：
  测试输入包含若干测试用例，每个测试用例的格式为
  第1行：N
  第2行：N名学生的成绩，相邻两数字用一个空格间隔
  第3行：给定分数
  当读到N=0时输入结束。其中N不超过1000，成绩分数为（包含）0到100之间的一个整数。
输出：
  对每个测试用例，将获得给定分数的学生人数输出。
样例输入：
3
80 60 90
60
2
85 66
0
5
60 75 90 55 75
75
0
样例输出：
1
0
2

*******************************************/

#include<stdio.h>

int main(){
    int n;
    while(scanf("%d",&n)!=EOF && n!=0){
        int Hash[101] = {0};    //建立一个初始为0的Hash数组用来记录各种分数出现的次数
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            Hash[x]++;
        }
        int x;
        scanf("%d",&x);
        printf("%d\n",Hash[x]);//得到需要查询的目标分数后，只需要简单的查询我们统计的数量即可。
    }
    return 0;
}





