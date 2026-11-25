#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream file("welcome.txt");
    if (!file.is_open())
    {
        cout << "Error opening the file";
        return 1;
    }
    file << "Hello Everybody";
    file.close();

    fstream f("welcome.txt", ios::in | ios::out);
    if (!f.is_open())
    {
        cout << "Error opening the file";
        return 1;
    }
    f.seekp(11);
    f << "one ";
    f.close();

    ifstream in("welcome.txt");
    string line;
    getline(in, line);
    cout << line << endl;
    in.close();

    cin.get();
    return 0;
}