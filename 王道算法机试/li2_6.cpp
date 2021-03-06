/**************************************************
题目描述：
    给你n个整数，请按从大到小的顺序输出其中前m大的数。
输入：
    每组测试数据有两行，第一行有两个数n,m(0<n,m<1000000),
    第二行包含n个各不相同，且都处于区间[-500000,500000]的整数。
输出：
    对每组测试数据按从大到小的顺序输出前m大的数。
样例输入：
5 3
3 -35 92 213 -644
213 92 3

**************************************************/

#include<stdio.h>
#define OFFSET 500000   //偏移量，用于补偿实际数字和数组下标之间的便宜
int Hash[1000000];  //Hash数组，记录每个数字是否出现，不出现为0，出现被标记为1

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m) != EOF){
        for(int i=-500000;i<=500000;i++){
            Hash[i+OFFSET] = 0;
        }//初始化，将每个数组都标记为未出现
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            Hash[x+OFFSET] = 1; //凡是出现过的数字，该数组的元素均被设置成1
        }
        for(int i=500000;i>=-500000;i--){   //输出前m个数
            if(Hash[i+OFFSET]==1){
                printf("%d",i);//输出该数字
                m--;
                if(m!=0) printf(" ");
                else{
                    printf("\n");
                    break;
                }
            }

        }
    }
    return 0;
}

