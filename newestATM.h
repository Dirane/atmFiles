// class description with its various prototypes
 #ifndef NEWESTATM_H
 #define NEWESTATM_H
 #include <iostream>
 #include <stdbool.h>
 #include"ClientData.h"

 using namespace std;

 class Account
 {
   private:
   	string UserName;
   	int accountNo;
   	int pin;
   	double balance;
   	int Borrow;
	      
	   	
 public:
 
    //default Account constructor
    Account(string , int, int, double, int);

    // function to run program
    void Launch();
    // functions to display various screens
     void DisplayLoginScreen( void ); // function displays the main page
     void DisplayMenuScreen( void );  // function prints the 3 main choice
    // functions to manage accounts
    void Withdrawal ();
    void Deposit ();
    void CheckBalance();
    void SeeMyAccouts();
    void SeeAllAccounts();
    void SetAtm();
    
	//void AddNewUser();      
   };
 #endif // end of atm header file
