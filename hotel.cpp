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

class Hotel_Mgmt: public Room
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
    for(int i=0;i<=cust;i++)
    {
        cout<<"\nGuest's Name: "<<rooms[i].customer.first_name<<" "<<rooms[i].customer.last_name<<endl;
        cout<<"Guest's Room Number: "<<rooms[i].room_number<<endl;
        cout<<"Guest's Mobile Nubmer: "<<rooms[i].customer.mobile_no<<endl;
        cout<<"Guest's Address(City Only): "<<rooms[i].customer.city_address<<endl;
        cout<<"----------------------------"<<endl;
    }
    getch();
}
void Hotel_Mgmt::search_guest()
{
    string name;
    string address;
    cout<<"Enter the guest's First Name: ";
    cin>>name;
    cout<<"Enter the guest's City of residence: ";
    cin>>address;
    bool found=false;
    for(int i=1;i<=cust;i++)
    {
        if(rooms[i].customer.first_name==name && rooms[i].customer.city_address==address)
        {
            cout<<"Guest's Full Name: "<<rooms[i].customer.first_name<<" "<<rooms[i].customer.last_name<<endl;
            cout<<"Guest' Room Number:"<<rooms[i].room_number<<endl;
            cout<<"Guest's Mobile Number: "<<rooms[i].customer.mobile_no<<endl;
            cout<<"Guest's Address(City Only): "<<rooms[i].customer.city_address<<endl;
            found=true;
            getch();
        }
       
    }
    if(found==false)
    {
        cout<<"No such record found in directory."<<endl;
        getch();
    }
}

void Hotel_Mgmt::check_out()
{
    int room_no;
    cout<<"Enter the room number: ";
    cin>>room_no;
    int temp1=0,temp2=0,todate,fromdate;
    temp1=rooms[room_no].customer.from_date[0];
    temp2=rooms[room_no].customer.from_date[1];
    fromdate=temp1*10+temp2;
    temp1=rooms[room_no].customer.to_date[0];
    temp2=rooms[room_no].customer.to_date[1];
    todate=temp1*10+temp2;
    int stay=todate-fromdate;
    cout<<"\nGuest's Name: "<<rooms[room_no].customer.first_name<<" "<<rooms[room_no].customer.last_name<<endl;
    cout<<"Guest's Room Number: "<<rooms[room_no].room_number<<endl;
    cout<<"Guest's Mobile Number: "<<rooms[room_no].customer.mobile_no<<endl;
    cout<<"Guest's City of Residence: "<<rooms[room_no].customer.city_address<<endl;
    cout<<"Total Payable Amount: "<<stay*rooms[room_no].room_rent<<endl;
    cout<<"Advance Paid: "<<rooms[room_no].customer.advance_pay<<endl;
    cout<<"Total Amount to be paid at Check-out: "<<stay*-rooms[room_no].customer.advance_pay<<endl;
    getch();
    cout<<"\t\tThank you for your stay!"<<endl;
    getch();
}

class Hotel: public Hotel_Mgmt
{
    public:
    void main_interface();
    void room_mgmt();
    class Hotel_Mgmt hmgmt;
    class Room room_obj;
};

void Hotel::main_interface()
{
    int option;
    cout<<"\t\t Welcome to Oasis Hotel!"<<endl;
    cout<<"1. Manage Rooms"<<endl;
    cout<<"2. Check-in"<<endl;
    cout<<"3. Check room availability"<<endl;
    cout<<"4. Search for a Guest"<<endl;
    cout<<"5. Guest Summary Report"<<endl;
    cout<<"6. Check-out"<<endl;
    cout<<"7. Exit"<<endl;
    cout<<"Please choose an Option: ";
    cin>>option;
    switch(option)
    {
        case 1:
        system("cls");
        this->room_mgmt();
        system("cls");
        this->main_interface();
        break;
        case 2:
        system("cls");
        if(roomno>cust)
        {
            hmgmt.check_in();
            system("cls");
            this->main_interface();
            break;
        }
        else
        {
            cout<<"Not enough room for more customers."<<endl;
            getch();
            break;
        }
        case 3:
        system("cls");
        room_obj.seach_room();
        system("cls");
        this->main_interface();
        break;
        case 4:
        system("cls");
        hmgmt.search_guest();
        system("cls");
        this->main_interface();
        break;
        case 5:
        hmgmt.report_of_guests();
        system("cls");
        this->main_interface();
        break;
        case 6:
        system("cls");
        hmgmt.check_out();
        system("cls");
        this->main_interface();
        break;
        case 7:
        cout<<"Thank you for using this Software!"<<endl;
        getch();
        break;
        default:
        cout<<"Enter option again: ";
        break;
    }
}

void Hotel::room_mgmt()
{
    int option1;
    cout<<"1. Add Room"<<endl;
    cout<<"2. Search Room"<<endl;
    cout<<"3. Search Room Information"<<endl;
    cout<<"4. Back to Main Menu"<<endl;
    cout<<"Enter your cjose option: ";
    cin>>option1;
    switch(option1)
    {
        case 1:
        system("cls");
        room_obj.add_room();
        system("cls");
        this->room_mgmt();
        break;
        case 2:
        system("cls");
        room_obj.seach_room();
        system("cls");
        this->room_mgmt();
        break;
        case 3:
        system("cls");
        room_obj.show_room_info();
        system("cls");
        this->room_mgmt();
        break;
        case 4:
        this->main_interface();
        break;
        default:
        cout<<"Enter chosen option:";
        break;
    }
}
int main()
{
    Hotel h;
    for(int i=1;i<51;i++)
    {
        rooms[i].room_status=0;
    }
    h.main_interface();
    return 0;
}