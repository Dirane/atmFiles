 /*------------------------------------------*
 *    University of Buea                     *
 *    Dept: Computer Science                 *
 *    CSC305 Course Project                  *
 *-------------------------------------------*
 *    Program to simulation an ATM           *
 * ------------------------------------------*
 *    Author: ngala Dirane Ngiri             *
 *    Matricule Number: SC14B371             *
 *-------------------------------------------*/

#include <iostream>
#include "newestATM.h"
#include "ClientData.h"
#include <fstream>

using namespace std;

//void outputLine(ostream &output, const ClientData &record);

int main()
{
	ClientData  newAcc(1,100,"DIRANE", 100.5);

    Launch();

    cout<<endl;
    cout<<endl;
    return 0;
} // end main function


