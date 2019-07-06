<<<<<<< HEAD
/*************************************************
 * 结构体定义
 */
#include <stdio.h>
#include <stdlib.h>
#define maxSize 100

// 顺序栈定义
typedef struct 
{
    int data[maxSize];     //存放栈中元素
    int top;      //栈顶指针
}SqStack;

//链栈结点丁宁以
typedef struct LNode
{
    int data;
    struct LNode *next;   //指向下一个结点
}LNode;

// 顺序队的定义
typedef struct 
{
    int data[maxSize];
    int front, rear;
}SqQueue;

// 链队定义
//结点定义
typedef struct QNode
{
    int data;
    struct QNode *next;
}QNode;

//链队类型定义
typedef struct 
{
    QNode *front;    //队头指针
    QNode *rear;    //队尾指针
}LiQueue;



// 进栈操作：st.data[++(st.top)] = x;       先移动指针，然后再进入元素
// 出栈操作：x = st.data[st.top--];         先取出元素，然后再移动指针

// 栈的初始化
void initStack(SqStack &st)
{
    st.top = -1;
}

// 判断栈空
int isEmpty(SqStack &st)
{
    if(st.top==-1)
        return 1;    //表示栈空
    else
        return 0;
}

// 进栈代码
int push(SqStack &st, int x)
{
    // 判断是否栈满，（上溢）
    if(st.top==maxSize-1)
        return 0;
    st.data[++st.top] = x;     // ++(st.top); st.data[st.top] = x;
    return 1; 
}

// 出栈代码
int pop(SqStack &st, int &x)
{
    // 判断是否会产生下溢
    if(st.top==-1)
        return 0;
    x = st.data[st.top];
    st.top--;
    return 1;
}

// 使用数组来表示栈
int stack[maxSize];
int top=-1;    //初始化
//进栈
stack[++top] = x;
//出栈
x = stack[top--];


// 链栈
/********
 * 两个特殊状态：
 *      栈空：lst->next = NULL;
 *      栈满：不存在
 * 两个操作：
 *      入栈： p->next = lst->next; lst->next = p;     //头插法
 *      出栈： p = lst->next; x = p->data; lst->next = p->next; free(p);     // 单链表的删除操作
 */

// 初始化栈
void initStack(LNode *&lst)
{
    // 初始化
    lst = (LNode*)malloc(sizeof(LNode));
    lst->next = NULL;
}

// 判断栈空
int isEmpty(LNode *lst)
{
    if(lst->next==NULL)
        return 1;
    else 
        return 0;
}

// 进栈代码
void push(LNode *lst, int x)
{
    LNode *p;
    p = (LNode*)malloc(sizeof(LNode));
    p->next = NULL;

    p->data = x;
    p->next = lst->next;
    lst->next = p;
}

