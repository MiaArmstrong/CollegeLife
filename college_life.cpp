/*Heading:
This is a program that stores hints about getting started in school. Students can add hints to three categories and they can also like a hint. 

By Mia Armstrong
CS163 
Program #1
*/
//File: college_life.cpp 
//This file houses all the ADT functions for the class College_Life


#include "college_life.h"
using namespace std;

//constructor to allocate memeory
College_Life::College_Life()
{
    head_registering = NULL;
    head_materials = NULL;
    head_homework = NULL;
    likes = 0;
}

//destructor to deallocate memory
College_Life::~College_Life()
{
    node * temp = head_registering;
    while (head_registering)
    {
        temp->entry.remove_entry();
        temp = temp->next;
        delete head_registering;
        head_registering = temp;
    }
    
    temp = head_materials;
    while (head_materials)
    {
        temp->entry.remove_entry();
        temp = temp->next;
        delete head_materials;
        head_materials = temp;
    }
   
    temp = head_homework;
    while (head_homework)
    {
        temp->entry.remove_entry(); 
        temp = temp->next;
        delete head_homwork;
        head_homework = temp;
    }
    delete temp;
           
}

//This function will take the hint and add it to the end 
//of the linear linked list of the specified category.
int College_Life::Add_Hint(int category, hint & to_add)
{
    
    if (category == 0)
       node * current = head_registering;
    else if(category == 1)
       node * curremt = head_materials;
    else if(category == 2)
       node * current = head_homework;
    else
       return 0;

    node * temp = new node;
    int success = temp->entry.copy_entry(to_add); //create a new node and fill it with data

    if(!current)
    {
        current = temp;
        current->next = NULL;
    }
    else 
    {
        while (current)
           current = current->next;
        current->next = temp;
        temp->next = NULL;
    }
    return success;   
}

//This function will determine if there is a match for the title entered.
//if there is a match it will increment the likes.
int College_Life::Like(int category, char matching_title[], hint & found);
{
    if (category == 0)
       node * current = head_registering;
    else if(category == 1)
       node * curremt = head_materials;
    else if(category == 2)
       node * current = head_homework;
    else
       return 0;
    
    if (!current)
       return 0;
    
    while (current) 
    {
       int success = current->entry.retrieve(category, matching_title, found);
       if (success != 0)
       {
           ++current->likes;
           return sucess;
       }
       else 
          current = current->next;
    }
}

//This function displays all the hints in each category
int College_Life::Display()
{
    Display(registering);
    Display(materials);
    Display(homework);
}

//This function displays all the hints in the specified category
int College_Life::Display(int category)
{
    if (category == 0)
       node * current = head_registering;
    else if (category = 1)
       node * curremt = head_materials;
    else if (category == 2)
       node * current = head_homework;
    else
       return 0;
    
    while (current)
    {
        current->entry.display();
        cout << "Likes: " << current->likes << endl;
        current = current->next;
    }
}


