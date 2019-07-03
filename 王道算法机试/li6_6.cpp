/********************************************************
题目大意：
    在给定的n*m图中，确定有几个@的块。块符合以下条件，其中的任意对@均相互直接或间接联通，
两个@直接相邻或者间接相邻即被视为连通
输入：
    THe input file contains one or more grids.Each grid begins with a line containing m and n, the number of rows and columns in the grid,
separated by a single space.If m=0 it signals the end of the input;otherwise 1<=m<=100 and 1<=n<=100.Following this are m lines of n characters
corresponds to one plot, and is either '*',representing the absence of oil, or '@',representing an oil pocket.
输出：
    For each grid, output the number of distinct oil deposits. Two diffrent pockets are part of the same oil deposit if they are adjacent horizonlly, vertically,
or diagonally. An oil deposit will not contain more than 100 pockets.
样例输入输出：
1 1
*
0
3 5
*@*@*
**@**
*@*@*
1
1 8
@@****@*
2
5 5
****@
*@@*@
*@*@*
@@@*@
@@**@
4
********************************************************/
#include<stdio.h>
char maze[101][101];  //保存地图信息
bool mark[101][101];  //为图上每一个点设立一个状态
int n,m;  //地图大小为n*m
int go[][2] = {1,0,
              -1,0,
               0,1,
               0,-1,
               1,1,
               1,-1,
               -1,-1,
               -1,1};  //八个相邻点与当前位置的坐标差

void DFS(int x, int y){//递归遍历所有与x，y直接或间接相邻的@
    for(int i=0;i<8;i++){//遍历八个相邻点
        int nx = x + go[i][0];
        int ny = y + go[i][1];  //计算其坐标
        if(nx<1|| nx>n || ny<1 || ny>m) continue; //若该坐标在地图外
        if(maze[nx][ny] == '*') continue;  //若该位置不是'@'
        if(mark[nx][ny]==true) continue;  //若该位置已经被计算过
        mark[nx][ny] = true;  //标记该位置为已经计算
        DFS(nx,ny);  //递归查询与该相邻位置直接相邻的点
    }

}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0 && m==0) break;
        for(int i=1;i<=n;i++){
            scanf("%s",maze[i]+1);//第i行地图信息保存在maze[i][1]到maze[i][m]中
        }
        int ans = 0;  //初始化计数器
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){  //按顺序遍历图中的位置
                if(mark[i][j]==true) continue; //若该位置已经被处理，跳过
                if(maze[i][j]=='*') continue; //若该位置不为@,跳过
                DFS(i,j); //递归遍历与其直接或间接相邻的@
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}



