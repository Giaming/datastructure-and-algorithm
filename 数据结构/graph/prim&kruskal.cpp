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