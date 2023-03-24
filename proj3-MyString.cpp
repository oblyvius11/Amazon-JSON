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
 * This file contains the definitions of the functions written.
 */
#include "proj3-MyString.h"

MyString::MyString() {
    size = 0;
    capacity = 0;
    data = new char[this -> capacity];

    data[size] = '\0';
}

MyString::MyString(const char *a) {
    size = 0;
    capacity = MAX_SIZE;
    data = new char[capacity];

    char* temp = nullptr;

    for (int i = 0; a[i] != '\0'; i++) {
        data[i] = a[i];
        size++;
    }

    if (size + 1 == capacity) {
        capacity *= 2;
        temp = new char[capacity];

        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }

        delete[] data;
        data = temp;
    }
    while (capacity / 4 > size) {
        capacity /= 2;
    }

    data[size] = '\0';
}

MyString::~MyString() {
    cout << "Deleting Data." << endl;
    delete[] data;
}

MyString::MyString(const MyString &a) {
    capacity = a.capacity;
    size = a.size;
    data = new char[capacity];

    for (int i = 0; i < size; i++) {
        data[i] = a.data[i];
    }
}

MyString& MyString::operator = (const MyString& a) {
    capacity = a.capacity;
    size = a.size;
    char* tmp;
    delete[] data;
    tmp = new char[capacity];

    data = tmp;

    for (int i = 0; i < size; i++) {
        data[i] = a.data[i];
    }

}

bool MyString::operator == (const MyString& a) const {
    bool comp;
    if (*data == *a.data) {
        comp = true;
    }
    else if (*data != *a.data) {
        comp = false;
    }

    return comp;
}

char& MyString::operator [ ] (int a) {
    return data[a];
}

void MyString::operator += (const MyString& a) {
    int newSize = size + a.size;
    char* newData = new char [newSize + 1];

    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    for (int i = 0; i < a.size; i++) {
        newData[size + i] = a.data[i];
    }

    newData[newSize] = '\0';

    delete[] data;

    data = newData;
    size = newSize;
}

MyString MyString::operator + (const MyString& a) const {

    MyString b;

    int newSize = size + a.size;
    char* newData = new char [newSize + 1];

    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    for (int i = 0; i < a.size; i++) {
        newData[size + i] = a.data[i];
    }

    newData[newSize] = '\0';

    b.data = newData;
    b.size = newSize;

    return b;

}

void MyString::getline(istream& in, char delimit) {
    char letter;
    string result;
    char* newSize;
    int count = 0;

    letter = in.get();

    while (in && letter != delimit) {
        result += letter;
        letter = in.get();
        count++;
    }

    if (count > size) {
        capacity *= 2;
    }

    while (capacity / 4 > size) {
        capacity /= 2;
    }

    delete[] data;

    data = new char [capacity];

    size = 0;

    for (int i = 0; i < result.length(); i++) {
        data[i] = result[i];
        size++;
    }

}

int MyString::length() const {
    return size;
}



ostream& operator<< (ostream& out, MyString& a) {
    out << a.data << endl;

    return out;
}



