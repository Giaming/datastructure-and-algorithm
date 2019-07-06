#include <stdio.h>
#include <malloc.h>
#include "graph.h"

/************************************
 *  不带权图的算法
 * ***********************************/
 //将邻接矩阵g转换成邻接表G
 void MatToList(MGraph g, ALGraph *&G)
 {
     int i,j;
     ArcNode *p;
     G = (ALGraph *)malloc(sizeof(ALGraph));
     //给邻接表中所有头结点的指针域置初值
     for(i=0;i<g.n;i++)
         G->adjlist[i].firstarc = NULL;
     //检查邻接矩阵中的每一个元素
     for(i=0;i<g.n;i++){
         for(j=g.n-1;j>=0;j--){
             if(g.edges[i][j]!=0){  //邻接矩阵的当前元素不为0
                p =(ArcNode *)malloc(sizeof(ArcNode));    //创建一个节点*p
                p->adjvex = j;   //存放相邻接点
                p->nextarc = G->adjlist[i].firstarc;   //采用头插法插入结点p
                G->adjlist[i].firstarc = p;
             }
         }
     }
     G->n = g.n;G->e = g.e;
}

//将邻接表G转换成邻接矩阵g
void ListToMat(ALGraph *G, MGraph &g){
    int i,j;
    ArcNode *p;
    for(i=0;i<G->n;i++){
        for(j=0;j<G->n;j++){
            g.edges[i][j] = 0;    //赋初值
        }
    }
    for(i=0;i<G->n;i++){
        p = G->adjlist[i].firstarc;
        while(p!=NULL){
            g.edges[i][p->adjvex] = 1;
            p = p->nextarc;
        }
    }
    g.n = G->n; g.e = G->e;
}
 
 
 //输出邻接矩阵g
 void DispMat(MGraph g){
     for(int i=0;i<g.n;i++){
         for(int j=0;j<g.n;j++){
             printf("%3d",g.edges[i][j]);
         }
         printf("\n");
     }
 }
 
 //输出邻接表G
 void DispList(ALGraph *G){   //这里为什么要用指针，是指向头结点的第一个结点的位置
     ArcNode *p;
     for(int i=0;i<G->n;i++){
         p = G->adjlist[i].firstarc;
         printf("%3d",i);
         while(p!=NULL){
             printf("%3d",p->adjvex);
             p = p->nextarc;
         }
         printf("\n");
     }
 }


 
/************************************
 *  带权图的算法
 * ***********************************/
 //将邻接矩阵转换为邻接表G
 void MatToList1(MGraph g, ALGraph *&G){
     ArcNode *p;
     G = (ALGraph*)malloc(sizeof(ALGraph));
     for(int i=0;i<g.n;i++){
         G->adjlist[i].firstarc = NULL;
     }
     for(int i=0;i<g.n;i++){
         for(int j=g.n-1;j>=0;j--){
             if(g.edges[i][j]!=0&&g.edges[i][j]!=INF){
                 p = (ArcNode*)malloc(sizeof(ArcNode));
                 p->adjvex = j;
                 p->info = g.edges[i][j];
                 p->nextarc = G->adjlist[i].firstarc;
                 G->adjlist[i].firstarc  = p;
             }
         }
     }
     G->n = g.n; G->e = g.e;
 }
 
 // 将邻接表转换为邻接矩阵g
 void ListToMat1(ALGraph *G, MGraph &g){
     ArcNode *p;
     for(int i=0;i<G->n;i++){
         for(int j=0;j<G->n;j++){
             //初始化邻接矩阵
             if(i==j)
                g.edges[i][j] = 0;
            else 
                g.edges[i][j]  = INF;
         }
     }
     for(int i=0;i<G->n;i++){
        p = G->adjlist[i].firstarc;
        while(p!=NULL){
            g.edges[i][p->adjvex] = p->info;
            p = p->nextarc;
        }
     }
     g.n = G->n; g.e = G->e;
 }
 
 
  //输出邻接矩阵g1
 void DispMat1(MGraph g){
     for(int i=0;i<g.n;i++){
         for(int j=0;j<g.n;j++){
            if(g.edges[i][j]==INF)
                printf("%5s","oo");
            else
                printf("%5d",g.edges[i][j]);
         }
         printf("\n");
     }
 }
 
 //输出邻接表G1
 void DispList1(ALGraph *G){   //这里为什么要用指针，是指向头结点的第一个结点的位置
     ArcNode *p;
     for(int i=0;i<G->n;i++){
         p = G->adjlist[i].firstarc;
         printf("%3d",i);
         while(p!=NULL){
             printf("%3d(%d)",p->adjvex,p->info);
             p = p->nextarc;
         }
         printf("\n");
     }
 }


