#include <stdio.h>
#include <malloc.h>
#include "graph.h"


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


