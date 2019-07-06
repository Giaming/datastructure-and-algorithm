#define maxSize 100
#include <stdlib.h>
/******************
 *  串的数据结构定义
 */

// 定长顺序存储结构体定义
typedef struct 
{
    char str[maxSize+1];  // 因为多出一个'\0'作为结束标志
    int length;   // 串的长度，不包含'\0'
}Str;

// 变长分配存储表示
typedef struct 
{
    char *ch;    // 指向动态分配存储区首地址的字符指针
    int length;
}Str;

// 串的基本操作
// 赋值操作
int strassign(Str& str, char *ch)
{
    if(str.ch)
        free(str.ch);     // 释放原空间串
    int len = 0;
    char *c = ch;
    while(*c)    // 求ch串的长度
    {
        ++len;
        ++c;
    }
    if(len==0)    //如果c为空串，则直接返回空串
    {
        str.ch=NULL;
        str.length = 0;
        return 1;
    }
    else
    {
        str.ch = (char*)malloc(sizeof(char)*(len+1));  // 为了多分配一个空间存放'\0'字符
        if(str.ch==NULL)
            return 0;
        else
        {
            c = ch;
            for(int i=0;i<=len;++i,++c)  //注意这里是小于等于,为了将最后的'\0'复制到新串中作为结束标志
            {
                str.ch[i] = *c;
            }
            str.length = len;
            return 1;
        }  
    }
}


// 取串长
int strlength(Str str)
{
    return str.length;
}

// 串比较操作
int strcompare(Str s1,Str s2)
{
    for(int i=0;i<s1.length&&i<s2.length;++i)
    {
        if(s1.ch[i]!=s2.ch[i])
            return s1.ch[i]-s2.ch[i];
    }
    return s1.length-s2.length;
}

// 串连接操作
int concat(Str &str,Str str1,Str str2)
{
    if(str.ch)
    {
        free(str.ch);
        str.ch = NULL;
    }
    str.ch = (char *)malloc(sizeof(char)*(str1.length+str2.length+1));
    if(str.ch==NULL)
        return 0;
    int i=0;
    while(i<str1.length)
    {
        str.ch[i] = str1.ch[i];
        ++i;
    }
    int j=0;
    while(j<str2.length)
    {
        str.ch[i+j] = str2.ch[j];
        ++j;
    }
    str.length = str1.length + str2.length;
    return 1;
}

// 求子串操作
int substring(Str &substr,Str str,int pos,int len)
{
    if(pos<0||pos>str.length||len<0||len>str.length-pos)   // 判断越界
        return 0;
    if(substr.ch)
    {
        free(substr.ch);
        substr.ch = NULL;
    }
    if(len==0)
    {
        substr.length=0;
        substr.ch = NULL;
        return 1;
    }
    else
    {
        substr.ch = (char*)malloc(sizeof(char)*(len+1));
        int i=pos;
        int j=0;
        while(i<pos+len)
        {
            substr.ch[j] = str.ch[i];
            ++j;++i;
        }
        substr.ch[j] = '\0';
        substr.length = len;
        return 1;
    }
}


// 子串的删除
Str DelStr(Str s,int i,int len)   // 删除从第i个字符开始的长度为j的子串
{
    int k;
    Str str;   // 定义结果串
    str.length = 0;   //初始化
    if(i<=0||i>s.length||(i+j)>s.length+1)  //越界判断
        return str;     // 参数不正确时返回空串
    for(k=0;k<i-1;k++)
        str.data[k] = s.data[k];   // 将s.data[0...i-1]复制到str
    for(k=i+j-1;k<s.length;k++)
        str.data[k-j] = s.data[k];
    str.length = s.length-j;
    return str;
}

