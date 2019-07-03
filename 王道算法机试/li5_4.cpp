/************************************************************
题目描述：
    In a episode of the Dick Van Dyke show, little Richie connects the freckles on his Dad's back to form a picture
of the Liberty Bell.Alas, one of the freckles turns out to be a scar,so his Ripley's engagement falls through. Consider
Dick's back to be a plane with freckles at various(x,y)locations. Your job is to tell Richie how to connect the dots so
as to minimize the amount of ink used. Richie connects the dots by drawing straight lines between pairs, possibly lifting
the pen between lines. When Richie is done there must be a sequence of connnected lines from any freckle to any other freckle.
大意：平面上有若干个点，我们需要用一些线段来讲这些点连接起来使任意两个点能够通过一系列的线段相连，给出所有点的坐标，
求一种连接方式使所有线段的长度和最小，求长度之和。
输入：
    The first line contains 0<n<=100, the number of freckles on Dick's back.
For each freckle, a line follows; each following line contains two real numbers
indicating the (x,y) coordinates of the freckle.
输出：
    Your program prints a single real number to two decimal places: the minimum total length of ink lines that can connect all
the freckles.
样例输入和输出：



************************************************************/
#include<stdio.h>
#include<math.h>
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
    int a,b;
    double cost; //权值变为长度，故改用浮点数
    bool operator < (const Edge &A) const{
        return cost < A.cost;
    }
}edge[6000];
struct Point{
    double x,y;  //点的两个坐标值
    double getDistance(Point A){//计算两个点的距离
        double tmp = (x - A.x)*(x - A.x) + (y - A.y)*(y-A.y);
        return sqrt(tmp);
    }
}list[101];

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++)  //输入
            scanf("%lf%lf",&list[i].x,&list[i].y);
        int size = 0;  //抽象出边的总数
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++){  //连接两点的线段抽象成边
                edge[size].a = i;
                edge[size].b = j;  //该边的两个顶点编号
                edge[size].cost = list[i].getDistance(list[j]);//边权值为两点之间的距离
                size ++;  //变得总数加一
            }
        sort(edge,edge+size);  //对边权值递增排序
        for(int i=1;i<=n;i++)
            Tree[i] = -1;
        double ans = 0;
        for(int i=0;i<size;i++){
            int a = findRoot(edge[i].a);
            int b = findRoot(edge[i].b);
            if(a!=b){
                Tree[a]=b;
                ans += edge[i].cost;
            }
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}






