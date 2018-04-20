#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED



#endif // TEXT_H_INCLUDED

//!开始文本
void text_start()
{
    char text[50];
    strcpy(text,"\nHello! Dear Qin\n\n\tGet ready to see it?\n");
    fp(text);
    delay();

    strcpy(text,"\tPlease Maximize the window\n");
    fp(text);
    strcpy(text,"\tand press any key to star our stories ;)\n");
    fp(text);
    strcpy(text,"\n\t( Press 'Windows + up' or click that bottom to Maximize the window)\n");
    fp(text);
    spacesmall();
    delay();
    strcpy(text,"\tQin:I see and I've been ready ;)\n\n");
    fp(text);
}

//!中间文本
void text_mid()
{
    char text[50];
    strcpy(text,"\tI am DEEPLY love you, my dear 琴儿.\n\n");
    fp(text);
    strcpy(text,"\tAnd I will be very sad\n\tif we are not together. :(\n\n");
    fp(text);
    strcpy(text,"\tSo I will do my best to marry you!\n");
    fp(text);
    strcpy(text,"\n\tPress to continue. :)\n");
    fp(text);
}

//!结尾文本
void text_end()
{
    char text[50];
    strcpy(text,"\tSurely someday,\n\tI'll tread the rainbow auspicious clouds to marry you.\n\n");
    fp(text);
    strcpy(text,"\t总有一天\n\t我会踏着七彩祥云\n\t去娶你 :)\n");
    fp(text);

    spacesmall();

    strcpy(text,"\tRemember\n\tbe right here waiting for me!\n");
    fp(text);
    strcpy(text,"\t一定不要忘了，\n\t在这儿等我 :)\n");
    fp(text);
    spacesmall();

    strcpy(text,"\tThis program is shot\n");
    fp(text);
    strcpy(text,"\tBut the love between us is never faded!\n\n");
    fp(text);
    strcpy(text,"\tPress Enter twice to see again.\n");
    fp(text);
    strcpy(text,"\tPress '!' in English and Enter to close me ;-)\n");
    fp(text);
}
