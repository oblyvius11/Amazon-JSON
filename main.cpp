

#include <iostream>
#include <sstream>
#include "proj3-MyString.h"

using namespace std;

int main()
{
    const char str[] = "Aiden";
    stringstream testFile;



    cout << "Creating MyString object named test1 and";
    cout << " assigning the \"Aiden\" to the object." << endl << endl;

    MyString test1(str);

    cout << "Printing the data of the  object using overloaded output operator: " << test1 << endl;

    MyString test2(" Grajo");

    cout << "Creating MyString object named test2 and";
    cout << " assigning the \" Grajo\" to the object using string parameters." << endl << endl;

    cout << "Adding the data of the  test2 object to the test1 object: " << endl;

    test1 += test2;

    cout << "Result: " << test1;
    cout << "Testing size return function: " << test1.length() << endl << endl;

    MyString test3;

    cout << "Testing getline function using stringstream containing \"Genuine confusion\": " << endl;

    testFile.str("Genuine confusion");
    test3.getline(testFile);

    cout << "Result of Test 3 Data: " << test3;
    cout << "Size: " << test3.length() << endl << endl;

    cout << "Testing overloaded assignment operator by assigning test4 with test3's data. " << endl;

    MyString test4 = test3;

    cout << "Test4 Data: " << test4 << endl;

    cout << "Testing overloaded comparison operator using test3 and test4. ";
    cout << "Expecting to be the same. " << endl;

    cout << "Result: ";

    if (test3 == test4) {
        cout << "Same data" << endl;
    }
    else {
        cout << "Data differs." << endl;
    }
    cout << endl;

    cout << "Testing overloaded bracket operator using test4. ";
    cout << "Expecting \"n\"." << endl;

    cout << "Result: " << test4[2] << endl;

    cout << "Testing copy constructor by assigning test5 with test3. ";
    cout << "Expecting same data as test3." << endl;

    MyString test5(test4);

    cout << "Result: " << test5 << endl;

    cout << "Testing concatenation operator using test1 and test2." << endl;

    test1 = test1 + test2;


    cout << "Expecting Aiden Grajo Grajo." << endl;
    cout  << "Result: " << test1 << endl;





    return 0;
}
