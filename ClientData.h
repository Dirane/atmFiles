// Class ATMData definition
#ifndef CLIENTDATA_H
#define CLIENTDATA_H

#include <string>
#include <fstream>
#include"newestATM.h"
using namespace std;

class ClientData
{
public:
// default ClientData constructor
ClientData( int = 0, int = 0, string = "", double = 0.0 );

// accessor functions for accountNumber
void setAccountNumber( int );
int getAccountNumber() const;

// accessor functions for Name
void setUserName( string ) ;
string getUserName() const;
// accessor functions for balance
void setBalance( double );
double getBalance() const;

// accessor functions for pin code
void setPinCode( int );
int getPinCode() const;


// file creator
void fileCreator();
void createAccount();
void outputLine(ostream &output, const ClientData &record);
void searchAccount();

private:
	int accountNumber;
	int pinCode;
	char UserName[15];
	double balance;
}; // end class ClientData

#endif
