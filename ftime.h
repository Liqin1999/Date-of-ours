#ifndef FTIME_H_INCLUDED
#define FTIME_H_INCLUDED



#endif // FTIME_H_INCLUDED
void weekday(int temp)
{
    switch(temp){
        case 0:printf("\t周日/Sunday");break;
        case 1:printf("\t周一/Monday");break;
        case 2:printf("\t周二/Tuesday");break;
        case 3:printf("\t周三/Wednesday");break;
        case 4:printf("\t周四/Thursday");break;
        case 5:printf("\t周五/Friday");break;
        case 6:printf("\t周六/Saturday");break;
    }
}

/*!
    公历闰年计算：按一回归年365天5小时48分45.5秒
    1、非整百年：能被4整除的为闰年。(如2004年就是闰年,2001年不是闰年)
    2、整百年：能被400整除的是闰年。(如2000年是闰年，1900年不是闰年)
    3、对于数值很大的年份：这年如果能被3200整除，并且能被172800整除则是闰年。
    如172800年是闰年，86400年不是闰年(因为虽然能被3200整除，但不能被172800整除)
    (此按一回归年365天5h48'45.5''计算)。
*/
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
void delay()
{
    Sleep(10);
}

//int timestamp(struct a)
//{
    //int time_start=(a.min+(a.hour+(a.day+(a.year-2000)yeartype(a.year)/*days*/)*24/*h*/)*60/*min*/)*60/*s*/
//}
