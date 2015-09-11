/*Heading:
This is a program that stores hints about getting started in school. Students can add hints to three categories and they can also like a hint. 

By Mia Armstrong
CS163 
Program #1
*/
//File: main.cpp
//This is the testbed for assignment 1. 

#include <iostream>
using namespace std;
#include <cstring>
#include "menu.h"
#include "college_life.h"

const int SIZE=100;


int main()
{
   College_Life my_hint; //creates entries
   hint to_add, found;   

   int command = 0;
   int command2 = 0;
   int category = 0;
   int success = 0;
   char title[SIZE]; //temporary for hint entries
   char notes[SIZE];
   char matching_title[SIZE];

   

   
   cout << "Welcome to College Life!" << endl;
   do
   {
      menu();
      command = read_command();
      if(4 == command)
      {
         success = my_hint.Display();
         if (success == 0)
           cout << "There are no hints to display." << endl;
      }
      if(1 == command)//category = registering
         category = 0; 
      else if(2 == command)//category = materials
         category = 1;
      else if(3 == command)//category = homework
         category = 2;
      if(0 < command < 4)
      {
         do
         { 
            menu2();
            command2 = read_command();
            if(1 == command2)
            {
                success = my_hint.Display(category);
                if (success == 0)
                   cout << "There are no hints to display. " << endl;
            }
            else if(2 == command2)
            {
               cout << "Enter the title of your hint. " << endl;
               cin.get(title, SIZE, '\n');
               cin.ignore(SIZE, '\n');
               cout << "Enter a hint and press enter." << endl;
               cin.get(notes, SIZE, '\n');
               cin.ignore(SIZE, '\n');
               //create a hint
               to_add.create_hint(title, notes);
               //Add it to the list
               my_hint.Add_Hint(to_add);
            }
            else if(3 == command2)
            {
              my_hint.Display(category);
              cout << "Enter the title of the hint you like." << endl;
              cin.get(matching_title, SIZE, '\n');
              cin.ignore(SIZE, '\n');
              if (my_hint.Like(category, matching_title, found))
              {
                  cout << "\n\nYou liked: " << endl;
                  found.display();
              }
              else 
                 cout << "Hint not found." << endl;
            }
          }while(4 != command2);
       }
    }while(again());
            
}