// 子串的替换
Str RepStr(Str s,int i,int j,Str t)  //将s中第i个字符开始的连续j个字符构成的子串用顺序串t替代
{
    int k;
    Str str;
    str.length = 0;
    if(i<=0||i>s.length||(i+j-1)>s.length)
        return str;
    for(k=0;k<i-1;k++)
        str.data[k] = s.data[k];
    for(k=0;k<t.length;k++)
        str.data[i-1+k] = t.data[k];
    for(k=i+j-1;k<s.length;k++)
        str.data[t.length+k-j] = s.data[k];
    str.length = s.length + t.length;
    return str; 
} 


/*******************************
 *   假设串采用顺序串存储，设计一个算法求串s中出现的第一个最长的连续相同字符构成的平台
 */
void LongestString(Str s, int &index, int &maxlen)
{
    int length,i=1,start;    //length保存局部平台的长度
    index = 0, maxlen = 1;   // index保存最长平台在s中的开始位置，maxlen保存其长度
    while(i<s.length)
    {
        start = i-1;    // 查找局部重复子串
        length = 1;
        while(i<s.length && s.data[i]==s.data[i-1])
        {
            i++;
            length++;
        }
        if(maxlen<length)
        {
            maxlen = length;
            index = i;
        }
        i++;
    }
}




// 串清空操作
int clearstring(Str &str)
{
    if(str.ch)
    {
        free(str.ch);
        str.ch = NULL;
    }
    str.length = 0;
    return 1;
}



// KMP算法
// Brute-Force 算法
// 时间复杂度为 O(m*n)z   // 该算法中存在回溯的情况，而KMP中不存在回溯的情况
int BF(Str s, Str t)   // s表示主串，t表示模式串
{
    int i=0,j=0;  // 这里的i和j都是从0开始，而天晴里面的是从1开始，见下面
    while (i<s.length && j<t.length)
    {
        if(s.data[i]==t.data[j])
        {
            i++;
            j++;
        }
        else
        {
            i=i-j+1;j=0;    // 扫描主串回退，子串从头开始匹配
        }
    }
    if(j>t.length)   // 表示匹配成功
        return (i-t.length);
    else
    {
        return -1;
    }
}

int BF1(Str s, Str t)
{
    int i=1,j=1,k=i;
    while(i<=s.length && j<=t.length)
    {
        if(s.data[i]==t.data[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j=1;
            i=++k;    // k中记录了上一次的起始位置
        }
    }
    if(j>t.length)
        return k;
    else
        return -1;
}



// KMP的next数组
/************************************
 * next[j] = 
 *          -1 当j=0时
 *          MAX{0<k<j且"t0t1...tk-1"="tj-k+1...tj-1"}       当集合非空时
 *          0    其他情况
 * 
 * next数组求解过程：
 *  (1)next[0] = -1, next[1] = 0(j=1),在1~j-1的位置上没有字符，属于其他情况，
 *  (2)如果next[j]=k,表示有"t0t1...tk-1"="tj-k+1...tj-1"
 *      若tk=tj,即有"t0t1...tk-1tk"="tj-k+1...tj-1tj",显然有next[j+1]=k+1
 *      若tk!=tj, 说明tj之前不存在长度为next[j]+1的子串和开头字符其的子串相同
 */

void GetNext(Str t, int next)
{
    int j,k;    
    j=0;k=-1;     // j扫描t,k记录t[j]之前与t开头相同的字符个数
    next[0]=-1;
    while(j<t.length-1)   //求t的所有位置的next值
    {
        if(k==-1||t.data[j]==t.data[k])    // k为-1或比较的字符相等时
        {
            j++;k++;   // j,k依次移动到下一个字符
            next[j] = k;
        }
        else
            k=next[k];
    }
}

// KMP 过程
i=0;j=0;
while(s和t都没有扫描完)
{
    if(j=-1或他们所指的字符相同)
        i和j分别增1;
    else
        i不变，j回退到j=next[j]（即模式串右滑）
}
if(j超界) 返回i-t的长度
else 返回-1

int KMPIndex(Str s, Str t)
{
    int next[maxSize],i=0,j=0;
    GetNext(t,next);
}
