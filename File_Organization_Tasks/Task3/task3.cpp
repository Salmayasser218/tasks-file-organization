#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream out("welcome.txt");
    out << "Hello Everybody";
    out.close();

    fstream file("welcome.txt", ios::in | ios::out);
    file.seekp(11);
    file << "one ";
    file.close();

    ifstream in("welcome.txt");
    string line;
    getline(in, line);
    cout << line << endl;
    in.close();

    cout << "Press Enter to exit...";
    cin.get();
    return 0;
}