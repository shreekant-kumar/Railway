#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED
struct train{
char train_no[10];
char from[10];
char to[10];
int fac_fare;
int sac_fare;
};
struct passenger
{
    char p_name[20];
    char gender;
    char train_no[20];
    char p_class;
    char address[20];
    int age;
    int ticketno;
    char mob_no[11];
};
typedef struct train train;
typedef struct passenger passenger;
int enterchoice();
void add_trains();
void view_trains();
int book_ticket(passenger);
int * get_ticket_no(char*);
void view_ticket(int);
void view_all_bookings();
void view_bookings(char*);
int cancel_ticket(int);
int cancel_train(char*);
passenger * get_passenger_details();
int check_train_no(char *);
int check_mob_no(char *);
int get_booked_ticket_count(char *,char);
int last_ticket_no();
int book_ticket(passenger);
#endif // RLYRES_H_INCLUDED
