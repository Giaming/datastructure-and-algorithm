#include <stdio.h>
#include <stdlib.h>

/***************************
 * 线性表的结构体定义和基本操作
 ***************************/ 
#define maxSize 100

// 顺序表的定义
typedef struct 
{
    int data[maxSize];     //存放顺序表元素的数组
    int length;             //存放顺序表的长度
}Sqlist;

// 单链表结点定义
typedef struct LNode
{
    int data;     //数据域
    struct LNode *next;      //指向后继结点
}LNode;

// 双链表的定义
typedef struct DLNode
{
    int data;   //数据域
    struct DLNode *prior;   //指向前驱
    struct DLNode *next;     //指向后继
}DLNode;

//定义结点
LNode *A = (LNode *)malloc(sizeof(LNode));


/****************************
 *  顺序表的操作
 */

/* 已知顺序表L中元素递增有序排列，设计一个算法，使得插入一个元素后顺序表仍然有序 */
// 找到插入元素位置
int findELem(SqList L, int x)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        if(x<L.data[i])    //因为是递增排序，所以是小于号
            return i;
    }
    return i;   
}

void insertElem(Sqlist &L, int x)
{
    int p = findELem(L,x);
    for(int i=L.length-1;i>=p;--i)    //将元素往后面挪,=p表示的是将第p个位置的元素往后挪
    {
        L.data[i+1] = L.data[i];
    }
    L.data[p] = x;
    ++(L.length);   //顺序表的长度加一
}


//查找一个元素x
int findE(Sqlist L,int x)
{
    int i;
    for(i=0;i<L.length;i++)
        if(x==L.data[i])
            return i;
    return -1;   //表示没有找到
}

//在L的第p个位置插入一个元素
int insertE(Sqlist &L,int p,int x)
{
    //先判断p的位置
    if(p<0||p>L.length||L.length==maxSize)   //越界
        return 0;   
    for(int i=L.length-1;i>=p,--i)
        L.data[i+1] = L.data[i];
    L.data[p] = x;
    ++(L.length);
    return 1;
}

// 删除顺序表中下标为p的元素
int deleteE(Sqlist &L,int p,int &x)   //用x来接收删除的元素的值
{
    if(p<0||p>L.length)
        return 0;
    x = L.data[p];  //将p位置的元素存放到x中
    for(int i=p;i<L.length;i++)
        L.data[i] = L.data[i+1];
    --(L.length);
    return 1;
}

// 初始化顺序表
void initList(Sqlist &L)
{
    L.length = 0;
}
// 求指定位置元素的算法
int getElem(Sqlist L, int p, int &e)
{
    if(p<0||p>L.length)
        return 0;   
    e = L.data[p];
    return 1;
}


/*********************************
 *  单链表的操作
 */

//合并两个有序的单链表
void merge(LNode *A, LNode *B, LNode *C)
{
    LNode *p = A->next;
    LNode *q = B->next;
    LNode *r;    //采用的是尾插法
    C = A;   //用A的头结点来做C的头结点
    C->next = NULL;    //初始化C
    free(B);
    r = C;
    // 合并两个链表
    while(p!=NULL&&q!=NULL)
    {
        if(p->data<=q->data)
        {
            r->next = p;
            p = p->next;
            r = r->next;
        }
        else
        {
            r->next = q;
            q = q->next;
            r = r->next;
        }
    }
    while (p!=NULL)
    {
        r->next = p;
    }
    while(q!=NULL)
    {
        r->next = q;
    }   
}


/*************************
 * 建立链表的两种方法
 **/ 

// 头插法
void createListF(LNode *&C, int a[], int n)
{
    // 初始化
    LNode *s;
    C = (LNode *)malloc(sizeof(LNode));
    C->next = NULL;
    for(int i=0;i<n;i++)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];     //这里s是个指针变量，所以要用->
        // 头插法关键语句
        s->next = C->next;
        C->next = s;            
    }
}

