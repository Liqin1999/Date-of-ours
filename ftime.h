#ifndef FTIME_H_INCLUDED
#define FTIME_H_INCLUDED



#endif // FTIME_H_INCLUDED
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
void loop()
{
    int i;
    for(i=0;i<5;i++){
        delay();
    }
}
void  cutdown()
{
    spacebig();
    dot_3();
    spacesmall();
    dot_2();
    spacesmall();
    dot_1();
}

//int timestamp(struct a)
//{
    //int time_start=(a.min+(a.hour+(a.day+(a.year-2000)yeartype(a.year)/*days*/)*24/*h*/)*60/*min*/)*60/*s*/
//}
