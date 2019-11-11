#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include "rlyres.h"

int main()
{
    int choice,i,n;
    char arr[10];
    passenger *ptr;
    int tkt_no;
    add_trains();
        int p;
while(1)
{
    choice=enterchoice();
    switch(choice)
{


    case 1:
        clrscr();
        view_trains();
        printf("press enter to return .........");
        getch();
        clrscr();
        break;
    case 9:
        clrscr();
        printf("enter train no:");
        scanf("%s",&arr);
       n=check_train_no(arr);
       printf("%d",n);
       getch();
       clrscr();
       break;
    case 10:

        break;
    case 2:
            clrscr();

         ptr=get_passenger_details();
         printf("pointer is:%d",*ptr);
         clrscr();
         p=book_ticket(*ptr);
         printf("%d",p);
         getch();
         clrscr();

        break;
    case 3:
        clrscr();
        printf("Enter thr ticket no:");
        scanf("%d",&tkt_no);
        view_ticket(tkt_no);
        getch();
        clrscr();
        break;
    case 5:
        clrscr();
        view_all_bookings();
        getch();
        clrscr();
        break;

    }
}

    i=enterchoice();
    getch();

}
