#include <stdio.h>
#include <malloc.h>
#include "graph.h"
#define maxSize 100


void Prim(MGraph g, int v)
{
    int lowcost[MAXV];   //最小边的权值
    int MIN;
    int closest[MAXV],k;
    //给lowcost[]和closest[] 赋权值
    for(int i=0;i<g.n;i++){
        lowcost[i] = g.edges[v][i];
        closest[i] = v;
    }
    //找出（n-1）个顶点
    for(int i=1;i<g.n;i++){
        MIN = INF;
        for(int j=0;j<g.n;j++){   //在U-V中找出离U最近的顶点k
            if(lowcost[j]&&lowcost[j]<MIN){
                MIN = lowcost[j];
                k = j;      //k记录最近顶点的编号
            }
        }
        printf("边(%d,%d)权为：%d\n",closest[k],k,MIN);    //输出最小生成树的一条边
        lowcost[k] = 0;    //标记k已经加入U
        for(int j=0;j<g.n;j++){   //对(V-U)中的顶点j进行调整
            if(lowcost[j]!=0&&g.edges[k][j]<lowcost[j])
            {
                lowcost[j] = g.edges[k][j];
                closest[j] = k;   //修改数组lowcost和closest
            }
        }
    }
}



// 执行过程：
// 1. 将v0到其他顶点的所有边当作侯选边
// 2. 重复以下步骤n-1次，使得其他n-1个顶点被并入到生成树中。
//     1）从侯选边中挑选出权值最小的边输出，并将与该边另一端相接的顶点v并入生成树中；
//     2）考查所有剩余顶点vi；如果(v,vi)的权值比lowcost[vi]小，则用(v,vi)的权值更新lowcast[vi].alignas


void prim(MGraph g, int v0, int &sum)
{
    int lowcost[maxSize],vset[maxSize],v;
    int i,j,k,min;
    v = v0;
    for(i=0;i<g.n;++i)     //初始化操作
    {
        lowcost[i] = g.edges[v0][i];//将与v0相邻的边的权值加入到lowcost数组
        vset[i] = 0;
    }
    vset[v0] = 1;   //将v0并入树中
    sum = 0;//sum清零用来累计树的权值
    for(i=0;i<g.n-1;++i)     //循环执行n-1次
    {
        min = INF;  
        //下面这个循环用于选出侯选边的最小者
        for(j=0;j<g.n;++j)
        {
            if(vset[j]==0&&lowcost[j]<min)
            {
                min = lowcost[j];
                k = j;
            }
        }
        vset[k] = 1;
        v = k;
        sum += min;   //这里用sum记录了最小生成树的权值
        //下面这个循环以刚并入的顶点v为媒介更新侯选边
        for(j=0;j<g.n;++j)
            if(vset[j]==0&&g.edges[v][j]<lowcost[j])    //执行的是过程中的第2）步
                lowcost[j] = g.edges[v][j];
    }
}


//kruskal算法
// 1. 建立一个v[i]数组表示当前顶点i的双亲（若v[i]=i表示此顶点为根），初始化使全部v[i] = i;
// 2. 对边按权值排序后，从最小的边开始，依从小到大判断其所连的两个顶点a和b的根，直至判断完所有的边：
//     1）若a和b根使同一个，则表示并入边ab会构成回路，跳过，继续判断下一边
//     2）若他们所连的根不同，则令v[a]=b,并入边ab

typedef struct 
{
    int a,b;   //a和b为一条边所连的两个顶点
    int w;//边的权值
}Road;
Road road[maxSize];
int v[maxSize];     //定义并查集数组
int getRoad(int a) //在并查集中查找根结点的函数
{
    while(a!=v[a]) a=v[a];     //一直往上查找，就能够找到根
    return a;
}

void Kruskal(MGraph g, int &sum, Road road[])
{
    int i;
    int N,E,a,b;
    N = g.n;
    E = g.e;
    sum = 0;
    for(i=0;i<N;++i) v[i]=i;
    sort(road,E);    //对road数组中的E条边按其权值从小到大进行排序
    for(i=0;i<E;++i)
    {
        a = getRoot(road[i].a);
        b = getRoot(road[i].b);
        if(a!=b)
        {
            v[a] = b;
            sum += road[i].w;       //求生成树的权值，这句并不是本算法的固定写法。
        }
    }
    
}


