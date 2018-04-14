#include<stdio.h>
#include<string.h>
#include<time.h>

#include"text.h"
#include"ftime.h"
#include"dotpoints.h"

int main()
{
    int i,j;
    char text[50];

    strcpy(text,"\nHello! Dear Qin \n\n\tGet ready to see it?\n");
    fp(text);
    delay();
    strcpy(text,"\tPlease Maximize the window\n");
    fp(text);
    strcpy(text,"\tand press Enter to star our stories ;)\n");
    fp(text);
    spacesmall();
    delay();
    strcpy(text,"\tQin:I see and I've been ready ;)");
    fp(text);

    getchar();//start
    spacesmall();
    line();

    //引用函数特效输出字符图案
    spacesmall();

    dot_dear();/*Print "Dear"*/
    spacesmall();

    dot_li();/*Print "Li"*/
    spacesmall();

    dot_qin();/*Print "Qin"*/
    spacebig();

    /*Print "I LOVE YOU"*/


    /*Print "See here"*/
    dot_see_here();
    spacesmall();

    /*Print "↓ ↓ ↓"*/
    for(i=0;i<3;i++){
        dot_down();
        spacesmall();
    }
    spacebig();

    line2();

    time_t timep;
    struct tm *p;
    time(&timep);
    p =localtime(&timep);
	/*
	** 此函数获得的tm结构体的时间，是已经进行过时区转化为本地时间
    ** p = gmtime(&timep);
	** 把日期和时间转换为格林威治(GMT)时间的函数
	*/
	strcpy(text,"\nNow the time of this moment is:\n\n");
	fp(text);delay();
    printf("\t%d年\t", 1900+p->tm_year);delay();
    printf("%d月", 1+p->tm_mon);delay();
    printf("%d日", p->tm_mday);delay();
    int w=p->tm_wday;
    weekday(w);delay();//函数确定输出周几，英文单词
    putchar('\n');delay();
    printf("\t今年的第 %d天\t", p->tm_yday);delay();//这一年的第几天
    putchar('\n');delay();
    printf("\t%d点", p->tm_hour);delay();
    printf(" %d分", p->tm_min);delay();
    printf(" %d秒", p->tm_sec);delay();
    printf("\tIsdst: %d\t", p->tm_isdst);//夏令时
    spacesmall();

/*Identify struct of our love*/
    struct lovetime{
        int year;
        int mon;
        int day;
        int hour;
        int min;
        int sec;
    }love;

/*Identify the moment we fall in love with each other*/
    love.year=2018;love.mon=1;love.day=1;
    love.hour=0;love.min=10;love.sec=0;

/*show the time our fall in love*/
    loop();
    spacesmall();
    strcpy(text,"The time we have been boyfriend/girlfriend is:\n\n");
    fp(text);
    printf("\t%d年\t",love.year);delay();
    printf("%d月",love.mon);delay();
    printf("%d日",love.day);delay();

    putchar('\n');delay();
    printf("\t%d点",love.hour);delay();
    printf(" %d分",love.min);delay();
    printf(" %d秒",love.sec);delay();
    spacesmall();

/*Calculating dates*/
    struct lovetime last;
    last.year=p->tm_year-love.year+1900;

    last.mon=p->tm_mon-love.mon+1;
    if(last.year>0){
        last.mon+=last.year*12;
    }

    int days=yeartype(1900+p->tm_year);//判断是否闰年
    last.day=p->tm_yday;
    if(last.year>0){
        last.day+=last.year*days;//引入变量days=365 or days=366，分别计算平年闰年的天数
    }

    if(p->tm_hour-love.hour<0){
        last.hour=(p->tm_hour+24-love.hour)+(last.day-1)*24;
    }
    else{
        last.hour=(p->tm_hour-love.hour)+last.day*24;
    }

    if(p->tm_min-love.min<0){
        last.min=(p->tm_min+60-love.min)+(last.hour-1)*60;
    }
    else{
        last.min=(p->tm_min-love.min)+last.hour*60;
    }


    if(p->tm_sec-love.sec<0){
        last.sec=(p->tm_sec+60-love.sec)+(last.min-1)*60;
    }
    else{
        last.sec=(p->tm_sec-love.sec)+last.min*60;
    }

/*Start nue dog */
    loop();
    spacesmall();
    //printf("The time we fall in love lasts:\n\n");
    strcpy(text,"The period we fall in love lasts:\n");
    fp(text);
    spacesmall();
    delay();
    //printf("\tcaculating");
    strcpy(text,"\tCaculating\0");
    fp(text);
    for(i=0;i<3;i++){
        putchar('.');
        loop();
    }

    loop();

    spacesmall();
    if(last.year==0){
        strcpy(text,"\tLess than 1 year\n");
        fp(text);
    }
    else{
        printf("\t%d\tyears\n",last.year);
    }
    delay();
    printf("\t%d\tmonths\n",last.mon);delay();
    printf("\t%d\tdays\n",last.day);delay();
    printf("\t%d\thours\n",last.hour);delay;
    printf("\t%d\tseconds\n",last.sec);delay();
    putchar('\n');
    printf("\t这是我们的第%d个一百天\n",last.day/100);delay();
    spacesmall();

    printf("Press Enter to continue.\n");
    getchar();
    line();

/*Print "Will"*/
/*Print "You"*/
/*Print "Marry"*/
/*Print "Me"*/
/*Print '?'*/

/*Print "POSTED"*/
/*Print "BY"*/
/*Print "YOUR"*/
/*Print "DEAR"*/
/*Print "ER QUE"*/

    spacesmall();
/*打印爱心*/
    float z,x,v,y0,ny,nx,nz,nd,d;
    for ( z = 1.5f; z > -1.5f; z -= 0.05f) {
        for ( x = -1.5f; x < 1.5f; x += 0.025f) {
            v = f(x, 0.0f, z);
            if (v <= 0.0f){
                y0 = h(x, z);
                ny = 0.01f;
                nx = h(x + ny, z) - y0;
                nz = h(x, z + ny) - y0;
                nd = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);
                d = (nx + ny - nz) * nd * 0.5f + 0.5f;
                putchar(".:-=+*#%@"[(int)(d * 5.0f)]);
            }
            else{
                putchar(' ');
            }
        }
        putchar('\n');delay();
    }

    //dot_hj();

    spacebig();
    strcpy(text,"\tThis program is shot\n");
    fp(text);
    strcpy(text,"\tBut the love between us is never faded!\n\n");
    fp(text);
    strcpy(text,"\tPress Enter twice to see again.\n");
    fp(text);
    strcpy(text,"\tPress '!' and Enter to close me ;-)\n");
    fp(text);

    spacesmall();

    getchar();
    if(getchar()=='!'){
        return 0;
    }
    else{
        line();
        spacesmall();
        return main();
    }
}

