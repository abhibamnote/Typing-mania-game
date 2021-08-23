#include<stdio.h>
#include<stdlib.h>
#include"conio2.h"
#include<time.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>

int  s1(void);
int  s2(void);
int  s4(void);
void s5(void);
void aftergame(float accuracy, float wpm,double usedtime);
void total();
void game(char *line);
void getdata();
void instruct();
struct userData{
    char username[16];
    char pass[6];
    float wordsp,accur;
}user,temp,t2;
void sort(struct userData arr[],int q);
int q=0;
int mistake=0,totalalp=0;
float wpm=0,accuracy=0;


struct userData arr[50];
long int size=sizeof(user);
int new_exist=0;
int main()
{
    FILE *ptr;
    ptr=fopen("list.dat","rb+");
    if(ptr==NULL)
    {
        ptr=fopen("list.dat","wb+");
        if(ptr==NULL)
        {
            printf("Unable to open file");
            exit(1);
        }
    }
    clock_t start, end;
    double usedtime;
    int r=0,j=0;
label:
    textcolor(WHITE);
    textbackground(BLACK);
    clrscr();
    r=s1();

    clrscr();
    switch(r)
    {
        case 1:
            {
                int r1=0;
                r1=s2();
                new_exist=r1;
                if(r1==0)
                {
                    goto label;
                }else if(r1==-1)
                {
                    textcolor(WHITE);
                    textbackground(BLACK);
                    clrscr();

                }

                switch(r1)           // MAIN game switch
                {
                    case 1:
                        {
                            // clrscr();
                            rewind(ptr);
                            getdata();
                            clrscr();
                            instruct();
                            clrscr();
                            total();
                            user.accur=accuracy;
                            user.wordsp=wpm;
                            fseek(ptr,0,SEEK_END);
                            fwrite(&user,size,1,ptr);
                            textcolor(WHITE);
                            textbackground(BLACK);
                            clrscr();
                            goto label;
                            break;
                        }
                    case 2:
                            getdata();
                            rewind(ptr);
                            while(fread(&temp,size,1,ptr)==1)
                            {
                                if(strcmp(temp.username,user.username)==0 && strcmp(temp.pass,user.pass)==0)
                                {
                                    j=1;
                                    break;
                                }


                            }
                        if(j==0)
                        {
                            textbackground(BLACK);
                            textcolor(WHITE);
                            clrscr();
                            printf("Given user does not exist\n");
                            printf("\n\t\tPress any key to go to main menu");
                            getch();
                            goto label;
                        }

                            clrscr();
                            instruct();
                            clrscr();
                            total();



                                user.accur=accuracy;
                                user.wordsp=wpm;
                                if(temp.wordsp<=user.wordsp && temp.accur<=user.accur)
                                    {

                                        rewind(ptr);
                                        while(fread(&temp,size,1,ptr)==1)
                                            {
                                                if(strcmp(temp.username,user.username)==0 && strcmp(temp.pass,user.pass)==0)
                                                {
                                                    temp.wordsp=user.wordsp;
                                                    temp.accur=user.accur;
                                                    fseek(ptr,-size,SEEK_CUR);
                                                    fwrite(&temp,size,1,ptr);
                                                    break;
                                                }


                                            }
                                    }

                            textcolor(WHITE);
                            textbackground(BLACK);
                            clrscr();
                            goto label;

                }
                break;
            }
        case 2:
            {
                q=0;
                rewind(ptr);
                while(fread(&t2,size,1,ptr)==1)
                {
                    arr[q]=t2;
                    q++;
                }
                sort(arr,q);
                int r=s4();

               if(r==1)
               {
                   goto label;
               }else if(r==2)
               {
                   textcolor(WHITE);
                   textbackground(BLACK);
                   clrscr();
               }else{
                goto label;
               }

                break;
            }

        case 3:
            {
               s5();
               char c;
               c=getch();

               if(c==8)
               {
                   goto label;
               }else if(c==27)
               {
                   textcolor(WHITE);
                   textbackground(BLACK);
                   clrscr();
               }

               break;
            }

        case 4:

            return 0;
            break;
    }
    fclose(ptr);
    return 0;

}
int s1(void)
{
    char ch1,ch2;
    int i=100,j=20;

    for(i=100;i>=20;i--)
        {
            if(i!=100)
            {
                gotoxy(i,j);
            }
            for(j=20;j>=5;j--)
            {
                textbackground(MAGENTA);
                gotoxy(i,j);
                printf(" ");

            }
            j=20;
        }

        textcolor(BLACK);

        gotoxy(37,5);
        //printf("\x1b[1m");
        printf("<-----------------TYPING GAME------------------>");

        //printf("\x1b[32m");
        gotoxy(21,10);
        printf("1.PLAY GAME\n");
        gotoxy(20,11);
        printf(" 2.LEADERBOARD\n");
        gotoxy(20,12);
        printf(" 3.ABOUT\n");
        gotoxy(20,13);
        printf(" 4.EXIT\n");
        gotoxy(20,10);
        _setcursortype(_SOLIDCURSOR);
        int y=10;
        int option=1;
        while(ch1=getch()!='\r')
    {
       ch2=getch();
       switch(ch2)
       {
            case 72:
                if(y==10)
                {
                    option=4;
                    y=13;

                }else{
                    option--;
                    y--;
                }
                gotoxy(20,y);
                break;
            case 80:
                if(y==13)
                {
                    option=1;
                    y=10;
                }else{
                    option++;
                    y++;
                }
                gotoxy(20,y);
               break;

       }
    }
    textcolor(WHITE);
    textbackground(BLACK);
    clrscr();
    return option;

}
void s5(void)
{
    int i=100,j=20;


    for(i=100;i>=20;i--)
        {
            if(i!=100)
            {
                gotoxy(i,j);
            }
            for(j=20;j>=5;j--)
            {
                textbackground(MAGENTA);
                gotoxy(i,j);
                printf(" ");

            }
            j=20;
        }

        textcolor(BLUE);
        gotoxy(37,5);
        //printf("\x1b[1m");
        printf("<-----------------TYPING GAME------------------>");
        gotoxy(20,8);
        textcolor(BLACK);
        printf("THIS IS A BASIC CONSOLE APPLICATION GAME WITHOUT THE USE OF GRAPHICS\n");
        gotoxy(20,9);
        printf("IT PROMPTS A PARAGRAPH ON THE SCREEN AND THEN THE USER CAN TYPE THE PARAGRAPH");
        gotoxy(20,10);
        printf("IT PRINTS THE TEXT IN GREEN IF USER HAS ENTERED THE CHARACTER CORRECTLY ELSE");
        gotoxy(20,11);
        printf("IT PRINTS THE CHARACTER IN RED.THE GAME ALSO PROVIDES A LEADERBOARD FOR A SENSE");
        gotoxy(20,12);
        printf("OF COMPETITION AND YOU CAN ALSO VIEW YOUR LATEST RESPONSE AND STATS FOR PREVIOUS");
        gotoxy(20,13);
        printf("RESPONSES.HAPPY TYPING , HOPE YOU LIKED THE PROGRAM :) .");
        textcolor(BLACK);
        gotoxy(30,17);
        printf("PRESS BACKSPACE TO GO BACK");
        gotoxy(30,18);
        printf("PRESS ESC TO EXIT");
        gotoxy(20,21);


}
int s2(void)
{

    clrscr();
    int i=100,j=20;

    for(i=100;i>=20;i--)
        {
            if(i!=100)
            {
                gotoxy(i,j);
            }
            for(j=20;j>=5;j--)
            {
                textbackground(MAGENTA);
                gotoxy(i,j);
                printf(" ");

            }
            j=20;
        }
        textcolor(BLUE);
        gotoxy(37,5);
        //printf("\x1b[1m");
        printf("<-----------------TYPING GAME------------------>");
        textcolor(BLACK);
        gotoxy(30,10);
        printf("1.NEW USER");
        gotoxy(30,11);
        printf("2.EXISTING USER");
        gotoxy(30,17);
        printf("PRESS BACKSPACE TO GO BACK");
        gotoxy(30,18);
        printf("PRESS ESC TO EXIT");
        gotoxy(30,10);

        char c1,c2;
        int y=10;
        int option=1;
        c1=getch();
        while(c1!='\r' && c1!=8 && c1!=27)
        {
            switch(c2=getch())
            {
                case 72:
                    {
                        if(y==10)
                        {
                            option=2;
                            y=11;
                        }
                        else{
                            option--;
                            y--;
                        }
                        gotoxy(30,y);
                        break;
                    }
                 case 80:
                     {
                         if(y==11)
                         {
                             option=1;
                             y=10;
                         }else{
                            option++;
                            y++;
                         }
                         gotoxy(30,y);
                         break;
                     }
            }
            c1=getch();
        }

    if(c1==8)
    {
        return 0;
    }
    else if(c1==27)
    {
        return -1;
    }
    else
    {return option;}

}

