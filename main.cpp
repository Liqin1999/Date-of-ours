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
int yeartype(int a)//�ж��Ƿ����꣬����ֵΪһ���е�����
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
        case 0:cout<<"\t����/Sunday";break;
        case 1:cout<<"\t��һ/Monday";break;
        case 2:cout<<"\t�ܶ�/Tuesday";break;
        case 3:cout<<"\t����/Wednesday";break;
        case 4:cout<<"\t����/Thursday";break;
        case 5:cout<<"\t����/Friday";break;
        case 6:cout<<"\t����/Saturday";break;
    }
}

int main()
{

//! Identify the moment we fall in love with each other

    class lovetime love;
    love.year=2018;love.mon=1;love.day=1;
    love.hour=0;love.min=38;love.sec=0;

    class lovetime lastmeet;//�ϴμ���ʱ��
    lastmeet.year=2018;lastmeet.mon=2;lastmeet.day=11;

/*show the time our fall in love*/
    int i;
    char text[50];

    spacesmall();
    strcpy(text,"The time we have been boyfriend/girlfriend is:");
    fp(text);
    spacesmall();
    cout<<"\t"<<love.year<<"�� "<<love.mon<<"��"<<love.day<<"��";delay();
    cout<<" Ԫ��"<<endl;
    cout<<"\t"<<love.hour<<"��"<<love.min<<"��"<<love.sec<<"��"<<endl;delay();
    spacesmall();

/*
** �˺�����õ�tm�ṹ���ʱ�䣬���Ѿ����й�ʱ��ת��Ϊ����ʱ��
** p = gmtime(&timep);
** �����ں�ʱ��ת��Ϊ��������(GMT)ʱ��ĺ���
*/
	strcpy(text,"Now the time of this moment is:\n\n");
	fp(text);delay();

    time_t timep;
    struct tm *p;
    time(&timep);
    p =localtime(&timep);

    cout<<"\t"<<1900+p->tm_year<<"��\t"<<1+p->tm_mon<<"��"<<p->tm_mday<<"��";delay();

    int w=p->tm_wday;//����ȷ������ܼ���Ӣ�ĵ���
    weekday(w);delay();
    cout<<endl;delay();
    cout<<"\t����ĵ�"<<p->tm_yday+1<<"��"<<endl;delay();//!��һ��ĵڼ��죬�㷨���ޣ����ϲ��һ��
    cout<<endl;delay();
    cout<<"\t"<<p->tm_hour<<"�� "<<p->tm_min<<"�� "<<p->tm_sec<<"��"<<endl;delay();
    cout<<"\tIsdst:\t"<<p->tm_isdst<<endl;//����ʱ

//!Calculating dates
    struct lovetime last;
    last.year=p->tm_year-love.year+1900;

    //��������
    last.mon=p->tm_mon-love.mon+1;
    for(i=last.year;i>0;i--){//'i' is years of our love continue
        last.mon+=last.year*12;
    }

    //��������
    int hundreds;
    //days=yeartype(1900+p->tm_year);
    //days�������㣬�ж��Ƿ�����
    last.day=p->tm_yday;//!�㷨���ޣ��󾫰����㿪ʼ
    for(i=1900+p->tm_year/*now*/;i-love.year>0;i--){//'i' is years of now, and self--
        last.day+=yeartype(i-1);//�������days=365 or days=366���ֱ����ƽ�����������
    }
    hundreds=last.day/100;//����ڼ���һ����

    //��������
    last.week=last.day/7;

    //����Сʱ
    if(p->tm_hour-love.hour<0){
        last.hour=(p->tm_hour+24-love.hour)+(last.day-1)*24;
    }
    else{
        last.hour=(p->tm_hour-love.hour)+last.day*24;
    }

    //�������
    if(p->tm_min-love.min<0){
        last.min=(p->tm_min+60-love.min)+(last.hour-1)*60;
    }
    else{
        last.min=(p->tm_min-love.min)+last.hour*60;
    }

    //��������
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
    cout<<"\t"<<last.day+1<<"\tdays"<<endl;delay();//���ճ��˵�˼ά��������1��ʼ
    cout<<endl;
    cout<<"\t"<<last.hour<<"\thours"<<endl;delay();
    cout<<"\t"<<last.min<<"\tminutes"<<endl;delay();
    cout<<"\t"<<last.sec<<"seconds"<<endl;delay();
    spacesmall();

//!Show more informations
    strcpy(text,"What's more...\n");
    fp(text);
    cout<<endl;
    cout<<"\t�������ǵĵ�"<<hundreds<<"��һ����"<<endl;delay();
    cout<<"\t������һ��һ���컹��"<<(hundreds+1)*100-last.day<<"��"<<endl;//������һ��һ���컹�ж�����

    //�������������һ��һ���죬�������ʾ��Ϣ
    if(last.day+25>=(hundreds+1)*100){
        cout<<"\n\t//���Ͼ��ǵ�"<<hundreds+1<<"��һ������ (*�R��Q))(������* )�g"<<endl;delay();
    }

    cout<<endl;
    system("pause");
    return 0;
}
