/**********************************************************
题目描述：
    给定一棵二叉树的前序遍历和中序遍历，给出其后序遍历的输出序列。
输入：
    两个字符串，其长度n均小于等于26
    第一行为前序遍历，第二行为中序遍历，二叉树结点的名称以大写字母ABC表示。
输出：
    输入样例可能有多组，对于每组测试样例，输出一行。
样例输入：
ABC
BAC
FDXEAG
XDEFAG
样例输出：
BCA
XEDGAF


*********************************************************/
#include<stdio.h>
#include<string.h>
struct Node{//树结点结构体
    Node *lchild;
    Node *rchild;
    char c;
}Tree[50];//静态内存分配数组
int loc;  //静态数组中已经分配的结点个数
Node *creat(){//申请一个结点空间，返回指向其的指针
    Tree[loc].lchild = Tree[loc].rchild=NULL;//初始化左右儿子为空
    return &Tree[loc++];//返回指针，且loc累加
}
char str1[30],str2[30];  //保存前序和中序遍历结果字符串

//后序遍历
void postOrder(Node *T){
    if(T->lchild != NULL)
        postOrder(T->lchild);//递归遍历左子树
    if(T->rchild != NULL)
        postOrder(T->rchild);
    printf("%c",T->c);//遍历根节点
}

//有前序遍历和中序遍历还原树，并返回根节点
//其中前序遍历结果为由str1[s1]到str1[e1],中序遍历结果为由str2[s2],str2[e2]
Node *build(int s1,int e1,int s2,int e2){
    Node* ret = creat();  //为该根节点申请空间
    ret->c = str1[s1];  //该节点字符为前序遍历中第一个字符
    int rootldx;
    for(int i=s2;i<=e2;i++){//查找该根节点字符在中序遍历中的位置
        if(str2[i]==str1[s1]){
            rootldx = i;
            break;
        }
    }
    if(rootldx != s2){//若左子树不为空
        ret->lchild=build(s1+1,s1+(rootldx-s2),s2,rootldx-1);//递归还原其左子树
    }
    if(rootldx != e2){//若右子树不为空
        ret->rchild=build(s1+(rootldx-s2)+1,e1,rootldx+1,e2);//递归还原右子树
    }
    return ret;//返回根节点指针
}

int main(){
    while(scanf("%s",str1)!=EOF){
        scanf("%s",str2);//输入
        loc = 0;//初始化静态内存空间中已经使用结点个数为0
        int L1 = strlen(str1);
        int L2 = strlen(str2);//计算两个字符串长度
        Node *T = build(0,L1-1,0,L2-1);//还原整棵树，其根节点指针保存在T中
        postOrder(T);
        printf("\n");
    }
    return 0;
}
