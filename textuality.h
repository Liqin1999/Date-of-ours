#ifndef TEXTUALITY_H_INCLUDED
#define TEXTUALITY_H_INCLUDED



#endif // TEXTUALITY_H_INCLUDED
void line()
{
    int i;
    for(i=0;i<30;i++){
        printf("_");
        delay();
    }
    putchar('\n');
}
void spacebig()
{
    int i;
    for(i=0;i<10;i++){
        putchar('\n');
        delay();
    }
}
void spacesmall()
{
    int i;
    for(i=0;i<3;i++){
        putchar('\n');
        delay();
    }
}
void fp(char text[50])
{
    int i;
    for(i=0;text[i]!='\0';i++){
        printf("%c",text[i]);
        delay();
    }
}
