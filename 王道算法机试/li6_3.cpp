/*****************************************************
题目描述：
    大家一定觉得运动以后喝可乐是一件非常惬意的事情，但是seeyou却不这么人为。因为每次当seeyou
买了可乐之后，阿牛就要求和seeyou一起分享这一瓶可乐，而且一定要喝的喝seeyou一样多。但seeyou手中
只有两个杯子，它们的容量分别是N毫升和M毫升，可乐的体积为S(S<101)毫升（正好装满一瓶），它们三个
之间可以互相到可乐（都是没有刻度的，且S==N+M，101>S>0,N>0,M>0）。聪明的ACMER你们说他们能平分吗？
如果能请输出倒可乐的最少的次数，如果不能输出"NO"。
输入：
    三个整数:S可乐的体积，N和M是两个杯子的容量，以"0 0 0"结束.
输出：
    如果能够平分的话请输出最少要倒的次数，否则输出"NO"。
样例输入输出：
7 4 3
NO
4 1 3
3


*****************************************************/
#include<stdio.h>
#include<queue>
using namespace std;
struct N{
    int a,b,c;//每个杯子中可乐的体积
    int t;//得到该体积的倾倒次数
};
queue<N> Q;  //队列
bool mark[101][101][101];  //对体积组(x,y,z)进行标记，即只有第一次得到包含体积组(x,y,z)的状态为有效状态，其余的舍去

//有容积为sa的杯子倒往容积为sb的杯子，其中引用参数a和b，初始化为原始杯子中可乐的体积，当函数调用完毕后，为各自杯中的新体积
void AtoB(int &a,int sa,int &b,int sb){
    if(sb-b>=a){//若a可以全部倒入b中
        b+=a;
        a =0;
    }
    else{
        a -= sb-b;
        b = sb;
    }
}

int BFS(int s, int n, int m){
    while(Q.empty() == false){
        N now = Q.front();
        Q.pop();
        int a,b,c;  //a,b,c临时保存三个杯子中可乐体积
        a = now.a;
        b = now.b;
        c = now.c;
        AtoB(a,s,b,n);  //有a倾倒向b
        if(mark[a][b][c]==false){//若该体积组尚未出现
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t+1;
            if(a == s/2 && b == s/2) return tmp.t;
            if(c == s/2 && b == s/2) return tmp.t;
            if(a == s/2 && c == s/2) return tmp.t;  //若该状态已经为平分状态，则直接返回状态的耗时
            Q.push(tmp);  //否则放入队列
        }
        a = now.a;
        b = now.b;
        c = now.c;  //重置a,b,c为未倾倒前的体积
        AtoB(b,n,a,s);  //b倾倒向a
        if(mark[a][b][c]==false){
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t+1;
            if(a == s/2 && b == s/2) return tmp.t;
            if(c == s/2 && b == s/2) return tmp.t;
            if(a == s/2 && c == s/2) return tmp.t;  //若该状态已经为平分状态，则直接返回状态的耗时
            Q.push(tmp);  //否则放入队列
        }
        a = now.a;
        b = now.b;
        c = now.c;  //重置a,b,c为未倾倒前的体积
        AtoB(a,s,c,m);  //a倾倒向c
        if(mark[a][b][c]==false){
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t+1;
            if(a == s/2 && b == s/2) return tmp.t;
            if(c == s/2 && b == s/2) return tmp.t;
            if(a == s/2 && c == s/2) return tmp.t;  //若该状态已经为平分状态，则直接返回状态的耗时
            Q.push(tmp);  //否则放入队列
        }
        a = now.a;
        b = now.b;
        c = now.c;  //重置a,b,c为未倾倒前的体积
        AtoB(c,m,a,s);  //c倾倒向a
        if(mark[a][b][c]==false){
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t+1;
            if(a == s/2 && b == s/2) return tmp.t;
            if(c == s/2 && b == s/2) return tmp.t;
            if(a == s/2 && c == s/2) return tmp.t;  //若该状态已经为平分状态，则直接返回状态的耗时
            Q.push(tmp);  //否则放入队列
        }
        a = now.a;
        b = now.b;
        c = now.c;  //重置a,b,c为未倾倒前的体积
        AtoB(b,n,c,m);  //b倾倒向c
        if(mark[a][b][c]==false){
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t+1;
            if(a == s/2 && b == s/2) return tmp.t;
            if(c == s/2 && b == s/2) return tmp.t;
            if(a == s/2 && c == s/2) return tmp.t;  //若该状态已经为平分状态，则直接返回状态的耗时
            Q.push(tmp);  //否则放入队列
        }
        a = now.a;
        b = now.b;
        c = now.c;  //重置a,b,c为未倾倒前的体积
        AtoB(c,m,b,n);  //a倾倒向c
        if(mark[a][b][c]==false){
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t+1;
            if(a == s/2 && b == s/2) return tmp.t;
            if(c == s/2 && b == s/2) return tmp.t;
            if(a == s/2 && c == s/2) return tmp.t;  //若该状态已经为平分状态，则直接返回状态的耗时
            Q.push(tmp);  //否则放入队列
        }
    }
    return -1;  //否则返回-1
}

int main(){
    int s,n,m;
    while(scanf("%d%d%d",&s,&n,&m) != EOF){
        if(s==0) break;//若s为0，则n,m为0则退出
        if(s%2==1){  //若s为奇数则不可能平分，直接输出NO
            puts("NO");
            continue;
        }
        for(int i=0;i<=s;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k<=m;k++){
                    mark[i][j][k] = false;
                }
            }
        }
        N tmp;
        tmp.a = s;
        tmp.b = 0;
        tmp.c = 0;
        tmp.t = 0;
        while(Q.empty()==false) Q.pop();
        Q.push(tmp);
        mark[s][0][0] = true;  //标记初始状态
        int rec = BFS(s,n,m);
        if(rec==-1)
            puts("NO");
        else
            printf("%d\n",rec);
    }
    return 0;
}





