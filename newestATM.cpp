/*-------------------------------------------*
 *    University of Buea                     *
 *    Dept: Computer Science                 *
 *    CSC305 Course Project                  *
 *-------------------------------------------*
 *    Program to simulation an ATM           *
 * ------------------------------------------*
 *    Author: Ngala Dirane Ngiri             *
 *    Matricule Number: SC14B371             *
 *-------------------------------------------*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include"ClientData.h"
#include"newestATM.h"


using namespace std;

// constructor for the ATM project
Account::Account(string name, int accNo, int code, double amt, int Bamt)
        : UserName(name),
          accountNo(accNo),
          pin(code),
          balance(amt),
          Borrow(Bamt)
                   
{  /*empty body */}; // end of constructor

void Account::SeeAllAccounts(){
int account;
	string name;
	double bal;
	int code, AccN;
	
	ifstream database("ATMData.txt", ios::in);
	
	//exit program if the file cannot open
	if (!database){
		cerr<<"\nFile could not be opened."<<endl;
		exit(1);
	}
	cout<<left<<setw(8)<<"\nName"<<setw(13)
	    <<"Account No"<<setw(13)<<"PIN code"<<setw(13)<<"Balance"<<endl<<fixed<<showpoint;
	    
	database>>name>>AccN>>code>>bal;
	
	while(!database.eof()){
		cout<<left<<setw(8)<<name<<setw(13)<<AccN
	    <<setw(13)<<code<<setw(8)<<setprecision(1)<<right<<bal<<endl;
		database>>name>>AccN>>code>>bal;
	}
	
	database.close();
	
	char ans;
 cout<<"\n\nDo you want another transaction?"
     <<"\n(...Enter \'y\' to continue or \'n\' to Exit...)";
     
 cin>>ans;
 if ((ans = 'y' )|| (ans = 'Y'))
     DisplayMenuScreen();
else
    exit(1);
} //end of See All Accounts

void Account::Withdrawal(){
	double amt;
	cout<<"\n\tEnter amount to withdraw\n"
	    <<"\tAmount Entered : ";
	cin>>amt;
	if (amt > balance + 10000)
	    cout<<"Insufficient funds";
	    else
	    balance -= amt;
}

void Account::Deposit(){
	system("cls");
	// ofstream constructor to open file Mydata.txt
 	ofstream database("ATMdata.txt", ios::app);
 	
 	// exit program if unable to create file database.txt 
 	if (!database) {
 		cerr<<"\nThe database could not be opened."<<endl;
 		exit(1); // exit program and ignore any othe instruction
	 }
 	
 	int account, code;
 	string name;
 	double amt;
 	
 	cout <<"\nPlease enter name : ";
 	cin >>name;
 	cout <<"\nPlease enter account number : ";
 	cin >>account;
 	cout <<"\nPlease enter PIN number : ";
 	cin >>code;
 	cout <<"\nPlease enter amount to deposit : ";
 	cin >>amt;
 	     
 	database<<name<<' '<<account<<' '<<code<<' '<<amt<<endl;
    database.close();
    
    cout<<"\nDeposit transaction successfully completed.";
    
    char ans;
 cout<<"\n\nDo you want another transaction?"
     <<"\n(...Enter \'y\' to continue or \'n\' to Exit...)";
     
 cin>>ans;
 if ((ans = 'y' )|| (ans = 'Y'))
     DisplayMenuScreen();
else
    exit(1);
}// end of deposits
	


void Account::CheckBalance(){
    	cout<<"\nThe net balance is "
    	    <<balance<<endl;
       }  
       
void Account::SeeMyAccouts(){
	cout<<left<<setw(10)<<"UserName"<<setw(13)<<"AccountNo"
	    <<setw(7)<<right<<setw(13)<<"Balance"<<endl;
	cout<<left<<setw(10)<<UserName<<setw(13)<<accountNo
	    <<setw(7)<<right<<setw(13)<<balance<<endl;
   }
   
  
 void Account::SetAtm(){
 	
 	int amt;
 	cout<<"\nPlease enter amount to load the ATM"
 	    <<"\nAmount Entered : ";
 	    
 	cin>>amt;
 	Borrow += amt;
 }
 


 //function to display Login Screen
