#include "graph.h"
#include <iostream>
using namespace std;
#define maxSize 100
void printfPath(int path[],int a)
{
    int stack[maxSize],top=-1;
    //这个循环以由叶子节点到根结点的顺序将其入栈
    while(path[a]!=1)
    {
        stack[++top] = a;
        a = path[a];
    }
    stack[++top] = a;
    while(top!=-1)
        cout<<stack[top--]<<" ";    //出栈并打印栈元素，实现顶点的逆序打印、
    cout <<endl;
}

void Dijkstra(MGraph g, int v, int dist[], int path[])
{
    int set[maxSize];
    int min,i,j,u;
    //从这句开始对各数组进行初始化
    for(i=0;i<g.n;++i)
    {
        dist[i] = g.edges[v][i];
        set[i] = 0;
        if(g.edges[v][i]<INF)
            path[i] = v;
        else
            path[i] = -1;
    }
    //初始化结束
    //关键操作开始
}