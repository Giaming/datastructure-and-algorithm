/********************************************
题目描述：
    目标是能看尽可能多的电视节目（贪心算法）

输入：
    输入数据包含多个测试实例，每个测试实例的第一行只有一个整数n(n<=100),
表示你喜欢看的节目的总数，然后是n行数据，每行包括两个数据Ti_s,Ti_e(1<=i<=n),
分别表示第i个节目的开始和结束时间，为了简化问题，每个时间都用一个正整数表示。
n=0表示输入结束，不做处理。
输出：
    对于每个测试实例，输出能完整看到的电视节目的个数，每个测试实例的输出占一行。
样例输入：



********************************************/

#include<stdio.h>
#include<algorithm>
using namespace std;

struct program{  //电视节目结构体
    int startTime; //开始时间
    int endTime; // 结束时间
    bool operator < (const program & A) const{
        return endTime < A.endTime;
    }
}buf[100];
int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        if(n==0) break;
        for(int i=0;i<n;i++)
            scanf("%d%d",&buf[i].startTime,&buf[i].endTime);
        sort(buf,buf+n);  //按照结束时间升序排序
        int currentTime = 0, ans = 0;  //记录当前时间变量初始值为0，答案技术初始值为0
        for(int i=0;i<n;i++){   //按照结束时间升序遍历所有的节目
            if(currentTime<=buf[i].startTime){  //若当前时间小于等于该节目的开始时间，那么收看应该在剩余节目里的结束时间最早的节目
                currentTime = buf[i].endTime;//当前时间变为该节目结束时间
                ans++;  //又收看了一个节目
            }
        }
        printf("%d\n",ans); //输出
    }
    return 0;
}

