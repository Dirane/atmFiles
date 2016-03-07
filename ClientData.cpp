// Class ClientData stores customer's account details.
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "ClientData.h"
using namespace std;

// default ClientData constructor
ClientData::ClientData( int accountNumberValue, int pinCodeValue,
 string UserNameString, double balanceValue )
 {
   setAccountNumber( accountNumberValue );
   setPinCode( pinCodeValue );
   setUserName( UserNameString );
   setBalance( balanceValue );
 } // end ClientData constructor

 // get account-number value
  int ClientData::getAccountNumber() const
  {
   return accountNumber;
  } // end function getAccountNumber

  // set account-number value
 void ClientData::setAccountNumber( int accountNumberValue )
 {
 accountNumber = accountNumberValue; // should valdate
 } // end function setAccountNumber

 // set pin-code value
 void ClientData::setPinCode(int pinCodeValue)
 {
 	pinCode = pinCodeValue;
 }// end function setPinCode
 
 // get pin code value
 int ClientData::getPinCode() const
 {
 	return pinCode;
 }// end function getpincode value
 
 // get last-name value
 string ClientData::getUserName() const
 {
   return UserName;
 } // end function getLastName

 // set last-name value
 void ClientData::setUserName( string UserNameString )
{
 // copy at most 15 characters from string to lastName
int length = UserNameString.size();
 length = ( length < 15 ? length : 14 );
 UserNameString.copy(UserName, length);
 UserName[ length ] = '\0' ; // append null character to lastName
 } // end function setName

 // get balance value
 double ClientData::getBalance() const
 {
   return balance;
 } // end function getBalance

// set balance value
 void ClientData:: setBalance( double balanceValue )
 {
   balance = balanceValue;
 } 
 
 void ClientData::fileCreator()
{
	ofstream outdatabase( "ATMData.txt", ios::out | ios::binary );

// exit program if ofstream could not open file
if (!outdatabase)
{
 cerr<< "File could not be opened." << endl;
 exit( 1 );
} // end if

ClientData blankClient; // constructor zeros out each data member


 // output 100 blank records to file
for ( int i = 0; i < 10000; ++i )
    outdatabase.write(reinterpret_cast< const char *>(&blankClient),
    sizeof(ClientData));

} // end file creator

// create account
void ClientData::createAccount ()
{
	int accountNumber;
	int pinCode;
	string UserName;
	
	double balance;

    fstream outdatabase( "ATMData.txt", ios::in | ios::out | ios::binary );

// exit program if fstream cannot open file
 if (!outdatabase)
    {
   cerr << "File could not be opened." << endl;
   exit( 1 );
   } // end if

  cout << "Enter account number (1 to 10000, 0 to end input)\n? ";

 // require user to specify account number
   ClientData database;
   cin >> accountNumber;

 // user enters information, which i  copied into file
while ( accountNumber > 0 && accountNumber <= 10000 )
 {
// user enters pin code, user name, and balance
cout << "Enter Pin code, User name,  balance\n? ";
 
 cin >> pinCode;
 cin >>UserName;

 cin >> balance;

 // set record accountNumber, pincode, UserName, balance values
   database.setAccountNumber( accountNumber ) ;
   database.setPinCode(pinCode);
   database.setUserName( UserName );
   //database.setFirstName( firstName ) ;
   database.setBalance( balance );

// seek position in file of user-specified record
outdatabase.seekp( ( database.getAccountNumber() - 1 ) *
sizeof( ClientData ) ) ;

 // enable user to enter another account
 cout << "Enter account number\n? ";
 cin >> accountNumber;
 } // end while
 } // end save data to file

void ClientData::outputLine(ostream &output, const ClientData &record )
{
output << left << setw(10) << record.getAccountNumber()
<< record.getPinCode()
<< setw( 16 ) << record. getUserName()

<< setw( 10 ) << setprecision( 2 ) << right << fixed
<< showpoint << record.getBalance() << endl;
} // end function outputLine

void ClientData::searchAccount()
 {
	ifstream indatabase("ATM.txt", ios::in | ios::binary);

// exit program if ifstream cannot open file
if (!indatabase )
 {
 cerr << "File could not be opened." << endl;
 exit( 1 );
 } // end if

 cout << left << setw( 10 ) << "Account" << setw( 16 )
<< setw( 11 ) << "User Name" << left
 << setw( 10 ) << right << "Balance" << endl;

 ClientData database; // create record

indatabase.read(reinterpret_cast< char *>(&database),
   sizeof(ClientData));

// read all records from fil e
while (indatabase && !indatabase.eof() )
{
  // display record
 
 if ( database.getAccountNumber() != 0 )
     //outputLine(cout, client);

  indatabase.read(reinterpret_cast < char *>(&database),
        sizeof(ClientData));
  
} // end while
} // end search record

