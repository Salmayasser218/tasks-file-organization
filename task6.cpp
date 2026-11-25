#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main()
{
    ofstream out("grades.txt");
    if (out.fail())
    {
        cout << "Unable to open the file";
        return 1;
    }
    int g;
    cout << "Enter 5 integer grades: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> g;
        out << g << endl;
    }
    out.close();

    ifstream in("grades.txt");
    if (in.fail())
    {
        cout << "Unable to open the file";
        return 1;
    }
    cout << "Grades in file:" << endl;
    while (in >> g)
    {
        cout << g << endl;
    }
    in.close();

    int del;
    cout << "Enter a grade to delete: ";
    cin >> del;

    in.open("grades.txt");
    ofstream temp("temp.txt");
    bool found = false;
    while (in >> g)
    {
        if (g == del)
            found = true;
        else
            temp << g << endl;
    }
    in.close();
    temp.close();

    if (found && remove("grades.txt") == 0 && rename("temp.txt", "grades.txt") == 0)
    {
        cout << "Success: grade deleted" << endl;
    }
    else
    {
        remove("temp.txt");
        cout << "Error: grade not found or file could not be replaced" << endl;
    }

    cin.ignore();
    cin.get();
    return 0;
}