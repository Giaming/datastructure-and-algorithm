/********************************************
题目描述:
  FatMouse prepared M pounds of cat food,ready to trade with the cats guarding
the warehouse containing his favorite food,JavaBean.
  The warehouse has N rooms. The i-th room contains J[i] pounds of JavaBeans and requires
F[i] pounds of cat food. FatMouse does not have to trade for all the JavaBeans in the room,
instead , he may get J[i]*a% pounds of JavaBeans if he pays F[i]*a% pounds of JavaBeans if he pays
F[i]*a% pounds of cat food. Here a is a real number. Now he is assigning this homework to you:
tell him the maximum amount of JavaBeans he can obtain.
输入：
    The input consists of multiple test cases. Each test case begins with a line containing two
non-negative integers M and N. The N lines follow, each contains two non-negative integers J[i]
and F[i] respectively. The last test case is followed by two-1's, All integers are not greater than 1000.
输出：
  For each test case, print in a single line a real number accurate up to 3 decimal places,which is the maximum
amount of JavaBeans that FatMouse can obtain.
样例输入：
5 3
7 2
4 3
5 2
20 3
25 18
24 15
15 10
-1 -1
样例输出：
13.333
31.500

********************************************/
#include<stdio.h>
#include<algorithm>
using namespace std;
struct goods{//表示可买物品的结构体
    double j;   //该物品总重
    double f;   //该物品总价值
    double s;   //该物品性价比
    bool operator < (const goods &A) const {
        return s > A.s;
    }
}buf[1000];

int main(){
    double m;
    int n;
    while(scanf("%lf%d",&m,&n) != EOF){
        if(m==-1 && n==-1) break;   //当n==-1时跳出循环，程序运行结束
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&buf[i].j,&buf[i].f);//输入
            buf[i].s = buf[i].j/buf[i].f;//计算性价比
        }
        sort(buf,buf+n);
        int idx = 0;//当前货物下标
        double ans = 0;//累加所能得到的总重量
        while(m>0&&idx<n){//循环条件为：既有物品剩余还有钱剩余时继续循环
                if(m>buf[idx].f){
                    ans += buf[idx].j;
                    m -= buf[idx].f;
                }//若能买下全部该物品
                else{
                    ans += buf[idx].j*m/buf[idx].f;
                    m=0;
                }//若只能买下部分该物品
                idx++;
        }
        printf("%.3lf\n",ans);//输出
    }
    return 0;
}













