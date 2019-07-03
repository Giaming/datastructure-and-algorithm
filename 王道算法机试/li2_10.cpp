/*************************************************
题目描述：
    输入N个学生的信息，然后进行查询。
输入:
    输入的第一行为N（N<=1000）
    接下来的N行包括N个学生的信息，信息格式如下：
    01 李江 男 21
    02 刘唐 男 23
    03 张军 男 19
    04 王娜 女 19
    然后输入一个M(M<=10000),接下来会有M行，代表M次查询，每行输入一个学号，格式如下:
    02
    03
    01
    04
输出：
    输出M行，每行包括一个对应于查询学生的信息。
    如果没有对应的学生信息，则输出"No Answer!"
样例输入：
4
01 李江 男 21
02 刘唐 男 23
03 张军 男 19
04 王娜 女 19
5
02
03
01
04
03
样例输出：
02 刘唐 男 23
03 张军 男 19
01 李江 男 21
04 王娜 女 19
03 张军 男 19

*************************************************/
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

struct Student{
    char no[100]; //学号
    char name[100]; //姓名
    int age; //年龄
    char sex[5]; //性别
    bool operator < (const Student & A) const{
        return strcmp(no,A.no) < 0;
    }
}buf[1000];

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%s%s%s%d",&buf[i].no,&buf[i].name,&buf[i].sex,&buf[i].age);
        }
        sort(buf,buf+n);//对数组排序使其按照学号升序排列
        int t;
        scanf("%d",&t); //有t组询问
        while(t--!=0){  //while循环保证查询次数t
                int ans = -1; //目标元素下标，初始化为-1
                char x[30];
                scanf("%s",x); //带查找学号
                int top = n-1,base=0;//初试时，开始下标为0，结束下标为n-1,查找子集为整个数组
                while(top>=base){
                    int mid = (top+base)/2; //计算中间节点下标
                    int tmp = strcmp(buf[mid].no,x);//比较中间点学号和目标学号
                    if(tmp==0){
                        ans = mid;
                        break;//若相等，则查找完成跳出二分查找
                    }
                    else if(tmp>0) top = mid-1;
                    else base = mid+1;
                }
                if(ans==-1){//若查找失败
                    printf("No Answer!\n");
                }
                else printf("%s %s %s %d\n",buf[ans].no,buf[ans].name,buf[ans].sex,buf[ans].age);
        }
    }
    return 0;
}

