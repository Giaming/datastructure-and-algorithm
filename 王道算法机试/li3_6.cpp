/**********************************************************
题目描述：
    判断两序列是否为同一二叉搜索树序列
输入：
    开始一个数n，（1<=n<=20）表示有n个需要判断，n=0的时候输入结束。
接下去一行是一个序列，序列长度小于10，包含(0~9)个数字，没有重复数字，
根据这个序列可以构造一棵二叉搜索树。
    接下去的n行有n个序列，每个序列格式跟第一个序列一样，请判断每个序列是否
能组成同一颗二叉搜索树。
输出：
    如果序列相同则输出yes，否则输出no
样例输入：
2
567432
543267
576342
0
样例输出：
yes
no

***********************************************************/

#include<stdio.h>
#include<string.h>
struct Node{
    Node *lchild;
    Node *rchild;
    int c;
}Tree[110];
int loc;
Node *creat(){
    Tree[loc].lchild=Tree[loc].rchild=NULL;
    return &Tree[loc++];
}

char str1[25],str2[25];//保存二叉排序树的遍历结果，
//将每一棵树的前序遍历得到的字符串和中序遍历的字符串连接，得到遍历结果字符串
int size1,size2; //保存在字符数组中的遍历得到字符个数
char *str;  //当前正在保存字符串
int *size;  //保存正在保存字符串中的字符个数
void preOrder(Node *T){
    str[(*size)++] = T->c+'0';//将结点中的字符放入正在保存的字符串中
    if(T->lchild!=NULL)
        preOrder(T->lchild);
    if(T->rchild!=NULL)
        preOrder(T->rchild);
}

void inOrder(Node *T){
    if(T->lchild!=NULL)
        inOrder(T->lchild);
    str[(*size)++] = T->c+'0';
    if(T->rchild!=NULL)
        inOrder(T->rchild);
}

Node *Insert(Node *T,int x){
    if(T==NULL){
        T = creat();
        T->c = x;
        return T;
    }
    else if(x<T->c)
        T->lchild = Insert(T->lchild,x);
    else if(x>T->c)
        T->rchild = Insert(T->rchild,x);
    return T;
}

int main(){
    int n;
    char tmp[12];
    while(scanf("%d",&n) != EOF && n!=0){
        loc = 0; //初始化静态空间为未使用
        Node *T = NULL;
        scanf("%s",tmp);//输入字符串
        for(int i=0;tmp[i]!=0;i++){
            T = Insert(T,tmp[i]-'0');//按顺序将数字插入二叉排序树
        }
        size1 = 0;//保存在第一个字符串中的字符初始化为0
        str = str1; //将正在保存字符串设定为第一个字符串
        size = &size1; //将正在保存字符串中的字符个数指针指向size1
        preOrder(T);
        inOrder(T);
        str1[size1] = 0;//向第一个字符串的最后一个字符添加为空字符，以便使用字符串函数
        while(n--!=0){//输入n个其他字符串
            scanf("%s",tmp);//输入
            Node *T2 = NULL;
            for(int i=0;tmp[i]!=0;i++){//建立二叉排序树
                T2 = Insert(T2,tmp[i]-'0');
            }
            size2 = 0;//第二个字符串保存字符初始化为0
            str = str2;
            size = &size2;
            preOrder(T2);
            inOrder(T2);
            str2[size2] = 0;
            puts(strcmp(str1,str2)==0 ? "yes" : "no");//比较两个遍历字符串，若相同则输出yes
        }
    }

    return 0;
}



