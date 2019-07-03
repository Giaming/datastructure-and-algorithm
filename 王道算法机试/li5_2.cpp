/******************************************************
题目描述：
    有10000000个小朋友，他们之中有N对好朋友，且朋友关系具有传递性：若A与B是朋友，B与C是朋友，那么他们也认为A与C是好朋友。
在给出的这N对朋友关系后，要求我们找出一个最大（人数最多）的集合，该集合中任意两人之间都是朋友关系或者该集合中只有一个人，
输出该最大人数。
样例输入：
    The first line of the input contains an integer n(0<=n<=100 000)-the number of direct friend-pairs.The following n lines each
contains a pair of numbers A and B separated by a single space that suggests A and B are direct friends.(A!=B,1<=A,B<=10000000)
输出：
    The output in one line contains exactly one integer equals to the maximum number of boys Mr. Wang may keep.
样例输入和输出：
4
1 2
3 4
5 6
1 6
4
4
1 2
3 4
5 6
7 8
2

*******************************************************/
#include<stdio.h>
using namespace std;
#define N 10000001    //下标0不存元素
int Tree[N];

int findRoot(int x){
    if(Tree[x]==-1) return x;
    else{
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

int sum[N];  //用sum[i]表示以结点i为根的树的结点个数，其中保存数据仅当Tree[i]为-1即该节点为树的根结点时有效
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<N;i++){//初始化结点信息
            Tree[i] = -1;
            sum[i] = 1;  //所有集合的元素个数为1
        }
        while(n--!=0){//循环输入n行，构建并查集
            int a,b;
            scanf("%d%d",&a,&b);
            a = findRoot(a);
            b = findRoot(b);
            if(a!=b){
                Tree[a] = b;
                sum[b]+=sum[a];//合并两集时，将成为子树的树的根结点上保存的该集合元素个数的数字累加到合并后新的树的树根
            }
        }
        int ans = 1;  //答案至少为1，故在这里先初始化为1
        for(int i=1;i<=N;i++){
            if(Tree[i]==-1 && sum[i]>ans) ans = sum[i];  //统计最大值
        }
        printf("%d\n",ans);
    }
    return 0;
}







