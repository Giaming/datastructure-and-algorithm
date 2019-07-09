#include <stdio.h>
#include <stdlib.h>
#define maxSize 256
// 树的结构体定义
typedef struct BTNode
{
    char data;    
    struct BTNode *lchild;  
    struct BTNode *rchild;
}BTNode;

// 递归实现二叉树的三种遍历算法

void Visit(BTNode *p)
{
    printf("%c",p->data);
}

// 前序遍历
void preorder(BTNode *p)
{
    if(p!=NULL)
    {
        Visit(p);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

// 中序遍历
void inorder(BTNode *p)
{
    if(p!=NULL)
    {
        preorder(p->lchild);
        Visit(p);
        preorder(p->rchild);
    }
}

// 后序遍历
void postorder(BTNode *p)
{
    if(p!=NULL)
    {
        preorder(p->lchild);
        preorder(p->rchild);
        Visit(p);
    }
}

// 二叉树遍历的非递归实现    // 利用栈实现


// 先序遍历
// 由于栈是FILO的，利用这个性质可以将递归使用栈来实现
/***********************
 * 1. 先使根结点入栈
 * 2. 根结点出栈，然后让根结点的右孩子先入栈，然后再是根结点的左孩子入栈（因为栈是FILO的，所以实现与逻辑是相反的）
 * 3. 然后循环实现上面的步骤，直到栈中没有元素
 */
void preorderNonrecursion(BTNode *bt)
{
    if(bt!=NULL)
    {
        BTNode *Stack[maxSize];    // 定义一个栈
        int top = -1;   // 栈的初始化
        BTNode *p;  
        Stack[++top] = bt;     // 根结点入栈
        while(top!=-1)
        {
            p = Stack[top--];    // 出栈并输出栈顶结点
            Visit(p);
            if(p->rchild!=NULL)
                Stack[++top] = p->rchild;
            if(p->lchild!=NULL)
                Stack[++top] = p->lchild;
        }
    }
}

// 中序遍历
/*****************
 * 1. 开始根结点入栈
 * 2. 循环执行如下操作： 如果栈顶结点的左孩子存在，则左孩子入栈；
 *                     如果栈顶结点的左孩子不存在，则出栈并输出栈顶结点，然后检查右孩子是否存在，如果存在，则右孩子入栈
 * 3. 当栈空时算法结束
 */
void inorderNonrecursion(BTNode *bt)
{
    if(bt!=NULL)
    {
        BTNode *Stack[maxSize];
        int top = -1;
        BTNode *p;
        p = bt;
        // 由于会出现当栈空状态时遍历还没有结束的情况，所以需要判断p是否为空
        while(top!=-1 || p!=NULL)
        {
            while(p!=NULL)     // 左孩子存在，则左孩子入栈
            {
                Stack[++top] = p;
                p = p->lchild;
            }
            if(top!=-1)     // 栈不空的情况，出栈并输出栈结点
            {
                p = Stack[top--];
                Visit(p);
                p = p->rchild;      // 右孩子结点（若存在），入栈
            }
        }
    }
}

// 后序遍历
/****************
 * 逆后序遍历只不过是先序遍历过程中对左右子树遍历顺序交换所得到的结果，然后再将逆后序遍历序列逆向输出即可得到后序遍历
 * 这里使用两个栈，一个用来实现逆后序遍历，一个用来实现序列的逆向输出
 */
void postNonrecursion(BTNode *bt)
{
    if(bt!=NULL)
    {
        // 定义两个栈
        BTNode *Stack1[maxSize]; int top1 = -1;
        BTNode *Stack2[maxSize]; int top2 = -1;
        BTNode *p = NULL;
        Stack1[++top1] = bt;
        while (top1!=-1)
        {
            p = Stack1[top1--];   // 出栈
            Stack2[++top2] = p;  
            if(p->lchild!=NULL)
                Stack1[++top1] = p->lchild;
            if(p->rchild!=NULL)
                Stack1[++top1] = p->rchild;
        }
        while(top2!=-1)
        {
            p = Stack2[top2--];
            Visit(p);    // 打印输出
        }
    }
}


int op(int a,char OP,int b) //完成算式a OP b
{
    if(OP=='+') return a+b;
    if(OP=='-') return a-b;
    if(OP=='*') return a*b;
    if(OP=='/')
    {
       if(b==0)
       {
           printf("ERROR");
           return 0;
       } 
       else
       {
           return a/b;
       }
    }
}

// 表达式(a-(b+c))*(d/e)存放在一个以二叉链表为存储结构的二叉树中，编写程序求出该表达式的值
// 该表达式需要先求出左子树所表示的表达式的值，然后求右子树所表示的表达式的值，最后再将两个结果相乘就是整个表达式的值
int comp(BTNode *p)
{
    int A, B;
    if(p!=NULL)
    {
        if(p->lchild!=NULL && p->rchild!=NULL)
        {
            A = comp(p->lchild);       // 后序遍历求出左子树的值
            B = comp(p->rchild);
            return op(A,B,p->data);   
        }
        else
            return p->data-'0';     // 如果当前结点的左右子树都为空，则为数值，直接返回数值
    }
    else return 0;
}