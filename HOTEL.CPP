//C++ PROJECT

//START OF THE PROGRAM FOR HOTEL MANAGEMENT

#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include <ctime>
#include <cstdlib>


using namespace std;

//START OF CLASS



class hotel
{

int room_no;
char name[30];
char address[50];
char phone[10];
char country[20];
char Gender;
int days;
char date[10];

public:

void main_menu();		//to dispay the main menu
void add();			//to book a room
void display(); 		//to display the customer record
void rooms();			//to display alloted rooms
void edit();			//to edit the customer record
int check(int);			//to check room status
void modify(int);		//to modify the record
void delete_rec(int);		//to delete the record
void bill(int);                 //for the bill of a record
void cash();				//for the payment modes without discount 
void Cheque();				// to multiply the discount base on the payment mode
void Credit_card();			//to  multiply the discount base on the payment mode
void company();				// to  multiply the discount base on renounce companies and non-renounce 
     };
    //END OF CLASS



//FOR DISPLAYING MAIN MENU



void hotel::main_menu()
{

int choice;
while(choice!=5)
{
//FOR DISPLAYING MAIN MENU
  system("cls");
cout<<"\n\t\t\t\t*************************";
cout<<"\n\t\t\t\t SIMPLE Hall MANAGEMENT ";
cout<<"\n\t\t\t\t      * MAIN MENU *";
cout<<"\n\t\t\t\t*************************";
cout<<"\n\n\n\t\t\t1.Book A Hall";
cout<<"\n\t\t\t2.Customer Records";
cout<<"\n\t\t\t3.Hall Allotted";
cout<<"\n\t\t\t4.Edit Record";
cout<<"\n\t\t\t5.Exit";
cout<<"\n\n\t\t\tEnter Your Choice: ";
cin>>choice;

switch(choice)
{

case 1:	add();
break;

case 2: display();
break;

case 3: rooms();
break;

case 4:	edit();
break;

case 5: break;

default:
{

cout<<"\n\n\t\t\tWrong choice.....!!!";
cout<<"\n\t\t\tEnter your favourite to   continue....!!";
getch();

}

}

}

}


//END OF MENU FUNCTION


//FUNCTION FOR BOOKING OF HALLS


void hotel::add()
{
//FUNCTION FOR BOOKING OF HALLS
  system("cls");
int r,flag;
ofstream fout("Record.dat",ios::app);

system("color c");

//Type of halls and the cost involved respectively
cout<<"\n\n ----------------------";
cout<<"\n\n Number of Halls :100 ";
cout<<"\n\n ----------------------";
cout<<"\n\t HALL TYPE\t HALL NO FROM/TO\tRATE PER DAY";
cout<<"\n";
cout<<"\n\t Moderate\t    1 - 60\t      ghc 1000 ";
cout<<"\n\t Executive\t   61 - 89\t      ghc 1800";
cout<<"\n\t Super Executive   96 -100            ghc 2500";
cout<<endl;
cout<<"\n Enter Customer Details"<<endl;
cout <<"\n Enter The Hall Number. you want to stay in :- "<<endl;
cin>>r;
//End of the hall types

int max, random_number,i;//creating variables to help generate numbers n it own 

flag=check(r);

if(flag)
cout<<"\n Sorry..!!!Room is already booked";

else
{
//Entering details of the customer
room_no=r;
cout<<" Name: ";
cin>>name;
cout<<" Address: ";
cin>>address;
cout<<"Expected Date to Report :";
cin>>date;
cout<<" Gender (M / F): ";
cin>>Gender;
cout<<" Phone Number: ";
cin>>phone;
cout<<" country: ";
cin>>country ;
cout<<" Number of Stay: ";
cin>>days;
cout<<"Expected Date to Checkout :";
cin>>date;
cout<<"Enter an intger number to get a booking id :";
cin>>max;
//End of entering details of the customer 

//this code is for generating the booking id 
	srand(time(0));
	random_number = (rand () %max)+1;
	cout<<random_number<<endl;
//end of code for generating the booking id 


int mode=0;//delaring a variable for the payment modes

//Selecting a payment mode the customer want to use
cout<<"\n Payment Modes"<<endl;

cout<<"1.Cash"<<endl;
cout<<"2.Traveler’s Cheque"<<endl;
cout<<"3.Credit Card"<<endl;
cout<<"4.Company "<<endl;
cout<<endl;
cout<<"choose mode payment"<<endl;
cin>>mode;

system("cls");
// options the customer want to choose
switch(mode){
	case 1: cash();
	break;
	case 2: Cheque();
	break;
	case 3: Credit_card();
	break;
	case 4: company();
	break;
	default:cout<<"No option choosen"<<endl;
	break;
}
//End of options customer want to choose



//print all the details of the customer 
cout<<"Name :"<<name<<endl;
cout<<"Address :"<<address<<endl;
cout<<"Expected Date to Report :"<<date<<endl;
cout<<"Gender (M / F) :"<<Gender<<endl;
cout<<"Room Number :"<<room_no<<endl;
cout<<" Phone Number :"<<phone<<endl;
cout<<" country :"<<country<<endl;
cout<<" Number of Stay :"<<days<<endl;
cout<<"Expected Date to Checkout  :"<<date<<endl;
cout<<"Enter an intger number to get a booking id   :"<<max<<endl;


//File handing to help store records
fout.write((char*)this,sizeof(hotel));
cout<<"\n Hall has been  booked...!!!";

}

cout<<"\n Enjoy your stay.....!!";

getch();
fout.close();

}


