/*Heading:
This is a program that stores hints about getting started in school. Students can add hints to three categories and they can also like a hint. 

By Mia Armstrong
CS163 
Program #1
*/
//File: menu.cpp
//This is the file for the functions for the menu

#include "menu.h"
using namespace std;

//Displays the first menu
void menu()
{
   cout << "Please choose an option: " << endl << endl
        << " 1) Registering " << endl << endl
        << " 2) Buying Materials " << endl << endl
        << " 3) Completing Homework " << endl << endl
        << " 4) Quit " << endl << endl << endl;
}

//Displays the second menu
void menu2 ()
{
   cout << "Please choose an option: " << endl << endl
        << " 1) View all hints in this category " << endl << endl
        << " 2) Add a hint to this category " << endl << endl
        << " 3) Like a hint in this category " << endl << endl
        << " 4) Return to main menu " << endl << endl << endl;
}

//This function makes sure that the response the user inputs is a number 
//between 1 and 4.
int get_num()
{
   int response = 0;
   cin >> response;
   cin.ignore(100, '\n');
   
   while (!cin || response < 0 || response > 4)
      {
         cout << "\nEnter a number between 1 and 4! Please try again. ";
         cin >> response;
         cin.ignore(100, '\n');
      }
      return response;
}

//This function prompts the user to quit the program or not.
bool again()
{
    char response;

    cout << "Would you like to quit (y/n)? ";
    cin >> response;
    cin.ignore(100, '\n');
    response = (tolower(response));
 
   while ('n' != response && 'y' != response)
    {
        cout << "Please enter y or n: ";
        cin >> response;
        cin.ignore(100, '\n');
        response = (tolower(response));
    }

    if ('y' == response)
       return false;
    else
       return true;
}

//This function prompts the user for a command and sends it to an error
//checking function.
int read_command()
{
   cout << " Please enter your choice: (1, 2, 3, or 4) ";
   int command = get_num();
   return command;
}

