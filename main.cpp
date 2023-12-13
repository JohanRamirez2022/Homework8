#include "ArrayDictionary.h"
#include <iostream>
#include <cstring>

using namespace std;

ArrayDictionary<int, string> contacts;

void search(int& number)
{
    cout << "name of " << number << "is: " << contacts.getValue(number) << endl;
}

void updateNum(int& oldNum, int& newNum, string& name)
{
    contacts.remove(oldNum);
    contacts.add(newNum, name);
}


void delNumber(int& num)
{
    contacts.remove(num);
}


void addNumber(string& name, int& number)
{
    contacts.add(number,name);
}

int main()
{

    int choice = 0; 
    int number;
    int number2;
    string name;
    string name2;

    cout << "Would you like to:" << endl;
    cout << "1) Add" << endl;
    cout << "2) Delete" << endl;
    cout << "3) Update " << endl;
    cout << "or" << endl;
    cout << "4) Search for a number?"<< endl;
    cout << "5) Exit." << endl;

    cin >> choice;
    while (choice != 5)
    {
        switch(choice)
        {
            case 1:

                cout << "Enter the name of the contact:" << endl;
                cin >> name;
                cout << "Enter the number of the contact:" << endl;
                cin >> number;

                addNumber(name, number);
                cout << contacts.getValue(number) << endl;
                break;

            case 2:
                cout << "Enter the number of the contact:" << endl;
                cin >> number;

                delNumber(number);
                break;

            case 3:
                cout<< "Enter the number of the contact you're updating:" << endl;
                cin >> number;
                cout << "Enter the updated number;" << endl;
                cin >> number2;
                cout << "Enter the updated name;" << endl;
                cin >> name;

                updateNum(number, number2, name);
                break;
                
            case 4:
                cout<< "Enter the number of the person who's name you're looking for:" << endl;
                cin >> number;

                search(number);
                break;
        }
    }
}