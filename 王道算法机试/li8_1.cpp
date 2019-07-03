/*********************************************************
题目描述：
    给定一个短字符串（不含空格），再给定若干个字符串，在这些字符串中删除所含有的短字符串。
输入：
    输入只有1组数据。
    输入一个短字符串（不含空格），再输入若干个字符串知道文件结束为止。
输出：
    删除输入的短字符串（不区分大小写）并去掉空格，输出。
样例输入输出：
n
#include
#clude
int main()
tma()
{
{




printf("Hi");
prtf("Hi");
}
}


*********************************************************/
#include<stdio.h>
#include<string>
#include<iostream>
#include<ctype.h>
using namespace std;
int main(){
    char str[101];
    gets(str);
    string a = str;//要删除的子串
    for(int i=0;i<a.size();i++){    //将a中的字符全部改为小写
        a[i] = tolower(a[i]);
    }
    while(gets(str)){//输入长字符串
        string b = str,c=b;//将字符串保存至b,c
        for(int i=0;i<b.size();i++){
            b[i] = tolower(b[i]);
        }
        int t = b.find(a,0);  //在b中查找a的位置
        while(t!=string::npos){//若查找成功，则重复循环
            c.erase(t,a.size());
            b.erase(t,a.size());
            t = b.find(a,0);//继续查找下一个
        }
        t = c.find(' ',0);  //查找c中空格
        while(t!=string::npos){
            c.erase(t,1);
            b.erase(t,1);
            t = b.find(a,0);
        }
        cout<<c<<endl;
    }
    return 0;
}





