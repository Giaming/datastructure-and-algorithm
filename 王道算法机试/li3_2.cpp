/*******************************************
题目描述:
    读入一个只包含+,-,*,/的非负整数计算表达式，计算该表达式的值。
输入：
    测试输入包含若干测试用例，每个测试用例占一行，每行不超过200个字符，整数和运算符之间用一个空格分割。
没有非法表达式。当一行中只有0时输入结束，相应的结果不要输出。
输出：
    对每个测试用例输出一行，即表达式的值，精确到小数点为2位。
样例输入：
1+2
4+2*5-7/11
0
样例输出：
3.00
13.36

*******************************************/
#include<stack>
#include<stdio.h>
using namespace std;
char str[220]; //保存表达式字符串
int mat[][5] = {//优先级矩阵，若mat[i][j]==1,则表示i号运算符优先级大于j号运算符优先级，
    //运算符编码规则为+为1号，-为2号，*为3号,/为4号，我们人为添加在表达式首尾的标记运算符为0号
    1,0,0,0,0,
    1,0,0,0,0,
    1,0,0,0,0,
    1,1,1,0,0,
    1,1,1,0,0,
};
stack<int> op;//运算符栈
stack<double> in;//数字栈，运算结果可能存在浮点数，所以保存元素为double

void getOp(bool &reto, int &retn, int &i){//获得表达式中下一个元素函数，若函数运行结束时，引用变量reto为true,则表示
    //该元素为一个运算符，其编号保存在一个引用变量retn中；
    //否则，表示该元素为一个数字，其值保存在一个引用变量retn中。引用变量i表示遍历到的字符串下标
    if(i==0 && op.empty() == true){//若此时遍历字符串第一个字符，且运算符栈为空，我们人为添加编号为0的标记字符
        reto = true;  //为运算符
        retn = 0; //编号为0
        return ;
    }
    if(str[i]==0){//若此时遍历字符为空字符，则表示字符串已经遍历完
        reto = true;
        retn = 0;
        return;
    }
    if(str[i]>='0' && str[i] <= '9'){//若当前字符为数字
        reto = false;  //返回数字
    }
    else{
        reto = true;    //返回运算符
        if(str[i]=='+'){
            retn = 1;
        }
        else if(str[i]=='-'){
            retn = 2;
        }
        else if(str[i]=='*'){
            retn = 3;
        }
        else if(str[i]=='/'){
            retn = 4;
        }
        i+=2;  //i递增，跳过该运算字符和该运算字符后的空格
        return;
    }
    retn=0; //返回结果为数字
    for(;str[i] != ' ' && str[i] != 0; i++){
        //若字符串未被遍历完，且下一个字符不是空格，则依次遍历其后数字，计算当前连续数字字符表示的数值
        retn *= 10;
        retn += str[i] - '0';
    }//计算该数字的数字值
    if(str[i]==' ')//若其后字符为空格，则表示字符串未被遍历完
        i++;
    return;
}

int main(){
    while(gets(str)){//输入字符串，当其位于文件尾时，gets返回0
        if(str[0]=='0' && str[1] == 0) break;   //若输入只有一个0，则退出
        bool retop;int retnum;   //定义函数所需的引用变量
        int idx = 0; //定义遍历到的字符串下标，初始值为0
        while(!op.empty()) op.pop();
        while(!in.empty()) in.pop();  //清空数字栈，和运算符栈
        while(true){//循环遍历表达式字符串
            getOp(retop,retnum,idx);//获取表达式中下一个元素
            if(retop == false){
                in.push((double)retnum);//将其压入数字栈中
            }
            else{
                double tmp;
                if(op.empty()==true || mat[retnum][op.top()]==1)
                    op.push(retnum);//若运算符栈为空或当前遍历到的运算符优先级大于栈顶运算符，将运算符压入运算符栈
                else{
                    while(mat[retnum][op.top()]==0){//只要当前与运算符优先级小于栈顶元素运算符，则重复循环
                        int ret = op.top();  //保存栈顶运算符
                        op.pop(); //弹出
                        double b = in.top();
                        in.pop();
                        double a = in.top();
                        in.pop();
                        //从数字栈栈顶弹出两个数字，依次保存在遍历a,b中
                        if(ret == 1) tmp = a+b;
                        else if(ret==2) tmp=a-b;
                        else if(ret==3) tmp=a*b;
                        else tmp=a/b;  //按照运算符类型完成运算
                        in.push(tmp);//将结果压入数字栈
                    }
                    op.push(retnum);//将单签运算符压入运算符栈
                }
            }
            if(op.size()==2 && op.top()==0)  break;//若运算符堆栈只有两个元素，且其栈顶元素为标记运算符，则表示表达式求值结束
        }
        printf("%.2f\n",in.top()); //输出数字栈中唯一的数字，即为答案
    }



    return 0;
}








