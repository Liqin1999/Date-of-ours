#include <iostream>
#include <string.h>
#include <time.h>
#include <windows.h>

using namespace std;

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
void delay()
{
    Sleep(10);
}
void spacesmall()
{
    int i;
    for(i=0;i<2;i++){
        cout<<endl;
    }
}
void fp(char text[50])
{
    int i;
    for(i=0;text[i]!='\0';i++){
        cout<<text[i];
        delay();
    }
}
int yeartype(int a)//判断是否闰年，返回值为一年中的天数
{
    int n;
    if(  (a%400==0) || (a%4==0&&a%100!=0) ){
        n=366;
    }
    else{
        n=365;
    }
    return n;
}
void weekday(int temp)
{
    switch(temp){
        case 0:cout<<"\t周日/Sunday";break;
        case 1:cout<<"\t周一/Monday";break;
        case 2:cout<<"\t周二/Tuesday";break;
        case 3:cout<<"\t周三/Wednesday";break;
        case 4:cout<<"\t周四/Thursday";break;
        case 5:cout<<"\t周五/Friday";break;
        case 6:cout<<"\t周六/Saturday";break;
    }
}

int main()
{

//! Identify the moment we fall in love with each other

    class lovetime love;
    love.year=2018;love.mon=1;love.day=1;
    love.hour=0;love.min=38;love.sec=0;

    class lovetime lastmeet;//上次见面时间
    lastmeet.year=2018;lastmeet.mon=2;lastmeet.day=11;

/*show the time our fall in love*/
    int i;
    char text[50];

    spacesmall();
    strcpy(text,"The time we have been boyfriend/girlfriend is:");
    fp(text);
    spacesmall();
    cout<<"\t"<<love.year<<"年 "<<love.mon<<"月"<<love.day<<"日";delay();
    cout<<" 元旦"<<endl;
    cout<<"\t"<<love.hour<<"点"<<love.min<<"分"<<love.sec<<"秒"<<endl;delay();
    spacesmall();

/*
** 此函数获得的tm结构体的时间，是已经进行过时区转化为本地时间
** p = gmtime(&timep);
** 把日期和时间转换为格林威治(GMT)时间的函数
*/
	strcpy(text,"Now the time of this moment is:\n\n");
	fp(text);delay();

    time_t timep;
    struct tm *p;
    time(&timep);
    p =localtime(&timep);

    cout<<"\t"<<1900+p->tm_year<<"年\t"<<1+p->tm_mon<<"月"<<p->tm_mday<<"日";delay();

    int w=p->tm_wday;//函数确定输出周几，英文单词
    weekday(w);delay();
    cout<<endl;delay();
    cout<<"\t今年的第"<<p->tm_yday+1<<"天"<<endl;delay();//!这一年的第几天，算法局限，补上差的一天
    cout<<endl;delay();
    cout<<"\t"<<p->tm_hour<<"点 "<<p->tm_min<<"分 "<<p->tm_sec<<"秒"<<endl;delay();
    cout<<"\tIsdst:\t"<<p->tm_isdst<<endl;//夏令时

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
    strcpy(text,"The period we fall in love lasts:\n");
    fp(text);
    cout<<endl;delay();

    if(last.year<0){
        cout<<"\tError!Break now!\n"<<endl;
        system("pause");
        exit(0);
    }
    if(last.year==0){
        strcpy(text,"\tLess than 1 year\n");
        fp(text);
    }
    else{
        cout<<"\t"<<last.year<<"+\tyears"<<endl;
    }
    delay();
    cout<<"\t"<<last.mon<<"+\tmonths"<<endl;delay();
    cout<<"\t"<<last.week<<"+\tweeks"<<endl;delay();
    cout<<"\t"<<last.day+1<<"\tdays"<<endl;delay();//按照常人的思维，天数从1开始
    cout<<endl;
    cout<<"\t"<<last.hour<<"\thours"<<endl;delay();
    cout<<"\t"<<last.min<<"\tminutes"<<endl;delay();
    cout<<"\t"<<last.sec<<"seconds"<<endl;delay();
    spacesmall();

//!Show more informations
    strcpy(text,"What's more...\n");
    fp(text);
    cout<<endl;
    cout<<"\t这是我们的第"<<hundreds<<"个一百天"<<endl;delay();
    cout<<"\t距离下一个一百天还有"<<(hundreds+1)*100-last.day<<"天"<<endl;//距离下一个一百天还有多少天

    //如果即将到达下一个一百天，就输出提示信息
    if(last.day+25>=(hundreds+1)*100){
        cout<<"\n\t//马上就是第"<<hundreds+1<<"个一百天啦 (*≧︶≦))(￣▽￣* )ゞ"<<endl;delay();
    }

    cout<<endl;
    system("pause");
    return 0;
}
