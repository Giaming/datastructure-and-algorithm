typedef int InfoType;
#define MAXV 100
#define INF 32767
//以下定义邻接矩阵类型
typedef struct{
    int no;  //编号
    InfoType info;  //顶点信息
}VertexType;  //顶点类型

typedef struct{
    int edges[MAXV][MAXV];  //邻接矩阵
    int n,e;  //顶点数，边数
    VertexType ves[MAXV];    //存放顶点信息
}MGraph;

//以下定义邻接表类型
//定义的是两类结点，一个是头结点，另一个是边结点
//边结点
typedef struct ANode{
    int adjvex;    //该边的终点位置，记录编号
    struct ANode *nextarc;  //指向吓一条边的指针
    InfoType info;  //用于存放权值
}ArcNode;

//定义头结点
typedef int Vertex;
typedef struct Vnode{   //邻接表头结点的类型
    Vertex data;  //顶点信息
    ArcNode *firstarc;     //指向第一条边
}VNode;

//定义邻接表
typedef VNode AdjList[MAXV];    //AdjList 是邻接表类型
typedef struct
{
    AdjList adjlist;   //邻接表
    int n,e;    //图中的顶点数n和边数e
}ALGraph;      //图的邻接表类型