//END OF BOOKING FUNCTION


//FUNCTION FOR DISPLAYING A PURTICULAR CUSTOMER`S RECORD

//for  the payment modes without discount
void hotel::cash(){
	float bill = 0;
	
	if(room_no <= 60){
		bill = 1000 * days;
	}
	else if(room_no > 60 && room_no < 89){
		bill = 1800 * days;
	}
	else{
		bill =  2500 * days;
	}
	cout<<"bill is: "<<bill<<endl;
};
//End  of function for paying in cash

//to  multiply the discount base on the payment mode 
void hotel::Cheque(){
	float bill =0;
	
	if(room_no<=60){
	
		bill = (1000 * days) * 0.3;
	}
	else if(room_no>60 && room_no<89){
		bill = (1800 * days) * 0.3;
	}
	else{
		bill =  (2500 * days) * 0.3;

	}
	
	cout<<"bill is: "<<bill<<endl;
};
//End  of function for paying in cheque

//to  multiply the discount base on the payment mode
void hotel::Credit_card(){
	float bill =0;
	
	if(room_no<=60){
	
		bill = (1000 * days) * 0.4;
	}
	else if(room_no>60 && room_no<89){
		bill = (1800 * days) * 0.4;
	}
	else{
		bill =  (2500 * days) * 0.4;

	}
	
	cout<<"bill is: "<<bill<<endl;
	
};
//End  of function for paying in Credit card

// to  multiply the discount base on renounce companies and non-renounce
void hotel::company(){
	
	string companyName[4]{"Cal","Mtn","Tigo"};
	float bill=0;
	string userinput;
	float discount=0.07;
	cout<<"Enter company name"<<endl;
	cin>>userinput;
	
	for(int i=0;i<1;i++){
		if(userinput==companyName[i]){
		discount = 0.12;
				
	}
	
	if(room_no<=60){
	
		bill = (1000 * days) * discount;
	}
	else if(room_no>60 && room_no<89){
		bill = (1800 * days) * discount;
	}
	else{
		bill =  (2500 * days) * discount;

	}
	
	cout<<"bill is: "<<bill<<endl;
	
	
	
}
}
		
		
 //End  of function for paying in company

//to display the customer record
void hotel::display()
{

  system("cls");

ifstream fin("Record.dat",ios::in);
int r,flag;

cout<<"\n Enter room no. for a particular customer`s details :- "<<endl;
cin>>r;

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{

  system("cls");
cout<<"\n Cusromer Details";
cout<<"\n ----------------";
cout<<"\n\n Room no: "<<room_no;
cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Phone no: "<<phone;
flag=1;
break;

}

}

if(flag==0)
cout<<"\n Sorry Room no. not found or vacant....!!";

cout<<"\n\nEnter your favourite to continue....!!";

getch();
fin.close();
}


//END OF DISPLAY FUNCTION



//FUNCTION TO DISPLAY ALL ROOMS OCCUPIED


void hotel::rooms()
{

  system("cls");

ifstream fin("Record.dat",ios::in);
cout<<"\n\t\t\t    List Of Rooms Allotted";
cout<<"\n\t\t\t    ----------------------";
cout<<"\n\n Room No.\tName\t\tAddress\t\t\t\tPhone No.\n";

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
cout<<"\n\n "<<room_no<<"\t\t"<<name;
cout<<"\t\t"<<address<<"\t\t"<<phone;

}