// 出栈代码
int pop(LNode *lst, int &x)
{
    LNode *p;
    if(lst->next == NULL)
        return 0;
   
    p = lst->next;
    x = p->data; 
    lst->next = p->next; 
    free(p);
    return 1;
=======
/*************************************************
 * 结构体定义
 */
#include <stdio.h>
#include <stdlib.h>
#define maxSize 100

// 顺序栈定义
typedef struct 
{
    int data[maxSize];     //存放栈中元素
    int top;      //栈顶指针
}SqStack;

//链栈结点丁宁以
typedef struct LNode
{
    int data;
    struct LNode *next;   //指向下一个结点
}LNode;

// 顺序队的定义
typedef struct 
{
    int data[maxSize];
    int front, rear;
}SqQueue;

// 链队定义
//结点定义
typedef struct QNode
{
    int data;
    struct QNode *next;
}QNode;

//链队类型定义
typedef struct 
{
    QNode *front;    //队头指针
    QNode *rear;    //队尾指针
}LiQueue;



// 进栈操作：st.data[++(st.top)] = x;       先移动指针，然后再进入元素
// 出栈操作：x = st.data[st.top--];         先取出元素，然后再移动指针

// 栈的初始化
void initStack(SqStack &st)
{
    st.top = -1;
}

// 判断栈空
int isEmpty(SqStack &st)
{
    if(st.top==-1)
        return 1;    //表示栈空
    else
        return 0;
}

// 进栈代码
int push(SqStack &st, int x)
{
    // 判断是否栈满，（上溢）
    if(st.top==maxSize-1)
        return 0;
    st.data[++st.top] = x;     // ++(st.top); st.data[st.top] = x;
    return 1; 
}

// 出栈代码
int pop(SqStack &st, int &x)
{
    // 判断是否会产生下溢
    if(st.top==-1)
        return 0;
    x = st.data[st.top];
    st.top--;
    return 1;
}

// 使用数组来表示栈
int stack[maxSize];
int top=-1;    //初始化
//进栈
stack[++top] = x;
//出栈
x = stack[top--];


// 链栈
/********
 * 两个特殊状态：
 *      栈空：lst->next = NULL;
 *      栈满：不存在
 * 两个操作：
 *      入栈： p->next = lst->next; lst->next = p;     //头插法
 *      出栈： p = lst->next; x = p->data; lst->next = p->next; free(p);     // 单链表的删除操作
 */

// 初始化栈
void initStack(LNode *&lst)
{
    // 初始化
    lst = (LNode*)malloc(sizeof(LNode));
    lst->next = NULL;
}

// 判断栈空
int isEmpty(LNode *lst)
{
    if(lst->next==NULL)   //这个是带有头结点的
        return 1;
    else 
        return 0;
}

// 进栈代码
void push(LNode *lst, int x)
{
    LNode *p;
    p = (LNode*)malloc(sizeof(LNode));
    p->next = NULL;

    p->data = x;
    p->next = lst->next;
    lst->next = p;
}

// 出栈代码
int pop(LNode *lst, int &x)
{
    LNode *p;
    if(lst->next == NULL)
        return 0;
   
    p = lst->next;
    x = p->data; 
    lst->next = p->next; 
    free(p);
    return 1;
}


// 栈的应用
/*******************
 * 判断一个表达式中的括号是否正确配对，表达式已经存入字符数组exp[]中，表达式中的字符个数为n
 * 
 * 思路： 使用栈来进行实现，当出现一个"("时，入栈，当出现一个")"时，出栈；
 */
int match(char exp[], int n)
{
    char stack[maxSize];  top=-1;   //初始化
    
    for(int i=0;i<n;i++)
    {
        if(exp[i]=='(')
            stack[++top] = 'C';
        if(exp[i]==')')
        {
            if(top==-1)  //表示当前栈已空
                return 0;
            else
            {
                --top;    //出栈
            }
        }
    }
    if(top==-1) return 1;
    else return 0;
}



/*************************
 * 编写一个函数，求后缀式的数值。其中后缀式存于一个字符数组exp中
 * 
 */
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

int com(char exp[])   // 后缀式计算函数
{
    int i,a,b,c;   // a,b为操作数，c保存结果
    int stack[maxSize]; int top=-1;  //初始化栈 
    char OP;
    for(int i=0;i!='\0';i++)
    {
        if(exp[i]>=0 && exp[i]<=9)   // 是数值，则入栈
            stack[++top] = exp[i];
        else  //表明是操作符
        {
            OP = exp[i];
            b = stack[top--];   //取出栈顶元素
            a = stack[top--];
            c = op(a,OP,b);
            stack[++top] = c;   //c入栈
        }
    }
    return stack[top];    
}

// 将一个字符'5'转换为一个整型变量，只需要执行int a = '5'-'0';
// 将一个整型变量转换为一个字符,只需要执行 char b = a+'0';

//栈链的应用
/****************************
 *  用不带头节点的单链表存储链栈，设计初始化栈，判断栈是否为空，进栈，出栈等相关操作
 */

void initStack(LNode *&lst)
{
    lst = NULL;
}
int isEmpty(LNode *lst)
{
    if(lst==NULL)
        return 1;
    else
        return 0;
}
void push(LNode *&lst, int x)
{
    LNode *p;
    p = (LNode*)malloc(sizeof(LNode));
    p->next = NULL;
    p->data = x;
    //插入操作
    p->next = lst;
    lst = p;
}
int pop(LNode *&lst, int &x)
{
    LNode *p;
    if(lst==NULL)
        return 0;  //失败
    p = lst;
    lst = p->next;
    x = p->data;
    free(p);
    return 1;
}



// 顺序队
/****************************
 *  两个状态：
 *      队空状态：qu.rear == qu.front;
 *      队满状态：(qu.rear+1)%maxSize==qu.front;    // 闲置了一个空位子
 * 
 *  两个操作：
 *      入队： qu.rear = (qu.rear+1)%maxSize; qu.data[qu.rear] = x;
 *      出队： qu.front = (qu.front+1)%maxSize; x = data[qu.front];
 * 
 *   元素入队时是先移动指针，然后在存入元素
 *   元素出队时也是先移动指针，然后在取出元素
 */
void initQueue(SqQueue &qu)
{
    qu.front = qu.rear = 0;     //队首和队尾指针重合，并且指向0
}
// 判断队空
int isQueueEmpty(SqQueue qu)
{
    if(qu.front==qu.rear)
        return 1;
    else
        return 0;
}
// 入队
int enQueue(SqQueue &qu, int x)
{
    if((qu.rear+1)%maxSize==qu.front)   //判断是否队满
        return 0;
    qu.rear  = (qu.rear+1)%maxSize;
    qu.data[qu.rear] = x;
    return 1;
}
// 出队
int deQueue(SqQueue &qu, int &x)
{
    if(qu.front==qu.rear)   // 判断是否队空
        return 0;
    qu.front = (qu.front+1)%maxSize;
    x = qu.data[qu.front];
    return 1;
}

// 链队
/***********************************
 *  两个状态：
 *      队空状态：lqu.front==NULL or lqu.rear==NULL
 *      不存在队满的情况
 *  两个操作：
 *      入队： lqu->rear->next = p; lqu->rear = p;
 *      出队： p = lqu->front; lqu->front=p->next;x=p->data;free(p)
 */

void initQueue(LiQueue *&lqu)
{
    lqu = (LiQueue*)malloc(sizeof(LiQueue));
    lqu->front = lqu->rear = NULL;
}
int isQueueEmpty(LiQueue *lqu)
{
    if(lqu->rear==NULL || lqu->front==NULL)
        return 1;
    else
        return 0;
}
// 入队
void enQueue(LiQueue *&lqu, int x)
{
    QNode *p;
    p = (QNode*)malloc(sizeof(QNode));
    p->data = x;
    if(lqu->rear==NULL)   // 如果队列为空
        lqu->front=lqu->rear=p;
    else
    {
        lqu->rear->next = p;
        lqu->rear = p;
    }
}
// 出队
int deQueue(LiQueue *&lqu, int &x)
{
    QNode *p;
    if(lqu->rear==NULL)  //如果队空
        return 0;
    else
        p = lqu->front;
    if(lqu->front==lqu->rear)    //队列中只有一个节点
        lqu->front = lqu->rear = NULL;
    else
        lqu->front=lqu->front->next;
    x = p->data;
    free(p);
    return 1;
>>>>>>> 4dbe4ef86e40e67cef09d32f429434cf6d239a59
}