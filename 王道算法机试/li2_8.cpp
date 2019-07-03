/********************************************
题目描述：
    把一个个大小差一圈的筐叠上去，使得从上往下看时，边筐花色交错。这个工作现在要让计算机来完成，得看你的了。
输入：
    输入是一个个的三元组，分别是，外筐尺寸n(n为满足0<n<80的奇整数)，中心花色字符，外筐花色字符，后二者都是
    ASCII可见字符。
输出：
    输出跌在一起的筐图案，中心花色与外筐花色字符从内层起交错相叠，多筐相叠时，最外筐的角总是被打磨掉。
    叠筐与叠筐之间应有一行间隔。
样例输入：
11 B A
5 @ W
样例输出：
11 B A
 AAAAAAAAA
ABBBBBBBBBA
ABAAAAAAABA
ABABBBBBABA
ABABAAABABA
ABABABABABA
ABABAAABABA
ABABBBBBABA
ABAAAAAAABA
ABBBBBBBBBA
 AAAAAAAAA

5 @ W

 @@@
@WWW@
@W@W@
@WWW@
 @@@



********************************************/

#include<stdio.h>

int main(){
    int OutPutBuf[82][82];//用于预排版的输出缓存
    int a,b;    //输入的两个字符
    int n; //叠筐大小
    bool firstCase = true;  //是否为第一组的数据标志，初始值为true
    while(scanf("%d %c %c",&n,&a,&b)== 3){  //scanf的返回值：成功赋值的数据项数
        if(firstCase==true){    //若是第一组数据
            firstCase = false;  //将第一组数据标志设置为false
        }
        else printf("\n");
        for(int i=1,j=1;i<=n;i+=2,j++){//从里至外输出每一个圈
            int x = n/2+1,y=x;
            x-=j-1;y-=j-1;//计算每个圈右上角点的坐标
            char c = j%2==1?a:b;//计算当前圈需要使用哪个字符
            for(int k=1;k<=i;k++){  //对当前圈赋值
                OutPutBuf[x+k-1][y]=c;//左边赋值
                OutPutBuf[x][y+k-1]=c;//上边赋值
                OutPutBuf[x+i-1][y+k-1]=c;//右边赋值
                OutPutBuf[x+k-1][y+i-1]=c;//下边赋值
            }
        }
        if(n!=1){
            OutPutBuf[1][1]=' ';
            OutPutBuf[n][1]=' ';
            OutPutBuf[1][n]=' ';
            OutPutBuf[n][n]=' ';    //将四角设置为空格
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf("%c",OutPutBuf[i][j]);
            }
            printf("\n");
        }//输出已将经过排版的在输出缓存中的数据
    }


    return 0;
}


