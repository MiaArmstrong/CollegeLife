/*Heading:
This is a program that stores hints about getting started in school. Students can add hints to three categories and they can also like a hint. 

By Mia Armstrong
CS163 
Program #1
*/
//File: hint.cpp
//This file contains all the functions for the data class, hint.

#include "hint.h"
using namespace std;

//This function is the constructor
hint::hint()
{
   title = NULL;
   notes = NULL;
}

//This function is the destructor
hint::~hint()
{ 
    if (title)
       delete [] title;
    title = NULL;
    if (notes)
       delete [] notes;
    notes = NULL;
}

//This function takes in a pointer to a title and notes and deep copies
//them into newly allocated arrays.
int hint::create_hint(char * title, char * notes)
{
    if (!title || !notes)
       return 0;
    
    title = new char[strlen(title) +1];
    strcpy(title, title);

    notes = new char[strlen(notes) +1];
    strcpy(notes, notes); 
}

//This function displays a hint.
int hint::display(void)
{
    cout << title  << '\n' << notes << endl;
}

//This function assists the ADT class destructor in deallocating the arrays
int hint::remove_entry(void)
{
    if (title)
       delete [] title;
    title = NULL;
    
    if (notes)
       delete [] notes;
    notes = NULL;

}
//This function takes the argument and copies it into
//the journal's data members. 
int hint::copy_hint(const hint & a_hint)
{
    if (title)
       delete [] title;
    if (notes)
       delete [] notes;

    if (a_hint.title)
    {
        title = new char[strlen(a_hint.title) + 1];
        strcpy(title, a_hint.title);
    }
    if (a_hint.notes)
    {
       notes = new char[strlen(a_hint.notes) + 1];
       strcpy(notes, a_hint.notes);
    }
}

//This function will return non-zero if the title sent in 
//as an argument matches the data member. It supplies the matching
//hint back as an argument.
int hint::retrieve(int category, char * matching_title, hint & found) 
{
   if (found.title && !strcmp(matching_title, found.title))
   {
       delete [] found.title;
       if (found.notes)
          delete [] found.notes;
       return 0;
    } // ensure there is no memory leak

    found.title = new char[strlen(title) +1];
    strcpy(found.title, title);
    if (notes)
    {
        found.notes = new char[strlen(notes) +1];
        strcpy(found.notes, notes);
    }
    
}


