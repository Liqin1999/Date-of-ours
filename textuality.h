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
