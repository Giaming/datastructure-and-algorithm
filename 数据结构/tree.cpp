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

// 写一个算法求出一个二叉树的深度（二叉树以二叉链表存储）
// 左子树深度为LD，右子树深度为RD；则整棵树的深度就为max{LD,RD}+1
int getDepth(BTNode *p)
{
    int LD,RD;     
    if(p==NULL)
        return 0;
    else
    {
        LD = getDepth(p->lchild);
        RD = getDepth(p->rchild);
        return (LD>RD?LD:RD)+1;
    }    
}

// 二叉树的查找
void search(BTNode *p, BTNode *&q, int key)
{
    if(p!=NULL)
    {
        if(p->data==key)
            q = p;     
        else
        {
            search(p->lchild,q,key);
            if(q==NULL)      // 剪枝操作
                search(p->rchild,q,key);  
        }
        
    }
}


// 层次遍历
/*******************
 * 建立一个队列，先将头结点入队列，然后出队列，访问该节点，如果它有左子树，则将左子树的根结点入队，
 * 如果它有右子树，则将右子树的根结点入队，然后出队列，对出队结点进行访问。
 */
void level(BTNode *p)
{
    int front,rear;
    BTNode *queue[maxSize];    // 定义一个循环队列，用来记录将要访问的层次上的结点
    front = rear = 0;
    BTNode *q;
    if(p!=NULL)
    {
        rear = (rear+1)%maxSize;
        queue[rear] = p;    // 根结点入队
        while(front!=rear)       // 当队列不空的时候进行循环
        {
            front = (front+1)%maxSize;
            q = queue[front];    // 访问队头结点
            Visit(q);
            if(q->lchild!=NULL)
            {
                rear = (rear+1)%maxSize;
                queue[rear] = q->lchild;
            }
            if(q->rchild!=NULL)
            {
                rear = (rear+1)%maxSize;
                queue[rear] = q->rchild;
            }
        }
    }
}


// 假设一个二叉树采用二叉树链表存储，设计一个算法，求出该二叉树的宽度（具有节点数最多的那一层上的结点个数）
// 采用非循环队列将访问的结点保存下来，然后记录下层次号。
typedef struct 
{
    BTNode *p;    //结点指针
    int lno;     // 结点所在层次号
}St;

int maxNode(BTNode *p)
{
    St que[maxSize];
    int front,rear;
    int Lno,i,j,n,max;
    front = rear = 0;    // 将队列置空
    BTNode *q;
    if(p!=NULL)
    {
        ++rear;
        que[rear].p = p;  // 树根入队
        que[rear].lno = 1;    // 已知条件
        while(front!=rear)
        {
            ++front;
            q = que[front].p;
            Lno = que[front].lno;      // 关键语句，Lno用来存取当前节点的层次号
            if(q->lchild!=NULL)
            {
                ++rear;
                que[rear].p = q->lchild;
                que[rear].lno = Lno+1;    // 关键语句：根据当前结点的层次号推知其孩子结点的层次号
            }
            if(q->rchild!=NULL)
            {
                ++rear;
                que[rear].p = q->rchild;
                que[rear].lno = Lno+1;
            }
        }// 循环结束的时候，Lno中保存的是这棵二叉树的最大层次
        // 以下代码找出含有结点最多的层中的结点数
        max = 0;
        for(i=1;i<Lno;i++)
        {
            n = 0;
            for(j=1;j<=rear;j++)
                if(que[j].lno==i)    // 这里需要对整个队列进行查询
                    ++n;
            if(max<n)
                max = n;
        }
        return max;
    }
    else return 0;
}



// 线索二叉树的定义
typedef struct TBTNode
{
    char data;
    int ltag,rtag;    // 线索标记
    struct TBTNode *lchild;
    struct TBTNode *rchild;
}TBTNode;

// 通过中序遍历对二叉树线索化的递归算法如下
void InThread(TBTNode *p, TBTNode *&pre)
{
    if(p!=NULL)
    {
        InThread(p->lchild,pre);   // 递归，左子树线索化
        if(p->lchild==NULL)
        {
            p->lchild=pre;    // 建立当前节点的前驱线索
            p->ltag = 1;
        }
        if(pre!=NULL && pre->rchild==NULL)
        {
            pre->rchild = p;      // 建立前驱结点的后继线索
            pre->rtag = 1;
        }    
        pre = p;
        p = p->rchild;
        InThread(p,pre);   // 递归，右子树线索化
    }
}

// 通过中序遍历建立中序线索化二叉树
void createInThread(TBTNode *root)
{
    TBTNode *pre = NULL;   // 前驱结点指针
    if(root!=NULL)
    {
        InThread(root, pre);
        pre->rchild = NULL;    // 非空二叉树，线索化
        pre->rtag = 1;     // 后处理中序最后一个结点
    }
}



// 前序线索二叉树
void preThread(TBTNode *p, TBTNode *&pre)
{
    if(p!=NULL)
    {
        if(p->lchild==NULL)
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        if(pre!=NULL && pre->rchild == NULL)
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        // 注意，这里在递归入口处有限制条件，左右指针不是线索才继续递归
        if(p->ltag == 0)
            preThread(p->lchild, pre);
        if(p->rtag == 0)
            preThread(p->rchild,pre);
    }
}

// 后序线索二叉树
void postThread(TBTNode *p, TBTNode *&pre)
{
    if(p!=NULL)
    {
        postThread(p->lchild, pre);    // 递归，左子树线索化
        postThread(p->rchild, pre);     // 递归，右子树线索化
        if(p->lchild==NULL)
        {
            p->lchild=pre;    // 建立当前结点的前驱序列
            p->ltag = 1;
        }
        if(pre!=NULL && pre->rchild==NULL)
        {
            pre->rchild = p;   // 建立前驱结点的后继线索
            pre->rtag = 1;
        }
        pre = p;
    }
}