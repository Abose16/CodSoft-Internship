#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <iomanip>
#define slots 3
#define rows 10
#define cols 10
using namespace std;

class multiplex
{
    string movies[50]={"John Wick 4","Barbie","Oppenheimer","Mission Impossible","Top Gun: Maverick","The Flash","\0"};
    int price[50]={100,150,300,250,130,120,0};
    int timings[50][slots]={1000,1500,2000,
                            1100,1600,1800,
                            1200,1700,2100,
                            1030,1330,1900,
                            1230,1400,1830,
                            1300,1530,2030,0};
    int seats[50][slots][rows][cols]={0};
public:
    int get_titles();
    void display_movies();
    ///For Customer
    void display_seats(int,int);
    int book_seats(int,int);
    int calc_cost(int,int);
    ///For Management
    void add_movies();
    void update_prices();
    void update_movies();
    void delete_movies();
    void update_timings();
}obj;

int multiplex::get_titles()         //General Use Case
{
    int titles=0;
    for(int i=0;;i++)
    {
        if(!movies[i][0])
            break;
        titles++;
    }
    return titles;
}

void multiplex::display_movies()    //General Use Case
{
    int i,j;
    cout<<endl;
    for(i=0;i<60;i++)
        cout<<"*";
    cout<<endl;
    cout<<endl<<setw(5)<<"Sl No"<<setw(10)<<"Slot 1"<<setw(10)<<"Slot 2"<<setw(10)<<"Slot 3"<<setw(25)<<"Movie Title"<<endl;
    cout<<endl;
    for(i=0;i<60;i++)
        cout<<"*";
    cout<<endl;
    for(i=0;i<get_titles();i++)
    {
        cout<<endl<<setw(5)<<i+1;
        for(j=0;j<slots;j++)
        {
            cout<<setw(10)<<timings[i][j];
        }
        cout<<setw(25)<<movies[i]<<endl;
    }
}

void multiplex::display_seats(int id, int slot)         //For Customer
{
    int i,j;
    for(i=0;i<rows;i++)
    {
        if(i==0)
        {
            cout<<endl<<"GOLD\n"<<endl;
        }
        if(i==3)
        {
            cout<<endl<<"SILVER\n"<<endl;
        }
        if(i==rows-3)
        {
            cout<<endl<<"BRONZE\n"<<endl;
        }
        for(j=0;j<cols;j++)
        {
            if(seats[id][slot][i][j])
                cout<<"[XX]";
            else
                cout<<"["<<(char)(i+65)<<j+1<<"]";
            if(j==2||j==cols-4)
                cout<<"   ";
        }
        cout<<endl;
    }
}

int multiplex::calc_cost(int id,int row)                //For Customer
{
    int base,cost;
    base=price[id];
    if(row<2)
        cost=base+150;
    else if(row<6)
        cost=base+50;
    else
        cost=base;
    return cost;
}

int multiplex::book_seats(int id, int slot)             //For Customer
{
    string num;
    char ch;
    int cost=0;
    while(1)
    {
        cout<<"\nEnter your desired seat number: ";
        fflush(stdin);
        cin>>num;
        if((num[0]>=65&&num[0]<=64+rows)&&(num[1]>=49&&num[1]<=48+cols))
        {
            if(seats[id][slot][num[0]-65][num[1]-49])
                cout<<"\nSorry! The selected seat is already booked."<<endl;
            else
            {
                seats[id][slot][num[0]-65][num[1]-49]=1;
                cost=cost+calc_cost(id,num[0]-65);
            }
        }
        else
            cout<<"\nImproper input."<<endl;
        cout<<"\nContinue selection ?(Y/N) ";
        fflush(stdin);
        cin>>ch;
        if(ch=='N'||ch=='n')
            break;
    }
    return cost;
}

void customer()
{
    int id,slot,cost,pay;
    char ch;
    string num;
    do
    {
        obj.display_movies();
        while(1)
        {
            cout<<"\nPlease enter your desired serial number: ";
            fflush(stdin);
            cin>>id;
            if(id>=1&&id<=obj.get_titles())
            {
                id--;
                break;
            }
        }
        while(1)
        {
            cout<<"Please enter your desired slot number: ";
            fflush(stdin);
            cin>>slot;
            if(slot>=1&&slot<=slots)
            {
                slot--;
                break;
            }
        }
        cout<<"Please select your seats: "<<endl;
        obj.display_seats(id,slot);
        cost=obj.book_seats(id,slot);
        while(cost)
        {
            cout<<"\nThe total cost of your selection is: "<<cost;
            cout<<"\nAmount paid by the user: ";
            fflush(stdin);
            cin>>pay;
            if(pay-cost<0)
                cout<<"\nInsufficient amount.\n";
            else if(pay-cost>500)
                cout<<"\nPlease limit your payments to the nearest hundred.\n";
            else
            {
                cout<<"\nPayment is successful!"<<endl<<"The change is: "<<pay-cost<<endl;
                break;
            }
        }
        cout<<"\nPress [E] to leave your session and go back to the login screen."<<endl;
        cout<<"Press any other key to book further tickets."<<endl;
        cout<<"Enter your choice: ";
        ch=getche();
        cout<<endl;
    }while(ch!='E'&&ch!='e');
    return;
}

