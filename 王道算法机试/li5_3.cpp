/************************************************************
题目描述：
    某省调查乡村交通状况，得到的统计表中列出了任意两个乡村间的距离。省政府“畅通工程”的目标是使全省任何两个
村庄间都可以实现公路交通（但不一定有直接的公路相连，只要间接相连即可），并要求铺设的公路总长度为最小。请计算
最小的公路总长度。
输入：
    测试输入包含若干个测试用例。每个测试用例的第一行给出村庄数目N(<100)；随后的N(N-1)/2行对应村庄间的距离，每行给出一对正整数，
分别是两个村庄的编号，以及2村庄之间的距离。为简单起见，村庄从1到N编号。当N为0时，输入结束，该用例不用处理。
输出：
    对每个测试用例，在1行中输出最小的公路总长度.
样例输入和输出：
3
1 2 1
1 3 2
2 3 4
3
4
1 2 1
1 3 4
1 4 1
2 3 3
2 4 2
3 4 5
5
***********************************************************/
#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 101
int Tree[N];
int findRoot(int x){
    if(Tree[x]==-1) return x;
    else{
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

struct Edge{
    int a,b;  //边的两个顶点的编号
    int cost;
    bool operator < (const Edge &A) const{//重载小于号使其可以按照边权值从小到大排列
        return cost < A.cost;
    }
}edge[6000];

int main(){
    int n;
    while(scanf("%d",&n)!=EOF && n!=0){
        for(int i=1;i<= n*(n-1)/2;i++)
            scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].cost);
        sort(edge+1,edge+1+n*(n-1)/2);  //按照边权值地政排列所有的边
        for(int i=1;i<=n;i++)
            Tree[i] = -1; //初始时所有的结点都属于孤立的集合
        int ans = 0;
        for(int i=1;i<=n*(n-1)/2;i++){  //按照边权值递增排列所有的边
            int a = findRoot(edge[i].a);
            int b = findRoot(edge[i].b);//查找两个顶点的集合信息
            if(a!=b){
                Tree[a] = b;
                ans += edge[i].cost;  //累加边权值
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}





