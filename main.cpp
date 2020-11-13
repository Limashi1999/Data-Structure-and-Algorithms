#include <iostream>
#include <iomanip>
#include <unistd.h>
#include<fstream>
#include<windows.h>
#include<string>
#include<stdlib.h>
#include<conio.h>

using namespace std;


class Reservation{

public:

    Reservation *next;
    Reservation *previous;

    string fname, lname, ID, phone_num, menu;
    int reserve_num, seat_num, seatNo, choice;
    Reservation();
    void display();
    void displaySeat();

};

Reservation::Reservation()
{
    next=NULL;
    previous=NULL;
}

void Reservation::display()
{
    cout<<"\t\t\t  "<<fname<<"\t"<<lname<<"\t"<<ID<<"\t"<<phone_num<<"\t"<<seatNo<<"\t"<<reserve_num<<"\n";
}

void Reservation::displaySeat()
{
    cout<<seatNo<<" - Booked"<<endl;
}

class ReservationList
{

 private:
    Reservation *first;

 public:

    int seat[10];
    int reserve =0;

    ReservationList();
    double deleteFirst();
    void displayList();
    void displaySeatList();
    bool deleteNote(int seat);
    void bubbleSort(int *array, int size);
    void make_reservation(string fname, string lname, string ID, string phone_num, int reserve_num, int meal_choice, int seatNo, int choice);
	bool checkSeat(int num);
	void find_reservation(int seat);

};

ReservationList::ReservationList()
{
    first=NULL;
}

void ReservationList:: make_reservation(string fname, string lname, string ID, string phone_num, int reserve_num, int meal_choice, int seatNo, int choice)
{
    Reservation *temp = new Reservation();

    temp->choice=choice;
    temp->seatNo=seatNo;
    temp->fname=fname;
    temp->lname=lname;
    temp->ID=ID;
    temp->phone_num=phone_num;

	reserve++;
	temp->reserve_num=reserve;

	system("cls");
	system("color F2");

	cout <<"\n\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
	cout << "\t\t\t                   Successfully Reserved              \n\n";
	cout << "\t\t\t               YOUR RESERVATION NUMBER IS : " << reserve << "\n\n";
	cout <<"\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";


	if(first == NULL)
    {
        first = temp;
    }
	else
	{
        temp->previous=NULL;
        temp->next=first;
        first->previous=first;
        first=temp;
    }

    cout<<"\nPress any key to go Main Menu ";
    getch();
    	system("color F1");

    system ("cls");

}
bool ReservationList::checkSeat(int num)
{

  Reservation *currentval=first;

  while(currentval!=NULL)
  {     if(num==currentval->seatNo)
        {
            return false;
        }

    currentval=currentval->next;

  }
    return true;

}

void ReservationList::displayList()
{

    Reservation *currentval=first;
        cout<<"\t\t\t---------------------------------------------------------------\n";

    if(first==NULL){
        cout<<"\t\t\t\t     There are no Reservations to Display\n";

    }
    else{
        cout<<"\t\t\t  "<<"fname"<<"\t\t"<<"lname"<<"\t"<<"ID  "<<"\t\t"<<"phone_num"<<"\t"<<"seatNo"<<"\t"<<"reserve_num"<<"\n\n";
        cout<<endl;
    }

    while(currentval!=NULL)
    {
        currentval->display() ;
        currentval=currentval->next;
    }
        cout<<"\t\t\t---------------------------------------------------------------\n";
        cout<<"\nPress any key to go Main Menu ";
        getch();
        system("cls");
}

void ReservationList::bubbleSort(int *array, int size)
{
    int temp;
   for(int i = 0; i<size-1; i++) {

      for(int j = 0; j<size-i; j++) {
         if(array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;


         }
      }

   }

}
void ReservationList::displaySeatList()
{
    int arr[50];
    int i=0;

    Reservation *currentval=first;

  while(currentval!=NULL)
  {

    arr[i]=currentval->seatNo;
    currentval=currentval->next;
    i++;
  }
  int arr2[i];
  for(int j=0;j<i;j++)
  {
      arr2[j]=arr[j];
  }
    bubbleSort(arr2,i);

    cout <<"\n\  ****************** Seats ******************\n"<< endl;

    for(int i=0;i<50;i++)
    {   if(i<9)
        {
            cout<<"0";
        }
        cout<<i+1<<"\t\t";
    }

    cout <<"\n\n  *************** Booked Seats ***************\n"<< endl;

    for(int j = 0; j<i; j++)
   {
        cout << arr2[j]<<" -Booked"<<endl;
   }

}

