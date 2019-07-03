/*********************************************************************
题目描述：
    输入一系列整数，建立二叉排序树，并进行前序，中序，后序遍历。
输入：
    输入第一行包括一个整数n(1<=n<=100)。接下来的一行包括n个整数。
输出：
    可能有多组测试数据，对于每组数据，将题目所给数据建立一个二叉排序树，
并将二叉排序树进行前序、中序和后序遍历。每种遍历结果输出一行。每行最后
一个数据之后有一个空格。
样例输入:
5
1 6 5 9 8
样例输出：
1 6 5 9 8
1 5 6 8 9
5 8 9 6 1


********************************************************************/
#include<stdio.h>
#include<string.h>
struct Node{
    Node *lchild;
    Node *rchild;
    int c;
}Tree[100];
int loc;//静态数组中被使用元素个数
//申请未使用的结点
Node *creat(){
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];//返回指针，且loc累加
}

/** \brief 前序遍历
 *
 * \param T Node*
 * \return void
 *
 */
void preOrder(Node *T){
    printf("%d ",T->c);
    if(T->lchild!=NULL)
        preOrder(T->lchild);
    if(T->rchild!=NULL)
        preOrder(T->rchild);
}


/** \brief 中序遍历
 *
 * \param T Node*
 * \return void
 *
 */
void inOrder(Node *T){
    if(T->lchild!=NULL)
        inOrder(T->lchild);
    printf("%d ",T->c);
    if(T->rchild!=NULL)
        inOrder(T->rchild);
}

void postOrder(Node *T){
    if(T->lchild!=NULL)
        postOrder(T->lchild);
    if(T->rchild!=NULL)
        postOrder(T->rchild);
    printf("%d ",T->c);
}

Node *Insert(Node *T,int x){//插入数字
    if(T==NULL){//若当前为空
        T = creat();//建立结点
        T->c = x;//数字直接插入其根节点
        return T;
    }
    else if(x<T->c)//若x小于根节点数值
        T->lchild = Insert(T->lchild,x);
    else if(x > T->c)
        T->rchild = Insert(T->rchild,x);//插入到右子树上，若根节点数值与x一样，根据题目要求直接忽略
    return T;
}

int main(){
    int n;
    while(scanf("%d",&n) !=EOF){
        loc = 0;
        Node *T = NULL;  //二叉排序树树根结点为空
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            T = Insert(T,x);//插入到排序树中
        }
        preOrder(T);//前序遍历
        printf("\n");
        inOrder(T);
        printf("\n");
        postOrder(T);
        printf("\n");
    }
    return 0;
}


