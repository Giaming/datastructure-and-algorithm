/***********************************
题目描述：
  有N个学生的数据，将学生数据按成绩高低排序，如果成绩相同则按姓名字符排序，
如果姓名的字符序也相同则按照学生的年龄排序，并输出N个学生排序后的信息。
输入：
  测试数据有多组，每组输入第一行有一个整数N(N<=1000),接下来的N行包括N个学生的数据。
每个学生的数据包括姓名（长度不超过100的字符串）、年龄（整形数）、成绩（小于等于100
的正数）。
输出：
  将学生信息按成绩排序，成绩相同的则按姓名的字母序进行排序。然后输出学生信息，
按照如下格式：姓名 年龄 成绩
样例输入：
3
abc 20 99
bcd 19 97
bed 20 97
样例输出：
bcd 19 97
bed 20 97
abc 20 99

提示：
    学生姓名的字母序区分字母的大小写，
    如A要比a的字母序靠前（因为A的ASCII码比a的ascii要小）
************************************/

//#include<stdio.h>
//#include<algorithm>
//#include<string.h>
//using namespace std;
//struct E{
//    char name[101];
//    int age;
//    int score;
//}buf[1000];
//
//bool cmp(E a, E b){ //实现比较规则
//    if(a.score != b.score)
//        return a.score<b.score; //若分数不相同则分数低者在前
//    int tmp = strcmp(a.name,b.name);
//    if(tmp!=0)
//        return tmp<0;   //若分数相同则名字字典序小者在前
//    else
//        return a.age < b.age;   //若名字也相同则年龄小者在前
//}
//
//int main()
//{
//    int n;
//    while(scanf("%d",&n)!=EOF){
//        for(int i=0;i<n;i++){
//            scanf("%s%d%d",&buf[i].name,&buf[i].age,&buf[i].score);
//        }
//        sort(buf,buf+n,cmp);    //利用自己定义的规则对数组进行排序
//        for(int i=0;i<n;i++)
//            printf("%s %d %d\n",buf[i].name,buf[i].age,buf[i].score);
//    }
//    return 0;
//}
//
//
