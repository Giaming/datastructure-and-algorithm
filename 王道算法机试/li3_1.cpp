/********************************************
题目描述：
    在某个字符串（长度不超过100）中有左括号、右括号和大小写字母；规定（与常见的算数式子一样）
任何一个左括号都从内到外与它右边且距离最近的右括号匹配。写一个程序，找到无法匹配的左括号和右
括号，输出原来字符串并在下一行标出不能匹配的括号。不能匹配的左括号用"$"标注，不能匹配的右括号
用"?"表示。
输入：
    输入包括多个数组，每组数据一行，包含一个字符串，只包含左右括号和大小写字母，字符串长度不超过100.
输出：
    对每组输出数据，输出两行，第一行包含原始输入字符，第二行有"$""?"和空格组成，"$"和"?"表示与之对应的
左括号和右括号不能匹配。
样例输入:
    )(rttyy())sss)(
样例输出：
    )(rttyy())sss)(
    ?           ?$


********************************************/
#include<stdio.h>
#include<stack>
using namespace std;
stack<int> S;  //定义一个堆栈
char str[110];  //保存输入字符串
char ans[110];  //保存输出字符串
int main(){
    while(scanf("%s",str)!=EOF){//输出字符串
        int i;
        for(i=0;str[i]!=0;i++){ //从左到右遍历字符串
            if(str[i]=='('){//若遇到左括号
                S.push(i);//将其数组下标放入堆栈中
                ans[i]=' ';  //暂且将对应的输出字符串位置改为空格
               }
            else if(str[i]==')'){//若遇到右括号
                if(S.empty()==false){//此时堆栈非空
                    S.pop();//栈顶位置左括号与其匹配，从栈中弹出该已经匹配的左括号
                    ans[i]=' '; //修改输出中该位置为空格
                }
                else    ans[i] = '?';//若堆栈为空，则无法找到左括号与其匹配，修改输出位置为'?'
            }
            else    ans[i]=' ';
        }
        while(!S.empty()){//当字符串遍历完成后，尚留在堆栈中的左括号无法匹配
            ans[S.top()]='$';  //修改其在输出中的位置为$
            S.pop();//弹出
        }
        ans[i]=0;  //为了输出形成字符串，在其最后一个字符后添加一个空字符
        puts(str);
        puts(ans);
    }

    return 0;
}