bool ReservationList::deleteNote(int seat)
{

    Reservation *previous=first;
    Reservation *current=first;

    system ("cls");

    while(current!=NULL)
    {

    if(current->seatNo==seat)
    {
        if(current==first)
        {
            first=first->next;

        }else

        previous->next=current->next;

        delete current;
        system("color F2");
        cout<<"\t\t\t\t--------------------------------\n";
        cout<<"\t\t\t\t    Successfully Deleted\n";
        cout<<"\t\t\t\t--------------------------------\n";
        cout<<"\nPress any key to go Main Menu ";
        getch();
        system("color F9");
        system ("cls");

        return true;

    }
    else

    {
        previous=current;
        current=current->next;

    }

    }
    system("color FC");
    cout<<"\t\t\t\t--------------------------------\n";
    cout<<"\t\t\t\t    Unsuccessfully Deleted\n";
    cout<<"\t\t\t\t--------------------------------\n";
    cout<<"\nPress any key to go Main Menu ";
    getch();
    system("color F9");
    system ("cls");
    return false;
}

void ReservationList:: find_reservation(int seat)
{

	Reservation *current = first;
    cout<<"\n\t\t\t\t:::::::::::::::::::::::::::::::::::::::::::::\n\n";

    while (current != NULL)
    {
        if (current->seatNo == seat)
        {
            cout << "\t\t\t\t\t   Reservation No : " << current->reserve_num<< endl;
            cout << "\t\t\t\t\t   First Name     : " << current->fname << endl;
            cout << "\t\t\t\t\t   Last Name      : " << current->lname << endl;
            cout << "\t\t\t\t\t   ID             : " << current->ID << endl;
            cout << "\t\t\t\t\t   Phone number   : " << current->phone_num << endl;
            cout << "\t\t\t\t\t   seat Number    : " << current->seatNo << endl;
            cout<<"\n\t\t\t\t:::::::::::::::::::::::::::::::::::::::::::::";

            cout<<"\n\nPress any key to go Main Menu ";

            getch();
            system("cls");

            return;

        }

        current= current->next;
    }

    cout<<"\n\t\t\t\t             Sorry!!! NOT FOUND             \n\n";
    cout<<"\t\t\t\t:::::::::::::::::::::::::::::::::::::::::::::";
    cout<<"\n\nPress any key to go Main Menu ";

    getch();
    system("cls");
}

