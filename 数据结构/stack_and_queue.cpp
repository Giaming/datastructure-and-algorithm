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
}