int main1(){
    int i,j;
    MGraph g,g1;
    ALGraph *G;
    int A[MAXV][6] = {{0,5,INF,7,INF,INF},{INF,0,4,INF,INF,INF},{8,INF,0,INF,9},{INF,INF,5,0,INF,6},{INF,INF,INF,5,0,INF},{3,INF,INF,INF,1,0}};
    g.n = 6;g.e = 10;
    for(i=0;i<g.n;i++){
        for(j=0;j<g.n;j++){
            g.edges[i][j] = A[i][j];
        }
    }
    printf("有向图的邻接矩阵：\n");
    DispMat(g);
    G = (ALGraph *)malloc(sizeof(ALGraph));
    printf("邻接矩阵转为邻接表：\n");
    MatToList1(g,G);
    DispList1(G);
    return 0;
}

/*********************************************
 * 
 * 以下算法实现图的深度优先遍历和广度优先遍历
 * 
 * ********************************************/

//定义全局数组
int visited[MAXV];   //里面的元素自动初始化为0

//递归深度优先遍历
void DFS(ALGraph *G, int v){   //采用的是邻接表的方法存储
    ArcNode *p;
    visited[v] = 1;
    printf("%3d",v);
    p = G->adjlist[v].firstarc;  //p指向顶点v的第一条边头结点
    while(p!=NULL){
        if(visited[p->adjvex]==0)
            DFS(G,p->adjvex);
        p = p->nextarc;
    }
}

//非递归深度优先遍历
void DFS1(ALGraph *G, int v){   
    ArcNode *p;
    ArcNode *St[MAXV];
    int top = -1,w;     //使用栈来实现
    for(int i=0;i<G->n;i++){
        visited[i] = 0;     //初始化顶点标志
    }
    printf("%3d",v);   // 访问结点v
    visited[v] = 1;
     //将顶点v的第一个相邻结点进栈
    St[top++] = G->adjlist[v].firstarc;
    //栈不空时循环
    while(top>-1){
        p = St[top--];    //出栈一个顶点作为当前节点
        while(p!=NULL){
            w = p->adjvex;
            if(visited[w]==0){
                printf("%3d",w);  //访问w
                visited[w] = 1;
                //访问完后进栈
                St[top++] = G->adjlist[w].firstarc;
                break;     //退出循环
            }
            p = p->nextarc;   //找下一个相邻结点
        }
    }
    printf("\n");
}

//广度优先遍历
void BFS(ALGraph *G, int v){
    ArcNode *p;
    int queue[MAXV],front=0,rear=0;
    int visited[MAXV];
    for(int i=0;i<G->n;i++) visited[i] = 0;
    printf("%3d",v);
    visited[v] = 1;
    rear = (rear+1)%MAXV;
    queue[rear] = v;   //v进队
    //若队列不空时循环
    while(front!=rear){
        front = (front+1)%MAXV;
        int w = queue[front];   //出队
        p = G->adjlist[w].firstarc;    //找与顶点w邻接的第一个顶点
        while(p!=NULL){
            if(visited[p->adjvex]==0){    //若当前节点未被访问
                printf("%3d",p->adjvex);
                visited[p->adjvex] = 1;
                rear = (rear+1)%MAXV;
                queue[rear] = p->adjvex;   //该顶点进队
            }
            p = p->nextarc;    //找下一个邻接顶点
        }
    }
    printf("\n");
}

int main2(){
    int i,j;
    MGraph g;
    ALGraph *G;
    int A[MAXV][6] = {{0,5,INF,7,INF,INF},{INF,0,4,INF,INF,INF},{8,INF,0,INF,9},{INF,INF,5,0,INF,6},{INF,INF,INF,5,0,INF},{3,INF,INF,INF,1,0}};
    g.n = 6;g.e = 10;
    for(i=0;i<g.n;i++){
        for(j=0;j<g.n;j++){
            g.edges[i][j] = A[i][j];
        }
    }
    G = (ALGraph *)malloc(sizeof(ALGraph));
    MatToList1(g,G);
    printf("图G的邻接表:\n");
    DispList1(G);
    printf("从顶点0开始的DFS（递归算法):\n");
    DFS(G,0); printf("\n");
    printf("从顶点0开始的DFS（非递归算法):\n");
    DFS1(G,0); printf("\n");
    printf("从顶点0开始的BFS（非递归算法):\n");
    BFS(G,0); printf("\n");
    return 0;
}

 
