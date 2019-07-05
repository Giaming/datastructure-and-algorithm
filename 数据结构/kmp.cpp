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