int s4(void)
{
   clrscr();
   int X=10,Y=10;
    int i=90,j=25;

    for(i=90;i>=5;i--)
        {
            if(i!=100)
            {
                gotoxy(i,j);
            }
            for(j=25;j>=5;j--)
            {
                textbackground(MAGENTA);
                gotoxy(i,j);
                printf(" ");

            }
            j=30;
        }
   textcolor(BLACK);
   gotoxy(10,5);
   printf("___________LEADERBOARD___________");
   gotoxy(8,7);
   printf("RANK");
   gotoxy(24,7);
   printf("USERNAME");
   gotoxy(45,7);
   printf("WPM");
   gotoxy(8,24);
   printf("PRESS BACKSPACE TO GO BACK");
   gotoxy(8,25);
   printf("PRESS ESC TO EXIT");
   for(i=0;i<10;i++)
    {
        gotoxy(X,Y);
        printf("%d ",i+1);
        gotoxy(X+14,Y);
        printf("%s",arr[i].username);
        gotoxy(X+34,Y);
        printf("%.2f",arr[i].wordsp);
        Y++;

    }


   char c1,c2;
   int x=8,y=9;
   gotoxy(x,y);

    while((c1=getch())==-32)
   {
       switch(c2=getch())
       {
            case 72:
                if(y==9)
                {
                    y=23;
                }else{
                    y--;
                }
                gotoxy(x,y);
                break;
            case 80:
                if(y==23)
                {
                    y=9;
                }else{
                    y++;
                }
                gotoxy(x,y);
                break;

       }

   }
   if(c1==8)
   { return 1;}
   else if(c1==27)
   {
       return 2;
   }
   return 0;
}

// MAINNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN GGGGGGGAAAAAAAAAAAAAMMMMMMMMMMMMMEEEEEEEEEEEEE
void game(char *line){
    int i=0;
    int j=0;
    char str[500];
    for(i=0,j=0;line[j]!='\0';i++,j++){
        str[i]=getch();

        if(str[i]==27)
        {
            break;
        }
        if(str[i]==line[j])
        {
            textcolor(GREEN);
            printf("%c",str[i]);
        }
        else if(str[i]!=line[j])
        {
            textcolor(RED);
            printf("%c",str[i]);
        }
        if(str[i]==8)
        {
            j=j-2;
            i=i-2;
        }
    }
    totalalp=strlen(str);
    for(int i=0;i<(strlen(line)-1);i++){
        if(str[i]!=line[i]){
            mistake++;
        }
    }

    textcolor(WHITE);
    printf("\n");
}


void total(){
    {
    clock_t start, end;
    double usedtime;

    textcolor(WHITE);
    textbackground(BLACK);
    clrscr();
    FILE* file = fopen("abc.txt", "r"); /* should check the result */
    char line[256];
    //instructions function here
    getch();
    start= clock();
    while (fgets(line, sizeof(line), file)) {
    printf("%s", line);
    game(line);

    }
    /* may check feof here to make a difference between eof and io failure -- network
       timeout for instance */

    end=clock();

    usedtime= ((double) (end - start)) / CLOCKS_PER_SEC;
       //printf("\n\n\n\n\nmistakes are %d.  %f",mistake,usedtime);
    fclose(file);

    wpm=(totalalp*60)/(usedtime*5);
    accuracy=((totalalp-mistake)*100)/totalalp;
    printf("\n\nPress any key to continue");
    getch();
    aftergame(accuracy,wpm,usedtime);

    }
}


void aftergame(float accuracy, float wpm,double usedtime){
    int i=80,j=20;

    for(i=80;i>=30;i--)
        {
            if(i!=80)
            {
                gotoxy(i,j);
            }
            for(j=25;j>=20;j--)
            {
                textbackground(MAGENTA);
                gotoxy(i,j);
                printf(" ");

            }
            j=25;
        }
        textcolor(BLACK);
		gotoxy(40,21);
		printf("Words per min are:- %.2f",wpm);
		gotoxy(40,22);
		printf("Accuracy is %.2f",accuracy);
        gotoxy(40,23);
        printf("Time used is %.2lf",usedtime);
        gotoxy(40,25);
        printf("Press any key to continue.");
		getch();
}

void getdata(){
	int i=80,j=20;

    for(i=80;i>=20;i--)
        {
            if(i!=80)
            {
                gotoxy(i,j);
            }
            for(j=20;j>=5;j--)
            {
                textbackground(MAGENTA);
                gotoxy(i,j);
                printf(" ");

            }
            j=20;
        }
        textcolor(BLACK);

		gotoxy(35,8);
		printf("Enter User name(15 characters max):- ");
		scanf("%s",user.username);
		gotoxy(35,10);
		printf("Enter a password(5 characters max):- ");
		scanf("%s",user.pass);
        textcolor(WHITE);
	    textbackground(BLACK);
}

void instruct(){
	int i=80,j=20;

    for(i=80;i>=20;i--)
        {
            if(i!=80)
            {
                gotoxy(i,j);
            }
            for(j=20;j>=5;j--)
            {
                textbackground(MAGENTA);
                gotoxy(i,j);
                printf(" ");

            }
            j=20;
        }
        textcolor(BLACK);

		gotoxy(20,6);
		printf("1) DO NOT USE [BACKSPACE] AFTER A LINE ENDS.");
		gotoxy(20,8);
		printf("2) PRESS [SPACE] AT THE END OF LINE TO MOVE TO NEXT LINE.");
		gotoxy(20,10);
		printf("3) YOU CANNOT END THE GAME ONCE STARTED. ");
		gotoxy(20,12);
		printf("4) ONCE YOU PRESS ANY KEY, THE TIMER STARTS. ");
		gotoxy(20,14);
		printf("5) DO NOT OPEN GAME IN FULLSCREEN");
		gotoxy(20,18);
		printf("Press any key to continue.");
		getch();
		textcolor(WHITE);
		textbackground(BLACK);

}
void sort(struct userData arr[],int q){
    int i,k,swap=0;
    struct userData temp;
    for(i=0;i<q-1;i++){
        for(k=0;k<q-1;k++){
            if(arr[k].wordsp<arr[k+1].wordsp){
            temp=arr[k+1];
            arr[k+1]=arr[k];
            arr[k]=temp;
            swap=1;
            }
        }
        if(swap==0){
            break;
        }
    }

}
