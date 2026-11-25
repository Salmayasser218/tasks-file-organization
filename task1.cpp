#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string name;
    int id;
    float grade;

    cout << "Enter Full Name: ";
    getline(cin, name);
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Grade: ";
    cin >> grade;

    ofstream myfile;
    myfile.open("Student.txt");

    if (!myfile.is_open())
    {
        cout << "Error, file is not opened";
    }
    else
    {
        myfile << "Name: " << name << endl;
        myfile << "ID: " << id << endl;
        myfile << "Grade: " << grade << endl;
        cout << "File opened successfully" << endl;
        cout << "Student data written successfully";
    }
    myfile.close();

    cin.ignore();
    cin.get();
    return 0;
}