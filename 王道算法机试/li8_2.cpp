/*********************************************************
题目描述：
    有一群人，打乒乓球比赛，两两捉对厮杀，每两个人之间最多打一场比赛。
    球赛的规则如下：如果A打败了B，B打败了C，而A与C之间没有进行过比赛，那么就认定，A一定能打败C。
    如果A打败了B，B打败了C，而且，C又打败了A，那个A、B、C三者都不可能成为冠军。
    根据这个规则，无序循环较量，或许就能确定冠军。你的任务就是面对一群比赛选手，在经过若干长厮杀之后，确定是否已经实际上产生了冠军。
输入：
    输入含有一些选手群，每群选手都以一个整数n(n<1000)开头，后跟n对选手的比赛结果，比赛结果以一对选手名字（中间隔一行）表示，前者战胜后者。
    如果n为0，则表示输入结束。
输出：
    对于每个选手群，若你判断出产生了冠军，则在一行中输出"YES",否则在一行中输出"No".
样例输入输出：
3
Alice Bob
Smith John
Alice Smith
Yes
5
a c
c d
d e
b e
a d
No

*********************************************************/
#include<stdio.h>
#include<vector>
#include<map>
#include<string>
#include<queue>
using namespace std;
map<string,int> M;  //定义一个完成从string到int映射的map
int in[2002];

int main(){
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0){
        for(int i=0;i<2*n;i++){
            in[i] = 0;  //初始化入度
        }
        M.clear();
        int idx = 0;   //下一个被映射的数字
        for(int i=0;i<n;i++){
            char str1[50],str2[50];
            scanf("%s%s",str1,str2);//输入两个选手名称
            string a = str1,b = str2;  //将两个字符串保存至string中
            int idxa,idxb;
            if(M.find(a)==M.end()){//map中没有对a的映射
                idxa = idx;
                M[a] = idx++;  //设定映射idx，并递增idx
            }
            else idxa = M[a];
            if(M.find(b)==M.end()){
                idxb = idx;
                M[b] = idx++;
            }
            else idxb = M[b];//确定b的映射
            in[idxb]++;//b的入度递增
        }
        int cnt = 0;
        for(int i=0;i<idx;i++){  //确定所有映射数字的入度，统计入度为0的个数
            if(in[i]==0)
                cnt++;
        }
        puts(cnt==1?"Yes":"No");
    }
    return 0;
}




