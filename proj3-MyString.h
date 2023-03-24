/**
 * file:  proj3-MyString.cpp
 * author:  Aiden Grajo
 * course: CSI 1440
 * assignment:  project 3
 * due date:  2/13/2023
 *
 * date modified:  2/12/2023
 *  - Testing functions
 *
 * This file contains the declarations and the class of the functions written.
 */
#include <iostream>
#include <fstream>
#include <cstring>

#ifndef PROJ3-MYSTRING_H_INCLUDED
#define PROJ3-MYSTRING_H_INCLUDED

using namespace std;

const int MAX_SIZE = 10;
class MyString {

public:

    // Default Constructor
    MyString(); //

    // Constructor with an initialization character string
    MyString(const char *); //

    // Destructor
    ~MyString(); //

    // Copy constructor
    MyString(const MyString &); //

    // Overloaded assignment operator, make a copy of MyString object
    MyString& operator = (const MyString&); //

    // Overloaded equivalence relational operator
    bool operator == (const MyString&) const; //

    // Overloaded [ ] should return a char by reference
    char& operator [ ] (int); //

    // Overloaded += operator, use to concatenate two MyStrings
    void operator += (const MyString&); //

    // Create a new MyString object that is the concatenation of two MyString objects
    MyString operator + (const MyString&) const;

    // Reads an entire line from a istream. Lines are terminated with delimit which is newline
    // ‘\n’ by default
    void getline(istream& in, char delimit = '\n'); //

    // Return the length of the string
    int length( ) const; //

    // Overloaded insertion operator
    friend ostream& operator<< (ostream& out, MyString&); //



private:
    int size;  // The number of characters currently stored in the string
           // object. Do NOT count the NULL character.
    int capacity; // The number of bytes currently allocated. This should always be at least
                  // size + 1. The extra byte is needed to store the NULL character.
    char *data; // Character pointer that points to an array of characters.

};


#endif // PROJ3-MYSTRING_H_INCLUDED
