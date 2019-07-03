/*******************************************
题目描述:
    we now use the Gregorian style of dating in Russia.The leap years are years with number divisible
by 100,or divisible by 400.For example,years of 2004,2180 and 2400 are leap.Years 2004,2181 and 2300 are not leap.
    Your task is to write a program which will compute the day of week corresponding to a given date in the
nearest past or in the future using today's agreement about dating.
输入：
    There is one single line contains the day number d,month name M and year name y(1000<=y<=3000).
The month name is the corresponding English name starting from the capital letter.
输出：
    Output a single line with the English name of the day of week corresponding to the date,
starting from the capital letter.All other letters must be in lower case.
样例输入:
    9 October 2001
    14 October 2001
样例输出:
    Tuesday
    Sunday
*******************************************/

#include<stdio.h>
#include<string.h>
#define ISEAP(x) x%100 != 0 && x%4==0 || x%400==0?1:0
int dayOfMonth[13][2] = {
    0,0,
    31,31,
    28,29,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31
};  //预存每月的天数，注意二月配合宏定义作特殊处理

struct Date{//日期类，方便日期的推移
    int Day;
    int Month;
    int Year;
    void nextDay(){//计算下一天的日期
        Day++;
        if(Day>dayOfMonth[Month][ISEAP(Year)]){ //若日期超过了当月最大天数
            Day = 1;
            Month++;//进入下一月
            if(Month>12){
                Month=1;
                Year++; //进入下一年
            }
        }
    }
};
int buf[3001][13][32];
char monthName[13][20] = {
    "",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};  //月名 每个月名对应下标1到12
char weekName[7][20] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};  //周名 对应下标0到6

int main(){
    Date tmp;
    int cnt = 0;
    tmp.Day = 1;
    tmp.Month = 1;
    tmp.Year = 0;
    while(tmp.Year != 3001){
        buf[tmp.Year][tmp.Month][tmp.Day] = cnt;
        tmp.nextDay();
        cnt++;
    }  //预处理出每一天与原点日期的天数差
    int d,m,y;
    char s[20];
    while(scanf("%d%s%d",&d,s,&y)!=EOF){
        for(m=1;m<=12;m++){
            if(strcmp(s,monthName[m]) == 0){
                break;  //将输入字符串与月名比较的出月数
            }
        }
        int days = buf[y][m][d] - buf[2018][12][31];  //计算给定日期与今日日期的天数间隔（注意可能为负）
        days +=1;  //今天（2012.7.16）为星期一，对应数组下标为1，则计算1经过days天后的下标
        puts(weekName[(days % 7 + 7) % 7]);//将计算后得出的下标用7对其取模，并且保证其为非负数，则该下标即为答案说对应的下标
    }
    return 0;
}