void Account::DisplayLoginScreen(void)
{
	system("cls");
    cout << "\n\t\t------------------------------------------"
	     << "\n\t\t|                                         |"
         << "\n\t\t|        Welcome to ATM Simulation        |"
         << "\n\t\t|      -----------------------------      |" 
         << "\n\t\t|                                         |"
         << "\n\t\t|             Designed by:                |"
         << "\n\t\t|          Ngala Dirane Ngiri             |"
         << "\n\t\t|              ------------               |"
         << "\n\t\t|          Matricule No: SC14B371         |"
         << "\n\t\t|                                         |"
         << "\n\t\t------------------------------------------"
         << "\n\n\t\t                Login Menu"
         << "\n\t\t             ----------------"
         << "\n\t\t 1 - Old User"
         << "\n\t\t 2 - New User"
         << "\n\t\t 3 - Administrator"
         << "\n\t\t 4 - Exit"
         << "\n\n\t\t   Select option using (1 - 4)"
         << "\n\t\t   Option Selected : ";
     
    return;
} // end of function DisplayLoginScreen()

 //function to display Main menu Screen
void Account::DisplayMenuScreen( void )
{
	system("cls");
    cout << "\n\t\t------------------------------------------"
	     << "\n\t\t|                                         |"
         << "\n\t\t|        Welcome to ATM Simulation        |"
         << "\n\t\t|      -----------------------------      |" 
         << "\n\t\t|                                         |"
         << "\n\t\t|             Designed by:                |"
         << "\n\t\t|          Ngala Dirane Ngiri             |"
         << "\n\t\t|              ------------               |"
         << "\n\t\t|          Matricule No: SC14B371         |"
         << "\n\t\t|                                         |" 
         << "\n\t\t------------------------------------------"
         << "\n\n\t\t               Main Menu"
         << "\n\t\t            --------------"
         << "\n\t\t 1 - Withdrawal"
         << "\n\t\t 2 - Deposit"
         << "\n\t\t 3 - Check Balance"
         << "\n\t\t 4 - See Account Details"
         << "\n\t\t 5 - Exit"
         << "\n\n\t\t   Select option using (1 - 5)"
         << "\n\t\t   Option Selected : ";
     
    int option;
  	cin>>option;
    switch (option){
    	case 1:
    		   system("cls");
    		   Withdrawal();
    		   break;
    	
    	case 2: 
    	       Deposit();
    	       break;
    	
    	case 3:
    		   CheckBalance();
    		   break;
    	
    	case 4:
    		   SeeMyAccouts();
    		   break;
    		   
        case 5:
		      DisplayLoginScreen();
	          break;
	    default:
	    	cout<<"\n\t\t Invalid choice\n";
	    	DisplayLoginScreen();
	    	break;
  } 
     return;
} // end of function DisplayMenuScreen()

 //The commander-in-chief. The one that pulls the trigger for the maggic to begin.
void Account::Launch()
{
    system("cls");
    DisplayLoginScreen();
    
    int Login;
    cin>>Login;
    
    switch (Login){
    	case 1:
    		   system("cls");
    		   searchAccount();
    		   break;
    	
    	case 2: 
    	       createAccount();
    	       break;
    	
    	case 3:
    		int choice;
    		   cout<< "\n\t\t 1 - See All Acounts"
         			<< "\n\t\t 2 - Reset ATM"
         			<< "\n\t\t 3 - Exit"
        			 << "\n\n\t\t   Select option using (1 - 3)"
        			 << "\n\t\t   Option Selected : ";
        			 switch(choice){
        			 	case 1:
        			 		SeeAllAccounts();
        			 		break;
        			 	case 2:
        			 		SetAtm();
        			 		break;
        			 	case 3:
        			 		DisplayLoginScreen();
        			 		break;
        			 		default:
        			 			cout<<"\n\t\tinvalid option\n";
        			 			DisplayLoginScreen();
        			 			break;
					 }
    		   break;
    	
    	case 4:
		   system("cls");
    		   cout<<"THANKYOU GOODBYE!!!";
    		   DisplayLoginScreen();
    		   break;
    	default:
    		cout<<"\n\t\tInvalid choice\n";
    		DisplayLoginScreen();
}
    
   
}

    