void multiplex::add_movies()        //For Management
{
    int i=get_titles();
    fflush(stdin);
    cout<<"\nEnter the name of the movie: ";
    getline(cin,movies[i]);
    fflush(stdin);
    cout<<"\nEnter the base price of the ticket: ";
    cin>>price[i];
    fflush(stdin);
    cout<<"\nEnter the timings of the movie...\n";
    for(int j=0;j<slots;j++)
    {
        cout<<"Slot "<<j+1<<": ";
        cin>>timings[i][j];
    }
    return;
}

void multiplex::delete_movies()     //For Management
{
    int i,j,k,p,q;
    do
    {
        cout<<endl<<"Enter the serial number of the movie to be deleted: ";
        fflush(stdin);
        cin>>i;
    }while(i<1||i>get_titles());
    i--;
    j=i;
    do
    {
        movies[j]=movies[j+1];
        j++;
    }while(movies[j][0]);
    j=i;
    do
    {
        for(k=0;k<slots;k++)
        {
            timings[j][k]=timings[j+1][k];
        }
        j++;
    }while(timings[j][0]);
    j=i;
    do
    {
        price[j]=price[j+1];
        j++;
    }while(price[j]);
    do
    {
        for(j=0;j<slots;j++)
        {
            for(p=0;p<rows;p++)
            {
                for(q=0;q<cols;q++)
                    seats[i][j][p][q]=seats[i+1][j][p][q];
            }
        }
        i++;
    }while(i<=get_titles());
    return;
}

void multiplex::update_movies()     //For Management
{
    int i;
    do
    {
        cout<<endl<<"Enter the serial number of the movie to be updated: ";
        fflush(stdin);
        cin>>i;
    }while(i<1||i>get_titles());
    cout<<endl<<"Enter a new movie name: ";
    fflush(stdin);
    getline(cin,movies[i-1]);
    return;
}

void multiplex::update_prices()     //For Management
{
    int i;
    do
    {
        cout<<endl<<"Enter the serial number of the movie whose price is to be updated: ";
        fflush(stdin);
        cin>>i;
    }while(i<1||i>get_titles());
    cout<<endl<<"Enter a new base price: ";
    fflush(stdin);
    cin>>price[i-1];
    return;
}

void multiplex::update_timings()    //For Management
{
    int i;
    do
    {
        cout<<endl<<"Enter the serial number of the movie whose timing is to be updated: ";
        fflush(stdin);
        cin>>i;
    }while(i<1||i>get_titles());
    cout<<endl<<"Enter the new timings...\n";
    for(int j=0;j<slots;j++)
    {
        cout<<"Slot "<<j+1<<": ";
        fflush(stdin);
        cin>>timings[i-1][j];
    }
    return;
}

void management()
{
    int ch,c=0;
    string pass;
    do
    {
        cout<<"\nPlease enter password: ";
        fflush(stdin);
        cin>>pass;
        if(pass=="M123N")
            break;
        cout<<"\nIncorrect Password..";
        cout<<"\n"<<4-c-1<<" attempt(s) remaining!\n";
        c++;
    }while(c<4);
    if(c==4)
        exit(0);
    do
    {
        obj.display_movies();
        cout<<endl;
        cout<<"1. Update prices."<<endl;
        cout<<"2. Update movies."<<endl;
        cout<<"3. Add new movie."<<endl;
        cout<<"4. Delete movies."<<endl;
        cout<<"5. Update timing."<<endl;
        cout<<"Your Choice: ";
        fflush(stdin);
        cin>>ch;
        switch(ch)
        {
            case 1: obj.update_prices();
                    break;
            case 2: obj.update_movies();
                    break;
            case 3: obj.add_movies();
                    break;
            case 4: obj.delete_movies();
                    break;
            case 5: obj.update_timings();
                    break;
           default: cout<<"\nInvalid Choice.\n";
        }
        cout<<"\nPress [E] to leave your session and go back to the login screen."<<endl;
        cout<<"Press any other key to make further changes."<<endl;
        cout<<"Enter your choice: ";
        ch=getche();
        cout<<endl;
    }while(ch!='E'&&ch!='e');
    return;
}

int main()
{
	//Movie ticket booking system
	char ch;
	do
    {
        while(1)
        {
            cout<<endl<<"Login as [C]ustomer or [M]anagement: ";
            fflush(stdin);
            cin>>ch;
            if(ch!='C'&&ch!='M')
            {
                cout<<endl<<"Please enter a valid selection."<<endl;
            }
            else
            {
                break;
            }
        }
        if(ch=='M')
            management();
        else
            customer();
        cout<<endl<<"Do you want to exit ?(Y/N) ";
        ch=getche();
        cout<<endl;
    }while(ch=='N'||ch=='n');
	return 0;
}
