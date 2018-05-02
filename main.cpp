#include <iostream>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdio.h>

#include "ftime.h"
#include "textuality.h"

using namespace std;

int main()
{

/*Identify struct of our love*/
    class lovetime{
    public:
        int year;
        int mon;
        int week;
        int day;
        int hour;
        int min;
        int sec;

    private:
        //

    };

//! Identify the moment we fall in love with each other

    class lovetime love;
    love.year=2018;love.mon=1;love.day=1;
    love.hour=0;love.min=38;love.sec=0;


/*show the time our fall in love*/
    int i;
    char text[50];
    spacesmall();
    strcpy(text,"The time we have been boyfriend/girlfriend is:\n\n");
    fp(text);
    printf("\t%d年\t",love.year);delay();
    //cout<< <<endl;
    printf("%d月",love.mon);delay();
    printf("%d日",love.day);delay();
    putchar('\n');delay();
    printf("\t%d点",love.hour);delay();
    printf(" %d分",love.min);delay();
    printf(" %d秒",love.sec);delay();
    spacesmall();

/*
** 此函数获得的tm结构体的时间，是已经进行过时区转化为本地时间
** p = gmtime(&timep);
** 把日期和时间转换为格林威治(GMT)时间的函数
*/
	strcpy(text,"\nNow the time of this moment is:\n\n");
	fp(text);delay();

    time_t timep;
    struct tm *p;
    time(&timep);
    p =localtime(&timep);

    printf("\t%d年\t", 1900+p->tm_year);delay();
    printf("%d月", 1+p->tm_mon);delay();
    printf("%d日", p->tm_mday);delay();

    int w=p->tm_wday;//函数确定输出周几，英文单词
    weekday(w);delay();

    putchar('\n');delay();
    printf("\t今年的第 %d天\t", p->tm_yday+1);delay();//!这一年的第几天，算法局限，补上差的一天
    putchar('\n');delay();
    printf("\t%d点", p->tm_hour);delay();
    printf(" %d分", p->tm_min);delay();
    printf(" %d秒", p->tm_sec);delay();
    printf("\tIsdst: %d\t", p->tm_isdst);//夏令时

//!Calculating dates
    struct lovetime last;
    last.year=p->tm_year-love.year+1900;

    //计算月数
    last.mon=p->tm_mon-love.mon+1;
    for(i=last.year;i>0;i--){//'i' is years of our love continue
        last.mon+=last.year*12;
    }

    //计算天数
    int hundreds;
    //days=yeartype(1900+p->tm_year);
    //days变量运算，判断是否闰年
    last.day=p->tm_yday;//!算法局限，求精按从零开始
    for(i=1900+p->tm_year/*now*/;i-love.year>0;i--){//'i' is years of now, and self--
        last.day+=yeartype(i-1);//引入变量days=365 or days=366，分别计算平年闰年的天数
    }
    hundreds=last.day/100;//计算第几个一百天

    //计算周数
    last.week=last.day/7;

    //计算小时
    if(p->tm_hour-love.hour<0){
        last.hour=(p->tm_hour+24-love.hour)+(last.day-1)*24;
    }
    else{
        last.hour=(p->tm_hour-love.hour)+last.day*24;
    }

    //计算分钟
    if(p->tm_min-love.min<0){
        last.min=(p->tm_min+60-love.min)+(last.hour-1)*60;
    }
    else{
        last.min=(p->tm_min-love.min)+last.hour*60;
    }

    //计算秒数
    if(p->tm_sec-love.sec<0){
        last.sec=(p->tm_sec+60-love.sec)+(last.min-1)*60;
    }
    else{
        last.sec=(p->tm_sec-love.sec)+last.min*60;
    }


/**/
//!Start nue dog
/**/
    spacesmall();
    //printf("The time we fall in love lasts:\n\n");
    strcpy(text,"The period we fall in love lasts:\n");
    fp(text);
    spacesmall();
    delay();
    strcpy(text,"\tCaculating\0");
    fp(text);
    for(i=0;i<3;i++){
        putchar('.');
        delay();
    }
    cout<<"\n"<<endl;
    if(last.year<0){
        printf("\tError!Break now!\n");
        system("pause");
        exit(0);
    }
    if(last.year==0){
        strcpy(text,"\tLess than 1 year\n");
        fp(text);
    }
    else{
        printf("\t%d\tyears\n",last.year);
    }
    delay();
    printf("\t%d\tmonths\n",last.mon);delay();
    printf("\t%d\tweeks\n",last.week);delay();
    printf("\t%d\tdays\n",last.day+1);delay();//按照常人的思维，天数从1开始
    putchar('\n');
    printf("\t%d\thours\n",last.hour);delay();
    printf("\t%d\tminutes\n",last.min);delay();
    printf("\t%d\tseconds\n",last.sec);delay();
    spacesmall();

//!Show more informations
    strcpy(text,"What's more...\n");
    fp(text);
    spacesmall();
    printf("\t这是我们的第%d个一百天\n",hundreds);delay();
    printf("\t距离下一个一百天还有%d天\n",(hundreds+1)*100-last.day);//距离下一个一百天还有多少天

    //如果即将到达下一个一百天，就输出提示信息
    if(last.day+25>=(hundreds+1)*100){
        printf("\n\t//马上就是第%d个一百天啦 (*≧︶≦))(￣▽￣* )ゞ\n",hundreds+1);delay();
    }

    system("pause");
    return 0;
}
