/********************************************************
题目描述：
    题目大意为：有一个N*M的迷宫，包括起点S,终点D,墙X，和地面，0秒时主人公从S出发，每秒能走到四个与其相邻的位置中的一个，
且每个位置被行走之后都不能再次走入，问是否存在这样的一条路径使主人在T秒时刚好走到D。
输入：
    The input consists of multiple test cases. The first line of each test case contains
three integers N,M,and T(1<N,M<7;0<T<50),which denote the sizes of the maze and the time at
which the door will open,respectively.The next N lines give the maze layout, with each line
containing M charaters. A charactor is one of the following:
    'X': a block of wall,which the doggie cannot enter;
    'S': the start point of the doggie;
    'D': the Door; or
    '.': an empty block.
    The input is terminated with 0's. This test case is not to be processed.
输出：
    For each test case, print in one line "YES" if the doggie can survive, or "NO" otherwise.
样例输入和输出：
4 4 5
S.X.
..X.
..XD
....
NO
3 4 5
S.X.
..X.
...D
YES

********************************************************/
#include<stdio.h>
char maze[8][8];  //保存地图信息
int n,m,t; //地图大小为n*m,从起点到终点能否恰好t秒
bool success; //是否找到所需状态标记
int go[][2]={1,0,-1,0,0,1,0,-1};  //四方向行走坐标差
void DFS(int x,int y,int time){//递归形式的深度优先搜索
    for(int i=0;i<4;i++){//枚举四个相邻的位置
        int nx = x + go[i][0];
        int ny = y + go[i][1];  //计算其坐标
        if(nx<1||nx>n||ny<1||ny>m) continue;  //若坐标在地图外则跳过
        if(maze[nx][ny] == 'X') continue;  //若该位置为墙，则跳过
        if(maze[nx][ny]=='D'){//若该位置为们
            if(time+1==t){//若所用时间为t
                success = true;//搜索成功
                return;
            }
            else continue;  //否则该状态的后续状态不可能为答案（经过的点不能再经过)
        }
        maze[nx][ny] = 'X';  //该状态拓展而来的后续状态中，该位置都不能经过，直接修改该位置为墙
        DFS(nx,ny,time+1);  //递归拓展该状态，所用时间递增
        maze[nx][ny] = '.';  //若其后续状态全部遍历完，则退回上层状态，将因为要搜索其后续状态而改为墙的位置，改回普通位置
        if(success)  return;  //假如已经成功，停止搜索
    }
}

int main(){
    while(scanf("%d%d%d",&n,&m,&t)!=EOF){
        if(n==0&&m==0&&t==0) break;
        for(int i=1;i<=n;i++)
            scanf("%s",maze[i]+1);
        success = false;    //初始化标记
        int sx,sy;
        for(int i=1;i<=n;i++){//寻找D的位置
            for(int j=1;j<=m;j++){
                if(maze[i][j]=='D'){
                    sx = i;
                    sy = j;
                }
            }
        }
        for(int i=1;i<=n;i++){  //寻找初始状态
            for(int j=1;j<=n;j++){
                if(maze[i][j]=='S' && (i+j)%2==((sx+sy)%2+t%2)%2){//找到S点后，先判断S和D的奇偶性关系，是否和t符合
                    maze[i][j] = 'X';  //将起点标记为墙
                    DFS(i,j,0);   //递归拓展初始状态
                }
            }
        }
        puts(success==true?"YES":"NO");
    }
    return 0;
}


