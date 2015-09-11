/*Heading:
This is a program that stores hints about getting started in school. Students can add hints to three categories and they can also like a hint. 

By Mia Armstrong
CS163 
Program #1
*/
//File: hint.h
//This file contains the data class.
//This supports title and notes for hint entries. 

#include <cstring>
#include <cctype>
#include <iostream>

class hint
{
    public:
       hint(void);
       ~hint(void);
       int create_hint(char * title, char * notes);
       int display(void);
       int remove_entry(void);
       int copy_hint(const hint & a_hint);
       int retrieve(int category, char * matching_title, hint & found);
    private:
       char * title;
       char * notes;
};

