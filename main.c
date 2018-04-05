#include <stdio.h>
#include <string.h>
#include <time.h>

void line()
{
    int i;
    for(i=0;i<40;i++){
        printf("*");delay();
    }
    putchar('\n');
}
void spacebig()
{
    printf("\n\n\n\n\n");
}
void spacesmall()
{
    printf("\n\n");
}
void delay()
{
    int i,j,k,t=300;
    for(i=0;i<t;i++){
        for(j=0;j<t;j++){
            for(k=0;k<t;k++){
                //null
            }
        }
    }
}
void weekday(int temp)
{
    switch(temp){
        case 0:printf("\t����/Sunday");break;
        case 1:printf("\t��һ/Monday");break;
        case 2:printf("\t�ܶ�/Tuesday");break;
        case 3:printf("\t����/Wednesday");break;
        case 4:printf("\t����/Thursday");break;
        case 5:printf("\t����/Friday");break;
        case 6:printf("\t����/Saturday");break;
    }
}
int yeartype(int a)//�ж��Ƿ����꣬����ֵΪһ���е�����
{
    int n;
    if( (a%4==0 && a%400==0)||a%400==0){
        n=366;
    }
    else{
        n=365;
    }
    return n;
}
float f(float x, float y, float z)
{
    float a;
    a = x * x + 9.0f / 4.0f * y * y + z * z - 1;
    return a * a * a - x * x * z * z * z - 9.0f / 80.0f * y * y * z * z * z;
}


float h(float x, float z)
{
    float y;
    for ( y = 1.0f; y >= 0.0f; y -= 0.001f)
        if (f(x, y, z) <= 0.0f)
            return y;
    return 0.0f;
}
int main()
{
    time_t timep;
    struct tm *p;
    time(&timep);
    p =localtime(&timep);

	/*
	** �˺�����õ�tm�ṹ���ʱ�䣬���Ѿ����й�ʱ��ת��Ϊ����ʱ��
    ** p = gmtime(&timep);
	** �����ں�ʱ��ת��Ϊ��������(GMT)ʱ��ĺ���
	*/
	printf("\nNow the time is:\n");delay();
    printf("\t%d��\t", 1900+p->tm_year);delay();
    printf("%d��", 1+p->tm_mon);delay();
    printf("%d��", p->tm_mday);delay();
    int w=p->tm_wday;
    weekday(w);delay();//����ȷ������ܼ���Ӣ�ĵ���
    putchar('\n');
    printf("\t����ĵ� %d��\t", p->tm_yday);delay();//��һ��ĵڼ���
    putchar('\n');
    printf("\t%d��", p->tm_hour);delay();
    printf(" %d��", p->tm_min);delay();
    printf(" %d��", p->tm_sec);delay();
    printf("\tIsdst: %d\t", p->tm_isdst);//����ʱ
    spacesmall();delay();
    line();

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
    spacesmall();
    //printf("The time we fall in love lasts:\n\n");
    char text[50];
    int i,j;
    strcpy(text,"The time we fall in love lasts:\n");
    for(i=0;text[i]!='\0';i++){
        printf("%c",text[i]);
        delay();
    }
    spacesmall();
    delay();
    printf("\tcaculating");
    for(i=0;i<5;i++){
        delay();
    }
    for(i=0;i<3;i++){
        putchar('.');
        for(j=0;j<5;j++){
            delay();
        }
    }
    spacesmall();
    if(last.year==0){
        printf("\tLess than 1 year\n");
    }
    else{
        printf("\t%d\tyears\n",last.year);
    }
    printf("\t%d\tmonths\n",last.mon);delay();
    printf("\t%d\tdays\n",last.day);delay();
    printf("\t%d\thours\n",last.hour);delay;
    printf("\t%d\tseconds\n",last.sec);delay();
    spacesmall();
    line();

/*Print 'L'*/
/*Print 'i'*/
    spacesmall();
/*Print 'Q'*/
/*Print 'i'*/
/*Print 'n'*/
    spacesmall();
/*Print 'Marry'*/
/*Print 'Me'*/
/*Print '?'*/
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

	return 0;
}