cout<<"\n\n\n\t\t\tEnter your favourite to continue.....!!";
getch();
fin.close();

}


//FUNCTION FOR EDITING RECORDS AND FOR BILL


void hotel::edit()
{

  system("cls");

int choice,r;
cout<<"\n EDIT MENU";
cout<<"\n ---------";
cout<<"\n\n 1.Modify Customer Record";
cout<<"\n 2.Delete Customer Record";
cout<<"\n 3. Bill Of Customer";
cout<<"\n Enter your choice: ";

cin>>choice;
  system("cls");

cout<<"\n Enter Hall Number: " ;
cin>>r;

switch(choice)
{

case 1:	modify(r);
break;

case 2:	delete_rec(r);
break;

case 3: bill(r);
break;

default: cout<<"\n Wrong Choice.....!!";

}
cout<<"\n Enter your favourite to continue....!!!";

getch();
}


int hotel::check(int r)
{

int flag=0;

ifstream fin("Record.dat",ios::in);

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{

flag=1;
break;

}

}

fin.close();
return(flag);

}
// End FUNCTION FOR EDITING RECORDS AND FOR BILL



//FUNCTION TO MODIFY CUSTOMERS RECORD


void hotel::modify(int r)
{

long pos,flag=0;

fstream file("Record.dat",ios::in|ios::out|ios::binary);

while(!file.eof())
{

pos=file.tellg();
file.read((char*)this,sizeof(hotel));

if(room_no==r)
{

cout<<"\n Enter New Details";
cout<<"\n -----------------";
cout<<"\n Name: ";
cin>>name;
cout<<" Address: ";
cin>>address;
cout<<" Phone no: ";
cin>>phone;
file.seekg(pos);
file.write((char*)this,sizeof(hotel));
cout<<"\n Record is modified....!!";
flag=1;
break;

}

}

if(flag==0)
cout<<"\n Sorry Room no. not found or vacant...!!";
file.close();

}


//END OF MODIFY FUNCTION


//FUNCTION FOR DELETING RECORD


void hotel::delete_rec(int r)
{

int flag=0;
char ch;
ifstream fin("Record.dat",ios::in);
ofstream fout("temp.dat",ios::out);

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
if(room_no==r)

{

cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Pone No: "<<phone;
cout<<"\n\n Do you want to delete this record(y/n): ";
cin>>ch;

if(ch=='n')
fout.write((char*)this,sizeof(hotel));
flag=1;

}

else
fout.write((char*)this,sizeof(hotel));

}

fin.close();
fout.close();

if(flag==0)
cout<<"\n Sorry room no. not found or vacant...!!";

else
{

remove("Record.dat");
rename("temp.dat","Record.dat");

}

}


//END OF DELETE FUNCTION


//FUNCTION FOR CUSTOMER`S BILL

void hotel::bill(int r)
{

hotel h1;
ifstream f1;
 f1.open("record.dat",ios::in|ios::binary);

if(!f1)
 cout<<"cannot open";

 else
 {

  f1.read((char*)&h1,sizeof (hotel));
  while(f1)

  {

  f1.read((char*)&h1,sizeof(hotel));

  }

  if (h1.room_no == r)
  {

  if(h1.room_no>=1&&h1.room_no<=30)
  cout<<"your bill = 2000";

  else if (h1.room_no>=35&&h1.room_no<=45)
  cout<<"your bill = 5000" ;

  else
  cout<<"your bill = 7000";

  }

  else
  { cout<<"room no. not found";}

  }

  f1.close();
  getch();

}

//END OF BILLING FUNCTION

//START OF MAIN PROGARM


int main()
{
	void bar();

hotel h;

  system("cls");

cout<<"\n\t\t\t****************************";
cout<<"\n\t\t\t* Hall MANAGEMENT PROJECT *";
cout<<"\n\t\t\t****************************";
cout<<"\n\n\t\tDeveloped By:";
cout<<"\t Prince Baidoo Gyan";

cout<<"\n\n\n\n\n\n\n\t\t\t\t\t***************************************";
cout<<"\n\n\n\n\n\n\n\t\t\t\t\t*Enter your favourite to continue....!!*";
cout<<"\n\n\n\n\n\n\n\t\t\t\t\t***************************************";

getch();

h.main_menu();
return 0;
}

//END OF MAIN PROGRAM