void menu()
{
    int x=1;
    ReservationList R1;

  do{

    int choice=0,journey=0,flight=0,seatNo=0,meal_choice=0;
    string fname, lname, ID, phone_num;

    cout <<"\n\t\t\t      :::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
    cout <<"\t\t\t\t ---------------------------------------             \n";
    cout <<"\t\t\t\t Make Reservation                ......     [1]      \n";
    cout <<"\t\t\t\t ---------------------------------------             \n";
    cout <<"\t\t\t\t Cancel Reservation              ......     [2]      \n";
    cout <<"\t\t\t\t ---------------------------------------             \n";
    cout <<"\t\t\t\t Search Reservation Details      ......     [3]      \n";
    cout <<"\t\t\t\t ---------------------------------------             \n";
    cout <<"\t\t\t\t Display Reservation List        ......     [4]      \n";
    cout <<"\t\t\t\t ---------------------------------------             \n";
    cout <<"\t\t\t\t Quit                            ......     [5]      \n";
    cout <<"\t\t\t\t ---------------------------------------             \n";
    cout <<"\n\t\t\t      :::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
    cout<<"Enter your choice : ";
    cin >> choice;

    system ("cls");

    switch(choice)
    {
        case 1:

            cout <<"\n\t\t\t  *************** Journey ********************\n"<< endl;
            cout <<"\t\t\t\t--------------------------------- \n";
            cout <<"\t\t\t\tSri Lanka to Sydney      .... [1] \n";
            cout <<"\t\t\t\t--------------------------------- \n";
            cout <<"\t\t\t\tSri Lanka to New York    .... [2] \n";
            cout <<"\t\t\t\t--------------------------------- \n";
            cout <<"\t\t\t\tSri Lanka to Melboune    .... [3] \n";
            cout <<"\t\t\t\t--------------------------------- \n";
            cout <<"\t\t\t\tSydney to Melboune       .... [4] \n";
            cout <<"\t\t\t\t--------------------------------- \n";
            cout <<"\t\t\t\tSydney to New York       .... [5] \n";
            cout <<"\t\t\t\t--------------------------------- \n\n";
            cout <<"\t\t\t  *********************************************"<< endl;

            cout<<"\nEnter your choice : ";
            cin >> journey;

            cout <<"\n\t\t\t  ****************** Flights ******************\n"<< endl;
            cout << "Airline:\t\t   \t\tDeparture:\tArrival:\tPrice:\t\n";

            if(journey==1 || journey==2 || journey==3)
            {
                cout << "\1Sri lankan Airlines   .... [1] \t10:00\t\t14:05\t\tRs.25000\n";
                cout << "\2QATAR                 .... [2] \t14:00\t\t18:05\t\tRs.21500\n";
                cout << "\3Emirates              .... [3] \t18:00\t\t22:05\t\tRs.24000\n";
            }
            else if(journey==4 || journey==5)
            {
                cout << "\1Sri lankan Airlines   .... [1] \t10:00\t\t14:05\t\tRs.35000\n";
                cout << "\2QATAR                 .... [2] \t14:00\t\t18:05\t\tRs.24500\n";
                cout << "\3Emirates              .... [3] \t18:00\t\t22:05\t\tRs.30000\n";
            }
            else
            {
                cout << "No Flights Found!!.\nTry again : ";
                cin >> journey;
            }
            cout <<"\n\t\t\t  *********************************************\n"<< endl;

            cout<<"\nEnter your choice : ";
            cin>>flight;
            R1.displaySeatList();

            cout<<"\n\nEnter the seat number : ";
            cin>>seatNo;


            if(R1.checkSeat(seatNo)==false)
            {
                cout<<"\t\t\t\t--------------------------------\n";
                cout<<"\t\t\t\t  This seat is already booked\n";
                cout<<"\t\t\t\t--------------------------------\n";
                cout<<"\nEnter a seat number again : ";
                cin>>seatNo;

            }

            cout<<"\n\t\t\t\t------ Enter Your Details ------";

            cout<<"\n\n\t\t\t\tEnter First Name : ";
            cin>>fname;
            cout<<"\t\t\t\t--------------------------------\n";

            cout<<"\t\t\t\tEnter Last Name : ";
            cin>>lname;
            cout<<"\t\t\t\t--------------------------------\n";

            cout<<"\t\t\t\tEnter ID : ";
            cin>>ID;
            cout<<"\t\t\t\t--------------------------------\n";

            cout<<"\t\t\t\tEnter Phone Number : ";
            cin>>phone_num;
            cout<<"\t\t\t\t--------------------------------\n";

            cout << "\t\t\t\tPlease Enter Your Menu Preference from below : \n\n";
            cout << "\t\t\t\t  Veg     ..... '1'\n";
            cout << "\t\t\t\t  Non-Veg ..... '2'\n";
            cout << "\t\t\t\t  No meal ..... '3'\n\n";

            cout <<"               Enter Your Choice : ";
            cin >> meal_choice;

            while(meal_choice>3 || meal_choice<1){
                cout<<"Try Again : ";
                cin>>meal_choice;
            }
            R1.make_reservation(fname, lname, ID, phone_num, journey, meal_choice, seatNo, flight);

            break;
        case 2:
            cout<<"\t\t\t\t----------------------------------------\n";
            cout<<"\t\t\t\t  Enter the seat Number to be deleted : ";
            cin>>seatNo;
            cout<<"\t\t\t\t----------------------------------------\n";
            R1.deleteNote(seatNo);
            break;

        case 3:
            cout << "Please enter your Seat No : ";
            cin >> seatNo;
            system("cls");
            R1.find_reservation(seatNo);
            break;

        case 4:
            R1.displayList();
            break;

        case 5:
            exit(0);
            break;

        default:
            cout << "Wrong input entered.\nTry again" << endl;
    }

  }while(x==1);

}

const char rocket[] =
"\t\t\t\t\t           _\n\
\t\t\t\t\t          /^\\\n\
\t\t\t\t\t        | |-| |\n\
\t\t\t\t\t       |  | |  |\n\
\t\t\t\t\t      || | | | ||\n\
\t\t\t\t\t          | |\n\
\t\t\t\t\t          | |\n\
\t\t\t\t\t          | |\n\
\t\t\t\t\t         /| |\\\n\
\t\t\t\t\t        / | | \\\n\
\t\t\t\t\t       |  | |  |\n\
\t\t\t\t\t        `-\"\"\"-`\n\n\
                              . . . . . . . . . . . . . . . . . . . . . . . \n\n\
                                  WELCOME TO AIRELINE RESERVATION SYSTEM    \n\n\
                              . . . . . . . . . . . . . . . . . . . . . . . \n\
";
int main()
{
        char a= 177,b=219;
    cout<<"\n\n\n\n\n\t\t\t\tLoading...";
    cout<<"\n\n\t\t\t\t";
    for(int i=0;i<=40;i++)
        cout<<" " ;
        Sleep(70);
    cout<<"\r";
    cout<<"\t\t\t\t";

    for(int i=0;i<=40;i++)
    {
        cout<<b;
        Sleep(40);
    }
    system ("cls");
    system("color F5");

    for (int i = 0; i < 50; i ++) printf("\n");
    printf("%s", rocket);
    int j = 220000;
    for (int i = 0; i < 50; i ++) {
        usleep(j);
        j = (int)(j * 0.94);
        printf("\n");
    }
    system("cls");
    system("color F1");



	menu();

    return 0;

}
