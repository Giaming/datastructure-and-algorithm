/***********************************************************
题目描述：
    改变汉诺塔游戏的玩法，不允许直接从最左（右）边移动到最右（左）边（每次移动一定是移到中间杆或从中间移出），
也不允许大盘放到小盘的上面。Daisy已经做过原来的汉诺塔问题和汉诺塔II，但碰到这个问题时，他想了很久都不能解决,
现在请你帮组她。现在有N个圆盘，她至少多少次移动才能把这些圆盘从最左边移动到最右边。
输入：
    包含多组数据，每次输入一个N值(1<=N<=35)。
输出：
    对于每组数据，输出移动最小的次数。
样例输入和输出：
1
2
3
26
12
531440

**********************************************************/
#include<stdio.h>
#include<string.h>

long long F(int num){
    if(num==1) return 2;
    else return 3*F(num-1)+2;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",F(n));
    }
    return 0;
}