// 尾插法
void createListR(LNode *&C, int a[], int n)
{
    // 初始化
    LNode *s,*r;   //r始终用来指向C的终端节点
    C = (LNode *)malloc(sizeof(LNode));
    C->next = NULL;
    r = C;
    for(int i=0;i<n;i++)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        //尾插法关键语句
        r->next = s;
        r = s;    // 或者 r = r->next;
    }
    r->next = NULL;
}


//  归并递减的单链表的算法
void merge(LNode *A, LNode *B, LNode *C)
{
    LNode *p = A->next;
    LNode *q = B->next;
    LNode *s;
    C = A;
    C->next = NULL;
    free(B);
    while(p!=NULL && q!=NULL)
    {
        //使用头插法
        if(p->data<=q->data){
            s = p;
            p = p->next;
            s->next = C->next;
            C->next = s;
        }
        else
        {
            s = q;
            q = q->next;
            s->next = C->next;
            C->next = s;
        }
    }
    // 下面和递增序列不同
    while (p!=NULL)
    {
        s = p;
        p = p->next;
        s->next = C->next;
        C->next = s;
    }
    while (q!=NULL)
    {
        s = q;
        q = q->next;
        s->next = C->next;
        C->next = s;
    }
    
}

//查找链表C中是否存在元素x
int findAndDel(LNode *C, int x)
{
    LNode *p,*q;
    p = C;
    // 查找
    while (p->next!=NULL)
    {
        if(p->next->data==x)
            break;
        p = p->next;
    }
    //删除
    if(p->next==NULL)
        return 0;
    else
    {
        q = p->next;
        p->next = q->next;
        free(q);
        return 1;
    }
}


/**************************
 *  双链表的操作
 */

// 使用尾插法建立双链表
void createDListR(DLNode *&L, int a[], int n)
{
    // 初始化过程
    DLNode *s,*r;
    L = (DLNode *)malloc(sizeof(DLNode));
    L->prior = NULL; L->next = NULL;
    r = L;
    // 插入元素    
    for(int i=0;i<n;i++)
    {
        s = (DLNode *)malloc(sizeof(DLNode));
        s->data = a[i];
        r->next = s;
        s->prior = r;
        r = s;
    }
    r->next = NULL;
}

// 头插法
void createDListF(DLNode *&L, int a[], int n)
{
    DLNode *s;
    L = (DLNode *)malloc(sizeof(DLNode));
    L->prior = NULL; L->next = NULL;
    for(int i=0;i<n;i++){
        s = (DLNode *)malloc(sizeof(DLNode));
        s->data = a[i];
        s->next = L->next;
        L->next->prior = s;
        L->next = s;
        s->prior = L;
    }
}


/**********************************************
 * 题目描述： 顺序表A中前m个元素递增有序，后n个元素也递增有序，设计一个算法使得整个顺序表有序。
 * 
 * 思路：将后面的n个元素插入到前面的m个元素中
 * 时间复杂度：O(mn)
 * 空间复杂度：O(1)
 */
void insertElem(int A[], int m, int n)
{
    int i,j;
    int temp;
    for(i=m;i<m+n;i++){
        temp = A[i];   //暂存变量
        for(j=i-1;j>=0&&temp<A[j];--j)   //后移元素
        {
            A[j+1] = A[j];   
        }
        A[j+1] = temp;   //因为for循环后j多移动了一位，因此在j+1处插入
    }
}



/********************************************
 * 题目描述：有两个递增的单链表A和B(A和B的元素个数分别为m,n，且A和B都带有头结点)，设计一个算法求集合A和集合B的差集A-B。
 * 将差集保存到A中
 * 
 * 思路： 使用merge的思想，如果元素相同，则删除掉该元素即可
 * 
 * 时间复杂度：O(m+n)
 */
void difference(LNode *A, LNode *B)
{
    LNode *p = A->next,*q = B->next;
    LNode *pre = A;   // 删除元素的时候用
    LNode *r;
    while (p!=NULL && q!=NULL)
    {
        if(p->data<q->data){
            pre = p;
            p = p->next;
        }
        else if(p->data>q->data){
            q = q->next;
        }
        else
        {
            pre->next = p->next;
            r = p;
            p = p->next;
            free(r);
        }   
    }
}


