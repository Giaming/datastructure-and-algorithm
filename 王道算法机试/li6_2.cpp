/***********************************************
题目描述：
    Ignatius被魔王抓走了，有一天魔王出差去了，这可是Ignatius逃亡的好机会。魔王住在一个城堡里，城堡是一个A*B*C的立方体，可以被表示成
A个B*C的矩阵，刚开始Ignatius被关在（0,0,0）的位置，离开城堡的门在（A-1，B-1，C-1）的位置，现在知道魔王将在T分钟之后回到城堡，Ignatius
每分钟能够从一个坐标走到相邻的六个坐标中的其中一个。现在给你城堡的地图，请你计算出Ignatius能够在魔王回来前离开城堡（只要走到出口就算离开城堡，
如果走到出口的时候魔王刚好回来也算逃脱成功），如果可以请输出需要多少分钟才能离开，如果不能则输出-1.
输入：
    输入数据的第一行是一个正整数K，表明测试数据的数量。每组测试数据的第一行是四个正整数A,B,C和T（1<=A,B,C<=50,1<=T<=1000）,它们分别代表城堡的
大小和魔王回来的时间，然后是A块输入数据（显示第0块，然后是第一块，第二块，...），每块输入数据有B行，每行有C个正整数，代表迷宫的布局，其中0代表路
，1代表墙。
输出：
    对于每组测试数据，如果Ignatius能够在魔王回来前离开城堡，那么请输出他最少需要多少分钟，否则输出-1.
样例输入输出：
1
3 3  4 20
0 1 1 1
0 0 1 1
0 1 1 1
1 1 1 1
1 0 0 1
0 1 1 1
0 0 0 0
0 1 1 0
0 1 1 0
11

***********************************************/
#include<stdio.h>
#include<queue>
using namespace std;
bool mark[50][50][50];  //标记数组
int maze[50][50][50];  //保存立方体信息
struct N{//状态结构体
    int x,y,z;
    int t;
};

queue<N> Q;  //队列中的元素为状态
int go[][3] = {//坐标变换数组，有坐标(x,y,z)扩展得到的新坐标均可通过(x+g0[i][0],y+go[i][1],z+go[i][2])得到
    1,0,0,
    -1,0,0,
    0,1,0,
    0,-1,0,
    0,0,1,
    0,0,-1
};
int BFS(int a,int b,int c){
    while(Q.empty()==false){
        N now = Q.front();  //得到队头状态
        Q.pop();
        for(int i=0;i<6;i++){//依次拓展其六个点
            int nx = now.x + go[i][0];
            int ny = now.y + go[i][1];
            int nz = now.z + go[i][2];
            if(nx<0||nx>=a||ny<0||ny>=b||nz<0||nz>=c)   continue;   //若新坐标在立方体外，则丢弃该坐标
            if(maze[nx][ny][nz]==1) continue;   //若该位置为墙，则丢弃改坐标
            if(mark[nx][ny][nz]==true) continue;  //若包含改坐标的状态已经得到过，则丢弃该状态
            N tmp;  //新的状态
            tmp.x = nx;
            tmp.y = ny;
            tmp.z = nz;
            tmp.t = now.t + 1;  //新状态的耗时
            Q.push(tmp);  //将新状态放入队列
            mark[nx][ny][nz] = true;  //标记该坐标
            if(nx == a-1 && ny==b-1 && nz==c-1) return tmp.t;
        }
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int a,b,c,t;
        scanf("%d%d%d%d",&a,&b,&c,&t);
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
                for(int k=0;k<c;k++){
                    scanf("%d",&maze[i][j][k]);
                    mark[i][j][k] = false;
                }
        while(Q.empty() ==false)    Q.pop();  //清空队列
        mark[0][0][0] = true;   //标记起点
        N tmp;
        tmp.t = tmp.y = tmp.x = tmp.z = 0;  //初始状态
        Q.push(tmp);   //将初始状态放入队列
        int rec = BFS(a,b,c);
        if(rec <= t) printf("%d\n",rec);
        else    printf("-1\n");
    }
    return 0;
}

