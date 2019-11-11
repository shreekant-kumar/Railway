#include<stdio.h>
#include<stdlib.h>
#include "conio2.h"
#include "rlyres.h"
#include<string.h>
#include<ctype.h>
int enterchoice()
{

    int choice,i;

    gotoxy(28,1);
    textattr(YELLOW);


    printf("railway reservation system \n");
    for(i=1; i<=70; i++)
    {
        printf("-");
        printf("-");

    }
    printf("1->View Trains\n2->Book Tickets\n3->View tickets\n4->Search Ticket no\n5->View All Bookings\n6->View Train Bookings\n7->Cancel Tickets\n8->Cancel Trains\n9->Search Train\n10->Quit\n\n");
    printf("enter choice:");

    scanf("%d",&choice);
    return choice;
}
void add_trains()
{
    FILE *fp=fopen("F:/railway reservation system//railway//alltrain1.txt","rb");
    if(fp==NULL)
    {

        train alltrains[5]=
        {
            {"123","BPL","DEL",2100,1500},
            {"543","BPL","GOMO",3100,2000},
            {"183","BPL","KOAA",4100,2500},
            {"523","BPL","CPR",4500,3000},
            {"529","BPL","DHN",2300,1400}

        };
        fp=fopen("F:/railway reservation system//railway//alltrain1.txt","wb");
        if(fp==NULL)
            printf("nothing");
        fwrite(&alltrains,5*sizeof(train),1,fp);
        printf("file saved successfully");
        fclose(fp);
        getch();
    }
    else
    {

        printf("\nfile not saved");
        fclose(fp);
    }

}
//-------------------------------------------------------------------------------------------------------//
void view_trains()
{
    int i;
    train tr;
    clrscr();

    for(i=1; i<=70; i++)
    {
        printf("-");

    }
    printf("Train no \tFrom \tTo \tFirst-AC \tSecond-AC\n");
    for(i=1; i<=70; i++)
    {
        printf("-");

    }



    FILE *fp=fopen("F:/railway reservation system//railway//alltrain1.txt","rb");

    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        printf("%s \t\t%s \t%s \t%d \t\t%d\n",tr.train_no,tr.from,tr.to,tr.fac_fare,tr.sac_fare);

    }
    for(i=1; i<=70; i++)
    {
        printf("-");

    }
    fclose(fp);
}
//---------------------------------------------------------------------------------------------------------//
int check_train_no(char *p)
{
    int i;
    FILE *fp=fopen("F:/railway reservation system//railway//alltrain1.txt","rb");
    for(i=1; i<=70; i++)
    {
        printf("-");

    }
    printf("Train no \tFrom \tTo\n");
    train tr;
    for(i=1; i<=70; i++)
    {
        printf("-");

    }
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {

        if(strcmp(p,tr.train_no)==0)
        {
            printf("%s \t\t%s \t%s\n",tr.train_no,tr.from,tr.to);
            return 0;
            break;
        }
    }
    for(i=1; i<=70; i++)
    {
        printf("-");

    }
    return 1;
    fclose(fp);
}
//------------------------------------------------------------------------------------------------------//
passenger * get_passenger_details()
{
    char *pos;
    int x=0;

    train tr;
    clrscr();
    gotoxy(50,1);
    textcolor(LIGHTGREEN);
    printf("press 0 to exit");
    FILE *fp=fopen("F://railway reservation system//railway//alltrain1.txt","rb");
    gotoxy(1,1);
    static passenger psn;
    printf("Enter the passenger name:");
    fflush(stdin);
    fgets(psn.p_name,20,stdin);
    //printf(psn.p_name);
    pos=strchr(psn.p_name,'\n');
    *pos='\0';

    if(strcmp(psn.p_name,"0")==0)
    {
        printf("Reservation cancelled");
        getch();
    }
//----------------------------------------------------------------------------------------------------------//
    while(1)
    {

        fflush(stdin);

        textattr(WHITE);
        printf("enter the Gender(M/F):");
        scanf("%c",&psn.gender);
        if(psn.gender=='M' || psn.gender=='F' || psn.gender=='m' || psn.gender=='f')
        {
            //printf("%c",psn.gender);

            break;
        }
        if(psn.gender=='0')
        {
            printf("Reservation cancelled");
        getch();
        return NULL;
        break;
        }


    }
//----------------------------------------------------------------------------------------------------------//
    do
    {
        x=1;
        fflush(stdin);

        textattr(RED);
        FILE *fp=fopen("F://railway reservation system//railway//alltrain1.txt","rb");
        printf("\nEnter the train no:");
        scanf("%s",&psn.train_no);

    if(strcmp(psn.train_no,"0")==0)
    {
        printf("Reservation cancelled");
        getch();
        break;
    }
        while(fread(&tr,sizeof(tr),1,fp)==1)
        {


            if(strcmp(psn.train_no,tr.train_no)==0)
            {
                //printf("you are choosen train no:%s",psn.train_no);
                x=2;
                break;
            }
        }
        if(x==2)
        {
              break;
        }



        printf("train not found");

    }
    while(x==1);

//-----------------------------------------------------------------------------------------------------//
while(1)
{
    fflush(stdin);
        textattr(YELLOW);
    printf("\nenter your prefernce(f/s):");
    scanf("%c",&psn.p_class);
    FILE *fp=fopen("F://railway reservation system//railway//alltrain1.txt","rb");

     while(fread(&tr,sizeof(tr),1,fp)==1)
        {


            if(strcmp(psn.train_no,tr.train_no)==0)
            {
                if(psn.p_class=='f')
                {
                  //  printf("\nyou are choosen first class AC:");
                    x=2;
                   //printf("\nAmt is:%d",tr.fac_fare);
                    break;
                }
                  else if(psn.p_class=='s')
                {
                     //printf("\nyou are choosen Second class AC:");
                     x=2;
                     //printf("\nAmt is:%d",tr.sac_fare);
                     break;

                }

                else
                {
                    printf("you are choosen Nothing!");
                    x=1;
                    break;
                }

            }
}
if(x==2)
    break;
}
//-------------------------------------------------------------------------------------------------------//
while(1)
{
    fflush(stdin);

    textattr(BLUE);
    printf("\nEnter your age:");
    scanf("%d",&psn.age);
    if(psn.age>1)
    {
        //printf("\nyou are choosen age is:%d",psn.age);
      break;
    }
    else{
        printf("plz take positive input");
    }


}
 //-----------------------------------------------------------------------------------------------//
   while(1)
   {
       char ok;

        textattr(WHITE);
       fflush(stdin);
       printf("\nEnter your Address in 30 character:");
       fgets(psn.address,30,stdin);
       // printf("\nyour address is%s",psn.address);
        pos=strchr(psn.address,'\n');
         *pos='\0';
         if(strcmp(psn.address,"0")==0)
    {
        printf("Reservation cancelled");

        getch();
        return NULL;
        break;
    }
    break;
        //printf("\nyou want to change your address enter (o/n)");
        //scanf("%c",&ok);
        /*if(ok=='n')
        {
            printf("\nmy address is:%s",psn.address);
            break;
        }
        else
            printf("enter address again");*/

   }
//------------------------------------------------------------------------------------------------------//
while(1){


    fflush(stdin);
     int n;
        textattr(YELLOW);
    printf("\nEnter your phone no:");
    scanf("%s",&psn.mob_no);


    n=check_mob_no(psn.mob_no);
    if(n==0)
    {

       printf("\nError in mobile no");


    }
    else{
        //printf("\nyour phone no is%s",psn.mob_no);
        break;
    }


}
//--------------------------------------------------------------------------------------------------------//
clrscr();
textcolor(YELLOW);
printf("Name of Passenger:%s\n",psn.p_name);
printf("Gender:%c\n",psn.gender);
printf("Train No.:%s\n",psn.train_no);
printf("Preferance:%c\n",psn.p_class);
printf("Age:%d\n",psn.age);
printf("Address:%s",psn.address);
printf("\nMobile No.:%s",psn.mob_no);



    getch();
    return &psn;
    return NULL;
}
int check_mob_no(char *p_mob)
{
    if(strlen(p_mob)!=10)
    {

        return 0;
    }
    while(*p_mob!='\0')
    {
        if(isdigit(*p_mob)==0)
        {

            return 0;
        }
         p_mob++;
    }

    return 1;
}
int get_booked_ticket_count(char *train_no,char clas)
{
    passenger psm;
    int count=0;
     FILE *fp=fopen("F://railway reservation system//railway//allbooking1.txt","rb");
    if(fp==NULL)
    {
        printf("file nhi mila");
        return 0;
    }
    printf("%s\n%c",train_no,clas);

    while(fread(&psm,sizeof(psm),1,fp)==1)
    {

        if(strcmp(psm.train_no,train_no)==0 && psm.p_class==clas)

           {
             ++count;

           }

    }
    fclose(fp);
    printf("count=%d",count);
    getch();
    return count;
}
int last_ticket_no()
{
    FILE *fp=fopen("F://railway reservation system//railway//allbooking1.txt","rb");
    if(fp==NULL)
    {
        printf("again not found");
        return 0;
    }

     passenger ps;
     ps.ticketno=0;
     fseek(fp,-1*sizeof(ps),SEEK_END);
     fread(&ps,sizeof(ps),1,fp);
     getch();
     printf("%d",ps.ticketno);
     return ps.ticketno;
}
int book_ticket(passenger psn)
{

    int s,m;
    train tm;

    fflush(stdin);

 FILE *fp=fopen("F://railway reservation system//railway//allbooking1.txt","ab+");
 if(fp==NULL)
 {
     fp=fopen("F://railway reservation system//railway//allbooking1.txt","wb+");
 }
    s=get_booked_ticket_count(psn.train_no,psn.p_class);
    printf("after count%d",s);
    getch();

    if(s==2)
    {
       printf("not found seats%s %c",psn.train_no,psn.p_class);
       return -1;
    }
        else{
        printf("\nnothing found");
        psn.ticketno=last_ticket_no()+1;
        fwrite(&psn,sizeof(psn),1,fp);
        fclose(fp);
        printf("%d",psn.ticketno);
        getch();
        return psn.ticketno;

        }
}
 void view_ticket(int n)
 {
     passenger pnb;
    FILE *fp=fopen("F://railway reservation system//railway//allbooking1.txt","rb");
    if(fp==NULL)
    {
        printf("nothing to ");

    }
    while(fread(&pnb,sizeof(pnb),1,fp)==1)
    {
        if(n==pnb.ticketno)
        {
            printf("my booking on ticket no is:%d\n",n);
            printf(" Name:%s\n Gender:%c\n mobile no:%s\n Age:%d\n Address:%s",pnb.p_name,pnb.gender,pnb.mob_no,pnb.age,pnb.address);
        }
    }

 }
 void view_all_bookings()
 {
      passenger pnb;
    FILE *fp=fopen("F://railway reservation system//railway//allbooking1.txt","rb");
    if(fp==NULL)
    {
        printf("nothing to ");

    }
    while(fread(&pnb,sizeof(pnb),1,fp)==1)
    {

        printf("ticket no:%d\n Name:%s\n Gender:%c\n mobile no:%s\n Age:%d\n Address:%s\n\n",pnb.ticketno,pnb.p_name,pnb.gender,pnb.mob_no,pnb.age,pnb.address);
    }
 }

