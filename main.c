#include<stdio.h>
#include<string.h>
#include<time.h>

#include"text.h"
#include"ftime.h"

int main()
{
    int i,j;
    char text[50];

    strcpy(text,"\nHello! Dear Qin \n\n\tGet ready for see it?\n");
    fp(text);
    delay();
    strcpy(text,"\tPlease Maximize the window\n");
    fp(text);
    strcpy(text,"\tand press Enter to star our stories:\n");
    fp(text);
    spacesmall();
    delay();
    strcpy(text,"\tQin:I see and I've been ready:");
    fp(text);

    getchar();//start
    spacesmall();
    line();
    //���ú�����Ч����ַ�ͼ��
/*Print "Dear"*/
    spacesmall();
/*1*/printf("************   \n");delay();
/*2*/printf(" **        *** \n");delay();
/*3*/printf(" **          **\n");delay();
/*4*/printf(" **            *      *********         **********    ***  ****\n");delay();
/*5*/printf(" **            *    ***       **     ***         **    ** **   \n");delay();
/*6*/printf(" **            *   **           *    *           **    ***     \n");delay();
/*7*/printf(" **            *   *            **              ***    **      \n");delay();
/*8*/printf(" **            *   ***************      ***********    **      \n");delay();
/*9*/printf(" **            *   **                ***          *    **      \n");delay();
/*0*/printf(" **          **     **               *           **    **      \n");delay();
/*1*/printf(" **        ***       ***      ***     **       ****    **      \n");delay();
/*2*/printf("************           ********        ********   **  ****     \n");delay();
/*Print 'L'*/
/*Print 'i'*/
    spacesmall();
/*1*/printf("****                 ** \n");delay();
/*2*/printf(" **                  ** \n");delay();
/*3*/printf(" **                     \n");delay();
/*4*/printf(" **                 *** \n");delay();
/*5*/printf(" **                  ** \n");delay();
/*6*/printf(" **                  ** \n");delay();
/*7*/printf(" **                  ** \n");delay();
/*8*/printf(" **                  ** \n");delay();
/*9*/printf(" **                  ** \n");delay();
/*0*/printf(" **            *     ** \n");delay();
/*1*/printf(" ***          **     ** \n");delay();
/*2*/printf("****************    ****\n");delay();
/*Print 'Q'*/
/*Print 'i'*/
/*Print 'n'*/
    spacesmall();
/*1*/printf("    *********        **\n");delay();
/*2*/printf("  **         **      **\n");delay();
/*3*/printf(" **           **       \n");delay();
/*4*/printf(" *            **    ***           *******    \n");delay();
/*5*/printf(" *             *     **     *** **      ***  \n");delay();
/*6*/printf(" *             *     **       **          ** \n");delay();
/*7*/printf(" **           **     **       **          ** \n");delay();
/*8*/printf(" **           **     **       **          ** \n");delay();
/*9*/printf(" **  **      **      **       **          ** \n");delay();
/*0*/printf("   **********        **       **          ** \n");delay();
/*1*/printf("      **             **       **          ** \n");delay();
/*2*/printf("       ****         ****     ****        ****\n");delay();
    spacebig();
    line();

    time_t timep;
    struct tm *p;
    time(&timep);
    p =localtime(&timep);
	/*
	** �˺�����õ�tm�ṹ���ʱ�䣬���Ѿ����й�ʱ��ת��Ϊ����ʱ��
    ** p = gmtime(&timep);
	** �����ں�ʱ��ת��Ϊ��������(GMT)ʱ��ĺ���
	*/
	strcpy(text,"\nNow the time is:\n");
	fp(text);delay();
    printf("\t%d��\t", 1900+p->tm_year);delay();
    printf("%d��", 1+p->tm_mon);delay();
    printf("%d��", p->tm_mday);delay();
    int w=p->tm_wday;
    weekday(w);delay();//����ȷ������ܼ���Ӣ�ĵ���
    putchar('\n');delay();
    printf("\t����ĵ� %d��\t", p->tm_yday);delay();//��һ��ĵڼ���
    putchar('\n');delay();
    printf("\t%d��", p->tm_hour);delay();
    printf(" %d��", p->tm_min);delay();
    printf(" %d��", p->tm_sec);delay();
    printf("\tIsdst: %d\t", p->tm_isdst);//����ʱ
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
    strcpy(text,"The time we have been boyfriend/girlfriend is:\n");
    fp(text);
    printf("\t%d��\t",love.year);delay();
    printf("%d��",love.mon);delay();
    printf("%d��",love.day);delay();

    putchar('\n');delay();
    printf("\t%d��",love.hour);delay();
    printf(" %d��",love.min);delay();
    printf(" %d��",love.sec);delay();
    spacesmall();

/*Calculating dates*/
    struct lovetime last;
    last.year=p->tm_year-love.year+1900;

    last.mon=p->tm_mon-love.mon+1;
    if(last.year>0){
        last.mon+=last.year*12;
    }

    int days=yeartype(1900+p->tm_year);//�ж��Ƿ�����
    last.day=p->tm_yday;
    if(last.year>0){
        last.day+=last.year*days;//�������days=365 or days=366���ֱ����ƽ�����������
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
    strcpy(text,"\tcaculating\0");
    fp(text);

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
    spacesmall();
    line();

/*Print 'Marry'*/
/*Print 'Me'*/
/*Print '?'*/

/*Print "I YOU"*/
/*Print "POSTED"*/
/*Print "BY"*/
/*Print "YOUR"*/
/*Print "DEAR"*/
/*Print "ER QUE"*/



    spacesmall();
/*��ӡ����*/
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

    spacesmall();
    strcpy(text,"\tPress Enter twice to continue\n");
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

