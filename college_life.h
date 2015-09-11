/*Heading:
This is a program that stores hints about getting started in school. Students can add hints to three categories and they can also like a hint. 

By Mia Armstrong
CS163 
Program #1
*/
// File: college_life.h
// This file contains the node structure as well as the ADT class which 
//uses LLLs.

#include "hint.h"
using namespace std;

struct node
{
    hint entry;
    int likes;
    node * next;
};

class College_Life
{
    public:
       College_Life();
       ~College_Life();
       int Add_Hint(hint & to_add);
       int Like(int category, char matching_title[], hint & found); //find and like by title
       int Display(); //display all
       int Display(int category); //display all for a category
    private:
       node * head_registering;
       node * head_materials;
       node * head_homework;
};

    
