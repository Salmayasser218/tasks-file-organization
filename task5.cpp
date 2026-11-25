#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream file("students.txt", ios::app);
    char name[20];
    int id;
    float grade;
    char choice;

    do
    {
        cout << "Enter name: ";
        cin.ignore();
        cin.getline(name, 20);
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter grade: ";
        cin >> grade;

        file << name << ", " << id << ", " << grade << " $" << endl;

        cout << "Add more records? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    file.close();
    cout << "Records saved to students.txt" << endl;

    cin.ignore();
    cin.get();
    return 0;
}