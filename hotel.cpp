#include <bits/stdc++.h>
#include <string.h>
#include <conio.h>
using namespace std;
int roomno=1;
int cust=1;
class Customer_Info
{
    public:
    string first_name;
    string last_name;
    string mobile_no;
    string city_address;
    string from_date;
    string to_date;
    int advance_pay;

};

class Room: public Customer_Info
{
    public:
    int room_number;
    char room_ac;
    string room_type;
    int room_rent;
    int room_status;
    class Customer_Info customer;
    void add_room();
    void seach_room();
    void show_room_info();
};
Room rooms[100];

void Room::add_room()
{
    cout<<"The number allocated to this room is: "<<roomno<<endl;
    rooms[roomno].room_number=roomno;
    cout<<"Does the room have an AC in it(Y/N): ";
    cin>>rooms[roomno].room_ac;
    cout<<"Please specify type of room from the options---\n";
    cout<<"1. Simple"<<endl;
    cout<<"2. Deluxe"<<endl;
    cout<<"3. Premium"<<endl;
    cout<<"4. suite"<<endl;
    cout<<"Please choose an option: ";
    cin>>rooms[roomno].room_type;
    cout<<"Please specify rent of the room: ";
    cin>>rooms[roomno].room_rent;
    rooms[roomno].room_status=0;
    cout<<"New Room Added!"<<endl;
    roomno++;
    getch();
}
void Room::seach_room()
{
    int room_no;
    cout<<"Please Enter number of the room you want to search:";
    cin>>room_no;
    if(room_no>roomno)
    {
        cout<<"The room does not exist."<<endl;
        getch();
    }
    else 
    {
        if(room_no<roomno && rooms[room_no].room_status==0)
        {
            cout<<"The Room is available."<<endl;
            getch();
        }
        else 
        {
            cout<<"The Room is occupied."<<endl;
        }
    }
}
void Room::show_room_info()
{
    int room_no;
    cout<<"Please enter room number: ";
    cin>>room_no;
    if(room_no<roomno)
    {
        cout<<"Room Number: "<<rooms[room_no].room_number<<endl;
        cout<<"Room type: "<<rooms[room_no].room_type<<endl;
        cout<<"If room is Air confitioned or not: "<<rooms[room_no].room_ac<<endl;
        cout<<"The rent of this Room(per day) is: "<<rooms[room_no].room_rent<<endl;
        if(rooms[room_no].room_status==1)
        {
            cout<<"The Room is occupied at the moment."<<endl;
        }
        else{
            cout<<"The room is available."<<endl;
        }
        getch();
    }
    else 
    {
        cout<<"The Room does not exist.";
        getch();
    }
}

class Hotel_Mgmt: public Room, public Customer_Info
{
    public:
    void check_in();
    void check_out();
    void report_of_guests();
    void search_guest();
    void allot_room();
};

void Hotel_Mgmt::check_in()
{
    cout<<"Guest's First Name: ";
    cin>>rooms[cust].customer.first_name;
    cout<<"Guest's Last Name: ";
    cin>>rooms[cust].customer.last_name;
    cout<<"Guest's Mobile Number: ";
    cin>>rooms[cust].customer.mobile_no;
    cout<<"Guest's Address(City Only): ";
    cin>>rooms[cust].customer.city_address;
    cout<<"Guest's Check-in Date(DD/MM/YY): ";
    cin>>rooms[cust].customer.from_date;
    cout<<"Guest's Check-out Date(DD/MM/YY): ";
    cin>>rooms[cust].customer.to_date;
    cout<<"Customer's Advance Payment(if any): ";
    cin>>rooms[cust].customer.advance_pay;
    this->allot_room();
    cout<<"Check-in Completed!\n Enjoy your stay in our Hotel!"<<endl;
    getch();
}
void Hotel_Mgmt::allot_room()
{
    if(roomno>cust)
    {
    if(rooms[cust].room_number==0)
    {
        cout<<"The room number alloted to this guest is: "<<cust;
        cust++;
    }
    else if(rooms[cust].room_number!=0) 
    {
        cout<<"The Room is already Reserved";
    }
    }
    else 
    {
        cout<<"Please add more rooms. All rooms Full"<<endl;
        getch();
    }
}

void Hotel_Mgmt::report_of_guests()
{
    int i;
    for(int i=0;i<=50;i++)
    {
        cout<<"\nGuest's Name: "<<rooms[i].customer.first_name<<" "<<rooms[i].customer.last_name<<endl;
        cout<<"Guest's Room Number: "<<rooms[i].room_number<<endl;
        cout<<"Guest's Mobile Nubmer: "<<rooms[i].customer.mobile_no<<endl;
        cout<<"Guest's Address(City Only): "<<rooms[i].customer.city_address<<endl;
        
    }
}
int main()
{
    return 0;
}