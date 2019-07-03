/*************************************************************
题目描述：
    哈夫曼数，第一行输入一个数n，表示叶节点的数。需要用这些叶节点生成哈弗曼树，根据哈夫曼树的概念，这些结点有权值，即weight，
题目需要输出所有结点的值与权值的乘积之和。
输入：
    输入有多组数据。
    每组第一行输入一个数n，接着输入n个叶节点（叶节点权值不超过100，2<=n<=100）
输出：
    输出权值
样例输入：
5
1 2 2 5 9
样例输出：
37


*************************************************************/

#include<queue>
#include<stdio.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> >  Q; //建立一个小顶堆
int main()
{
    int n;
    while(scanf("%d",&n) != EOF){
        while(Q.empty() == false) Q.pop();  //清空堆中元素
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            Q.push(x);//将权值放入堆中
        }
        int ans = 0; //保存答案
        while(Q.size()>1){  //当堆中元素大于1个
            int a = Q.top();
            Q.pop();
            int b = Q.top();
            Q.pop();//取出堆中两个最小元素
            ans += a+b;//其父节点必为非叶子结点
            Q.push(a+b);//将双亲结点的权值放回堆中
        }
        printf("%d",ans);
    }


    return 0;
}




