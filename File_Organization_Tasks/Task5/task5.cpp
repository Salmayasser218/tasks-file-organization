#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char name[20], c = 'y';
    int id;
    float grade;
    ofstream out("students.txt", ios::app);
    while (c == 'y') {
        cout << "Enter name: ";
        cin.ignore();
        cin.getline(name, 20);
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Grade: ";
        cin >> grade;
        out << name << ", " << id << ", " << grade << " $";
        cout << "Add more (y/n)? ";
        cin >> c;
    }
    out.close();
    return 0;
}